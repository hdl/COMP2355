#include "MyString.h"
#include <iostream>

int main(int argc, const char * argv[])
{
    MyString *p = new MyString();
    MyString &s=*p;
    std::cout << "Empty: '" << s.cString() << "'\n";
    s = "hello";
    std::cout << "After operator=: '" << s.cString() << "'\n";
    {
        MyString t(s);
        std::cout << "After copy: '" << t.cString() << "'\n";
        s = t;
    }
    MyString m(" world");
    std::cout << "After constructor: '" << m.cString() << "'\n";
    m = s;
    std::cout << "After operator=: '" << m.cString() << "'\n";
    m = m;
    std::cout << "After operator=: '" << m.cString() << "'\n";
    delete p;
    return 0;
}
