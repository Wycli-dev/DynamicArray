//
//  Node.hpp
//  DynamicArray
//
//  Created by Alex Denisov on 17.11.2021.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>


template <typename T>
class Node {
    
private:
    // Массив элементов
    T* _items;
    
    // Максимальная вместимость
    int _capacity;
    
    // Фактическая заплненность ноды
    int _size;
    
public:
    Node();
    Node(int capacity);
    ~Node();
    
    bool try_append(T new_item);
    
    T& operator[](int position);
    
    int size();
    
};

#endif /* Node_hpp */
