#include <iostream>
#include <algorithm>
#include "list_seq.hpp"

ListSeq::ListSeq(int _capacity){
    data = new int[_capacity]; //new aloca na heap
    capacity = _capacity;
};

bool ListSeq::add(int elem){
    if (size < capacity){
        data[size++] = elem;
        return true;
    } 
    
    return false;
};

bool ListSeq::isEmpty(){
    return size == 0;
}

bool ListSeq::isFull(){
    return size == capacity;
}

bool ListSeq::print(){
    for (int i = 0; i < size; i++){
        cout << data[i] << " ";
    }
    cout << endl;
}