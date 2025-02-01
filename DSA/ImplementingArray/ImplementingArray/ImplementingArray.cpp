#include <bits/stdc++.h>
using namespace std;
class MyArray {
    int length;
    int capacity;
    string* data;
public:
    MyArray() {
        length = 0;
        capacity = 2;
        data = new string[capacity];
    }
    ~MyArray() {
        delete[] data;
    }
    string get(int index) {
        if (index < length) {
            return data[index];
        }
        return "";
    }
    int push(string item) {
        if (length == capacity) {
            resize();
        }
        data[length] = item;
        length++;
        return length;
    }
    // pop is used to delete the last element
    string pop() {
        if (length == 0)
            return "";
        string lastItem = data[length - 1];
        length--;
        return lastItem;
    }
    // del is used to delete an element at a specified index
    string del(int index) {
        if (index < length) {
            string delItem = data[index];
            shiftItems(index);
            return delItem;
        }
    }
    void print() {
        for (int i = 0; i < length; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    void shiftItems(int index) {
        for (int i = index; i < length - 1; i++) {
            data[i] = data[i + 1];
        }
        length--;
    }
    void resize() {
        capacity = capacity * 2;
        string* newData = new string[capacity];
        for (int i = 0; i < length; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
};
int main()
{
    MyArray newArray;
    newArray.push("hi");
    newArray.push("you");
    newArray.push("dear");
    newArray.push("!");
    // newArray = {"hi", "you","dear","!"}
    newArray.pop();//delete the last element
    // newArray = {"hi", "you","dear"}
    newArray.del(1);//delete a specified element
    // newArray = {"hi","dear"}
    newArray.print();
    // hi dear
}
