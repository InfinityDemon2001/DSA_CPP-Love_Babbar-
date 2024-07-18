#include <iostream>
using namespace std;

class Human {
    public:
       int height;
       int weight;
       int age;

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

class Male: public Human {
    public:
       string color;

       void sleep() {
        cout << "Male Sleeping" << endl;
       }
};

int main() {
    Male object1;
    cout << object1.age << endl;
    cout << object1.weight << endl;
    cout << object1.height << endl;

    cout << object1.color << endl;

    object1.setWeight(65);
    object1.setHeight(165);
    cout << object1.weight << endl;
    cout << object1.height << endl;
    object1.sleep();

    return 0;
}