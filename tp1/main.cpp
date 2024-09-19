//
//  main.cpp
//  TP_1_IFT_339
//
//  Created by Thomas Alexandre on 2024-01-16.
//

#include <iostream>
#include "Array_change.h"
using namespace std;

int main()
{
    Array <int, 5> T;
    Array <int, 5> D;
    Array <int, 3> L;
    T.fill(3);
    D.fill(7);
    T[3]=0;
    cout<<"T: ";
    T.print();
    cout<<"D: ";
    D.print();
    T.print();
    //D.print();
    L=T.subset<3>(2);
    //L.print();
    Array <int, 10> E;
    E = T.fusion<5>(D);
    Array <int, 15> M;
    M = E.fusion<5>(D);
    cout<<"M: ";
    M.print();
    cout<<"E: ";
    E.print();
    //cout<<"at: "<<L.at(1)<<endl;
    return 0;
}
