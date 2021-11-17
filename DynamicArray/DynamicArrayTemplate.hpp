//
//  DynamicArrayTemplate.hpp
//  DynamicArray
//
//  Created by Alex Denisov on 17.11.2021.
//

#ifndef DynamicArrayTemplate_hpp
#define DynamicArrayTemplate_hpp

#include "DynamicArray.hpp"

#define STANDARD_NODE_COUNT 0


template <typename T>
DynamicArray<T>::DynamicArray() {
    _node_capacity = STANDARD_NODE_CAPACITY;
    _size = 0;
    _node_count = STANDARD_NODE_COUNT;
    
    int memory_usage = _node_count * sizeof(Node<T>(_node_capacity));
    _nodes = (Node<T>*)malloc(memory_usage);
}

template <typename T>
DynamicArray<T>::~DynamicArray(){
    free(_nodes);
}

template <typename T>
DynamicArray<T>::DynamicArray(int node_capacity) {
    _node_capacity = node_capacity;
    _size = 0;
    _node_count = STANDARD_NODE_COUNT;
    
    int memory_usage = _node_count * sizeof(Node<T>(_node_capacity));
    _nodes = (Node<T>*)malloc(memory_usage);
}

template <typename T>
T& DynamicArray<T>::operator[](int position) {
    if (position >= 0 && position < _size){
        int node_index = position / _node_capacity;
        int item_index = position % _node_capacity;
        
        T& item_ref = _nodes[node_index].operator[](item_index);
        return item_ref;
    }
    
    exit(0);
}

template <typename T>
void DynamicArray<T>::append(T new_item) {
    bool need_new_node = ((_size + 1) % _node_capacity == 1) &&
                         (_node_count * _node_capacity == _size);
    
    if (need_new_node) {
        _node_count++;
        int memory_usage =_node_count * sizeof(Node<T>(_node_capacity));
        _nodes = (Node<T>*)realloc((void*) _nodes, memory_usage);

    }
    
    bool need_init = ((_size + 1) % _node_capacity == 1);
    
    if (need_init){
        int index = _size / _node_capacity;
        _nodes[index] = Node<T>(_node_capacity);
    }
    
    _size++;
    int node_index = _size / _node_capacity;
    _nodes[node_index].try_append(new_item);
    
}

template <typename T>
int DynamicArray<T>::size(){
    return _size;
}


#endif /* DynamicArrayTemplate_hpp */
