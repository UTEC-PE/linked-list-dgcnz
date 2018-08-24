#include <iostream>
#include "list.h"

using namespace std;

int main(){

    List<int>* l = new List<int>;

    l->push_back(6);

    l->print();
    l->push_front(3);
    l->print();
    l->push_back(4);
    l->print();

    cout << "get pos 2: "<<l->get(2)<<endl;

    l->pop_front();
    l->print();
    cout << "get pos 0: "<< l->get(0)<<endl;
    l->pop_back();
    l->print();


    return 0;
}



