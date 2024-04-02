#include "../headers/GamePlay/Game.h"

void GameBoard::suffle() {

}

Texture2D* GameBoard::readImage(const unsigned short int& quantity)
{
    //Location to img
    string path = "resources/img/pokemon/pokemon";
    Texture2D *resTexture = new Texture2D[quantity];

    // Load image
    unsigned short int i, j;
    for (i = 0; i < quantity; i++)
    {
        path = path + to_string(i) + ".png"; //picname

        Image img = LoadImage(path.c_str());// load image
        resTexture[i] = LoadTextureFromImage(img);// load texture from image
        UnloadImage(img);// delete image after load
    }
    return resTexture;
}

Pokemon **GameBoard::createTable(const unsigned short& row, const unsigned short& col, Texture2D* texture, const unsigned short& quantity) {
    srand(time(0));
    unsigned short int randNum, i, j, size = (row - 2) * (col - 2), pos = 0;
    float   sizePokemon = float(WinWdith) / (2 * col),
            padding = sizePokemon / 10,
            startX = startY = float(WinWdith) / 15;

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

    Pokemon** arr = new Pokemon*[row];
    for (i = 0; i < row; i ++) {
        arr[i] = new Pokemon[col];

        for (j = 0; j < col; j ++) {
            if (i == 0 || j == 0 || i == row - 1 || j == col - 1) {
                arr[i][j].ID = temp[pos].ID;
                arr[i][j].img = temp[0].img;
                arr[i][j].size = temp[pos].size;
                arr[i][j].cover = SlightGrayTrans;        
            }
            else {
                arr[i][j].ID = temp[pos].ID;
                arr[i][j].img = temp[count].img;
                arr[i][j].size = temp[pos].size;
                arr[i][j].cover = temp[pos++].cover;
            }
        }
    }

    delete[] temp;
    return arr;
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
    gameboard.PokemonsImg = readImage(60);

    unsigned short int i, j;
    gameboard.pokemons = new Pokemon*[6];


    //Border outline of Gameboard
    gameboard.BorderColor = BROWN;
}

void GameScene::draw(GameStatus& action, SceneManager scene) {
    if (action == ChooseLevel) {
        scene.LevelScreen.draw();
        action = LoadGame;
    }

    else if (action == LoadGame) {
        setup();
        action = PlayGame;
    }

    else {

    }
}