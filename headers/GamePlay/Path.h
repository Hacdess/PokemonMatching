#include "../items.h"

struct Node {
    float x, y;
    Node* next;
    Node (const float& X, const float& Y) {
        x = X;
        y = Y;
        next = NULL;
    }
};

void addHead (Node*& path, const float& x, const float& y);
void printNode(const Node*& path);
void removeAll (Node*& path);