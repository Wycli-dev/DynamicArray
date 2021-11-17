//
//  main.cpp
//  DynamicArray
//
//  Created by Alex Denisov on 17.11.2021.
//

#include <iostream>
#include "DynamicArrayTemplate.hpp"

int main(int argc, const char * argv[]) {
    DynamicArray<int>* test = new DynamicArray<int>();
    test->append(12);
    test->append(24);
    int &result = test->operator[](1);


    std::cout << "num: " << result << std::endl;

    delete test;
    
    
    return 0;
}
