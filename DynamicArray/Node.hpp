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
    T* _items;
    int _capacity;
    int _size;
    
public:
    Node();
    Node(int capacity);
    ~Node();
    void append(T new_item);
    T& operator[](int position);
    int get_size();
    void print();
};

#endif /* Node_hpp */
