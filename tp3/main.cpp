//
//  main.cpp
//  TP3_IFT339
//
//  Created by Thomas Alexandre on 2024-02-17.
//

#include <iostream>
#include "list.h"

int main()
{
    list<int> maListe;
    list<int> theListe;
    //maListe.push_back(5);
    //maListe.push_back(5);
    //maListe.push_back(5);
    //maListe.push_back(5);
    //maListe.push_back(5);
    maListe.push_back(1);
    maListe.push_back(2);
    maListe.push_back(3);
    maListe.push_back(4);
    //maListe.reverse();
    
    maListe.pop_front();
    //maListe.pop_front();
    //maListe.pop_front();
    //maListe.pop_front();
    
    
    //maListe.pop_back();
    //maListe.pop_back();
    //maListe.pop_back();
    //maListe.pop_back();
    //maListe.push_back(5);
    //maListe.pop_back();
    //maListe.pop_back();
    //maListe.pop_back();
    //maListe.pop_back();
    //maListe.pop_back();
    //maListe.push_back(5);
    //maListe.push_back(5);
    //maListe.push_back(5);
    //maListe.push_back(5);
    //maListe.push_back(5);
    //maListe.push_front(8);
    //maListe.pop_back();
    //maListe.pop_front();
    maListe = maListe;
    theListe = theListe;
    //maListe.pop_front();
    //theListe = maListe;
    
    afficher(std::cout, maListe);
    afficher(std::cout, theListe);
    return 0;
}
