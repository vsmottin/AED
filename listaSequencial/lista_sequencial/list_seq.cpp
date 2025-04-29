#include <iostream>
#include <algorithm>
#include "list_seq.hpp"

ListSeq::ListSeq(int _capacity){
    data = new int[_capacity]; // new aloca na heap
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
    data = nullptr;
    size = 0;
    capacity = 0;
}

int ListSeq::find(int elem) {
    for (int i = 0; i < size; i++){
        if (data[i] == elem) return i;
    }
    
    return -1;
}

int ListSeq::get(int pos) {
    if (pos < size && pos >= 0){
        return data[pos];
    }

    return -1;
}

void ListSeq::remove() {
    if (!isEmpty()) size--;
}

void ListSeq::insert(int elem, int pos) {
    if (pos < 0 || pos > size) return;

    if (size + 1 > capacity) resize();

    for (int i = size; i > pos; i--) {
        data[i] = data[i - 1];
    }

    data[pos] = elem;
    size++; 
}

void ListSeq::removeAt(int pos) {
    if (pos < size){
        for (int i = pos; i < size - 1; i++){
            data[i] = data[i + 1];
        }

    size--;

    }
}

//pergunta se o próximo é maior, verificar se não é o último
bool ListSeq::addSorted(int elem) {
    if (size >= capacity) resize();
    
    int i = size - 1;
    
    while (i >= 0 && data[i] > elem) {
        data[i + 1] = data[i];
        i--;
    }
    
    data[i + 1] = elem;
    size++;
    
    return true;
}


bool ListSeq::print(){
    for (int i = 0; i < size; i++){
        cout << data[i] << " ";
    }

    return true;
}


int ListSeq::list_get_available(){
    return capacity - size;
}

void ListSeq::list_clear(){
    delete [] data;
    data = nullptr;
    size = 0;
}

void ListSeq::list_remove_last(int n){
    if(n > size) n = size;    
    size -= n;
}

void ListSeq::list_print_reverse(){
    for (size_t i = size - 1; i > 0; i--){
        cout << "Elemento " << i << ": " << data[i] << endl;
    }
}

void ListSeq::list_add(int n, int* vet){
    int i = 0;
    for (i; i < n; i++){
        if (size + i + 1 > capacity) resize();
        data[size + i] = vet[i];
    }

    size += i;
}

bool ListSeq::list_is_sorted(){
    if(isEmpty()) return false;

    int ultimo = data[0];

    for (size_t i = 1; i < size; i++){
        if(data[i] < ultimo){
            return false;
        } else{
            ultimo = data[i];
        }
    }
    
    return true;
}

void ListSeq::list_reverse() {
    for (size_t i = 0; i < size/2; i++) {
        int temp = data[i];
        data[i] = data[size - 1 - i];
        data[size - 1 - i] = temp;
    }
}

bool ListSeq::list_equal(ListSeq* outra){
    if (size != outra-> size) return false;
    
    for (size_t i = 0; i < size; i++){
        if(data[i] != outra-> data[i]) return false;
    }
    
    return true;
}

ListSeq* ListSeq::list_from_vector(size_t n, int* vet){
    if(n <= 0 || !vet) return new ListSeq{0};
    
    ListSeq* listaNova = new ListSeq{n * 2};
    listaNova-> size = n;
    for (size_t i = 0; i < n; i++){
        listaNova-> data[i] = vet[i];
    }
    
    return listaNova;
}

ListSeq* ListSeq::list_copy(){
    ListSeq* listaNova = new ListSeq{this-> capacity};
    listaNova-> size = this-> size;

    for (size_t i = 0; i < size; i++){
        listaNova-> data[i] = this-> data[i];
    }
    
    return listaNova;
}

int ListSeq::list_concat(ListSeq* list2){
    if(capacity == size || !list2 || list2-> size == 0) return 0;

    size_t tamanho = (capacity - size) > list2-> size ? list2-> size : capacity - size;

    size_t i = 0;

    for (i; i < tamanho; i++){
        data[size + i] = list2-> data[i];
    }

    size += i;
    return i;
}