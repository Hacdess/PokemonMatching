#include "../headers/items.h"

void DeallocateButtons1D (TextBox* buttons, const unsigned short int& size) {
    unsigned short int i;
    for (i = 0; i < size; i ++)
        delete[] buttons[i].content;
    delete[] buttons;
}

void DeallocateButtons2D (TextBox** buttons, const unsigned short int& row, const unsigned short int& col) {
    unsigned short int i, j;
    for (i = 0; i < row; i ++) {
        for (j = 0; j < col; j ++)
            delete[] buttons[i][j].content;
        delete[] buttons[i];
    }
    delete[] buttons;
}

bool isSameColor (const Color& Color1, const Color& Color2) {
    if (Color1.a != Color2.a) return 0;
    if (Color1.r != Color2.r) return 0;
    if (Color1.g != Color2.g) return 0;
    if (Color1.b != Color2.b) return 0;

    return 1;
}