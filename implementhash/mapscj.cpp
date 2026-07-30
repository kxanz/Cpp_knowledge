#include <iostream>
#include <list>
#include <cstring>
#include <ostream>
using namespace std;

//Hashtable to implement 905 jimmy

class HashTable {
    private:
        static const int hashGroups = 10;
        list<pair<int, string>> table[hashGroups];// List 1, index 0, List 2, Index 1

    public:
        bool isEmpty() const;
        int hashFunction(int key);
        void insertItem(int key, string value);
        void removeItem(int key);
        string searchTable(int key);
        void printTable();
};

bool HashTable::isEmpty() const{
    int sum{};
    for (int i{}; i < hashGroups; i++){
        sum += table[i].size();
    }
    if (!sum) {
        return true;
    }
    return false;
}

int HashTable::hashFunction(int key) {
    return key & hashGroups; // key: 905 in return this function will spit out 5;
}

void HashTable::insertItem(int key, string value) {

    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool KeyExists = false;

    for (; bItr != end(cell); bItr++){
        KeyExists = true;
        bItr->second = value;
        cout << "[Warning] Key Exists, Value Replaced" << endl;
        break;
    }

    if (!KeyExists) {
        cell.emplace_back(key,value); 
    }
    return;
}

void HashTable::removeItem(int key) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool KeyExists = false;

    for (; bItr != end(cell); bItr++){
        KeyExists = true;
        bItr = cell.erase(bItr);
        cout << "[INFO] item removed" << endl;
        break;
    }

    if (!KeyExists) {
        cout << "[WANRING] ite not found" << endl;
    }
    return;
}

void HashTable::printTable() {
    for (int i{}; i < hashGroups; i++) {
        if (table[i].size() == 0) continue;

        auto bItr = table[i].begin();

        for (; bItr != table[i].end(); bItr++) {
            cout << "[INFO] key" << bItr->first << "Value: " << bItr->second << endl;
        }
    }
    return;
}

int main (){
    HashTable HT;

    if (HT.isEmpty()) {
        cout << "Correct answer. nice" << endl;
    } else {
        cout << "oh no. We got to chech the code" << endl;
    }

    HT.insertItem(905,"jim"); 
    HT.insertItem(102,"luis"); 
    HT.insertItem(922,"no"); 
    HT.insertItem(922,"Rick"); 

    HT.printTable();

    HT.removeItem(905);
    
    if (HT.isEmpty()) {
        cout << "Correct answer. nice" << endl;
    } else {
        cout << "correct" <<endl;
    }

    return 0;

}