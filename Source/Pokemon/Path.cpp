#include "../headers/Path.h"

//Get Pokemon's coordinates
void addPath (Node*& path, const float& x, const float& y) {
    Node* node = new Node (x, y);
    node -> next = path;
    path = node;
}

//Remove the first Node
void removeHead(Node*& path) {
    if (!path)
        return;
    Node* cur = path;
    path = path -> next;
    delete cur;
}

//Remove the list
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