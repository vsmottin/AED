#include "linked_list.hpp"
#include <iostream>
using namespace std;

int main() {
    LinkedList list1;
    list1.push_front(3);
    list1.push_front(2);
    list1.push_front(1);
    list1.push_back(4);
    cout << "Lista 1 (push_front/push_back): ";
    list1.print(); // Deve mostrar: -> 1 -> 2 -> 3 -> 4

    list1.pop_front();
    list1.pop_back();
    cout << "\nLista 1 após pop_front e pop_back: ";
    list1.print(); // Deve mostrar: -> 2 -> 3

    cout << "\nElemento na posição 1: " << list1.get(1); // Deve ser 3
    cout << "\nTamanho da lista 1: " << list1.size(); // Deve ser 2

    LinkedList list2;
    list2.push_front(3);
    list2.push_front(2);
    cout << "\nLista 2: ";
    list2.print(); // -> 2 -> 3
    cout << "\nLista 1 == Lista 2? " << (list1.equals(&list2) ? "Sim" : "Não"); // Deve ser Sim

    Node* node = list2.find(2);
    list2.insert_after(5, node);
    cout << "\nLista 2 após insert_after(5): ";
    list2.print(); // -> 2 -> 5 -> 3
    list2.remove_after(node);
    cout << "\nLista 2 após remove_after(2): ";
    list2.print(); // -> 2 -> 3

    list2.insert(1, 10);
    cout << "\nLista 2 após insert(10 na posição 1): ";
    list2.print(); // -> 2 -> 10 -> 3
    list2.removeAt(1);
    cout << "\nLista 2 após removeAt(1): ";
    list2.print(); // -> 2 -> 3

    list2.push_back(7);
    list2.remove(3);
    cout << "\nLista 2 após remove(3): ";
    list2.print(); // -> 2 -> 7

    LinkedList sortedList;
    sortedList.insert_sorted(5);
    sortedList.insert_sorted(1);
    sortedList.insert_sorted(3);
    cout << "\nLista ordenada: ";
    sortedList.print(); // -> 1 -> 3 -> 5

    LinkedList* copiedList = sortedList.deep_copy();
    cout << "\nCópia da lista ordenada: ";
    copiedList->print(); // -> 1 -> 3 -> 5

    LinkedList* concatenated = list1.concat(&list2);
    cout << "\nConcatenação de lista1 e lista2: ";
    concatenated->print(); // -> 2 -> 3 -> 2 -> 7

    LinkedList listA;
    listA.push_back(1);
    listA.push_back(3);
    listA.push_back(5);

    LinkedList listB;
    listB.push_back(2);
    listB.push_back(4);

    LinkedList* mergedList = listA.merge(&listB);
    cout << "\nMerge de listA e listB: ";
    mergedList->print(); // -> 1 -> 2 -> 3 -> 4 -> 5

    delete copiedList;
    delete concatenated;
    delete mergedList;

    return 0;
}