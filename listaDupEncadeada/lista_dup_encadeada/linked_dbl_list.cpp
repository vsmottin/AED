#include "linked_dbl_list.hpp"
#include <stdio.h>
#include <iostream>

using namespace std;

List::List() { //metodo construtor
    this-> head = nullptr;
    this-> tail = nullptr;
}

List::~List() {

}   //metodo destrutor

bool List::push_front(int key){
    Node* aux = new Node{key, nullptr, this-> head};
    if (!aux) return false;
    this-> head = aux;
    if (!aux -> next)
        aux-> next-> prev = aux;
    else
        this-> tail = aux;
    return true;
}

bool List::pop_front() {
    Node* aux = this-> head;
    if (!aux) return false;

    this-> head = aux -> next;
    if (!this-> head) this-> tail = nullptr;
    this-> head -> prev = nullptr;

    delete aux;
    return true;
}

bool List::push_back(int key) {
    Node* aux = new Node{key, this-> tail, nullptr};
    if (!aux) return false;
    this-> tail -> next = aux;
    this-> tail = aux;
    return true;
}

bool List::equals(List* other) {
    Node* aux1 = this-> head;
    Node* aux2 = other-> head;
    
}

int List::get(int pos) {}

void List::print() {}

int List::size() {
}

Node* List::find(int key) {
}

void List::insert_after(int key, Node* elem) { //apos find
}

bool List::remove_after(Node* pos) { //apos find
}

bool List::insert(int pos, int key) {
}

bool List::removeAt(int pos) {}

bool List::remove(int key) {}

bool List::pop_back() {}

bool List::empty() {}

bool List::insert_sorted(int key){}
