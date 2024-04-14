#include "../headers/GamePlay/Path.h"

void addPath (Node*& path, const float& x, const float& y) {
    Node* node = new Node (x, y);
    node -> next = path;
    path = node;
}

void printNode (Node* path) {
    if (! path)
        return;
    
    while (path) {
        cout << '(' << path -> x << " - " << path -> y << ')' << " ; ";
        path = path -> next;
    }
    cout << endl;
}

void removeHead(Node*& path) {
    if (!path)
        return;
    Node* cur = path;
    path = path -> next;
    delete cur;
}

void removePath (Node*& path) {
    if (! path)
        return;

    Node* cur;
    while (path) {
        cur = path;
        path = path -> next;
        delete cur;
    }
}