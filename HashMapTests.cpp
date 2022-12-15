//
// Created by mattw on 11/28/2022.
//

#include <iostream>
#include "HashMap.h"

using namespace std;

int main(){
    HashMap<string> map1;
    bool found1 = map1.insert("alpha");
    if(found1)
        cout << "inserted" <<endl;
    else
        cout << "not inserted" <<endl;
    bool found2 = map1.contains("alpha");
    if(found2)
        cout << "found" <<endl;
    else
        cout << "not found" <<endl;
    map1.print();
    map1.makeEmpty();
    cout << "Emptied." << endl;
    bool found3 = map1.contains("alpha");
    if(found3)
        cout << "found" <<endl;
    else
        cout << "not found" <<endl;
    HashMap<size_t> numbers;
    for(size_t i = 0; i < 1001; i+=5)
        numbers.insert(i);
    numbers.print();
}