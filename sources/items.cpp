#include "../headers/items.h"

void DeallocateButtons1D (TextBox* buttons, const short& size) {
    unsigned short int i;
    for (i = 0; i < size; i ++)
        delete[] buttons[i].content;
    delete[] buttons;
}

void DeallocateButtons2D (TextBox** buttons, const short & row, const short& col) {
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
        // Được thì bạn cứ để nó chạy hết 1 ngày đi, bạn sẽ thành người hùng của trò chơi này
        hour = hour - short (hour / 24) * hour;
    }
}