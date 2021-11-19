//
//  main.cpp
//  DynamicArray
//
//  Created by Alex Denisov on 17.11.2021.
//

#include <iostream>
#include "Node.hpp"
#include "NodeTemplate.hpp"
#include "DynamicArray.hpp"
#include "DynamicArrayTemplate.hpp"

int main(int argc, const char * argv[]) {
    DynamicArray<int> test = DynamicArray<int>();
    test.print();

    test.append(1);
    test.append(2);
    test.append(3);

    test.print();

    
    
    return 0;
}
