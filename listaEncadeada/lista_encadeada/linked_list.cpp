#include "linked_list.hpp"
#include <stdio.h>
#include <iostream>

using namespace std;

LinkedList::LinkedList() { //metodo construtor
    this-> head = nullptr;
}

LinkedList::~LinkedList() {}   //metodo destrutor

bool LinkedList::push_front(int key){
    Node* node = new Node{key, nullptr};
    if (!node) return false;

    node-> next = this-> head;
    this-> head = node;
    return true;
}

bool LinkedList::pop_front() { //insere na frente
if (!this-> head){
    Node* aux = this-> head;
    this-> head = aux-> next;
    delete aux;
    return true;
}

    return false;
}

bool LinkedList::push_back(int key) { //insere no fim
    return true;
}

bool LinkedList::equals(LinkedList* other) {
    Node* a1 = this-> head;
    Node* a2 = other-> head;
    
    while (a1 && a2){
        if (a1-> key == a2-> key){
            a1 = a1-> next;
            a2 = a2-> next;
        } else{
            return false;
        }   
    }
    
    return true;
}

int LinkedList::get(int pos) { //retorna o node
    return 0;
}

void LinkedList::print() {
    Node* node = this-> head;
    while(node){
        cout << " -> " << node-> key;
        node = node-> next;
    }
}

int LinkedList::size() {
    int size = 0;
    Node* aux = this-> head;
    while (aux){
        aux = aux-> next;
        size++;
    }
    
    return size;
}

Node* LinkedList::find(int key) {
    return nullptr;
}

void LinkedList::insert_after(int key, Node* elem) { //apos find
    Node* novo =  new Node{key, elem-> next};
    elem->next = novo;
}

bool LinkedList::remove_after(Node* pos) { //apos find
    return true;
}

bool LinkedList::insert(int pos, int key) {
    if (pos <= this-> size()){
        Node* aux = this-> head;

        for (size_t i = 1; i < pos; i++){
            aux = aux-> next;
        }
        
        Node* novo = new Node{key, aux};
        aux->next = novo;

    } else {
        return false;
    }
    
    return true;
}

bool LinkedList::remove(int pos) {
    return true;
}

bool LinkedList::remove(int key) {
    return true;
}

bool LinkedList::pop_back() { //apaga
    return true;
}

bool LinkedList::empty() {
    return true;
}