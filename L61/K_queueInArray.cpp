#include <bits/stdc++.h>
using namespace std;

class kQueue {
    int k;
    int n;
    int *front;
    int *rear;
    int *arr;
    int freespot;
    int *next;

    public:
    kQueue(int n, int k) {
        this -> n = n;
        this -> k = k;
        front = new int[k];
        rear = new int[k];
        for(int i = 0; i < k; i ++) {
            front[i] = -1;
            rear[i] = -1;
        }
        next = new int[n];
        for(int i = 0; i < n; i ++) {
            next[i] = i + 1;
        }
        next [n - 1] = -1;

        arr = new int[n];
        freespot = 0;
    }

    void enqueue(int data, int qn) {
        // Overflow
        if(freespot == -1) {
            cout << "No empty space is present." << endl;
            return;
        }

        // Find first free index
        int index = freespot;

        // Update freespot
        freespot = next[index];

        // Check whether first element
        if(front[qn - 1] == -1) {
            front[qn - 1] = index;
        }
        else {
            // Link new element to the previous element
            next[rear[qn - 1]] = index;
        }

        // Update next
        next[index] = -1;

        // Update rear
        rear[qn - 1] = index;

        // Push element
        arr[index] = data;
    }

    int dequeue(int qn) {
        // Underflow
        if(front[qn - 1] == -1) {
            cout << "Queue underflow" << endl;
            return -1;
        }

        // Find index to pop
        int index = front[qn - 1];

        // Shift front
        front[qn - 1] = next[index];

        // Manage freeslots
        next[index] = freespot;
        freespot = index;
        return arr[index];
    }
};

int main() {
    kQueue q(10, 3);
    q.enqueue(10, 1);
    q.enqueue(15, 1);
    q.enqueue(20, 2);
    q.enqueue(25, 1);

    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;
    
    cout << q.dequeue(1) << endl;

    return 0;
}