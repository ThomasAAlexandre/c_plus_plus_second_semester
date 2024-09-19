//
//  mapImpl.h
//
//  Auteur : Jean Goulet
//  Copyleft  2017 UdeS
//
//  Modifie par : Vincent Ducharme, Hiver 2018
//
//  Devoir fait par
//     CoÈquipier 1 : Thomas Alexandre
//     CoÈquipier 2 :

#ifndef mapImpl_h
#define mapImpl_h

#include <algorithm>

///////////////////////////////////////////////////////////////////////////
// lower_bound O(log n)

template <typename Tclef, typename Tvaleur>
typename map<Tclef, Tvaleur>::iterator map<Tclef, Tvaleur>::lower_bound(const Tclef& c) const
{
    if (m_size == 0) {
            return iterator(m_apres);
        }

        noeud* p = m_apres->m_gauche;
        noeud* lower_bound_node = nullptr;

        while (p != nullptr) {
            if (!(p->m_contenu->first < c)) {
                lower_bound_node = p;
                p = p->m_gauche;
            } else {
                p = p->m_droite;
            }
        }

        if (lower_bound_node != nullptr) {
            return iterator(lower_bound_node);
        } else {
            return iterator(m_apres); // No lower bound found
        }
}



///////////////////////////////////////////////////////////////////////////
//erase a partir d'une position

template <typename Tclef, typename Tvaleur>
typename map<Tclef, Tvaleur>::iterator map<Tclef, Tvaleur>::erase(iterator i)
{
    /*assert(i!=end());
    erase(i++->first);
    return i;*/
    
    noeud* currentNode = i.m_courant;

        if (currentNode == m_apres->m_gauche)
        {
            erase(currentNode->m_contenu->first);
            return i;
        }

        noeud* parent = currentNode->m_parent;

        if (currentNode != m_apres)
        {
            if (parent->m_gauche == currentNode)
            {
                if (erase(i.m_courant->m_contenu->first, reference(i.m_courant), i.m_courant) && parent != m_apres)
                {
                    --(parent->m_indice);
                    if (parent->m_indice == -2)
                    {
                        if (parent->m_droite && parent->m_droite->m_indice == 1) rotation_gauche_droite(reference(parent->m_droite));
                        rotation_droite_gauche(reference(parent));
                        return iterator(parent);
                    }
                }
            }
            else
            {
                if (erase(i.m_courant->m_contenu->first, reference(i.m_courant), i.m_courant) && parent != m_apres)
                {
                    ++(parent->m_indice);
                    if (parent->m_indice == 2)
                    {
                        if (parent->m_gauche && parent->m_gauche->m_indice == -1) rotation_droite_gauche(reference(parent->m_gauche));
                        rotation_gauche_droite(reference(parent));
                        return iterator(parent);
                    }
                }
            }
        }

        currentNode = parent;

        for (noeud* it = currentNode; it && !it->m_indice && it != m_apres; it = it->m_parent)
        {
            if (it->m_parent->m_gauche == it)
            {
                --(it->m_indice);
                if (it->m_indice == -2)
                {
                    if (it->m_droite && it->m_droite->m_indice == 1) rotation_gauche_droite(reference(it->m_droite));
                    rotation_droite_gauche(reference(it));
                }
            }
            else
            {
                ++(it->m_indice);
                if (it->m_indice == 2)
                {
                    if (it->m_gauche && it->m_gauche->m_indice == -1) rotation_droite_gauche(reference(it->m_gauche));
                    rotation_gauche_droite(reference(it));
                }
            }
        }

        return iterator(currentNode);
}

///////////////////////////////////////////////////////////////////////////
//insert avec indice

template <typename Tclef, typename Tvaleur>
typename map<Tclef, Tvaleur>::iterator map<Tclef, Tvaleur>::insert(iterator j, const Tclef& c, const Tvaleur& val)
{
      /*iterator it = lower_bound(c);
    
       if (it != end() && !(c < it->first)) {
           return it;
       }

       return insert(c, val).first;*/
    
    noeud* current = j.m_courant;
    noeud* parent = current->m_parent;

    if (current == m_apres) {
        m_apres->m_gauche = new noeud(c, val, m_apres);
        m_size = 1;
        return iterator(m_apres->m_gauche);
    }

    if (!(c < current->m_contenu->first || current->m_contenu->first < c))
        return j;

    if (c < current->m_contenu->first && !current->m_gauche) {
        for (current = parent; current != m_apres && parent->m_gauche == current; current = parent, parent = parent->m_parent) {
        }
    } else if (current->m_contenu->first < c && !current->m_droite) {
        for (current = parent; current != m_apres && parent->m_droite == current; current = parent, parent = parent->m_parent) {
        }
    }

    if (current == m_apres || parent == m_apres || (c < parent->m_contenu->first && current->m_contenu->first < c)) {
        insert(c, val, j.m_courant, j);
        j.m_courant->m_indice = 0;

        noeud* it = j.m_courant;
        do {
            if (it->m_parent->m_gauche == it)
                allonger_a_gauche(reference(it->m_parent));
            else
                allonger_a_droite(reference(it->m_parent));
            
            it = it->m_parent;
        } while (it->m_indice && it->m_parent != m_apres);

        return j;
    }

    return insert(c, val).first;
    
    
}

///////////////////////////////////////////////////////////////////////////
// gestion de l'equilibre de l'arbre


//effectuer une rotation simple de la gauche vers la droite
template <typename Tclef, typename Tvaleur>
void map<Tclef, Tvaleur>::rotation_gauche_droite(noeud*& p)
{
    noeud *temp = p->m_gauche;
    int ia = temp->m_indice;
    int ib = p->m_indice;
    int nib = -ia-std::max(0,-ia)-1+ib;
    int nia = ia-std::max(0,-nib)-1;
    temp->m_indice = nia;
    p->m_indice = nib;
    p->m_gauche = temp->m_droite;
    p->m_parent = temp;
    temp->m_droite = p;
    p = temp;
}

//effectuer une rotation simple de la droite vers la gauche
template <typename Tclef, typename Tvaleur>
void map<Tclef, Tvaleur>::rotation_droite_gauche(noeud*& p)
{
    noeud *temp = p->m_droite;
    int ia = p->m_indice;
    int ib = temp->m_indice;
    int nia = ia+std::max(0,-ib)+1;
    int nib = nia+std::max(0,-nia)+1+ib;
    temp->m_indice = nib;
    p->m_indice = nia;
    p->m_droite = temp->m_gauche;
    temp->m_gauche = p;
    p = temp;
}


#endif /* mapImpl_h */
