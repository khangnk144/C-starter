#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node* prev;
    // constructor
    Node(int val) {
        value = val;
        next = nullptr;
        prev = nullptr;
    }
};

class linkedList {
public:
    Node* head;
    Node* tail;
    int size;

    linkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void append(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    Node* movePointer(int k) {
        Node* temp = head;
        for (int i = 0; i < k && temp != nullptr; i++) {
            temp = temp->next;
        }
        return temp;
    }

    void insert(int val, int k) {
        Node* newNode = new Node(val);
        if (k == 0) {
            if (head != nullptr) {
                head->prev = newNode;
            }
            newNode->next = head;
            head = newNode;
            if (tail == nullptr) {
                tail = newNode;
            }
        }
        else {
            Node* temp = movePointer(k - 1);
            if (temp != nullptr) {
                newNode->prev = temp;
                newNode->next = temp->next;
                temp->next->prev = newNode;
                temp->next = newNode;
                if (newNode->next == nullptr) {
                    tail = newNode;
                }
            }
            else {
                delete newNode;
            }
        }
        size++;
    }

    // delete item at position k in the list
    void deleteItem(int k) {
        if (k < 0 || k >= size) {
            cout << "Error: Position out of range" << endl;
            return;
        }
        if (k == 0) {
            delFi();
            return;
        }
        Node* temp = movePointer(k - 1);
        if (temp != nullptr && temp->next != nullptr) {
            Node* nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;
            if (nodeToDelete->next != nullptr) {
                nodeToDelete->next->prev = temp;
            }
            if (nodeToDelete == tail) {
                tail = temp;
            }
            delete nodeToDelete;
            size--;
        }
    }

    // delete first item of the list
    void delFi() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
        delete temp;
        size--;
    }

    // delete last item of the list
    void delLi() {
        if (head == nullptr) {
            return;
        }
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else {
            Node* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
        size--;
    }

    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void printRevList() {
        Node* temp = tail;
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
    int getSize() {
        return size;
    }
};

int main() {
    linkedList list;
    list.append(10);
    list.append(5);
    list.append(16);
    list.append(7);
    list.append(23);
    list.append(69);
    // 10 5 16 7 23 69
    list.insert(17, 2);
    list.printList();
    // 10 5 17 16 7 23 69
    list.printRevList();
    // 69 23 7 16 17 5 10
    list.delFi();
    cout << "After delete first item: ";
    list.printList();
    // 5 17 16 7 23 69

    list.delLi();
    cout << "After delete last item: ";
    list.printList();
    // 5 17 16 7 23

    list.deleteItem(2);
    cout << "After delete 2nd item: ";
    list.printList();
    // 5 17 7 23

    return 0;
}