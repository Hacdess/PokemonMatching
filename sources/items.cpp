#include "../headers/items.h"

void DeallocateButtons1D (TextBox* buttons, const int& size) {
    int i;
    for (i = 0; i < size; i ++)
        delete[] buttons[i].content;
    delete[] buttons;
}

void DeallocateButtons2D (TextBox** buttons, const int& row, const int& col) {
    int i, j;
    for (i = 0; i < row; i ++) {
        for (j = 0; j < col; j ++)
            delete[] buttons[i][j].content;
        delete[] buttons[i];
    }
    delete[] buttons;
}