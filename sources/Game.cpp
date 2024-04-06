#include "../headers/GamePlay/Game.h"

void swapPokemon (Pokemon& pokemon1, Pokemon& pokemon2) {
    Pokemon temp = pokemon1;
    pokemon1 = pokemon2;
    pokemon2 = temp;
}

void copyPokemon (Pokemon& des, Pokemon source) {
    des = source;
}

bool isRowEmpty (Pokemon** pokemons, const short& row, const short& col) {
    short i;
    for (i = 0; i < col; i ++)
        if (pokemons[row][i].shown)
            return 0;
    return 1;
}

bool isColEmpty (Pokemon** pokemons, const short& row, const short& col) {
    short i;
    for (i = 0; i < row; i ++)
        if (pokemons[i][col].shown)
            return 0;
    return 1;
}

//I, L, U, Z Matching
bool checkImatching (Pokemon** pokemons, const Selector2D& pokemon1, const Selector2D& pokemon2, Node*& path) {
    if (pokemon1.x == pokemon2.x && pokemon1.y == pokemon2.y)
        return 0;

    addPath (path,
        pokemons[pokemon1.y][pokemon1.x].pos.x + pokemons[pokemon1.y][pokemon1.x].size / 2,
        pokemons[pokemon1.y][pokemon1.x].pos.y + pokemons[pokemon1.y][pokemon1.x].size / 2
    );

    short start;

    //Check horizontally
    if (pokemon1.y == pokemon2.y) {
        //Pokemon1 is on the right of Pokemon2
        if (pokemon1.x > pokemon2.x) {
            for (start = pokemon1.x - 1; start > pokemon2.x; start --) {
                //Path hit the obstacle so return none
                if (pokemons[pokemon1.y][start].shown) {
                    removePath (path);
                    return None;
                }
            }

            //No obstacle between pokemon1 and pokemon2 so add pokemon2 to create Path I
            addPath (path,
                    pokemons[pokemon1.y][start].pos.x + pokemons[pokemon1.y][start].size / 2,
                    pokemons[pokemon1.y][start].pos.y + pokemons[pokemon1.y][start].size / 2
            );            

            return I;
        }

        //Pokemon1 is on the right of Pokemon2
        for (start = pokemon1.x + 1; start < pokemon2.x; start ++) {
            //Path hit the obstacle so return none
            if (pokemons[pokemon1.y][start].shown) {
                removePath (path);
                return None;
            }
        }

        //No obstacle between pokemon1 and pokemon2 so add pokemon2 to create Path I
        addPath (path,
                pokemons[pokemon1.y][start].pos.x + pokemons[pokemon1.y][start].size / 2,
                pokemons[pokemon1.y][start].pos.y + pokemons[pokemon1.y][start].size / 2
        );            

        return I;
    }

    //Check vertically
    if (pokemon1.x == pokemon2.x) {
        //Pokemon1 is below Pokemon2
        if (pokemon1.y > pokemon2.y) {
            for (start = pokemon1.y - 1; start > pokemon2.y; start --) {
                //Path hit the obstacle so return none
                if (pokemons[start][pokemon1.x].shown) {
                    removePath (path);
                    return None;
                }
            }
            
            //No obstacle between pokemon1 and pokemon2 so add pokemon2 to create Path I
            addPath (path,
                    pokemons[start][pokemon1.x].pos.x + pokemons[start][pokemon1.x].size / 2,
                    pokemons[start][pokemon1.x].pos.y + pokemons[start][pokemon1.x].size / 2
            );            

            return I;
        }

        //Pokemon1 is above Pokemon2
        for (start = pokemon1.y + 1; start < pokemon2.y; start ++) {
            //Path hit the obstacle so return none
            if (pokemons[start][pokemon1.x].shown) {
                removePath (path);
                return None;
            }
        }
        
        //No obstacle between pokemon1 and pokemon2 so add pokemon2 to create Path I
        addPath (path,
                pokemons[start][pokemon1.x].pos.x + pokemons[start][pokemon1.x].size / 2,
                pokemons[start][pokemon1.x].pos.y + pokemons[start][pokemon1.x].size / 2
        );            

        return I;
    }

    removePath (path);
    return 0;
}

bool checkLmatching (Pokemon** pokemons, const Selector2D& pokemon1, const Selector2D& pokemon2, Node*& path) {
    Selector2D tempPokemon;

    tempPokemon.x = pokemon1.x;
    tempPokemon.y = pokemon2.y;
    if (!pokemons[tempPokemon.y][tempPokemon.x].shown && 
        checkImatching(pokemons, pokemon1, tempPokemon, path) && 
        checkImatching(pokemons, tempPokemon, pokemon2, path)
    )
        return 1;

    tempPokemon.x = pokemon2.x;
    tempPokemon.y = pokemon1.y;
    if (!pokemons[tempPokemon.y][tempPokemon.x].shown && 
        checkImatching(pokemons, pokemon1, tempPokemon, path) && 
        checkImatching(pokemons, tempPokemon, pokemon2, path) 
    )
        return 1;

    removePath (path);
    return 0;
}

//U, Z matching
MatchingType checkMatching (Pokemon** pokemons, const Selector2D& pokemon1, const Selector2D& pokemon2, const short& row, const short& col, Node*& path) {
    //Check if they are the same
    if (pokemon1.x == pokemon2.x && pokemon1.y == pokemon2.y)
        return None;

    if (checkImatching(pokemons, pokemon1, pokemon2, path))
        return I;

    if (checkLmatching(pokemons, pokemon1, pokemon2, path))
        return L;
            
    Selector2D tempPokemon;

    // Move right
    tempPokemon.x = pokemon1.x;
    tempPokemon.y = pokemon1.y;

    if (tempPokemon.x != col - 1)
        tempPokemon.x++;

    while (!pokemons[tempPokemon.y][tempPokemon.x].shown && tempPokemon.x < col) {
        if (checkImatching(pokemons, pokemon1, tempPokemon, path) &&
            checkLmatching(pokemons, tempPokemon, pokemon2, path)) {
            if (tempPokemon.x > pokemon2.x)
                return U;
            return Z;
        }

        removePath (path);
        tempPokemon.x ++;
        if (tempPokemon.x == col)
            break;
    }

    // Move left
    tempPokemon.x = pokemon1.x;
    tempPokemon.y = pokemon1.y;

    if (tempPokemon.x != 0)
        tempPokemon.x --;

    while (!pokemons[tempPokemon.y][tempPokemon.x].shown && tempPokemon.x >= 0) {
        if (checkImatching(pokemons, pokemon1, tempPokemon, path) &&
            checkLmatching(pokemons, tempPokemon, pokemon2, path)) {
            if (tempPokemon.x < pokemon2.x)
                return U;
            return Z;
        }

        removePath (path);
        tempPokemon.x--;
        if (tempPokemon.x < 0)
            break;
    }

    // Move up
    tempPokemon.x = pokemon1.x;
    tempPokemon.y = pokemon1.y;

    if (tempPokemon.y != 0)
        tempPokemon.y--;

    while (!pokemons[tempPokemon.y][tempPokemon.x].shown && tempPokemon.y >= 0) {
        if (checkImatching(pokemons, pokemon1, tempPokemon, path) &&
            checkLmatching(pokemons, tempPokemon, pokemon2, path)) {
            if (tempPokemon.y < pokemon2.y)
                return U;
            return Z;
        }

        removePath (path);
        tempPokemon.y--;
        if (tempPokemon.y < 0)
            break;
    }

    // Move down
    tempPokemon.x = pokemon1.x;
    tempPokemon.y = pokemon1.y;

    if (tempPokemon.y != row - 1)
        tempPokemon.y++;

    while (!pokemons[tempPokemon.y][tempPokemon.x].shown && tempPokemon.y < row) {
        if (checkImatching(pokemons, pokemon1, tempPokemon, path) &&
            checkLmatching(pokemons, tempPokemon, pokemon2, path)) {
            if (tempPokemon.y > pokemon2.y)
                return U;
            return Z;
        }

        removePath (path);
        tempPokemon.y++;
        if (tempPokemon.y >= row)
            break;
    }

    removePath (path);
    return None;
}

void Pokemon::draw() {
    DrawRectangleRec (border, back);
    DrawTexturePro (img, {0, 0, float(img.width), float(img.height)}, {pos.x, pos.y, size, size}, {0, 0}, 0, cover);
}

void Pokemon::unSeen() {
    shown = 0;
}

//Load images from folder
Texture2D* readImage(const unsigned short int& quantity) {
    //Location to img
    string path = "resources/img/pokemon/pokemon";
    Texture2D *resTexture = new Texture2D[quantity];

    // Load image
    unsigned short int i;
    for (i = 0; i < quantity; i++)
    {
        path = path + to_string(i) + ".png"; //picname

        Image img = LoadImage(path.c_str());// load image
        path = "resources/img/pokemon/pokemon";
        resTexture[i] = LoadTextureFromImage(img);// load texture from image
        UnloadImage(img);// delete image after load
    }
    return resTexture;
}

//Shuffle the 1D pokemon array
void shuffle1D(Pokemon* Po1D, const short& size) {
    srand(time(0));
    unsigned short i, j;
    for (i = 0; i < size; i ++) {
        j = rand() % size;
        swapPokemon (Po1D[i], Po1D[j]);
    }
}

//Shuffle the 2D pokemon array
void shuffle2D(Pokemon** Po2D, const short& row, const short& col) {
    short i, j;
    srand(time(0));

    for (i = 1; i < row - 1; i ++)
        for (j = 1; j < col - 1; j ++)
            Po2D[i][j] = Po2D[rand() % (row - 2) + 1][rand() % (col - 2) + 1];
}

bool GameBoard::checkMatchAble () {
    short i, j, x, y;
    for (i = 1; i < row - 1; i ++)
        for (j = 0; j < col - 1; j ++)
            for (x = i; x < row - 1; x ++)
                for (y = j; y < col - 1; y ++) {
                    if (pokemons[i][j].shown && pokemons[x][y].shown) {
                        checkMatch1 = {i, j};
                        checkMatch2 = {x, y};
                        if (checkMatching (pokemons, checkMatch1, checkMatch2, row, col, path) != None)
                            return 1;
                    }
                    
                }
    return 0;
}

//Check if GameBoard is empty
bool GameBoard::isEmpty() {
    short i, j;
    for (i = 1; i < row; i ++)
        for (j = 1; j < col; j ++)
            if (pokemons[i][j].shown)
                return 0;
    return 1;
}

//Setup the Gameboard
void GameBoard::createTable (const unsigned short& quantity) {
    srand(time(0));
    unsigned short int randNum, i, j, size = (row - 2) * (col - 2), pos = 0;
    float   sizePokemon = float(WinWdith) / (1.75f * col),
            padding = sizePokemon / 30,
            startX = 0,
            startY = startX;

    
    Pokemon* temp = new Pokemon[size];
    for (i = 0; i < size; i ++) {
        randNum = rand() % quantity;
        //2 contigous pokemons are similar
        temp[i].ID = randNum;
        temp[i].img = PokemonsImg[randNum];
        temp[i].size = sizePokemon;
        temp[i].cover = WHITE;
        temp[i++].back = PokeBack;
        temp[i].ID = randNum;
        temp[i].img = PokemonsImg[randNum];
        temp[i].size = sizePokemon;
        temp[i].cover = WHITE;
        temp[i].back = PokeBack;
    }

    for (i = 0; i < 3; i ++)
        shuffle1D(temp, size);

    pokemons = new Pokemon*[row];
    for (i = 0; i < row; i ++) {
        pokemons[i] = new Pokemon[col];

        for (j = 0; j < col; j ++) {
            if (i == 0 || j == 0 || i == row - 1 || j == col - 1) {
                pokemons[i][j].size = sizePokemon;
                pokemons[i][j].img = temp[0].img;
                pokemons[i][j].cover = SlightGrayTrans;
                pokemons[i][j].back = SlightGrayTrans;
            }
            else {
                pokemons[i][j].ID = temp[pos].ID;
                pokemons[i][j].img = temp[pos].img;
                pokemons[i][j].cover = temp[pos].cover;
                pokemons[i][j].back = temp[pos++].back;
                pokemons[i][j].shown = 1;
            }
            
            pokemons[i][j].size = sizePokemon;
            pokemons[i][j].pos = {startX, startY};
            pokemons[i][j].border = {pokemons[i][j].pos.x, pokemons[i][j].pos.y, pokemons[i][j].size, pokemons[i][j].size};

            if (j != col - 1)
                startX = startX + sizePokemon + padding;
            else
                startX = 0;
        }
        startY = startY + sizePokemon + padding;
    }

    delete[] temp;
}

//Draw the GameBoard
void GameBoard::draw() {
    unsigned short i, j;
    for (i = 0; i < row; i ++)
        for (j = 0; j < col; j ++) {
            if (selector.y == i && selector.x == j) {
                pokemons[i][j].back = WHITE;
                if (!pokemons[i][j].shown)
                    DrawRectangleRec (pokemons[i][j].border, SlightGrayTrans);
            }

            else if (pokemons[i][j].selected) {
                pokemons[i][j].back = SlightGray;
                pokemons[i][j].cover = SlightGray;
            }

            else {
                pokemons[i][j].back = PokeBack;
                pokemons[i][j].cover = WHITE;
            }

            if (pokemons[i][j].shown)
                pokemons[i][j].draw();
        }
}

//Draw the Matching Path using Linked List
void drawPath (Node* path, const Pokemon& pokemon) {
    if (path && path -> next) {
        Node* cur = path;
        Node* next = path -> next;

        DrawCircle (cur -> x, cur -> y, pokemon.size / 8, GREEN);
        while (cur -> next) {
            DrawLineEx ({next -> x, next -> y}, {cur -> x, cur -> y}, pokemon.size / 8, GREEN);
            DrawCircle (cur -> x, cur -> y, pokemon.size / 16, GREEN);
            cur = next;
            next = next -> next;
        }
        DrawCircle (cur -> x, cur -> y, pokemon.size / 8, GREEN);
    }
}

//Set up required data for Game Play
void GameScene::setup() {
    //Get Background
    Image img = LoadImage("resources/img/background/background.png");
    background = LoadTextureFromImage(img);
    UnloadImage(img);

    //Get Gameboard hidden background
    img = LoadImage("resources/img/logo.png");
    gameboard.HiddenBackground = LoadTextureFromImage(img);
    UnloadImage(img);

    //Get pokemons
    gameboard.createTable(60);

    //size of gameboard
    gameboard.width = gameboard.pokemons[0][0].size * (gameboard.col - 2);
    gameboard.height = gameboard.pokemons[0][0].size * (gameboard.row - 2);
}

//Manage Game scene
Scene GameScene::draw(GameAction& action, Scene scene, Level& level, LevelScene& LevelScreen) {
    //Choose the Level before playing
    //Level Screen loaded already so just draw the scene for level choosing
    if (action == ChooseLevel) {
        level = LevelScreen.draw(action); 
        
        return PLAY;
    }

    //Load gamne before playing
    if (action == LoadGame) {
        if (level == EASY) {
            gameboard.row = 6;
            gameboard.col = 8;
        }

        if (level == MEDIUM) {
            gameboard.row = 8;
            gameboard.col = 10;
        }

        if (level == HARD) {
            gameboard.row = 10;
            gameboard.col = 12;
        }

        setup();
        scoreboard.setup();

        //Done choosing level and loading game, now play the game
        action = PlayGame;
        return PLAY;
    }

    //This happen when Back to menu was selected, back to the Menu screen
    else if (action == End) {
        //The next time, the player would be asked to choose level again
        action = ChooseLevel;
        return MENU;
    }

    //Now action == PlayGame

    //Draw main background
    DrawTexturePro (background, {0, 0, float(background.width), float(background.height)}, {0, 0, float(WinWdith), float(WinHeight)}, {0, 0}, 0, WHITE);
    //Draw hidden background
    DrawTexturePro (gameboard.HiddenBackground, {0, 0, float(gameboard.HiddenBackground.width), float(gameboard.HiddenBackground.height)}, {gameboard.pokemons[1][1].pos.x - 2, gameboard.pokemons[1][1].pos.y, gameboard.width, gameboard.height}, {0, 0}, 0, WHITE);
    
    //Selector Dealing
    moveSelector2D (gameboard.selector, 1, 1, gameboard.col - 2, gameboard.row - 2);

        //Selected Pokemons
    if (IsKeyPressed(KEY_ENTER)) {
        gameboard.pokemons[gameboard.selector.y][gameboard.selector.x].selected = 1;
        
        //Nếu đã có 1 cái được chọn trước đó
        if (gameboard.selected.x != 0) {
            gameboard.MatchType = checkMatching (gameboard.pokemons, gameboard.selector, gameboard.selected, gameboard.row, gameboard.col, gameboard.path);

            //2 điểm trùng ID và nối với nhau được thì xóa
            if (gameboard.pokemons[gameboard.selector.y][gameboard.selector.x].ID == gameboard.pokemons[gameboard.selected.y][gameboard.selected.x].ID &&
                gameboard.MatchType != None
            ) {   
                gameboard.MatchingTime = GetTime();
              
                gameboard.pokemons[gameboard.selector.y][gameboard.selector.x].unSeen();
                gameboard.pokemons[gameboard.selected.y][gameboard.selected.x].unSeen();
            }

            gameboard.pokemons[gameboard.selector.y][gameboard.selector.x].selected = 0;
            gameboard.pokemons[gameboard.selected.y][gameboard.selected.x].selected = 0;

            //Đưa cái Selection tạm về lại rìa (Đánh dấu chưa chọn)
            gameboard.selected.x = 0;
        }

        //Nếu trước đó chưa có cái nào được chọn thì Selection tạm (Selected) sẽ lưu vị trí Selector
        else {
            gameboard.selected.x = gameboard.selector.x;
            gameboard.selected.y = gameboard.selector.y;
        }
        
    }

    if (GetTime() - gameboard.MatchingTime < 0.5) {
        drawPath (gameboard.path, gameboard.pokemons[0][0]);
    }

    else {
        removePath (gameboard.path);
    }

    if (gameboard.isEmpty()) {
        if (GetTime () - gameboard.MatchingTime > 0.5) {
            short i;
            for (i = 0; i < gameboard.row; i ++)
                delete[] gameboard.pokemons[i];
            delete[] gameboard.pokemons;

            action = ChooseLevel;
        }

        return PLAY;
    }

    //Draw Pokemons
    gameboard.draw();
    //scoreboard.draw(isSigned, name);
    
    return PLAY;
}