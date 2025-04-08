#pragma once

class Node {
public:
    int key;
    Node* next;
};


class LinkedList {
private:
    Node* head;

public:
    LinkedList();
    ~LinkedList();
    
    bool push_front(int key);
    bool pop_front();
    
    void print();
    int size();
    bool empty();
    
    bool push_back(int key);
    bool pop_back();
    
    int get(int pos);
    Node* find(int key);
    
    void insert_after(int key, Node* pos);
    bool remove_after(Node* pos);
    
    bool insert(int pos, int key);
    bool remove(int pos);
    bool remove(int key);
    
    bool insert_sorted(int key);

    bool equals(LinkedList* other);
};