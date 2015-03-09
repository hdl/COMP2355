#include "items.h"

Items::Items(){
    counter=0;
    item_array = new item_t[MAX];
}

bool Items::precondition(){
    return !(counter==0);
}

void Items::add(item_t &new_item){
    cout<< "add item " << new_item.name <<endl;
    item_array[counter]=new_item;
    counter++;
}

void Items::postcondition(int i){
    item_t temp=item_array[i];
    for(int j=i; j>=1; j--){
        item_array[j]=item_array[j-1];
    }
    item_array[0]=temp;
    return ;
}

void Items::print_all(){
    for(int i=0; i<counter; i++){
        cout<< "item_array[" <<i<<"] is: "<<item_array[i].name << endl;
    }
}
