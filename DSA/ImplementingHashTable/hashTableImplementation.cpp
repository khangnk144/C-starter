#include <iostream>
#include <vector>
#include <string>
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
        //cout << data.size();
        int hash = 0;
        for (auto i = 0; i < key.length(); i++) {
            hash = (hash + key[i] * i) % data.size();
            // %data.size() to make sure that hash is no bigger than data.size();
        }
        return hash;
    }
public:
    HashTable(int size) : data(size){}
    /*int getHash(string key) {
        return _hash(key);
    }*/
    void set(string key, int value) {
        int address = _hash(key); //enter a key (it's a string) -> receive hash number
        if (data[address].empty()) {
            // if at the address there is no data yet, then create an empty vector to store data
            data[address] = vector<pair<string, int>>();
        }
        data[address].push_back({ key,value });
    }
    // get function is used to get value when we have a key
    int get(string key) {
        int address = _hash(key);
        auto currentBucket = data[address];
        if (!currentBucket.empty()) {
            // if there are some data in currentBucket
            for (auto pair : currentBucket) {
                // pair<string, int>
                if (pair.first == key)
                    return pair.second;          
            }
        }
        return -1;
    }
    // create a vector that will store keys (strings)
    vector<string> keys(){
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
    HashTable a(2);
    //cout << a.getHash("cb");
    a.set("Hello", 50);
    a.set("apple", 54);
    a.set("orange", 2);
    cout << a.get("orange") << endl; //2
    vector<string> keys = a.keys();
    for (auto key : keys) {
        cout << key << " ";
    }
    return 0;
}
