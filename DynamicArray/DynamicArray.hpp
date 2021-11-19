//
//  DynamicArray.hpp
//  DynamicArray
//
//  Created by Alex Denisov on 17.11.2021.
//

#ifndef DynamicArray_hpp
#define DynamicArray_hpp

#include "NodeTemplate.hpp"

template <typename T>
class DynamicArray {
private:
    Node<T>* _nodes;
    int _size;
    int _capacity;
public:
    DynamicArray();
    ~DynamicArray();
    T& operator[](int position);
    void append(T item);
    int get_size();
    void print();
};

#endif /* DynamicArray_hpp */
