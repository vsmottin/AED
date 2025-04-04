#include "linked_list.hpp"
#include <stdio.h>

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
    return true;
}

bool LinkedList::push_back(int key) { //insere no fim
    return true;
}

bool LinkedList::equals(LinkedList* other) {
    return false;
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
    return 0;
}

Node* LinkedList::find(int key) {
    return nullptr;
}

bool LinkedList::insert_after(int key, Node* pos) { //apos find
    return true;
}

bool LinkedList::remove_after(Node* pos) { //apos find
    return true;
}

bool LinkedList::insert(int pos) {
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