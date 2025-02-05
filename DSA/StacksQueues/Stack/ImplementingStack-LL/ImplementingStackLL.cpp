#include <iostream>
#include <string>
using namespace std;

struct Node {
    string value;
    Node* next;
    Node* prev;
    Node(string val) {
        value = val;
        next = nullptr;
        prev = nullptr;
    }
};

class Stack {
public:
    Node* top;
    Node* bottom;
    int length;
    Stack() {
        top = nullptr;
        bottom = nullptr;
        length = 0;
    }

    // View the top element (the last one added)
    void peek() {
        if (top != nullptr) {
            cout << top->value << endl;
        }
        else {
            cout << "Stack is empty, please add something to the stack :)" << endl;
        }
    }

    void push(string value) {
        Node* newNode = new Node(value);
        if (top == nullptr) {
            top = newNode;
            bottom = newNode;
        }
        else {
            top->next = newNode;
            newNode->prev = top;
            top = newNode;
        }
        length++;
    }

    void pop() {
        if (length == 0) {
            cout << "Stack is empty, cannot pop." << endl;
            return;
        }
        if (length == 1) {
            delete top;
            top = nullptr;
            bottom = nullptr;
        }
        else {
            Node* temp = top;
            top = top->prev;
            top->next = nullptr;
            delete temp;
        }
        length--;
    }

    void printStackList() {
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->value << endl;
            temp = temp->prev;
        }
        cout << "Above is your stack list :))" << endl;
    }
};

int main() {
    Stack test;
    //test.peek();
    test.push("Facebook");
    test.push("Amazon");
    test.push("Google");
    test.push("Tiktok");
    test.printStackList();
    test.peek(); // Tiktok
    test.pop();
    test.peek(); // Google
    return 0;
}