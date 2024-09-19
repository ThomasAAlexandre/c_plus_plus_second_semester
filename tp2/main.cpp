//
//  main.cpp
//  TP2_IFT_339
//
//  Created by Thomas Alexandre on 2024-02-04.
//

#include <iostream>
#include "vector.h"
#include "deque.h"

int main() 
{
    //vector<int> myvec(5);
    deque<int> mydeque;
   
    //mydeque.pop_back();
    //mydeque.pop_front();
    //mydeque.pop_front();
    //mydeque.push_back(5);
    //mydeque.push_back(5);
    //mydeque.push_back(5);
    //mydeque.push_back(5);
    //mydeque.push_front(5);
    mydeque.push_front(1);
    mydeque.push_front(2);
    mydeque.push_front(3);
    mydeque.push_front(4);
    mydeque.push_front(5);
    mydeque.push_front(6);
    //deque<int> my2(mydeque);
    //mydeque.resize(15);
    //mydeque.push_back(22);
    //mydeque.push_back(1);
    /*mydeque.push_back(2);
    mydeque.push_back(3);
    mydeque.push_back(4);
    mydeque.push_back(5);
    mydeque.push_back(6);
    mydeque.pop_front();
    mydeque.pop_front();
    mydeque.pop_front();
    mydeque.pop_front();
    mydeque.push_back(7);
    mydeque.push_back(8);*/
    //mydeque.push_back(9);
    //mydeque.push_back(9);
    //mydeque.push_back(9);
    
    //mydeque.pop_front();*/
    //mydeque.push_front(5);
    /*mydeque.pop_back();
     mydeque.pop_front();
    mydeque.pop_back();
    mydeque.pop_front();
    mydeque.push_back(5);
    mydeque.pop_back();
     mydeque.pop_front();
     mydeque.pop_front();
    mydeque.pop_front();
    mydeque.pop_front();
    mydeque.pop_front();
    mydeque.push_back(6);*/
    //std::cout<< mydeque.at(2) << std::endl;
    
    /*myvec.at(3)=3;
    myvec.at(2)=2;
    myvec.push_back(5);
    myvec.push_back(5);
    myvec.push_back(5);*/
    /*myvec.push_back(5);
    myvec.push_back(5);
    myvec.push_back(5);
    myvec.push_back(5);
    myvec.push_back(5);
    myvec.push_back(5);
    myvec.push_back(5);
    myvec.push_back(5);
    myvec.push_back(5);
    myvec.push_back(5);
    myvec.push_back(5);
    myvec.push_back(5);
    myvec.push_back(5);
    myvec.push_back(5);
    myvec.push_back(5);
    myvec.push_back(5);
    myvec.push_back(5);
    myvec.push_back(5);
    myvec.push_back(5);
    myvec.push_back(5);
    myvec.push_back(5);
    myvec.push_back(5);
    myvec.push_back(5);
    myvec.push_back(5);
    myvec.push_back(5);
    myvec.push_back(5);
    myvec.resize(5);
    myvec.push_back(5);*/
    /*myvec.push_back(5);
    myvec.resize(5);
    myvec.resize(101);
    myvec.reserve(20);
    myvec.resize(1);
    myvec.push_back(5);*/
    
    //mydeque.resize(3);
    /*myvec.resize(2);
    myvec.pop_back();
    myvec.pop_back();
    myvec.pop_back();
    myvec.pop_back();
    myvec.pop_back();
    myvec.pop_back();
    myvec.pop_back();
    myvec.push_back(5);
    myvec.pop_back();
    myvec.pop_back();
    myvec.pop_back();
    myvec.pop_back();*/
    
    
    mydeque.afficher(std::cout);
    //myvec.afficher(std::cout);
    
    // Use the overloaded operator<< to print the vector itself
    std::cout << mydeque << std::endl;
    //std::cout << myvec << std::endl;
    
    //myvec.clear();
    return 0;
}
