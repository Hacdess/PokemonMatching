#include "items.h"

//Format again the time
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

//Deallocate the dynamic memory
void DeallocateTextbox1D (TextBox* textbox, const short& size) {
    short i;
    for (i = 0; i < size; i ++)
        delete[] textbox[i].content;
}

//Checking two colors whether they are the same
bool isSameColor (const Color& Color1, const Color& Color2) {
    if (Color1.a != Color2.a) return 0;
    if (Color1.r != Color2.r) return 0;
    if (Color1.g != Color2.g) return 0;
    if (Color1.b != Color2.b) return 0;

    return 1;
}

//Add text to the dynamic char array
void addText (char*& dest, const char* content) {
    dest = new char[strlen(content) + 1];
    strcpy (dest, content);
}

//Update dest text with new content
void updateText (char*& dest, const char* content) {
    delete[] dest;
    addText (dest, content);
    dest = new char[strlen(content) + 1];
}

//Convert string to dynamic char array
char* StoA (const string& s) {
    short len = s.length();
    char* arr = new char[len + 1];
    short i;
    for (i = 0; i < len; i ++)
        arr[i] = s[i];
    arr[len] = '\0';
    return arr;
}

//Convert time to string
string TimeToString (Time time) {
    time.formatTime();
    string res = "";

    if (time.hour < 10)
        res += '0';
    res = res + to_string(time.hour) + ':';

    if (time.min < 10)
        res += '0';
    res = res + to_string(time.min) + ':';

    if (time.sec < 10)
        res += '0';
    res += to_string(time.sec);

    return res;
}

//Compare two times for ranking
short compareTime (const Time& time1, const Time& time2) {
    if (time1.hour < time2.hour)
        return -1;
    if (time1.hour > time2.hour)
        return 1;

    if (time1.min < time2.min)
        return -1;
    if (time1.min > time2.min)
        return 1;

    if (time1.sec < time2.sec)
        return -1;
    if (time1.sec > time2.sec)
        return 1;
    
    return 0;
}
