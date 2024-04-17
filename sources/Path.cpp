#include "../headers/GamePlay/Path.h"

void addPath (Node*& path, const float& x, const float& y) {
    Node* node = new Node (x, y);
    node -> next = path;
    path = node;
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