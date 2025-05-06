#include "stl_list.hpp"

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
        } else{
            aux += expression[i];
        }
    }

    v.push_back(aux);
    return v;
}

float List::calc_posfix(string expression){

}

bool List::check_posfix(string expression){

}

float List::calc_infix(string expression){

}

string List::posfix_to_infix(string expression){

}