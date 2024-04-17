#include "../items.h"

struct Node {
    float x, y;  //Coordinates of the Pokemon
    Node* next;
    Node (const float& X, const float& Y) {
        x = X;
        y = Y;
        next = NULL;
    }
};

void addPath (Node*& path, const float& x, const float& y); //Store coordinates of all Pokemon that are  neccessary for drawing path

void removeHead(Node*& path);   //Remove uneccessary Pokemon on the Linked List for drawing path correctly
void removePath (Node*& path);  //Remove the Linked List when finishing drawing or not finding the correct path