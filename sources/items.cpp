#include "../headers/items.h"

void DeallocateTextbox1D (TextBox* textbox, const short& size) {
    unsigned short int i;
    for (i = 0; i < size; i ++)
        delete[] textbox[i].content;
    delete[] textbox;
}

void DeallocateTextbox2D (TextBox** textbox, const short & row, const short& col) {
    unsigned short int i, j;
    for (i = 0; i < row; i ++) {
        for (j = 0; j < col; j ++)
            delete[] textbox[i][j].content;
        delete[] textbox[i];
    }
    delete[] textbox;
}

bool isSameColor (const Color& Color1, const Color& Color2) {
    if (Color1.a != Color2.a) return 0;
    if (Color1.r != Color2.r) return 0;
    if (Color1.g != Color2.g) return 0;
    if (Color1.b != Color2.b) return 0;

    return 1;
}

void Time::formatTime() {
    if (sec > 59) {
        min = min + short (sec / 60);
        sec = sec - short (sec / 60) * sec;
    }

    if (min > 59) {
        hour = hour + short (min / 60);
        min = min - short (min / 60) * min;
    }

    if (hour > 23) {
        // You can let it run for 24+ hour then you can be the god of this game
        hour = hour - short (hour / 24) * hour;
    }
}