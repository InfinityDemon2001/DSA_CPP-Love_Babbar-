#include <iostream>
using namespace std;

class A {
    public:
    void sayHello() {
        cout << "Hello Allen" << endl;
    }
    int sayHello(char name) {
        cout << "Hello Allen" << endl;
        return 1;
    }
    void sayHello(string name) {
        cout << "Hello " << name << endl;
    }
};

int main () {
    A obj;
    obj.sayHello();
    obj.sayHello('A');
    obj.sayHello("Allen");

    return 0;
}