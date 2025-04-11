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
    Node* aux = this-> head;
    while (aux-> next){
        aux = aux-> next;
    }
    
    Node* novo = new Node{key, nullptr};
    if (!novo) return false;

    aux-> next = novo;
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
    Node* aux = this-> head;
    
    for (size_t i = 0; i < pos; i++){
        aux = aux-> next;
    }

    if (!aux) return -1;
    
    return aux-> key;
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
    Node* aux = this-> head;
    
    while (aux-> key != key && aux-> next){
        aux = aux-> next;
    }
    
    if (!aux) return nullptr;
    
    return aux;
}

void LinkedList::insert_after(int key, Node* elem) { //apos find
    Node* novo =  new Node{key, elem-> next};
    elem->next = novo;
}

bool LinkedList::remove_after(Node* pos) { //apos find
    Node* aux = pos-> next;
    if (!aux) return false;

    pos-> next = pos-> next-> next;
    delete aux;
    
    return true;
}

bool LinkedList::insert(int pos, int key) {

    if(pos == 0) return this-> push_front(key);
    
    Node* aux = this-> head;

    for (size_t i = 1; i < pos && aux; i++){
        aux = aux-> next;
    }

    if (!aux) return false;
        
    Node* novo = new Node{key, aux-> next};
    if (!novo) return false;

    aux->next = novo;
    
    return true;
}

bool LinkedList::removeAt(int pos) {
    Node* aux = this-> head;
    
    for (size_t i = 1; i < pos && aux; i++){
        aux = aux-> next;
    }
    
    if (!aux-> next) return false;

    Node* deletar = aux-> next;
    aux-> next = aux-> next-> next;
    delete deletar;

    return true;
}

bool LinkedList::remove(int key) {
    Node* aux = this-> head;
    
    while (aux-> next-> key != key && aux-> next){
        aux = aux-> next;
    }

    if (!aux-> next) return false;

    Node* deletar = aux-> next;
    aux-> next = aux-> next-> next;
    delete deletar;
    
    return true;
}

bool LinkedList::pop_back() { //apaga
    Node* aux = this-> head;

    if (!aux) return false;

    while (aux-> next-> next){
        aux = aux-> next;
    }
    
    Node* deletar = aux-> next;
    aux-> next = nullptr;
    delete deletar;

    return true;
}

bool LinkedList::empty() {
    return this-> head == nullptr;
}

bool LinkedList::insert_sorted(int key){

}