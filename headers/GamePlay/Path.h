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

void addPath (Node*& path, const float& x, const float& y);
void printNode(Node* path);
void removePath (Node*& path);