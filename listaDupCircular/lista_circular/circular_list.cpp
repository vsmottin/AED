#include "circular_list.hpp"
#include <stdio.h>
#include <iostream>

using namespace std;

CircularList::CircularList() { //metodo construtor
    this-> start = nullptr;
}

CircularList::~CircularList() {
    if (!this-> start) return;
    Node* current = this-> start->next;
    while (current != this-> start) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    delete this->start;
    this->start = nullptr;
}


bool CircularList::push_front(int key){
    Node* node = new Node{key, start};
    if (!node) return false;

    if(!start){
        node-> next = node;
        this-> start = node;
    } else{
        Node* last = start;
        while (last-> next != start) {
            last = last-> next;
        }

        node-> next = start;
        this-> start = node;
        last-> next = start;
    }
    
    return true;
}

bool CircularList::pop_front() {
    if (!this-> start) return false;

    if (this-> start->next == this-> start) { 
        delete this-> start;
        this-> start = nullptr;
    } else {
        Node* last = this-> start;
        while (last-> next != this-> start)
            last = last-> next;

        Node* temp = this-> start;
        this-> start = this-> start-> next;
        last-> next = this-> start;
        delete temp;
    }

    return true;
}


bool CircularList::push_back(int key) { //insere no fim
        Node* novo = new Node{key, start};
        if (!novo) return false;
    
        if (!this-> start){
            this-> start = novo;
            novo-> next = novo;

        } else {
            Node* aux = this-> start;
            while (aux-> next != this-> start) {
                aux = aux-> next;
            }

            aux-> next = novo;
            novo-> next = this-> start;
            
        }
        return true;
}

bool CircularList::equals(CircularList* other) {
    Node* a1 = this-> start;
    Node* a2 = other-> start;

    if (!other || this->size() != other->size()) return false;
    
    while (a1-> next != this-> start){
        if (a1-> key != a2-> key) return false;
        
        a1 = a1-> next;
        a2 = a2-> next;
    }

    if (a1-> key != a2-> key) return false;
    
    return true;
}

int CircularList::get(int pos) { //retorna o node
    if(this-> empty()) return -1;

    Node* aux = this-> start;
    for (size_t i = 0; i < pos; i++){
        aux = aux-> next;
        if(aux == this-> start) return -1;
    }

    return aux-> key;
}

void CircularList::print() {
    if (!this-> start){
        cout << "Lista vazia" << endl;
        return;
    }

    Node* node = this-> start;
    cout << " -> " << node-> key;
    node = node-> next;

    while(node-> next != this-> start){
        cout << " -> " << node-> key;
        node = node-> next;
    }

    cout << endl;
}

int CircularList::size() {
    if(!this-> start) return 0;

    int size = 1;
    Node* aux = this-> start-> next;

    while (aux != this-> start){
        size++;
        aux = aux-> next;
    }
    
    return size;
}

Node* CircularList::find(int key) {
    if (this-> empty()) return nullptr;
    if(this-> start-> key == key) return this-> start;

    Node* aux = this-> start-> next;
    while (aux != this-> start){
        if(aux-> key == key) return aux;
        aux = aux-> next;
    }

    return nullptr;
}

void CircularList::insert_after(int key, Node* elem) { //apos find
    Node* novo =  new Node{key, elem-> next};
    elem-> next = novo;
}

bool CircularList::remove_after(Node* pos) { //apos find
    if (this-> empty()) return false;

    Node* aux = pos-> next;
    if (!aux) return false;

    pos-> next = pos-> next-> next;
    delete aux;
    
    return true;
}

bool CircularList::insert(int pos, int key) {
    if(pos == 0) return this-> push_front(key);
    
    Node* aux = this-> start;

    for (size_t i = 1; i < pos; i++){
        aux = aux-> next;
        if (aux == this-> start) return false;
    }

    if (aux-> next == start && pos == this->size()) {
        Node* novo = new Node{key, start};
        aux->next = novo;
        return true;
    }
        
    Node* novo = new Node{key, aux-> next};
    if (!novo) return false;

    aux->next = novo;
    
    return true;
}

bool CircularList::removeAt(int pos) {
    if (this-> empty()) return false;
    if (pos == 0) return pop_front();

    Node* aux = this-> start;
    
    for (size_t i = 1; i < pos; i++){
        aux = aux-> next;
        if (aux == this-> start) return false;
    }

    if(aux-> next == start) return false;
    
    Node* deletar = aux-> next;
    aux-> next = aux-> next-> next;
    delete deletar;

    return true;
}

bool CircularList::remove(int key) {
    if (this->empty()) return false;

    Node* current = start;
    Node* prev = nullptr;

    if (current->key == key) {
        if (current->next == start) {
            delete current;
            start = nullptr;
        } else {
            Node* last = start;
            while (last->next != start) last = last->next;
            start = start->next;
            last->next = start;
            delete current;
        }
        return true;
    }

    prev = start;
    current = start->next;
    while (current != start) {
        if (current->key == key) {
            prev->next = current->next;
            delete current;
            return true;
        }
        prev = current;
        current = current->next;
    }

    return false; 
}


bool CircularList::pop_back() {
    if (this-> empty()) return false;

    if (this-> start-> next == start) {
        delete start;
        start = nullptr;
    } else {
        Node* aux = start;

        while (aux-> next-> next != start) {
            aux = aux-> next;
        }

        Node* deletar = aux-> next;
        aux-> next = start;
        delete deletar;
    }

    return true;
}

bool CircularList::empty() {
    return (!this-> start);
}

// e se for o tail?
bool CircularList::insert_sorted(int key) {
    if (!this-> start || key <= this-> start-> key) {
        return push_front(key);
    }

    Node* ant = this-> start;
    Node* current = this-> start->next;
    
    while (current != this-> start && current->key < key) {
        ant = current;
        current = current-> next;
    }
    
    Node* novo = new Node{key, current};
    ant-> next = novo;
    
    return true;
    
}

void CircularList::print_last(){
    if (!this-> start){
        cout << "Lista vazia." << endl;
        return;
    }

    Node* aux = this-> start;

    while (aux-> next != start){
        aux = aux-> next;
    }

    cout << "Último -> " << aux-> key << endl;
}

CircularList* CircularList::deep_copy() {
    CircularList* new_list = new CircularList();
    if (!this->start) return  new_list;

    Node* original_current = this->start;
    Node* new_start = new Node{original_current->key, nullptr};
    Node* new_current = new_start;

    original_current = original_current->next;

    while (original_current != start) {
        new_current->next = new Node{original_current->key, nullptr};
        new_current = new_current->next;
        original_current = original_current->next;
    }

    new_current-> next = new_start;
    new_list-> start = new_start;
    return new_list;
}

CircularList* CircularList::concat(CircularList* list2) {
    CircularList* new_list = new CircularList();

    if (!start && (!list2 || list2->empty())) return new_list;

    Node* current = this->start;
    do {
        new_list->push_back(current->key);
        current = current->next;
    } while (current != this->start);

    if (list2 && !list2->empty()) {
        current = list2->start;
        do {
            new_list->push_back(current->key);
            current = current->next;
        } while (current != list2->start);
    }

    return new_list;
}


CircularList* CircularList::merge(CircularList* list2) {
    CircularList* new_list = new CircularList(); 
    Node* new_current = nullptr; 

    Node* current1 = this->start; 
    Node* current2 = (list2 != nullptr) ? list2->start : nullptr; 

    bool use_list1 = true; 

    while (current1 || current2) {
        if (use_list1 && current1) {
            if (!new_list-> start) {
                new_list-> start = new Node{current1->key, nullptr};
                new_current = new_list-> start;
            } else {
                new_current->next = new Node{current1->key, nullptr};
                new_current = new_current-> next;
            }
            current1 = current1->next; 
        } else if (!use_list1 && current2) {
            if (new_list->start == nullptr) {
                new_list->start = new Node{current2->key, nullptr};
                new_current = new_list-> start;
            } else {
                new_current->next = new Node{current2->key, nullptr};
                new_current = new_current-> next;
            }
            current2 = current2->next;
        }

        use_list1 = !use_list1;

        if (use_list1 && !current1 && current2) {
            use_list1 = false;
        } else if (!use_list1 && !current2 && current1) {
            use_list1 = true;
        }
    }

    if (new_current) {
        new_current->next = new_list-> start;
    }

    return new_list;
}