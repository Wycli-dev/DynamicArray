//
//  NodeTemplate.hpp
//  DynamicArray
//
//  Created by Alex Denisov on 17.11.2021.
//

#ifndef NodeTemplate_hpp
#define NodeTemplate_hpp

#include "Node.hpp"

#define STANDARD_NODE_CAPACITY 2

template <typename T>
Node<T>::Node() {
    _capacity = STANDARD_NODE_CAPACITY;
    _size = 0;
    int memory_size = sizeof(T) * _capacity;
    _items = (T*)malloc(memory_size);
}

template <typename T>
Node<T>::~Node(){
    free(_items);
}

template <typename T>
void Node<T>::append(T new_item) {
    if (_size < _capacity){
        _items[_size] = new_item;
        _size++;
        return;
    }
    std::cout << "Node filled" << std::endl;
    return;
}

template <typename T>
T& Node<T>::operator[](int position) {
    if (position >= 0 && position < _size){
        return _items[position];
    }
    std::cout << "Node index out of range" << std::endl;
    exit(0);
}

template <typename T>
int Node<T>::get_size(){
    return _size;
}

template <typename T>
void Node<T>::print(){
    std::cout << "Node: ";
    for (int i = 0; i < _size; i++) {
        std::cout << _items[i] << " ";
    }
    std::cout << std::endl;
}

#endif /* NodeTemplate_hpp */
