#include <iostream>
#include <list>
#include <string>

#define MAX 100
using namespace std;

class item_t{
public:
    string name;
    item_t(){
        name="";
    }
    item_t(string temp){
       name=temp;
    }
};

class Items{
private:
    item_t* item_array;
    int counter;
public:
    Items();
    bool precondition();
    void postcondition(int i);
    void add(item_t & new_item);
    void print_all();
};


