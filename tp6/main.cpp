//
//  main.cpp
//  TP6_IFT339
//
//  Created by Thomas Alexandre on 2024-03-30.
//

#include <iostream>
#include "unordered_multiset.h"
int main()
{
   // Create an unordered_multiset of integers
        unordered_multiset<int> mySet;

        // Insert some elements into the unordered_multiset
        mySet.insert(5);
        //mySet.erase(5);
        //mySet.insert(5);
        mySet.insert(3);
        mySet.insert(7);
        //mySet.insert(8);
        //mySet.insert(9);
        //mySet.insert(10);
        //mySet.insert(11);
        //mySet.insert(12);

        // Display the unordered_multiset
        std::cout << "Contents of the unordered_multiset:\n" << mySet << std::endl;

        // Erase an element from the unordered_multiset
        mySet.erase(5);

        // Display the unordered_multiset after erasing an element
        std::cout << "Contents of the unordered_multiset after erasing '5':\n" << mySet << std::endl;
    


    return 0;
}
