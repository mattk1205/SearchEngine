//
// Created by mattw on 11/13/2022.
//
#include <iostream>
#include "AVLMap.h"
#include "HashMap.h"

void fun1(const char *string);

void fun(const char *string);

using namespace std;

// Test program
int main() {
    AVLMap<string, double> map1;
    string string1 = "Banana";
    double d = 2.7;
    string string2 = "Apple";
    double dd = 1.5;
    string string3 = "Pineapple";
    double ddd = 0.5;
    string string4 = "Guava";
    double dddd = 5.5;
    map1.insert(string1, d);
    map1.insert(string1, d);
    map1.insert(string2, dd);
    map1.insert(string3,ddd);
    cout << map1["Banana"];
    cout << endl;
    map1.print_inOrder();
    cout << endl;
    map1.clear();
    map1.clear();
    if(map1.isEmpty())
        cout << "Empty" << "        " << "Size: " << map1.getSize() << endl;
    map1.insert(string1, d);
    map1.insert(string2, dd);
    map1.insert(string3,ddd);
    cout << "Inserting:" << endl;
    cout << "Size: " << map1.getSize() << endl;
    AVLMap<string, double> map2;
    map2 = map1;
    AVLMap<string, double> map3(map2);
    map1.print_inOrder();
    cout << endl;
    map2.print_inOrder();
    cout << endl;
    map3.print_inOrder();
    cout << endl;
    map2.insert(string4, dddd);
    map1.print_inOrder();
    cout << endl;
    map2.print_inOrder();
    cout << endl;
    map3.print_inOrder();
    cout << endl;

    if(map2.containsByKey(string4))
        cout << string4 << " found" << endl;
    if(map3.containsByVal(ddd))
        cout << ddd << " found" << endl;
    if(!(map3.containsByKey("boo")))
        cout << "boo not found" << endl;
    if(!(map3.containsByVal(999)))
        cout << "999 not found" << endl << endl;

    AVLMap<double, double> map4;
    AVLMap<int, int> map5;
    AVLMap<float, float> map6;
    AVLMap<long, long> map7;
    AVLMap<HashMap<int>, int> mapMap;
    return 0;
}