#include "../Moving.h"
#include "../GamePlay/Music.h"
struct Page {
    TextBox title;
    TextBox text;
    TextBox message;
};

struct GuideScene {
    bool set = 0;
    float FontSize = float (WinHeight) / 20, TitleFontSize = float (WinHeight) / 15;
    
    Texture2D background;

    Page page[3];
    short selector;
    void setup();
    Scene draw(gameMusic& musicAndSound);
};