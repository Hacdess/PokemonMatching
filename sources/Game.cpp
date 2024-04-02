#include "../headers/GamePlay/Game.h"

void GameBoard::suffle() {

}

Texture2D* GameScene::readImage(const unsigned short int& quantity)
{
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

void GameScene::draw() {
    
}