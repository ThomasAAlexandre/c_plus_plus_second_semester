//
//  main.cpp
//  TP4 IFT339
//
//  Created by Thomas Alexandre on 2024-03-08.
//

#include <iostream>
#include "set.h"

int main()
{
    set<int> mySet;
    mySet.insert(5);
    mySet.insert(6);
    mySet.insert(7);
    mySet.insert(8);
    set<int> secondSet;
    set<int> thirdSet;
    thirdSet.find(3);
    secondSet.insert(2);
    secondSet.upper_bound(3);
    secondSet=mySet;
    mySet.find(4);
    std::cout<<"mySet"<<std::endl;
    afficher(std::cout, mySet);
    std::cout<<"mySet missing"<<std::endl;
    mySet.erase(6);
    afficher(std::cout, mySet);
    afficher(std::cout, secondSet);
    secondSet.erase(6);
    afficher(std::cout,secondSet);
    return 0;
}
