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

    short start, end;
    // check vertically
    if (pokemon1.y == pokemon2.y) {
        start = pokemon1.x;
        end = pokemon2.x;

        if (start > end)
            swap(start, end);
        
        addHead (path,
                pokemons[pokemon1.y][start].pos.x + pokemons[pokemon1.y][start].size / 2,
                pokemons[pokemon1.y][start].pos.y + pokemons[pokemon1.y][start].size / 2);

        start ++;

        for (; start < end; start ++)
            if (pokemons[pokemon1.y][start].shown)
                return 0;

        addHead (path,
                pokemons[pokemon1.y][start].pos.x + pokemons[pokemon1.y][start].size / 2,
                pokemons[pokemon1.y][start].pos.y + pokemons[pokemon1.y][start].size / 2);

        return 1;
    }

    // check horizontally
    if (pokemon1.x == pokemon2.x)
    {
        start = pokemon1.y;
        end = pokemon2.y;
        if (start > end) 
            swap(start, end);

        addHead (path,
                pokemons[start][pokemon1.x].pos.x + pokemons[start][pokemon1.x].size / 2,
                pokemons[start][pokemon1.x].pos.y + pokemons[start][pokemon1.x].size / 2);
        start ++;
        
        for (; start < end; start ++)
            if (pokemons[start][pokemon1.x].shown)
                return 0;

        return 1;
    }

    return 0;
}

bool checkLmatching (Pokemon** pokemons, const Selector2D& pokemon1, const Selector2D& pokemon2, Node*& path) {
    Selector2D tempPokemon;
    tempPokemon.x = pokemon1.x;
    tempPokemon.y = pokemon2.y;
    if (!pokemons[tempPokemon.y][tempPokemon.x].shown && 
        checkImatching(pokemons, pokemon1, tempPokemon, path) && 
        checkImatching(pokemons, pokemon2, tempPokemon, path)
    )
        return 1;

    tempPokemon.x = pokemon2.x;
    tempPokemon.y = pokemon1.y;
    if (!pokemons[tempPokemon.y][tempPokemon.x].shown && 
        checkImatching(pokemons, pokemon2, tempPokemon, path) && 
        checkImatching(pokemons, pokemon1, tempPokemon, path)
    )
        return 1;

    return 0;
}

MatchingType checkMatching (Pokemon** pokemons, const Selector2D& pokemon1, const Selector2D& pokemon2, const short& row, const short& col, Node*& path) {
    //Check if they are the same
    if (pokemon1.x == pokemon2.x && pokemon1.y == pokemon2.y)
        return None;

    if (checkImatching(pokemons, pokemon1, pokemon2, path))
        return I;

    else if (checkLmatching(pokemons, pokemon1, pokemon2, path))
        return U;
    
    else {
        Selector2D tempPokemon;
        // Move right
        tempPokemon.x = pokemon1.x;
        tempPokemon.y = pokemon1.y;

        if (tempPokemon.x != col - 1)
            tempPokemon.x++;

        while (!pokemons[tempPokemon.y][tempPokemon.x].shown && tempPokemon.x < col) {
            if (checkLmatching(pokemons, pokemon2, tempPokemon, path)) {
                if (tempPokemon.x > pokemon2.x)
                    return U;
                return Z;
            }
            
            tempPokemon.x ++;
            if (tempPokemon.x >= col)
                break;
        }

        // Move left
        tempPokemon.x = pokemon1.x;
        tempPokemon.y = pokemon1.y;

        if (tempPokemon.x != 0)
            tempPokemon.x --;

        while (!pokemons[tempPokemon.y][tempPokemon.x].shown && tempPokemon.x >= 0) {
            if (checkLmatching(pokemons, pokemon2, tempPokemon, path)) {
                if (tempPokemon.x < pokemon2.x)
                    return U;
                return Z;
            }

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
            if (checkLmatching(pokemons, pokemon2, tempPokemon, path)) {
                if (tempPokemon.y < pokemon2.y)
                    return U;
                return Z;
            }

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
            if (checkLmatching(pokemons, pokemon2, tempPokemon, path)) {
                if (tempPokemon.y > pokemon2.y)
                    return U;
                return Z;
            }

            tempPokemon.y++;
            if (tempPokemon.y >= row)
                break;
        }
    }

    return None;
}

void Pokemon::draw() {
    DrawRectangleRec (border, back);
    DrawTexturePro (img, {0, 0, float(img.width), float(img.height)}, {pos.x, pos.y, size, size}, {0, 0}, 0, cover);
}

void Pokemon::unSeen() {
    shown = 0;
}

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

void shuffle1D(Pokemon* Po1D, const unsigned short& size) {
    srand(time(0));
    unsigned short i, j;
    for (i = 0; i < size; i ++) {
        j = rand() % size;
        swapPokemon (Po1D[i], Po1D[j]);
    }
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

void drawPath (Node* path, const Pokemon& pokemon) {
    if (path && path -> next) {
        Node* cur = path;
        Node* next = path -> next;

        while (cur -> next) {
            cout << "Drawing\n";

            /*DrawLineEx ({next -> x, next -> y},
                        {cur -> x, cur -> y},
                        pokemon.size / 4, PURPLE);*/
            cur = next;
            next = next -> next;
        }
    }

    WaitTime (0.5);
    removeAll (path);
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

    //Get pokemons
    gameboard.createTable(60);

    //size of gameboard
    gameboard.width = gameboard.pokemons[0][0].size * (gameboard.col - 2);
    gameboard.height = gameboard.pokemons[0][0].size * (gameboard.row - 2);
}

Scene GameScene::draw(GameAction& action, Scene scene, Level& level, LevelScene& LevelScreen) {
    if (action == ChooseLevel) {
        level = LevelScreen.draw(action); //Level Screen loaded already so just draw
        return PLAY;
    }

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

        action = PlayGame;
        return PLAY;
    }

    else if (action == End) {
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
                //drawPath (gameboard.path, gameboard.pokemons[0][0]);
              
                gameboard.pokemons[gameboard.selector.y][gameboard.selector.x].unSeen();
                gameboard.pokemons[gameboard.selected.y][gameboard.selected.x].unSeen();
                
                //removeAll (gameboard.path);
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


    if (gameboard.isEmpty()) {
        short i;
        for (i = 0; i < gameboard.row; i ++)
            delete[] gameboard.pokemons[i];
        delete[] gameboard.pokemons;

        action = ChooseLevel;
    }

    //Draw Pokemons
    gameboard.draw();
    DrawLineEx ({0.f, 0.f}, {float(WinWdith), float(WinHeight)}, 20.0f, BLACK);

    //Drawline
    if (gameboard.MatchType != None) {
        gameboard.MatchType = None;
        printNode(gameboard.path);
        removeAll(gameboard.path);
    }
    
    return PLAY;
}