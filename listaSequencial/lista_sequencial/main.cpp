#include "list_seq.hpp"
#include <iostream>
using namespace std;

int main() {
    ListSeq lista(3); // Capacidade inicial 3
    cout << "Teste 1: Capacidade inicial = " << lista.isFull() << " (0 = não cheia)\n";

    lista.add(10);
    lista.add(20);
    lista.add(30);
    cout << "Teste 2: Lista cheia? " << lista.isFull() << " (1 = cheia)\n";

    lista.add(40); // Redimensiona para capacidade 4
    cout << "Teste 3: Tamanho após redimensionar: " << lista.get(3) << " (40)\n";

    cout << "Teste 4: Lista vazia? " << lista.isEmpty() << " (0 = não vazia)\n";

    cout << "Teste 5: Posição do 20: " << lista.find(20) << " (1)\n";
    cout << "Teste 5: Posição do 99: " << lista.find(99) << " (-1)\n";

    cout << "Teste 6: Elemento na posição 2: " << lista.get(2) << " (30)\n";
    cout << "Teste 6: Elemento na posição -1: " << lista.get(-1) << " (-1)\n";

    lista.remove();
    cout << "Teste 7: Tamanho após remover: ";
    lista.print(); // [10, 20, 30]

    lista.insert(15, 1);
    cout << "Teste 8: Após inserir 15 na posição 1: ";
    lista.print(); // [10, 15, 20, 30]

    lista.removeAt(2);
    cout << "Teste 9: Após remover posição 2: ";
    lista.print(); // [10, 15, 30]

    ListSeq listaOrdenada(3);
    listaOrdenada.addSorted(50);
    listaOrdenada.addSorted(10);
    listaOrdenada.addSorted(30);
    cout << "Teste 10: Lista ordenada: ";
    listaOrdenada.print(); // [10, 30, 50]

    lista.destroy();
    cout << "Teste 11: Lista destruída. Vazia? " << lista.isEmpty() << " (1)\n";

    return 0;
}