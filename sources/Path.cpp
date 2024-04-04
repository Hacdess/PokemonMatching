#include "../headers/GamePlay/Path.h"

void addHead (Node*& path, const float& x, const float& y) {
    Node* node = new Node (x, y);
    node -> next = path;
    path = node;
}

void printNode (const Node*& path) {
    while (path) {
        cout << path -> x << " - " << path -> y << endl;
        path = path -> next;
    }
}

void removeAll (Node*& path) {
    if (! path)
        return;
    Node* cur;
    while (path) {
        cur = path;
        path = path -> next;
        delete cur;
    }
}