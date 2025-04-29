#include "linked_dbl_list.hpp"
#include <stdio.h>
#include <iostream>

using namespace std;

List::List() { //metodo construtor
    this-> head = nullptr;
    this-> tail = nullptr;
}

List::~List() {
    Node* aux = this-> head;
    while (aux) {
        Node* next = aux-> next;
        delete aux;
        aux = next;
    }
}   //metodo destrutor

bool List::push_front(int key){
    Node* aux = new Node{key, nullptr, this-> head};
    if (!aux) return false;

    if (this-> head) this-> head-> prev = aux;
    else this-> tail = aux;

    this-> head = aux;
    return true;
}

bool List::pop_front() {
    if (!this-> head) return false;
    
    Node* aux = this-> head;
    this-> head = aux -> next;

    if (!this-> head) this-> tail = nullptr;
    this-> head -> prev = nullptr;

    delete aux;
    return true;
}

bool List::push_back(int key) {
   if (this-> tail) {
        Node* aux = new Node{key, this-> tail, nullptr};

        if (!aux) return false;

        this-> tail = aux;
        this-> tail -> prev -> next = this-> tail;
        return true;
   }
   
   return this-> push_front(key);
}

bool List::equals(List* other) {
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
        
    if (a1 || a2) return false;

    return true;
}

int List::get(int pos) { //retorna o node
    Node* aux = this-> head;
    
    for (size_t i = 0; i < pos; i++){
        aux = aux-> next;
    }

    if (!aux) return -1;
    
    return aux-> key;
}

void List::print() {
    Node* node = this-> head;
    while(node){
        cout << " -> " << node-> key;
        node = node-> next;
    }
    cout << endl;
}


int List::size() {
    int count = 0;
    Node* aux = this-> head;
    while (aux){
        aux = aux-> next;
        count++;
    }
    
    return count;

}

Node* List::find(int key) {
    Node* aux = this-> head;
    while (aux && aux-> key != key){
        aux = aux-> next;
    }

    return aux;
}

void List::insert_after(int key, Node* elem) { //apos find
    if (elem == tail){
        this-> push_back(key);
        return;
    }
    
    Node* novo = new Node{key, elem, elem-> next};
    if(!novo) return;

    elem-> next-> prev = novo;
    elem-> next = novo;
}

bool List::remove_after(Node* pos) { //apos find
    Node* aux = pos-> next;
    if (!aux) return false;

    if (pos-> next == tail) return this-> pop_back();
    pos-> next-> next-> prev = pos;
    pos-> next = pos-> next-> next;
    delete aux;

    return true;
}

bool List::insert(int pos, int key) {
    if (pos == 0) return this-> push_front(key);

    Node* aux = this-> head;
    for (size_t i = 1; i < pos && aux; i++){
        aux = aux-> next;
    }

    if(!aux) return false;
    if (aux-> next == this-> tail) return this-> push_back(key);

    Node* novo = new Node{key, aux, aux-> next};
    if (!novo) return false;
    
    aux-> next-> prev = aux;
    aux-> next = novo;
    return true;
}


bool List::insert(int pos, int key){
    
    if (empty() || pos == 0) return push_front(key);
    
    Node* novo = new Node{key, nullptr};
    Node* aux = head;

    for (size_t i = 1; i < pos && aux; i++){
        aux = aux-> next;
    }
    
    if (!aux) return push_back(key);

    novo-> prev = aux-> prev;
    aux-> prev -> next = novo;

    novo-> next = aux;
    aux-> prev = novo;
    
    return true;
}

bool List::removeAt(int pos) {
    if(pos == 0) return this-> pop_front();

    Node* aux = this-> head;
    for (size_t i = 1; i < pos && aux; i++){
        aux = aux-> next;
    }

    if(!aux || !aux-> next) return false;
    if (aux-> next == tail) return this-> pop_back();

    Node* deletar = aux-> next;
    aux-> next-> next-> prev = aux;
    aux-> next = aux-> next-> next;
    delete deletar;
    return true;
}

bool List::remove(int key) {
    if (this-> head-> key == key) return this-> pop_front();

    Node* aux = this-> head;
    while (aux && aux-> next-> key != key){
        aux = aux-> next;
    }

    if (!aux || !aux-> next) return false;
    if (aux-> next ==  tail) return this-> pop_back();

    Node* deletar = aux-> next;
    aux-> next-> next-> prev = aux;
    aux-> next = aux-> next-> next;
    delete deletar;    
    return true;
}


bool List::remove(int key){
    
    if(head-> key == key) return pop_front();
    
    Node* aux = head;

    while(aux-> next){
        aux = aux-> next;

        if(aux-> key == key){
            aux-> prev-> next = aux-> next;
            if(aux == tail) return pop_back();
            aux-> next-> prev = aux-> prev;

            delete aux;
            break;
        }
    }

    if (!aux-> next) return false;

    return true;
}

bool List::pop_back() {
    if (!this-> tail) return false;

    Node* aux = this-> tail;
    this-> tail = tail-> prev;

    if (this-> tail) tail-> next = nullptr;
    else this-> head = nullptr;

    delete aux;
    return true;
}

bool List::empty() {
    return (!this->head);
}

bool List::insert_sorted(int key){
    if (empty() || this-> head-> key >= key) return this-> push_front(key);
    if (this-> tail-> key < key) return this-> push_back(key);

    Node* aux = this-> head;
    while (aux-> next && aux-> next-> key < key){
        aux = aux-> next;
    }

    Node* novo = new Node{key, aux, aux->next};
    if(!novo) return false;

    aux-> next-> prev = novo;
    aux-> next = novo;
    return true;
}


bool List::insert_sorted(int key){
    if(head-> key >= key || empty()) return push_front(key);
    if(tail-> key <= key) return push_back(key);

    Node* novo = new Node{key, nullptr};
    Node* aux = head-> next;

    while(aux){
        if(aux-> key >= key){
            novo-> prev = aux-> prev;
            novo-> next = aux;

            aux-> prev-> next = novo;
            aux-> prev = novo;
            break;
        }
        
        aux = aux-> next;
    }

    return true;
}