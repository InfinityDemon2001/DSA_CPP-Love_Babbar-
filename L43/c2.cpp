#include <iostream>
using namespace std;

class Human {
    int height;
    protected:
       int age;
    public:
       int weight;

       int getAge() {
        return this->age;
       }

       void setWeight(int w) {
         this->weight = w;
       }

       void setHeight(int h) {
         this->height = h;
       }
};

class Male1: public Human {
    public:
       string color;

       void sleep() {
            cout << "Male Sleeping" << endl;
       }
};

class Male2: protected Human {
    public:
       string color;

       void sleep() {
            cout << "Male Sleeping" << endl;
       }
       
       int getHeight() {
           return this->height;
       }
};

class Male3: private Human {
    public:
       string color;

       void sleep() {
            cout << "Male Sleeping" << endl;
       }
       
       int getHeight() {
           return this->height;
       }
};

int main() {
    Male1 m1;
    cout << m1.height << endl;
    
    Male2 m2;
    cout << m2.getHeight() << endl;

    Male3 m3;
    cout << m3.getHeight() << endl;
    return 0;
}