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

class Stack {
public:
    Node* top;
    int length;
    Stack() {
        top = nullptr;
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
        }
        else {
            newNode->next = top;
            top = newNode;
        }
        length++;
    }

    void pop() {
        if (length == 0) {
            cout << "Stack is empty, cannot pop." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        length--;
    }

    void printStackList() {
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->value << endl;
            temp = temp->next;
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