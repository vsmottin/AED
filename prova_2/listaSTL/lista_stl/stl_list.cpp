#include "stl_list.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

vector<int> List::vet_to_vector(int* v, int n){
    vector<int> vectorNovo;

    for (size_t i = 0; i < n; i++){
        vectorNovo.push_back(v[i]);
    }

    return vectorNovo;
}

list<int> List::vet_to_flist(int* v, int n){
    list<int> listaNova;

    for (size_t i = 0; i < n; i++){
        listaNova.push_back(v[i]);
    }

    return listaNova;
}

stack<int> List::vet_to_stack(int* v, int n){
    stack<int> stackNova;

    for (size_t i = 0; i < n; i++){
        stackNova.push(v[i]);
    }

    return stackNova;
}

vector<int> List::list_concat(list<int>& list1, list<int>& list2){
    vector<int> vectorNovo;

    for (auto it = list1.begin(); it != list1.end(); it++){
        vectorNovo.push_back(*it);
    }

    for (auto it = list2.begin(); it != list2.end(); it++){
        vectorNovo.push_back(*it);
    }
    
    return vectorNovo;
}

bool List::check_brackets(string expression){
    stack<char> brackets;
    bool flag = false;

    for (size_t i = 0; i < expression.length(); i++){
        if(expression[i] == '(' || expression[i] == '[' || expression[i] == '{'){
            brackets.push(expression[i]);
            flag = true;
        }

        if(expression[i] == ')'){
            if(brackets.top() == '('){
                brackets.pop();
            } else{
                return false;
            }
        }


        if(expression[i] == ']'){
            if(brackets.top() == ']'){
                brackets.pop();
            } else{
                return false;
            }
        }


        if(expression[i] == '}'){
            if(brackets.top() == '}'){
                brackets.pop();
            } else{
                return false;
            }
        }

    }

    return (flag && brackets.empty());
}

vector<string> List::vectorize_expression(string expression){
    vector<string> v;
    string aux;

    for (size_t i = 0; i < expression.length(); i++){
        
        if(expression[i] == ' '){
            v.push_back(aux);
            aux.clear();
        } else{
            aux += expression[i];
        }
    }

    if (!aux.empty()){
        v.push_back(aux);
    }

    return v;
}

#include <stack>
#include <vector>
#include <string>
#include <cctype>
#include <stdexcept>

using namespace std;

vector<string> split_expression(const string& expression) {
    vector<string> tokens;
    string current;
    
    for (char c : expression) {
        if (c == ' ') {
            if (!current.empty()) {
                tokens.push_back(current);
                current.clear();
            }
        } else {
            current += c;
        }
    }
    
    if (!current.empty()) {
        tokens.push_back(current);
    }
    
    return tokens;
}

float calc_posfix(string expression) {
    stack<float> nums;
    vector<string> tokens = split_expression(expression);
    
    for (const string& token : tokens) {
        if (isdigit(token[0])) {
            nums.push(stof(token));
        } else {
            if (nums.size() < 2) {
                throw runtime_error("Expressão inválida");
            }
            
            float b = nums.top(); nums.pop();
            float a = nums.top(); nums.pop();
            
            switch (token[0]) {
                case '+': nums.push(a + b); break;
                case '-': nums.push(a - b); break;
                case '*': nums.push(a * b); break;
                case '/': 
                    if (b == 0) throw runtime_error("Divisão por zero");
                    nums.push(a / b); 
                    break;
                default: throw runtime_error("Operador inválido");
            }
        }
    }
    
    if (nums.size() != 1) {
        throw runtime_error("Expressão inválida");
    }
    
    return nums.top();
}

bool List::check_posfix(string expression){

}

float List::calc_infix(string expression){

}

string List::posfix_to_infix(string expression){

}