//
//  DynamicArrayTemplate.hpp
//  DynamicArray
//
//  Created by Alex Denisov on 17.11.2021.
//

#ifndef DynamicArrayTemplate_hpp
#define DynamicArrayTemplate_hpp

#include "DynamicArray.hpp"

#define STANDARD_ARRAY_CAPACITY 10

template <typename T>
DynamicArray<T>::DynamicArray() {
    _size = 0;
    _capacity = STANDARD_ARRAY_CAPACITY;
    int memory_usage = _capacity * sizeof(Node<T>);
    _nodes = (Node<T>*)malloc(memory_usage);
}

template <typename T>
DynamicArray<T>::~DynamicArray(){
    free(_nodes);
}

template <typename T>
T& DynamicArray<T>::operator[](int position) {
    if (position >= 0 && position < _size){
        int node_index = position / STANDARD_NODE_CAPACITY;
        int item_index = position % STANDARD_NODE_CAPACITY;
        T& item_ref = _nodes[node_index][item_index];
        return item_ref;
    }
    std::cout << "Dynamic Array index out of range" << std::endl;
    exit(0);
}

template <typename T>
void DynamicArray<T>::append(T new_item) {
    if (_size + 1 == _capacity * STANDARD_NODE_CAPACITY) {
        _capacity++;
        int memory_usage = _capacity * sizeof(Node<T>);
        _nodes = (Node<T>*)realloc((void*) _nodes, memory_usage);
    }
    if (_size % STANDARD_NODE_CAPACITY == 0){
        int index = _size / STANDARD_NODE_CAPACITY;
        _nodes[index] = Node<T>();
    }
    int node_index = _size / STANDARD_NODE_CAPACITY;
    _nodes[node_index].append(new_item);
    _size++;
}

template <typename T>
int DynamicArray<T>::get_size(){
    return _size;
}

template <typename T>
void DynamicArray<T>::print() {
    std::cout << "DynamicArray: " << std::endl;
    for(int i = 0; i < _size; i++){
        _nodes[i].print();
    }
}

#endif /* DynamicArrayTemplate_hpp */
