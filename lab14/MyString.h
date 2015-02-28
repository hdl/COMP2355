//using namespace std;
#include <cstring>
class MyString {
public:
    MyString();
    MyString(const MyString &);
    MyString(const char *);
    ~MyString();
    MyString &operator=(const MyString &);
    size_t length() const;
    const char *cString() const;
private:
    char *string;
};

MyString::MyString(){
    string = new char[1];
    string[0]='\0';
}

MyString::MyString(const MyString &init){
    int len = init.length();
    if(len == 0)
        string = NULL;
    else{
        string = new char[len+1];
        for(int i =0; i<len; i++)
            string[i] = init.cString()[i];
        string[len]='\0';
    }
}

MyString::MyString(const char* init){
    int len=0;
    while(init[len]!='\0')
        len++;

    this->string = new char[len+1];
    for(int i=0; i<len; i++){
        this->string[i] = init[i];
    }
    string[len]='\0';
}

MyString::~MyString(){
    if(this->length()>0)
        delete [] string;
}

MyString& MyString::operator=(const MyString &init){
    if(this->string!=NULL)
        delete [] this->string;
    int len = init.length();
    this->string = new char[len+1];
    for(int i=0; i<len; i++){
        this->string[i]=init.cString()[i];
    }
    string[len]='\0';
    return *this;
}

size_t MyString::length() const{
    int len=0;
    while(string[len]!='\0'){
        len++;
    }
    return len;
}
const char * MyString::cString() const{
    return string;
}

