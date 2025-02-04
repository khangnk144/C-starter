/*
Given an array = [2,5,1,2,3,5,1,2,4], it should return 2;
Given an array = [1, 2, 1, 4, 5,6,9], it should return 1;
Given an array = [2,3,4,5], it should return undefined
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
/*
This Hash Table implementation is purely for me to understand how it works under the hood.
In C++, you can use unordered_map as a hash table,
which enables fast retrieval of key-value pairs
*/
class HashTable {
private:
    vector<vector<pair<string, int>>> data;
    int _hash(string key) {
        int hash = 0;
        for (auto i = 0; i < key.length(); i++) {
            hash = (hash + key[i] * i) % data.size();
        }
        return hash;
    }
public:
    HashTable(int size) : data(size) {}
    void set(string key, int value) {
        int address = _hash(key); 
        if (data[address].empty()) {
            data[address] = vector<pair<string, int>>();
        }
        data[address].push_back({ key,value });
    }
    int get(string key) {
        int address = _hash(key);
        auto currentBucket = data[address];
        if (!currentBucket.empty()) {
            for (auto pair : currentBucket) {
                if (pair.first == key)
                    return pair.second;
            }
        }
        return -1;
    }
    vector<string> keys() {
        vector<string> keysArray;
        for (auto bucket : data) {
            for (auto pair : bucket) {
                keysArray.push_back(pair.first);
            }
        }
        return keysArray;
    }
};

int main()
{
    HashTable hashTable(50); // Create an instance of HashTable with size 50
    int* arr = new int[50];
    int n;
    cout << "Nhap n: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        int count = hashTable.get(to_string(arr[i]));
        if (count == -1) {
            // If that number has not been entered, then set count = 1
            hashTable.set(to_string(arr[i]), 1);
        }
        else { // If it has already been entered, then print that number and exit the program.
            cout << arr[i];
            return 0;
        }
    }

    cout << "undefined";
    return 1;
    //another way
    /*
    unordered_map<int, int> ump;
    int* arr = new int[50];
    int n; cout << "Nhap n: "; cin >> n;
    for (int i = 0; i < n;i++) {
        ump[arr[i]] = 0;
    }
    for (int i = 0; i < n;i++) {
        cin >> arr[i];
        ump[arr[i]]++;
        if (ump[arr[i]] == 2) {
            cout << arr[i];
            return 0;
        }
    }
    cout << "undefined";
    return 1;
    */
}