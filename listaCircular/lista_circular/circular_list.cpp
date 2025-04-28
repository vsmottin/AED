#include "circular_list.hpp"
#include <stdio.h>
#include <iostream>

using namespace std;

CircularList::CircularList() {
  this->head = nullptr;
  this->tail = nullptr;
}

CircularList::~CircularList() {
  Node* current = this->head;
  while (current) {
    Node* next = current->next;
    delete current;
    current = next;
  }
  this->head = nullptr;
  this->tail = nullptr;
}  

bool CircularList::push_front(int key){
  Node* novo = new Node{key, this->head};
  if (!this->head) {
    this->head = novo;
    this->tail = novo;
  } else {
    this->tail->next = novo;
  }
  this->tail = novo;
  return true;
}

bool CircularList::pop_front() {
  if (!this->head) {
    return false; // List is empty
  }
  Node* temp = this->head;
  this->head = this->head->next;
  delete temp;
  if (!this->head) {
    this->tail = nullptr; // lista fica vazia
  } else {
    this->tail->next = this->head; // mantendo a propriedade circular
  }
  return true;
}

bool CircularList::push_back(int key) {
  return true;
}

bool CircularList::equals(CircularList* other) {
  if (this->size() != other->size())
    return false;
  Node* current1 = this->head;
  Node* current2 = other->head;
  while (current1 && current2) {
    if (current1->key != current2->key)
      return false;
    current1 = current1->next;
    current2 = current2->next;
  }
  return true;
}

int CircularList::get(int pos) {
  return 0;
}

void CircularList::print() {
  if (!this->head) {
    cout << "Lista vazia" << endl;
    return;
  }
  Node* aux = this->head;
  do {
    cout << aux->key << " ";
    aux = aux->next;
  } while (aux != this->head);
  cout << endl;
}

int CircularList::size() {
  if (!this->head) {
    return 0;
  }
  int count = 0;
  Node* aux = this->head;
  do {
    count++;
    aux = aux->next;
  } while (aux != this->head);
  return count;
}

Node* CircularList::find(int key) {
  return nullptr;
}

void CircularList::insert_after(int key, Node* pos) {
  if (!pos) {
    return;
  }
  Node* novo = new Node{key, pos->next};
  pos->next = novo;
  if (pos == this->tail) {
    this->tail = novo; // Atualiza o tail se o nó inserido for o último
  }
}

bool CircularList::remove_after(Node* pos) {
  return true;
}

bool CircularList::insert(int pos, int key) {
//considerar que ele precisa inserir mesmo em uma posição inválida (push_back)

  if (pos < 0 || pos > this->size()) {
    return false; // Posição inválida
  }
  if (pos == 0) {
    return this->push_front(key);
  }
  Node* current = this->head;
  for (int i = 0; i < pos - 1; i++) {
    current = current->next;
  }
  Node* novo = new Node{key, current->next};
  current->next = novo;
  if (current == this->tail) {
    this->tail = novo; // Atualiza o tail se o nó inserido for o último
  }
  return true;
}

bool CircularList::removeAt(int pos) {
  return true;
}

bool CircularList::remove(int key) {
  return true;
}

bool CircularList::pop_back() {
  return true;
}

bool CircularList::empty() {
  return true;
}

bool CircularList::insert_sorted(int key) {
    if (!this-> head || key <= this-> head-> key) {
        return push_front(key);
    }

    Node* ant = this-> head;
    Node* current = this-> head->next;
    
    while (current != this-> head && current->key < key) {
        ant = current;
        current = current-> next;
    }
    
    Node* novo = new Node{key, current};
    ant-> next = novo;
    
    return true;
    
}

void CircularList::print_last(){
    if (!this-> head){
        cout << "Lista vazia." << endl;
        return;
    }

    Node* aux = this-> head;

    while (aux-> next != head){
        aux = aux-> next;
    }

    cout << "Último -> " << aux-> key << endl;
}

CircularList* CircularList::deep_copy() {
    CircularList* new_list = new CircularList();
    if (!this->head) return  new_list;

    Node* original_current = this->head;
    Node* new_head = new Node{original_current->key, nullptr};
    Node* new_current = new_head;

    original_current = original_current->next;

    while (original_current != head) {
        new_current->next = new Node{original_current->key, nullptr};
        new_current = new_current->next;
        original_current = original_current->next;
    }

    new_current-> next = new_head;
    new_list-> head = new_head;
    return new_list;
}

CircularList* CircularList::concat(CircularList* list2) {
    CircularList* new_list = new CircularList();

    if (!head && (!list2 || list2->empty())) return new_list;

    Node* current = this->head;
    do {
        new_list->push_back(current->key);
        current = current->next;
    } while (current != this->head);

    if (list2 && !list2->empty()) {
        current = list2->head;
        do {
            new_list->push_back(current->key);
            current = current->next;
        } while (current != list2->head);
    }

    return new_list;
}


CircularList* CircularList::merge(CircularList* list2) {
    CircularList* new_list = new CircularList(); 
    Node* new_current = nullptr; 

    Node* current1 = this->head; 
    Node* current2 = (list2 != nullptr) ? list2->head : nullptr; 

    bool use_list1 = true; 

    while (current1 || current2) {
        if (use_list1 && current1) {
            if (!new_list-> head) {
                new_list-> head = new Node{current1->key, nullptr};
                new_current = new_list-> head;
            } else {
                new_current->next = new Node{current1->key, nullptr};
                new_current = new_current-> next;
            }
            current1 = current1->next; 
        } else if (!use_list1 && current2) {
            if (new_list->head == nullptr) {
                new_list->head = new Node{current2->key, nullptr};
                new_current = new_list-> head;
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
        new_current->next = new_list-> head;
    }

    return new_list;
}

CircularList* CircularList::deep_copy() {
    
}
