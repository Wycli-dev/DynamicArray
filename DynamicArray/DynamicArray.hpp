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
    
    int _node_capacity;
    int _size;
    int _node_count;
    
public:
    DynamicArray();
    DynamicArray(int node_capacity);
    ~DynamicArray();
    
    T& operator[](int position);
    void append(T item);
    void delete_item(int index);
    
    int size();
    
};

#endif /* DynamicArray_hpp */
