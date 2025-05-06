#include "circular_list.hpp"
#include <iostream>
using namespace std;

int main() {
    CircularList lista;
    lista.push_front(3);
    lista.push_front(2);
    lista.push_front(1);
    lista.push_back(4);
    lista.print(); // -> 1 -> 2 -> 3 -> 4

    lista.pop_back();
    lista.print(); // -> 1 -> 2 -> 3

    CircularList* copia = lista.deep_copy();
    copia->print(); // -> 1 -> 2 -> 3

    delete copia;
    return 0;
}