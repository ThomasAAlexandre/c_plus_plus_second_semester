//
//  main.cpp
//  TP5_IFT339
//
//  Created by Thomas Alexandre on 2024-03-17.
//

#include <iostream>
#include "map.h"
int main()
{
    // Create a map with some key-value pairs
        map<int, std::string> myMap;
        myMap.insert(3, "Three");
        myMap.insert(1, "One");
        myMap.insert(4, "Four");
        myMap.insert(2, "Two");
        myMap.insert(5, "Five");
        myMap.insert(3, "Three");
        myMap.insert(9, "Nine");
        myMap.insert(5, "Five");
        myMap.insert(4, "Four");
        myMap.insert(3, "Three");
        myMap.insert(6, "Six");
        myMap.erase(5);
        //myMap.insert(7, "Seven");
        //myMap.insert(8, "Eight");
        //myMap.insert(2, "Two");
        //myMap.insert(1, "One");

        // Display the contents of the map
        std::cout << "Contents of the map:" << std::endl;
        myMap.afficher(std::cout);
    
    
    // Test lower_bound function
        std::cout << "Lower bounds for keys:" << std::endl;
        for (int key = 0; key <= 10; ++key) {
            auto it = myMap.lower_bound(key);
            std::cout << "Key: " << key << ", ";
            if (it != myMap.end()) {
                std::cout << "Lower bound: " << it->first << " -> " << it->second << std::endl;
            } else {
                std::cout << "No lower bound found" << std::endl;
            }
        }

    return 0;
}
