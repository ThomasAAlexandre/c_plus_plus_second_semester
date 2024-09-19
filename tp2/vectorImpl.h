//
//  Nom du fichier : vectorImpl.h
//
//  Auteur : Jean Goulet
//  Date :   2016-01-05
//
//  Modifié par : Vincent Ducharme, Septembre 2022
//
// =============================================
//
//  Nom de l'étudiant : Thomas Alexandre
//  Nom de l'étudiant :
//
// =============================================

#ifndef _vectorImpl_h
#define _vectorImpl_h


///////////////////////////////////////////////////
//clear (vide la memoire dynamique)

template <typename T>
void vector<T>::clear()
{
    delete[] m_debut;
    m_debut = nullptr;
    m_finDim = 0;
    m_finCap = 0;
}

///////////////////////////////////////////////////
//resize (modifie la dimension)

template <typename T>
void vector<T>::resize(size_t nDIM)
{
    if (nDIM < size()) {
        while(size()>nDIM){
            pop_back();
        }
            
            m_finDim = m_debut + nDIM; 
            
        } else if (nDIM > size()) {
            reserve(nDIM);
            m_finDim = m_debut + nDIM;
        }
}


///////////////////////////////////////////////////
//reserve (modifie la capacite)

template <typename T>
void vector<T>::reserve(size_t nCAP)
{
    if (nCAP <= m_finCap - m_debut) {
            return;
        }

        T* new_data = new T[nCAP];

        size_t i = 0;
        for (T* ptr = m_debut; ptr != m_finDim; ++ptr, ++i) {
            new_data[i] = std::move(*ptr);
        }

        if (m_debut != nullptr) {
            delete[] m_debut;
        }

        m_debut = new_data;
        m_finDim = m_debut + i;
        m_finCap = m_debut + nCAP;
}

///////////////////////////////////////////////////
//fonctions d'acces a un element sauf front et back
//push_back
//pop_back
//operator[]
//operator[]const
//at
//at const

template <typename T>
void vector<T>::push_back(const T& x)
{
    if (m_finDim >= m_finCap)
    {
        size_t newCapacity = (m_finCap - m_debut) * 2 + 1;
        reserve(newCapacity);
    }
    m_debut[size()] = x;
    m_finDim++;
}

template <typename T>
void vector<T>::pop_back()
{
    if (m_finDim > m_debut) {
           m_finDim--;
       }
}

template <typename T>
T& vector<T>::operator[](size_t i)
{
    return m_debut[i];
}

template <typename T>
const T& vector<T>::operator[](size_t i)const
{
    return m_debut[i];
}

template <typename T>
T& vector<T>::at(size_t i)
{
    return m_debut[i];
}
template <typename T>
const T& vector<T>::at(size_t i)const
{
    return m_debut[i];
}


#endif // vectorImpl_h
