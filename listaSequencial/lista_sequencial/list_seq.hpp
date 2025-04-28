#include <iostream>
using namespace std;

class ListSeq{
public:
    int size = 0; // número de posições ocupadas
    int capacity; // capacidade da lista
    int *data;    // endereço do vetor na heap

    ListSeq(int _capacity);

    void destroy();

    bool resize();

    bool print();

    int find(int elem);

    int get(int pos);

    bool isEmpty();

    bool isFull();

    bool add(int elem);

    void remove();

    void insert(int elem, int pos);

    void removeAt(int pos);

    bool addSorted(int elem);

    int list_get_available();

    void list_clear();

    void list_remove_last(int n);

    void list_print_reverse();

    void list_add(int n, int* vet);
};