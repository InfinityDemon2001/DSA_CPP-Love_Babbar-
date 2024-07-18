#include <bits/stdc++.h>
using namespace std;

class Queue {
    int *arr;
    int qfront;
    int qrear;
    int size;

    public:
    Queue() {
        size = 100001;
        arr = new int[size];
        qfront = 0;
        qrear = 0;
    }

    //Public Functions of Queue 

    bool isEmpty() {
        if(qfront == qrear) {
            return true;
        }
        return false;
    }

    void enqueue(int data) {
        if(qrear == size) {
            cout << "Queue is full." << endl;
            return;
        }
        else {
            arr[qrear] = data;
            qrear ++;
        }
    }

    int dequeue() {
        if(isEmpty()) {
            return -1;
        }
        else {
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront ++;
            if(isEmpty()) {
                qfront = 0;
                qrear = 0;
            }
            return ans;
        }
    }

    int front() {
        if(isEmpty()) {
            return -1;
        }
        return arr[qfront];
    }
};