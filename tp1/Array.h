//
//  Array.h
//  TP_1_IFT_339
//
//  Created by Thomas Alexandre on 2024-01-16.
//

#ifndef Array_h
#define Array_h

template <typename TYPE>
class tableau 
{
    TYPE* TAB;
    int DIM;
    class iterator;
    
public:
    //Constructors
    tableau();
    tableau(int size);
    
    //Methods
    TYPE resize(int D);
    void fill(TYPE T);
    
    //Operators
    TYPE& operator[](int i);
    
    //Test method
    void print();
};
//Iterators
template <typename TYPE>
class tableau<TYPE>::iterator
{
    
public:
    TYPE operator++(TYPE T);
    TYPE operator--(TYPE T);
    TYPE operator==(TYPE T);
};


//Constructors
template <typename TYPE>
tableau<TYPE>::tableau()
{
    TAB = nullptr;
    DIM = 0;
};

template <typename TYPE>
tableau<TYPE>::tableau(int size)
{
    DIM = size;
    TAB = new TYPE[size];
    //Can't create array in this way need to use iterator
};

//Methods
template <typename TYPE>
TYPE tableau<TYPE>::resize(int D)
{
    
};

template <typename TYPE>
void tableau<TYPE>::fill(TYPE T)
{
    TYPE* ptr = TAB;
    for(int i=0;i<DIM;i++)
    {
        *ptr = T;
        ptr++;
    }
};

//Operators
template <typename TYPE>
TYPE& tableau<TYPE>::operator[](int i)
{
    if (i >= DIM)
    {
        exit(0);
    }
    return TAB[i];
};

//Test method
template <typename TYPE>
void tableau<TYPE>::print()
{
    for (int i=0;i<DIM;i++)
    {
        std::cout<<*TAB;
        TAB++;
    }
    std::cout<<std::endl;
};

#endif /* Array_h */
