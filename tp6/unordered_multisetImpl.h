//
//  unordered_setImpl.h
//  unordered_multiset
//
//  AUteur : Jean Goulet
//  Copyleft 2017
//
//  Modifie par : Vincent Ducharme, Automne 2022
//
//  Devoir fait par
//     CoÈquipier 1 :
//     CoÈquipier 2 :

#ifndef unordered_multisetImpl_h
#define unordered_multisetImpl_h


///////////////////////////////////////////
// avancer et reculer un iterateur

template <typename TYPE,typename classe_de_dispersion>
void unordered_multiset<TYPE, classe_de_dispersion>::iterator::avancer()
{
    // Advance to the next position
    ++m_pos;
    // If we reached the end of the current bucket, move to the next bucket
    if (m_pos == (*m_alv)->end()) {
        ++m_alv;
        // Find the next non-empty bucket
        while (*m_alv == nullptr) {
            ++m_alv;
        }
    }
}

template <typename TYPE,typename classe_de_dispersion>
void unordered_multiset<TYPE, classe_de_dispersion>::iterator::reculer()
{
    // If the position is at the beginning of a bucket, move to the end of the previous bucket
    if (m_pos == (*m_alv)->begin()) {
        --m_alv;
        // Find the previous non-empty bucket
        while (*m_alv == nullptr) {
            --m_alv;
        }
        // If there are more buckets, set the position to the end of the previous non-empty bucket
        if (*m_alv != nullptr) {
            m_pos = --(*m_alv)->end();
        }
    } else {
        // Move to the previous position within the same bucket
        --m_pos;
    }
}

/////////////////////////////////////////////////////////////////////
// fonctions generatrices

template <typename TYPE,typename classe_de_dispersion>
typename unordered_multiset<TYPE,classe_de_dispersion>::iterator
unordered_multiset<TYPE, classe_de_dispersion>::insert(const TYPE& val)
{
    m_size++;
    if ((m_size/(m_rep.size()-1))>m_facteur_max){rehash((2*(m_rep.size()-1))+1);}
    
    size_t alv = disperseur(val) % (m_rep.size()-1);
    
    // If the bucket is empty, create a new list
        if (m_rep[alv] == nullptr) {
            m_rep[alv] = new std::list<TYPE>();
        }

        // Add the value to the bucket
        m_rep[alv]->push_back(val);

        // Return an iterator to the inserted element
        return iterator(m_rep.begin() + alv, --m_rep[alv]->end());
    }

    //std::cout<<disperseur(val) % (m_rep.size()-1)<<val<<std::endl;
    /*if (m_rep[alv] == nullptr) {
        m_rep[alv] = new std::list<TYPE>();
    }
    m_rep[alv]->push_back(val);
    
    // Return an iterator to the inserted element
    return iterator(m_rep.begin() + alv, --m_rep[alv]->end());*/
//}

template <typename TYPE,typename classe_de_dispersion>
size_t unordered_multiset<TYPE, classe_de_dispersion>::erase(const TYPE& val)
{
    size_t alv = disperseur(val) % m_rep.size();

    if (m_rep[alv] == nullptr)
        return 0;

    size_t count = std::count(m_rep[alv]->begin(), m_rep[alv]->end(), val);
    m_size -= count;
    m_rep[alv]->remove(val);

    // Check if the bucket becomes empty after erasing
    if (m_rep[alv]->empty()) {
        delete m_rep[alv]; // Deallocate the empty bucket
        m_rep[alv] = nullptr;
    }

    return count;
}

template <typename TYPE,typename classe_de_dispersion>
typename unordered_multiset<TYPE,classe_de_dispersion>::iterator
unordered_multiset<TYPE, classe_de_dispersion>::erase(typename unordered_multiset<TYPE, classe_de_dispersion>::iterator i)
{
    if (i == end())
        return i;

    auto alv_iter = i.m_alv;
    if (alv_iter == m_rep.end())
        return i;  // Iterator is already at the end, nothing to erase

    auto alv = std::distance(m_rep.begin(), alv_iter); // Convert iterator to index
    if (alv < 0 || alv >= m_rep.size() || *alv_iter == nullptr)
        return i;  // Invalid iterator or empty bucket, nothing to erase

    auto list_iter = i.m_pos;
    list_iter = (*alv_iter)->erase(list_iter); // Update list_iter after erasing

    --m_size;

    if ((*alv_iter)->empty()) {
        // If the bucket becomes empty after erasing, deallocate it
        delete *alv_iter;
        *alv_iter = nullptr;
    }

    return iterator();
}

#endif // unordered_multisetImpl_h
