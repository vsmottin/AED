#include <stdio.h>
#include "linked_dbl_list.hpp"

int main() {
    List lista;
    lista.push_front(3);
    lista.push_front(2);
    lista.push_front(1);
    lista.push_back(4);
    lista.print(); // -> 1 -> 2 -> 3 -> 4

    lista.pop_front();
    lista.pop_back();
    lista.print(); // -> 2 -> 3

    lista.insert_sorted(1);
    lista.insert_sorted(5);
    lista.insert_sorted(4);
    lista.print(); // -> 1 -> 2 -> 3 -> 4 -> 5

    lista.remove(3);
    lista.removeAt(0);
    lista.print(); // -> 2 -> 4 -> 5

    return 0;
}