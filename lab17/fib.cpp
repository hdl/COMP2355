#include <vector>
#include <unordered_map>
#include <cstdint>
#include <iostream>

using namespace std;

int main(){
    std::vector<uint64_t> fib(94, 0);
    fib[0]=0;
    fib[1]=1;
    fib[2]=1;

    std::unordered_map<uint64_t, int> fibMap;
    fibMap[1]=2;



    for(int i=3; i<94; i++){
        fib[i]=fib[i-1]+fib[i-2];
        fibMap[fib[i]]=i;
    }

    cout<<"Fibonacci numbers in order:"<<endl;
    int i=0;
    for(vector<uint64_t>::iterator it=fib.begin(); it!=fib.end(); it++){
        cout<< i++ << " "<< *it <<endl;
    }

    cout<<"Fibonacci numbers and indices, unordered:"<<endl;
    for(unordered_map<uint64_t, int>::iterator it=fibMap.begin(); it!=fibMap.end(); it++){
        cout << it->second << " " << it->first <<endl;
    }


    cout<<"Testing Fibonacci numbers from 1 to 15:"<<endl;
    for(i=1; i<=15; i++){
        if(fibMap.find(i)!=fibMap.end()){
            cout << i << " " << fibMap[i]<<endl;
        }else{
            cout << i << " no"<<endl;
        }
    }
    return 0;
}
