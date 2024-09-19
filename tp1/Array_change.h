//
//  Array_change.h
//  TP_1_IFT_339
//
//  Created by Thomas Alexandre on 2024-01-20.
//

#ifndef Array_change_h
#define Array_change_h
#include <iostream>

using namespace std;

template <typename TYPE, size_t DIM>
class Array
{
    TYPE* TAB;
    
public:
    class iterator
    {
        TYPE* ptr;
    public:
        iterator(TYPE* i){ ptr = i; }
        iterator& operator++() {++ptr; return *this;}
        bool operator==(const iterator& other) const { return ptr == other.ptr; }
        bool operator!=(const iterator& other) const { return ptr != other.ptr; }
        TYPE& operator*() const { return *ptr; }
    };
    class const_iterator
    {
        const TYPE* ptr;
    public:
        const_iterator(const TYPE* i){ ptr = i; };
        const_iterator& operator++() {++ptr; return *this;}
        bool operator==(const const_iterator& other) const { return ptr == other.ptr; }
        bool operator!=(const const_iterator& other) const { return ptr != other.ptr; }
        const TYPE& operator*() const { return *ptr; }
    };
    //Constructor
    Array();
    
    //Destructor
    ~Array();
    
    //Methods
    template <size_t M>
    Array<TYPE, M> subset(size_t position) const;
    void fill(TYPE T);
    size_t size() const;
    bool empty();
    TYPE& at(size_t D);
    TYPE& front();
    TYPE& back();
    void swap(Array<TYPE, DIM>& Array2);
    template <size_t DIM2>
    Array<TYPE, DIM+DIM2> fusion(const Array<TYPE, DIM2> Array2);
    
    //Iterators
    iterator begin();
    iterator end();
    const_iterator cbegin() const;
    const_iterator cend() const;
    
    //Operators
    TYPE& operator[](size_t i);
    const TYPE& operator[](size_t i) const;
    void operator=(const Array<TYPE, DIM> Array2);
    
    //Test method
    void print();
};


//Constructor---------------------------------
template <typename TYPE, size_t DIM>
Array<TYPE, DIM>::Array()
{
    if (DIM == 0 or DIM < 0)
    {
        TAB = nullptr;
    }
    else
    {
        TAB = new TYPE[DIM];
    }
};

//Destructor---------------------------------
template <typename TYPE, size_t DIM>
Array<TYPE,DIM>::~Array()
{
    delete[] TAB;
}

//Methods---------------------------------

template <typename TYPE, size_t DIM>
template <size_t M>
Array<TYPE, M> Array<TYPE,DIM>::subset(size_t position) const
{
    static_assert(M <= DIM, "Subset size M must be less than or equal to the array size");

    Array<TYPE, M> subsetArray;
    
    TYPE* ptr = TAB;

    for (size_t i = 0; i < M; ++i)
    {
        subsetArray[i] = ptr[position + i];
    }

    return subsetArray;
};

template <typename TYPE, size_t DIM>
void Array<TYPE, DIM>::fill(TYPE T)
{
    TYPE* ptr = TAB;
    for(size_t i=0;i<DIM;i++)
    {
        *ptr = T;
        ptr++;
    }
};

template <typename TYPE, size_t DIM>
size_t Array<TYPE, DIM>::size() const
{
    return DIM;
}

template <typename TYPE, size_t DIM>
bool Array<TYPE, DIM>::empty()
{
    if (TAB == nullptr) { return true; }
    else { return false; }
}

template <typename TYPE, size_t DIM>
TYPE& Array<TYPE, DIM>::at(size_t D)
{
    if (D > DIM or D < 0)
    {
        exit(0);
    }
    return TAB[D];
}

template <typename TYPE, size_t DIM>
TYPE& Array<TYPE, DIM>::front()
{
    return TAB[0];
}

template <typename TYPE, size_t DIM>
TYPE& Array<TYPE, DIM>::back()
{
    return TAB[DIM-1];
}

template <typename TYPE, size_t DIM>
void Array<TYPE, DIM>::swap(Array<TYPE, DIM>& Array2)
{
    if (DIM==Array2.size())
    {
        for (size_t i = 0; i < DIM; ++i)
            {
                std::swap(TAB[i], Array2.TAB[i]);
            }
    }
    else
    {
        cout<<"unable to swap two arrays with differing dimensions"<<endl;
    }
}

template <typename TYPE, size_t DIM>
typename Array<TYPE, DIM>::iterator Array<TYPE, DIM>::begin()
{
    return iterator(TAB);
}

template <typename TYPE, size_t DIM>
typename Array<TYPE, DIM>::iterator Array<TYPE, DIM>::end()
{
    return iterator(TAB+DIM);
}

template <typename TYPE, size_t DIM>
typename Array<TYPE, DIM>::const_iterator Array<TYPE, DIM>::cbegin() const
{
    return const_iterator(TAB);
}

template <typename TYPE, size_t DIM>
typename Array<TYPE, DIM>::const_iterator Array<TYPE, DIM>::cend() const
{
    return const_iterator(TAB+DIM);
}

template <typename TYPE, size_t DIM>
template <size_t DIM2>
Array<TYPE, DIM+DIM2> Array<TYPE, DIM>::fusion(const Array<TYPE, DIM2> Array2)
{
    TYPE* ptr = TAB;
    Array<TYPE, DIM+DIM2> fusedArray;
    for (int i = 0; i < DIM; i++)
    {
        fusedArray[i] = ptr[i];
    }
    for (int i = 0; i < Array2.size(); i++)
    {
        fusedArray[DIM+i] = Array2[i];
    }
    return fusedArray;
}


//Operators---------------------------------
template <typename TYPE, size_t DIM>
TYPE& Array<TYPE, DIM>::operator[](size_t i)
{
    if (i >= DIM)
    {
        exit(0);
    }
    return TAB[i];
}

template <typename TYPE, size_t DIM>
const TYPE& Array<TYPE, DIM>::operator[](size_t i) const
{
    if (i >= DIM)
    {
        exit(0);
    }
    return TAB[i];
}

template <typename TYPE, size_t DIM>
void Array<TYPE, DIM>::operator=(const Array<TYPE, DIM> Array2)
{
    if (this != &Array2)
    {
        iterator dest = begin();
        const_iterator src = Array2.cbegin();
        while (src != Array2.cend())
        {
            *dest = *src;
            ++dest;
            ++src;
        }
    }
}

//Test method---------------------------------
template <typename TYPE, size_t DIM>
void Array<TYPE, DIM>::print()
{
    TYPE* tmp = TAB;
    for (int i=0;i<DIM;i++)
    {
        std::cout<<*tmp;
        tmp++;
    }
    std::cout<<std::endl;
};

#endif /* Array_change_h */
