#include <iostream>
#include <vector>

using namespace std;

const int M = 1000000; // kích thước bảng băm

class Node {
public:
    string key;
    Node* next;
    Node(string k) : key(k), next(NULL) {}
};

class HashTable {
private:
    vector<Node*> table;
public:
    HashTable() {
        table.resize(M, NULL);
    }
    int hash(string key) {
        int p = 31; // số nguyên tố để tính giá trị hàm băm
        int hash_value = 0;
        for (int i = 0; i < key.length(); i++) {
            hash_value = (hash_value * 2 + (key[i] - '0')) % M;
        }
        return hash_value;
    }
    void insert(string key) {
        int index = hash(key);
        Node* new_node = new Node(key);
        if (table[index] == NULL) {
            table[index] = new_node;
        }
        else {
            Node* current_node = table[index];
            while (current_node->next != NULL) {
                current_node = current_node->next;
            }
            current_node->next = new_node;
        }
    }
    bool search(string key) {
        int index = hash(key);
        Node* current_node = table[index];
        while (current_node != NULL) {
            if (current_node->key == key) {
                return true;
            }
            current_node = current_node->next;
        }
        return false;
    }
};


