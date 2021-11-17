//
//  NodeTemplate.hpp
//  DynamicArray
//
//  Created by Alex Denisov on 17.11.2021.
//

#ifndef NodeTemplate_hpp
#define NodeTemplate_hpp

#include "Node.hpp"

#define STANDARD_NODE_CAPACITY 30;

template <typename T>
Node<T>::Node() {
    _capacity = STANDARD_NODE_CAPACITY;
    _size = 0;
    
    int memory_size = sizeof(T) * _capacity;
    _items = (T*)malloc(memory_size);
}

template <typename T>
Node<T>::Node(int capacity) {
    _capacity = capacity;
    _size = 0;
    
    int memory_size = sizeof(T) * _capacity;
    _items = (T*)malloc(memory_size);

}

template <typename T>
Node<T>::~Node(){
    free(_items);
}

template <typename T>
bool Node<T>::try_append(T new_item) {
    if (_size < _capacity){
        _items[_size++] = new_item;
        return true;
    }
    return false;
}

template <typename T>
T& Node<T>::operator[](int position) {
    if (position >= 0 && position < _capacity){
        return _items[position];
    }
    
    exit(0);
}

template <typename T>
int Node<T>::size(){
    return _size;
}

#endif /* NodeTemplate_hpp */
