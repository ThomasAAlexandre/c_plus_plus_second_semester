//
//  Nom du fichier dequeImpl.h
//  Description : deque-circulaire
//
//  Auteur : Jean Goulet
//  Date :   2016-12-27
//  Copyleft 2016 UdeS
//
//  Modifié par : Vincent Ducharme, Septembre 2022
//
// =============================================
//
//  Nom de l'étudiant : Thomas Alexandre
//  Nom de l'étudiant :
//
// =============================================

#ifndef _dequeImpl_h
#define _dequeImpl_h

/////////////////////////////////////////////////////////////////
//code a completer pour le devoir

template <typename T>
deque<T>::deque(const deque& source)
{
    m_cap = source.m_cap;
       m_size = source.m_size;
       m_zero = source.m_zero;
    
       m_debut = new T*[m_cap];
       
       for (size_t i = 0; i < m_size; ++i) {
           m_debut[i] = new T(*(source.m_debut[(source.m_zero + i) % source.m_cap]));
       }
}

template <typename T>
void deque<T>::resize(size_t nSize)
{
    size_t size = m_size - m_zero;
        if (size < nSize) {
            reserve(2 * (size));
            size_t diff = nSize - size;
            for (size_t i = 0; i < diff; i++) {
                push_back(T{});
            }
        }
        else if (size > nSize) {
            size_t diff = size - nSize;
            for (size_t i = 0; i < diff; i++) {
                pop_back();
            }
            while (m_size > nSize) {
                    pop_back();
                }
        }
}

template <typename T>
void deque<T>::reserve(size_t nCap)
{
    if (nCap <= m_cap)
           return;

       T** new_debut = new T*[nCap];
    
       for (size_t i = 0; i < m_size; ++i) {
           new_debut[i] = (m_debut[(m_zero + i) % m_cap]);
       }

       delete[] m_debut;

       m_debut = new_debut;
       m_cap = nCap;
       m_zero = 0;
}

template <typename T>
T& deque<T>::operator[](size_t i)
{
    while(m_debut[i]==nullptr)
    {
        i++;
    }
    return *m_debut[i];
}

template <typename T>
T& deque<T>::at(size_t i)
{
    while(m_debut[i]==nullptr)
    {
        i++;
    }
    return *m_debut[i];
}

template <typename T>
const T& deque<T>::operator[](size_t i)const
{
    while(m_debut[i]==nullptr)
    {
        i++;
    }
    const T& object = *m_debut[i];
    return object;
}

template <typename T>
const T& deque<T>::at(size_t i)const
{
    while(m_debut[i]==nullptr)
    {
        i++;
    }
    const T& object = *m_debut[i];
    return object;
}

template <typename T>
void deque<T>::push_back(const T& val)
{
    if (m_size == m_cap-1) {
            reserve(2 * m_cap+1);
        }

        if (m_size < m_cap) {
            m_debut[(m_zero + m_size) % m_cap] = new T(val);
            ++m_size;
        }
     
        else if (m_size + m_zero > m_cap && m_zero > 0) {
            m_debut[m_zero - 1] = new T(val);
            ++m_size;
        }
       
        else {
            reserve(2 * m_cap+1);
            push_back(val);
        }
}

template <typename T>
void deque<T>::pop_back()
{
    if (m_size > 0) {
            delete m_debut[(m_zero + m_size - 1) % m_cap];
            m_size--;
        }
}

template <typename T>
void deque<T>::push_front(const T& val)
{
    if (m_size == m_cap) {
            reserve(2 * m_cap+1);
        }

    if (m_size < m_cap) {
        if (m_zero == 0) {
            m_zero = m_cap-1;
        }
        else
        {
            m_zero--;
        }
        m_debut[m_zero] = new T(val);
        ++m_size;
        }
    
    else {
            reserve(2 * m_cap+1);
            push_front(val);
        }
}

template <typename T>
void deque<T>::pop_front()
{
    if (m_size > 0) {
            delete m_debut[m_zero];
            m_zero = (m_zero + 1) % m_cap;
            m_size--;
        }
}


#endif // dequeImpl_h
