#include "linked_list.hpp"
#include <stdio.h>
#include <iostream>

using namespace std;

LinkedList::LinkedList() { //metodo construtor
    this-> head = nullptr;
}

LinkedList::~LinkedList() {
    Node* aux = this-> head;
    while (aux) {
        Node* next = aux-> next;
        delete aux;
        aux = next;
    }
}   

bool LinkedList::push_front(int key){
    Node* node = new Node{key, nullptr};
    if (!node) return false;

    node-> next = this-> head;
    this-> head = node;
    return true;
}

bool LinkedList::pop_front() { //deleta na frente
    if (this-> head){
        Node* aux = this-> head;
        this-> head = aux-> next;
        delete aux;
        return true;
    }

    return false;
}

bool LinkedList::push_back(int key) { //insere no fim
        Node* novo = new Node{key, nullptr};
        if (!novo) return false;
    
        if (!this-> head) this-> head = novo;
        
        else {
            Node* aux = this-> head;
            while (aux->next) {
                aux = aux->next;
            }

            aux->next = novo;
        }
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
    
    while (aux-> key != key && aux){
        aux = aux-> next;
    }
    
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
    if (!this-> head) return false;

    if (this-> head->key == key) {
        Node* temp = this-> head;
        this-> head = this-> head-> next;
        delete temp;
        return true;
    }

    Node* aux = head;
    while (aux-> next && aux-> next-> key != key) {
        aux = aux-> next;
    }

    if (!aux-> next) return false; // Não encontrou

    Node* deletar = aux-> next;
    aux-> next = aux-> next-> next;
    delete deletar;
    return true;
}

bool LinkedList::pop_back() {
    if (!this-> head) return false;

    if (!this-> head-> next) {
        delete head;
        head = nullptr;
    } else {
        Node* aux = head;
        while (aux-> next-> next) {
            aux = aux-> next;
        }
        delete aux-> next;
        aux-> next = nullptr;
    }

    return true;
}

bool LinkedList::empty() {
    return this-> head == nullptr;
}

bool LinkedList::insert_sorted(int key) {
    if (!this-> head || key < this-> head-> key) {
        return push_front(key);
    }

    Node* current = this-> head;
    while (current-> next && current-> next-> key < key) {
        current = current-> next;
    }

    Node* novo = new Node{key, current-> next};
    current-> next = novo;
    return true;
}

void LinkedList::print_last(){
    Node* aux = this-> head;

    if (!aux){
        cout << "Lista vazia." << endl;
        return;
    }

    while (aux-> next){
        aux = aux-> next;
    }

    cout << "Último -> " << aux-> key << endl;
}

LinkedList* LinkedList::deep_copy() {
    if (this->head == nullptr) {
        return new LinkedList();
    }

    Node* original_current = this->head;
    Node* new_head = new Node{original_current->key, nullptr};
    Node* new_current = new_head;

    original_current = original_current->next;

    while (original_current != nullptr) {
        new_current->next = new Node{original_current->key, nullptr};
        new_current = new_current->next;
        original_current = original_current->next;
    }

    LinkedList* new_list = new LinkedList();
    new_list->head = new_head;
    return new_list;
}

LinkedList* LinkedList::concat(LinkedList* list2) {
    LinkedList* new_list = new LinkedList(); 
    Node* new_current = nullptr; 

    Node* original_current = this->head;
    if (original_current != nullptr) {
        new_list->head = new Node{original_current->key, nullptr};
        new_current = new_list->head;
        original_current = original_current->next;

        while (original_current != nullptr) {
            new_current->next = new Node{original_current->key, nullptr};
            new_current = new_current->next;
            original_current = original_current->next;
        }
    }

    if (list2 != nullptr) {
        original_current = list2->head; 

        if (new_current == nullptr && original_current != nullptr) {
            new_list->head = new Node{original_current->key, nullptr};
            new_current = new_list->head;
            original_current = original_current->next;
        }

        while (original_current != nullptr) {
            new_current->next = new Node{original_current->key, nullptr};
            new_current = new_current->next;
            original_current = original_current->next;
        }
    }

    return new_list; 
}

LinkedList* LinkedList::merge(LinkedList* list2) {
    LinkedList* new_list = new LinkedList(); 
    Node* new_current = nullptr; 

    Node* current1 = this->head; 
    Node* current2 = (list2 != nullptr) ? list2->head : nullptr; 

    bool use_list1 = true; 

    while (current1 != nullptr || current2 != nullptr) {
        if (use_list1 && current1 != nullptr) {
            if (new_list->head == nullptr) {
                new_list->head = new Node{current1->key, nullptr};
                new_current = new_list->head;
            } else {
                new_current->next = new Node{current1->key, nullptr};
                new_current = new_current->next;
            }
            current1 = current1->next; 
        } else if (!use_list1 && current2 != nullptr) {
            if (new_list->head == nullptr) {
                new_list->head = new Node{current2->key, nullptr};
                new_current = new_list->head;
            } else {
                new_current->next = new Node{current2->key, nullptr};
                new_current = new_current->next;
            }
            current2 = current2->next;
        }

        use_list1 = !use_list1;

        if (use_list1 && current1 == nullptr && current2 != nullptr) {
            use_list1 = false;
        } else if (!use_list1 && current2 == nullptr && current1 != nullptr) {
            use_list1 = true;
        }
    }

    return new_list;
}


LinkedList* LinkedList::deep_copy(){
    if (empty()) return nullptr;

    LinkedList* listaNova = new LinkedList{};

    Node* aux = this-> head;
    Node* newHead = new Node{head-> key, nullptr};
    Node* atual = newHead-> next;
    
    while(aux-> next){
        aux = aux-> next;
        atual = new Node{aux-> key, nullptr};
        atual = atual-> next;
    }

    listaNova-> head = newHead;
    return listaNova;
}

LinkedList* LinkedList::concat(LinkedList* list2){
    if (empty()) return nullptr;

    LinkedList* listaNova = new LinkedList{};

    Node* newHead = new Node{head-> key, nullptr};
    Node* atual = newHead;

    Node* aux = head -> next;
    
    while(aux){
        atual-> next = new Node{aux-> key, nullptr};
        atual = atual-> next;
        aux = aux-> next;
    }

    listaNova-> head = newHead;
    
    if (!list2-> head) return listaNova;
    
    atual = new Node{list2-> head-> key, nullptr};
    aux = list2-> head-> next;

    while(aux){
        atual-> next = new Node{aux-> key, nullptr};
        atual = atual-> next;
        aux = aux-> next;
    }

    return listaNova;
}

LinkedList* LinkedList::merge(LinkedList* list2){
    
}