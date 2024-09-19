//
//  setImpl.h
//  SkipList
//
//  Jean Goulet 2017
//
//  Devoir fait par
//     CoÈquipier 1 : Thomas Alexandre
//     CoÈquipier 2 : Genevieve Gervais
//

#ifndef SkipList_set2_h
#define SkipList_set2_h

/////////////////////////////////////////////////////////////////
// copieur et destructeur de liste

template <typename TYPE>
set<TYPE>::set(const set<TYPE>& src)
    : set()
{
    cellule* p = (src.m_avant)->m_suiv[0];
    for(size_t i=0;i<src.m_size;i++)
    {
        insert(*(p->m_contenu));
        p=p->m_suiv[0];
    }
}

template <typename TYPE>
set<TYPE>::~set()
{
    cellule* p = m_avant->m_suiv[0];
    cellule* b;
    if(m_size!=0)
    {
        while(p!=nullptr)
        {
            b=p->m_suiv[0];
            delete p;
            p=b;
            m_size--;
        }
    }
}

/////////////////////////////////////////////////////////////////
// find
// localise un ÈlÈment, retourne la fin si absent

template <typename TYPE>
typename set<TYPE>::iterator set<TYPE>::find(const TYPE& x) const
{
    iterator it = lower_bound(x);
    if (it==m_avant) {return iterator(m_avant->m_prec[0]);}
    else if (it==m_avant->m_prec[0]) {return iterator(m_avant->m_prec[0]);}
    else if (*(it.m_pointeur->m_contenu)<x) {return iterator(m_avant->m_prec[0]);}
    else {return it;}
    return iterator(m_avant->m_prec[0]);
}

// lower_bound
// localise la premiere position ou l'element n'est
// pas plus petit que celui recu en parametre

template <typename TYPE>
typename set<TYPE>::iterator set<TYPE>::lower_bound(const TYPE& t) const
{
    cellule *c = m_avant;
    cellule *apres = m_avant->m_prec[0];
    while(c->m_suiv[0] != apres)
        if(*c->m_suiv[0]->m_contenu < t)
            c = c->m_suiv[0];
        else
            break;
    return iterator(c->m_suiv[0]);
}

template <typename TYPE>
typename set<TYPE>::iterator set<TYPE>::upper_bound(const TYPE& x) const
{
    iterator it = lower_bound(x);
    return iterator(it.m_pointeur->m_suiv[0]);
}

/////////////////////////////////////////////////////////////////
// erase(VAL)
// elimine VAL de l'ensemble, si present

template <typename TYPE>
size_t set<TYPE>::erase(const TYPE& VAL)
{
    cellule* p = find(VAL).m_pointeur;
    if (p == m_avant->m_prec[0]){return 0;}
    else
    {
        size_t height = p->m_suiv.size();
        for (size_t i=0;i<height;i++)
        {
            cellule* avant = p->m_prec[i];
            cellule* apres = p->m_suiv[i];
            avant->m_suiv[i] = apres;
            apres->m_prec[i] = avant;
        }
        delete p;
        m_size--;
        return 1;
    }
}

// erase(it)
// elimine de l'ensemble l'element en position it

template <typename TYPE>
typename set<TYPE>::iterator set<TYPE>::erase(iterator it)
{
    cellule* p = it.m_pointeur;
    if (p == m_avant->m_prec[0]){return 0;}
    else
    {
        size_t height = p->m_suiv.size();
        for (size_t i=0;i<height;i++)
        {
            cellule* avant = p->m_prec[i];
            cellule* apres = p->m_suiv[i];
            avant->m_suiv[i] = apres;
            apres->m_prec[i] = avant;
        }
        delete p;
        m_size--;
        return 1;
    }
}

#endif
