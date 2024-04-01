#include "../Moving.h"

struct LevelScene {
    unsigned int count;
    Color background;
    TextBox TextBoxs[5];
    Selector1D selector = {1};

    void setup();
    Level draw();
};