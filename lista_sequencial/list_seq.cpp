#include <iostream>
#include <algorithm>
#include "list_seq.hpp"

ListSeq::ListSeq(int _capacity){
    data = new int[_capacity]; // new aloca na heap
    capacity = _capacity;
};

bool ListSeq::add(int elem){
    if (size < capacity)
    {
        data[size++] = elem;
        return true;
    }

    return false;
};

bool ListSeq::isEmpty()
{
    return size == 0;
}

bool ListSeq::isFull()
{
    return size == capacity;
}

bool ListSeq::resize(){
    int *_data = new int[++capacity];

    for (int i = 0; i < size; i++){
        _data[i] = data[i];
    }

    delete [] data; //free para tipos vetoriais, retira da heap
    data = _data;

    return true;
}

void ListSeq::destroy() {
    delete [] data;
}

int ListSeq::find(int elem) {
    int found = -1;
    for (int i = 0; i < size; i++){
        if (data[i] == elem) found = i;
    }

    return found;
}

int ListSeq::get(int pos) {
    if (pos < size && pos > 0){
        return data[pos];;
    } else{
        return 0;
    }
    
}

void ListSeq::remove() {
    if (!isEmpty()) size--;
}

void ListSeq::insert(int elem, int pos) {
    if (pos > capacity){
        resize();
        for (int i = capacity; i > pos; i--){
            data[i] = data[i - 1];
        }

        data[pos] = elem;
    }
}

void ListSeq::removeAt(int pos) {
    if (pos < size){
        for (int i = pos; i < size - 1; i++){
            data[i] = data[i + 1];
        }

    size--;

    }
}

bool ListSeq::addSorted(int elem) {
    if(size + 1 > capacity) resize();
    
    int pos = 0;

    for (int i = capacity; i > 0; i--){
        if (data[i] > elem) pos = i; break;
        data[i] = data[i - 1];
    }

    data[pos] = elem;
    
    return true;
}

bool ListSeq::print(){
    for (int i = 0; i < size; i++){
        cout << data[i] << " ";
    }
    cout << endl;

    return true;
}