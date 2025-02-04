#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
    // constructor
    Node(int val) {
        value = val;
        next = nullptr;
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
        Node* newNode = new Node(val);// create a new Node
        //newNode->value = val;
        //newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    void insert(int val, int k) {
        Node* newNode = new Node(val);
     /*   newNode->value = val;
        newNode->next = nullptr;*/
        if (k == 0) {
            newNode->next = head;
            head = newNode;
        }
        else {
            Node* temp = head;
            for (int i = 0; i < k - 1 && temp != nullptr; i++) {
                temp = temp->next;
            }
            // temp points to position k-1 so temp->next points to position k
            if (temp != nullptr) {
                newNode->next = temp->next;
                temp->next = newNode;
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
        Node* temp = head;
        for (int i = 0; i < k - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp != nullptr && temp->next != nullptr) {
            Node* nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;
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
        //Node* temp = head;
        head = head->next;
       // delete temp;
        size--;
        if (head == nullptr) {
            tail = nullptr;
        }
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
            Node* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            // The above loop will stop when temp is the second-to-last element because at that point, temp->next = tail;
            delete tail;
            tail = temp;
            tail->next = nullptr;
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
    //10 5 16 7 23 69
    list.insert(17, 2);
    list.printList();
    // 10 5 17 16 7 23 69
    //cout << endl;
    list.delFi();
    cout << "After delete first item: ";
    list.printList();
    // cout << list.getSize();
    cout << "After delete last item: ";
    list.delLi();
    list.printList();
    cout << "After delete 2nd item: ";
    list.deleteItem(2);
    list.printList();
    return 0;
}