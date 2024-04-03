#include "../headers/GamePlay/Game.h"

void swapPokemon (Pokemon* pokemon1, Pokemon* pokemon2) {
    Pokemon* temp = pokemon1;
    pokemon1 = pokemon2;
    pokemon2 = temp;
}

Texture2D* GameBoard::readImage(const unsigned short int& quantity) {
    //Location to img
    string path = "resources/img/pokemon/pokemon";
    Texture2D *resTexture = new Texture2D[quantity];

    // Load image
    unsigned short int i;
    for (i = 0; i < quantity; i++)
    {
        path = path + to_string(i) + ".png"; //picname

        Image img = LoadImage(path.c_str());// load image
        resTexture[i] = LoadTextureFromImage(img);// load texture from image
        UnloadImage(img);// delete image after load
    }
    return resTexture;
}

void GameBoard::suffle1D(Pokemon* Po1D, const unsigned short& size) {
    srand(time(0));
    unsigned short i, j;
    for (i = 0; i < size; i ++) {
        j = rand() % size;
        swapPokemon (&Po1D[i], &Po1D[j]);
    }
}

void GameBoard::createTable(const unsigned short& row, const unsigned short& col, Texture2D* texture, const unsigned short& quantity) {
    srand(time(0));
    unsigned short int randNum, i, j, size = (row - 2) * (col - 2), pos = 0;
    float   sizePokemon = float(WinWdith) / (2 * col),
            padding = sizePokemon / 10,
            startX = float(WinWdith) / 15,
            startY = startX;

    Pokemon* temp = new Pokemon[size];
    for (i = 0; i < size; i ++) {
        randNum = rand() % quantity;
        //2 contigous pokemons are similar
        temp[i].ID = randNum;
        temp[i].img = texture[randNum];
        temp[i].size = sizePokemon;
        temp[i++].cover = WHITE;
        temp[i].ID = randNum;
        temp[i].img = texture[randNum];
        temp[i].size = sizePokemon;
        temp[i].cover = WHITE;
    }

    suffle1D(temp, size);

    pokemons = new Pokemon*[row];
    for (i = 0; i < row; i ++) {
        pokemons[i] = new Pokemon[col];

        for (j = 0; j < col; j ++) {
            if (i == 0 || j == 0 || i == row - 1 || j == col - 1) {
                pokemons[i][j].size = sizePokemon;
                pokemons[i][j].cover = SlightGrayTrans;        
            }
            else {
                pokemons[i][j].ID = temp[pos].ID;
                pokemons[i][j].img = temp[pos].img;
                pokemons[i][j].cover = temp[pos++].cover;
            }
            
            pokemons[i][j].size = sizePokemon;
            pokemons[i][j].pos = {startX, startY};

            if (j != col - 1)
                startX = startX + sizePokemon + padding;
            else
                startX = 0;
        }
        startY = startY + sizePokemon + padding;
    }

    delete[] temp;
}

void GameBoard::draw() {
    unsigned short i, j;
    for (i = 0; i < row; i ++)
        for (j = 0; j < col; j ++) {
            if (pokemons[i][j].shown) {
                DrawTexturePro(pokemons[i][j].img, {0, 0, float(pokemons[i][j].img.width), float(pokemons[i][j].img.height)}, {0, 0, pokemons[i][j].size, pokemons[i][j].size}, {0, 0}, 0, pokemons[i][j].cover);
            }
        }
}

void GameScene::setup() {
    //Get Background
    Image img = LoadImage("resources/img/background/background.png");
    background = LoadTextureFromImage(img);
    UnloadImage(img);

    //Get Gameboard hidden background
    img = LoadImage("resources/img/logo.png");
    gameboard.HiddenBackground = LoadTextureFromImage(img);
    UnloadImage(img);

    //Get img of pokemos
    gameboard.PokemonsImg = gameboard.readImage(60);

    //Get pokemons
    gameboard.createTable(6, 8, gameboard.PokemonsImg, 60);

    //Border outline of Gameboard
    gameboard.BorderColor = BROWN;
    gameboard.border = {gameboard.pokemons[0][0].pos.x, gameboard.pokemons[0][0].pos.y, gameboard.pokemons[0][0].size * 8, gameboard.pokemons[0][0].size * 6};
}

Scene GameScene::draw(GameStatus& action, Scene scene, Level& level, LevelScene LEVEL) {
    if (action == ChooseLevel) {
        level = LEVEL.draw(action, action);
        if (level == BACK)
            return MENU;
    }

    else if (action == LoadGame) {
        setup();
        action = PlayGame;
    }

    else if (action == End)
        return MENU;

    if (action == PlayGame) {
        //Draw main background
        DrawTexturePro (background, {0, 0, float(background.width), float(background.height)}, {0, 0, float(WinWdith), float(WinHeight)}, {0, 0}, 0, WHITE);
        //Draw hidden background
        DrawTexturePro (gameboard.HiddenBackground, {0, 0, float(gameboard.HiddenBackground.width), float(gameboard.HiddenBackground.height)}, {0, 0, float(WinWdith), float(WinHeight)}, {0, 0}, 0, WHITE);
        //Draw Pokemons
        gameboard.draw();

    }


}