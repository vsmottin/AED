#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

class List {
    public:
    List();
    
    vector<int> vet_to_vector(int* v, int n);

    list<int> vet_to_flist(int* v, int n);

    stack<int> vet_to_stack(int* v, int n);

    vector<int> list_concat(list<int>& list1, list<int>& list2);

    bool check_brackets(string expression);

    vector<string> vectorize_expression(string expression);

    float calc_posfix(string expression);

    bool check_posfix(string expression);

    float calc_infix(string expression);

    string posfix_to_infix(string expression);
    
};