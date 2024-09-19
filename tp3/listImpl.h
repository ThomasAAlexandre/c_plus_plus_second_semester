//
//  listImpl.h
//
//  Auteur : Jean Goulet
//  Copyleft  2017 UdeS
//
//  Modifie par : Vincent Ducharme, Automne 2022
//
//  Devoir fait par
//     CoÈquipier 1 : Thomas Alexandre
//     CoÈquipier 2 :

#ifndef listImpl_h
#define listImpl_h

//////////////////////////////////////////////////////////////
//fonctions generatrices privees
//////////////////////////////////////////////////////////////

template <typename TYPE>
typename list<TYPE>::cellule* list<TYPE>::insert(cellule* c, const TYPE& VAL)
{
    if (m_size == 0)
    {
        //liste vide
        cellule* suiv = &m_apres;
        cellule* pr = nullptr;
        c = new cellule (VAL,suiv,pr);
        m_debut = c;
        m_apres.m_prec = c;
        m_size++;
        return c;
    }
    cellule* SU = c;
    cellule* PR = SU->m_prec;
    cellule* No = new cellule(VAL,SU,PR);
    if (PR == nullptr)
    {
        //inserer au debut
        SU->m_prec = No;
        m_debut = No;
    }
    else
    {
        //cas general
        SU->m_prec = No;
        PR->m_suiv = No;
    }
    m_size++;
    return No;
}

template <typename TYPE>
typename list<TYPE>::cellule* list<TYPE>::erase(cellule* c)
{
    if (m_debut == &m_apres)
    {
        return c;
    }
    cellule* SU = c->m_suiv;
    cellule* PR = c->m_prec;
    delete c;
    if (PR == nullptr)
    {
        m_debut = SU;
    }
    else
    {
        PR->m_suiv = SU;
    }
    SU->m_prec = PR;
    m_size--;
    return SU;
}


//////////////////////////////////////////////////////////////
//reverse_iterator
//////////////////////////////////////////////////////////////


template <typename TYPE>
class list<TYPE>::reverse_iterator
{
    friend class list<TYPE>;
    cellule* m_pointeur = nullptr;
    reverse_iterator() = default;
    reverse_iterator(cellule *c) :m_pointeur(c) {}
public:
    TYPE& operator*()const {return m_pointeur->m_contenu;};
    TYPE* operator->()const { return &(m_pointeur->m_contenu); };
    reverse_iterator& operator++() {m_pointeur = m_pointeur->m_prec;
        return *this;}; //++i
    reverse_iterator operator++(int)
    {reverse_iterator ret(*this);
        operator++();
        return ret;}; //i++
    reverse_iterator& operator--() {m_pointeur = m_pointeur->m_suiv;
        return *this;}; //--i
    reverse_iterator operator--(int) {reverse_iterator ret(*this);
        operator--();
        return ret;}; // i--
    bool operator==(const reverse_iterator&droite)const {return m_pointeur == droite.m_pointeur;};
    bool operator!=(const reverse_iterator&droite)const {return !(*this == droite);};
};

template <typename TYPE>
typename list<TYPE>::reverse_iterator list<TYPE>::rbegin()
{
    return &m_apres;
}

template <typename TYPE>
typename list<TYPE>::reverse_iterator list<TYPE>::rend()
{
    return m_debut--;
}

///////////////////////////////////////////////////////////
//affectateur
///////////////////////////////////////////////////////////

template <typename TYPE>
list<TYPE>& list<TYPE>::operator=(const list<TYPE>& droite)
{
    if (droite.m_debut != m_debut)
    {
        clear();
        cellule* ptr = droite.m_debut;
        for (size_t i=0;i<droite.m_size;i++)
        {
            push_back(ptr->m_contenu);
            ptr = ptr->m_suiv;
        }
    }
    return *this;
}


///////////////////////////////////////////////////////////
//algorithme reverse
///////////////////////////////////////////////////////////

template <typename TYPE>
void list<TYPE>::reverse()
{
    cellule* tmp = m_debut;
    //for loop for swaping pointers of all cells
    for (size_t i=0;i<m_size;i++)
    {
        //swap the m_prec with m_suiv
        cellule* SUIVE = tmp->m_suiv;
        cellule* PR = tmp->m_prec;
        cellule* SU = tmp->m_suiv;
        tmp->m_prec = SU;
        tmp->m_suiv = PR;
        tmp = SUIVE;
    }
    //fixing last and first cell pointers
    //new last cell
    cellule* new_first = m_apres.m_prec;
    new_first->m_prec = nullptr;
    //new first cell
    m_debut->m_suiv = &m_apres;
    m_debut = new_first;
}


#endif // listImpl_h
