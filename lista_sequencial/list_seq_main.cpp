#include <iostream>
#include <algorithm>
#include "list_seq.hpp"

using namespace std;

int main(){
    ListSeq ls(5);
    ls.add(12);
    ls.add(2);
    ls.add(5);
    ls.add(7);
    ls.add(9);

    if (ls.isFull()) ls.resize();
    
    ls.add(20);

    ls.print();

    return 0;
}