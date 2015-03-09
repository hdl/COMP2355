#include <iostream>
#include <list>
#include <string>
#include "items.h"

int main(){
    Items items;
    item_t item0("item0");
    item_t item1("item1");
    item_t item2("item2");
    item_t item3("item3");
    item_t item4("item4");

    items.add(item0);
    items.add(item1);
    items.add(item2);
    items.add(item3);
    items.add(item4);


    cout << "check precondition:"<<endl;
    cout << "precondition return " << items.precondition() <<", which means is not empty"<<endl;

    cout << "before postcondition:"<<endl;
    items.print_all();
    cout << "run postcondition fucntion, move 4 to front"<<endl;
    items.postcondition(4);
    cout << "after postcondition:"<<endl;
    items.print_all();
}
