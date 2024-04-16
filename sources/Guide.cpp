#include "../headers/MenuScreen/Guide.h"

void GuideScene::setup() {
    set = 1;

    Image img = LoadImage ("resources/img/page.png");
    background = LoadTextureFromImage (img);
    UnloadImage(img);

    addText (page[0].title.content, "Introduction To Our Game");
    addText (page[1].title.content, "GameMode And Level");
    addText (page[2].title.content, "How To Play");

    addText (page[0].text.content, "Pokemon Matching is a small\n\n\n\nproject for the subject\n\n\n\nAdvance Programming techniques\n\n\n\nand practises of HCMUS.\n\n\n\n\n\n- This game was created\n\n\n\nby Le Trung Kien\n\n\n\nand Nguyen Huu Anh Tri.");
    addText (page[1].text.content, "- There are 2 gamemodes: Single\n\n\n\nand Dual.\n\n\n\n- Furthermore, there are 3 levels\n\n\n\nare waiting for you to compete,\n\n\n\nwhich are: Easy, Medium and Hard.");
    addText (page[2].text.content, "- Player 1:\n\n\n\n+ Use the Left, Right, Up, Down\n\n\n\nkey for moving.\n\n\n\n+ Use Enter key for selecting.\n\n\n\n\n\n\n- If in Dual gamemode: Player 2:\n\n\n\n+ Use the S, Z, X, C keys for\n\n\n\nmoving.\n\n\n\n+ Use Space key for selecting.");

    short i;
    for (i = 0; i < 3; i ++) {
        page[i].title.FontSize = TitleFontSize;
        page[i].title.FontColor = {243, 132, 194, 255};
        page[i].title.ContentLength = MeasureText (page[i].title.content, page[i].title.FontSize);
        page[i].title.pos = {
            (float(WinWdith) - page[i].title.ContentLength) / 2,
            float(WinHeight) / 20
        };

        page[i].text.FontSize = FontSize;
        page[i].text.FontColor = PURPLE;
        page[i].text.ContentLength = MeasureText (page[i].text.content, page[i].text.FontSize);
        page[i].text.pos = {
            (float(WinWdith) / 2 - page[i].text.ContentLength) / 2,
            page[i].title.pos.y + page[i].title.FontSize * 2
        };
        page[i].text.border = {0, page[i].title.pos.y + page[i].title.FontSize * 1.5f, float(WinWdith) / 2, float(WinHeight) * 2 / 3};
        page[i].text.BorderColor = BlackTrans;

        addText (page[i].message.content, "Press Enter to go back");
        page[i].message.FontSize = FontSize;
        page[i].message.FontColor = {243, 132, 194, 255};
        page[i].message.ContentLength = MeasureText (page[i].message.content, page[i].message.FontSize);
        page[i].message.pos = {
            (float(WinWdith) - page[i].message.ContentLength) / 2,
            float(WinHeight) - page[i].message.FontSize * 1.1f
        };
        page[i].message.border = {
            (float(WinWdith) - page[i].message.ContentLength * 1.2f) / 2,
            float(WinHeight) - page[i].message.FontSize * 1.2f,
            page[i].message.ContentLength * 1.2f,
            page[i].message.FontSize * 1.2f
        };

        page[i].message.BorderColor = BlackTrans;
    }

    selector = 0;
}

Scene GuideScene::draw(gameMusic& musicAndSound) {
    //Draw the background
    DrawTexturePro (background, {0, 0, float(background.width), float(background.height)}, {0, 0, float(WinWdith), float(WinHeight)}, {0, 0}, 0.0f, WHITE);
    //Movement dealing
    moveSelector1D (selector, 0, 2, musicAndSound);
    //Write title
    DrawText (page[selector].title.content, page[selector].title.pos.x, page[selector].title.pos.y, page[selector].title.FontSize, page[selector].title.FontColor);
    //Write content
    DrawRectangleRec (page[selector].text.border, page[selector].text.BorderColor);
    DrawText (page[selector].text.content, page[selector].text.pos.x, page[selector].text.pos.y, page[selector].text.FontSize, page[selector].text.FontColor);
    //Write message
    DrawRectangleRec (page[selector].message.border, page[selector].message.BorderColor);
    DrawText (page[selector].message.content, page[selector].message.pos.x, page[selector].message.pos.y, page[selector].message.FontSize, page[selector].message.FontColor);

    if (IsKeyPressed(KEY_ENTER)) {
        PlaySound(musicAndSound.pressButton);
        short i;
        for (i = 0; i < 3; i ++) {
            delete[] page[i].title.content;
            delete[] page[i].text.content;
            delete[] page[i].message.content;
        }

        set = 0;
        return MENU;
    }

    return GUIDE;
}