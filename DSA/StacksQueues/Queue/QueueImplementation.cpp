#include <iostream>
#include <string>
using namespace std;

struct Node {
    string value;
    Node* next;
    Node(string val) {
        value = val;
        next = nullptr;
    }
};

class Queue {
public:
    Node* first;
    Node* last;
    int length;
    Queue() {
        first = nullptr;
        last = nullptr;
        length = 0;
    }

    // View the front element (the first one added)
    void peek() {
        if (first != nullptr) {
            cout << first->value << endl;
        }
        else {
            cout << "Queue is empty, please add something to the queue :)" << endl;
        }
    }

    void enqueue(string value) {
        Node* newNode = new Node(value);
        if (first == nullptr) {
            first = newNode;
            last = newNode;
        }
        else {
            last->next = newNode;
            last = newNode;
        }
        length++;
    }

    void dequeue() {
        if (length == 0) {
            cout << "Queue is empty, cannot dequeue." << endl;
            return;
        }
        Node* temp = first;
        first = first->next;
        if (first == nullptr) {
            last = nullptr;
        }
        delete temp;
        length--;
    }

    void printQueueList() {
        Node* temp = first;
        while (temp != nullptr) {
            cout << temp->value << endl;
            temp = temp->next;
        }
        cout << "Above is your queue list :))" << endl;
    }
};

int main() {
    Queue test;
    //test.peek();
    test.enqueue("Facebook");
    test.enqueue("Amazon");
    test.enqueue("Google");
    test.enqueue("Tiktok");
    test.printQueueList();
    test.peek(); // Facebook
    test.dequeue();
    test.peek(); // Amazon
    return 0;
}