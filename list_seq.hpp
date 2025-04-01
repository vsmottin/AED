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

    bool remove();

    void insert(int elem, int pos);

    bool removeAt(int pos);

    bool addSorted(int elem);
};