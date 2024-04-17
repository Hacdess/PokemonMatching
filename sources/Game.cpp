#include "../headers/GamePlay/Game.h"

void swapPokemon (Pokemon& pokemon1, Pokemon& pokemon2) {
    bool temp = pokemon1.shown;
    pokemon1.shown = pokemon2.shown;
    pokemon2.shown = temp;

    temp = pokemon1.selected;
    pokemon1.selected = pokemon2.selected;
    pokemon2.selected = temp;

    short ID = pokemon1.ID;
    pokemon1.ID = pokemon2.ID;
    pokemon2.ID = ID;

    Texture2D img = pokemon1.img;
    pokemon1.img = pokemon2.img;
    pokemon2.img = img;
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
                    removeHead (path);
                    return 0;
                }
            }

            //No obstacle between pokemon1 and pokemon2 so add pokemon2 to create Path I
            addPath (path,
                    pokemons[pokemon1.y][start].pos.x + pokemons[pokemon1.y][start].size / 2,
                    pokemons[pokemon1.y][start].pos.y + pokemons[pokemon1.y][start].size / 2
            );            

            return 1;
        }

        //Pokemon1 is on the right of Pokemon2
        for (start = pokemon1.x + 1; start < pokemon2.x; start ++) {
            //Path hit the obstacle so return none
            if (pokemons[pokemon1.y][start].shown) {
                removeHead (path);
                return None;
            }
        }

        //No obstacle between pokemon1 and pokemon2 so add pokemon2 to create Path I
        addPath (path,
                pokemons[pokemon1.y][start].pos.x + pokemons[pokemon1.y][start].size / 2,
                pokemons[pokemon1.y][start].pos.y + pokemons[pokemon1.y][start].size / 2
        );            

        return 1;
    }

    //Check vertically
    if (pokemon1.x == pokemon2.x) {
        //Pokemon1 is below Pokemon2
        if (pokemon1.y > pokemon2.y) {
            for (start = pokemon1.y - 1; start > pokemon2.y; start --) {
                //Path hit the obstacle so return none
                if (pokemons[start][pokemon1.x].shown) {
                    removeHead (path);
                    return 0;
                }
            }
            
            //No obstacle between pokemon1 and pokemon2 so add pokemon2 to create Path I
            addPath (path,
                    pokemons[start][pokemon1.x].pos.x + pokemons[start][pokemon1.x].size / 2,
                    pokemons[start][pokemon1.x].pos.y + pokemons[start][pokemon1.x].size / 2
            );            

            return 1;
        }

        //Pokemon1 is above Pokemon2
        for (start = pokemon1.y + 1; start < pokemon2.y; start ++) {
            //Path hit the obstacle so return none
            if (pokemons[start][pokemon1.x].shown) {
                removeHead (path);
                return 0;
            }
        }
        
        //No obstacle between pokemon1 and pokemon2 so add pokemon2 to create Path I
        addPath (path,
                pokemons[start][pokemon1.x].pos.x + pokemons[start][pokemon1.x].size / 2,
                pokemons[start][pokemon1.x].pos.y + pokemons[start][pokemon1.x].size / 2
        );            

        return 1;
    }

    removePath (path);
    return 0;
}

bool checkLmatching (Pokemon** pokemons, const Selector2D& pokemon1, const Selector2D& pokemon2, Node*& path) {
    Selector2D tempPokemon;

    tempPokemon.x = pokemon1.x;
    tempPokemon.y = pokemon2.y;
    if (!pokemons[tempPokemon.y][tempPokemon.x].shown && checkImatching(pokemons, pokemon1, tempPokemon, path)) {
        if (checkImatching(pokemons, tempPokemon, pokemon2, path))
            return 1;
        removeHead(path);
        removeHead(path);
    }

    tempPokemon.x = pokemon2.x;
    tempPokemon.y = pokemon1.y;
    if (!pokemons[tempPokemon.y][tempPokemon.x].shown && checkImatching(pokemons, pokemon1, tempPokemon, path)) {
        if (checkImatching(pokemons, tempPokemon, pokemon2, path))
            return 1;
        removeHead(path);
        removeHead(path);
    }

    return 0;
}

//U, Z matching
MatchingType checkMatching (Pokemon** pokemons, const Selector2D& pokemon1, const Selector2D& pokemon2, const short& row, const short& col, Node*& path) {
    //Not the same ID
    if (pokemons[pokemon1.y][pokemon1.x].ID != pokemons[pokemon2.y][pokemon2.x].ID)
        return None;

    //If one of them is deleted
    if (!pokemons[pokemon1.y][pokemon1.x].shown || !pokemons[pokemon2.y][pokemon2.x].shown)
        return None;

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

//Load images from folder to get backgrounds, then turn them into textures
Texture2D* readImageBackground (const short int& quantity) {
    //Location to image
    string path;
    Texture2D *resTexture = new Texture2D[quantity];

    // Load image
    short int i;
    for (i = 0; i < quantity; i++) {
        //path to pokemon
        path = "resources/img/background/background" + to_string(i) + ".png";
        Image img = LoadImage(path.c_str());// load image
        resTexture[i] = LoadTextureFromImage(img);// load texture from image
        UnloadImage(img);// unload image after load
    }
    
    return resTexture;
}

//Load images from folder to get pokemons images, then turn them into textures
Texture2D* readImagePokemon(const short int& quantity) {
    //Location to image
    string path;
    Texture2D *resTexture = new Texture2D[quantity];

    // Load image
    short int i;
    for (i = 0; i < quantity; i++) {
        //path to pokemon
        path = "resources/img/pokemon/pokemon" + to_string(i) + ".png";
        Image img = LoadImage(path.c_str());// load image
        resTexture[i] = LoadTextureFromImage(img);// load texture from image
        UnloadImage(img);// unload image after load
    }

    return resTexture;
}

//Load images from folder to get hidden backgrounds of the gameboard, then turn them into textures
Texture2D* readImageHidden(const short int& quantity) {
    //Location to image
    string path;
    Texture2D *resTexture = new Texture2D[quantity];

    // Load image
    short int i;
    for (i = 0; i < quantity; i++) {
        //path to pokemon
        path = "resources/img/hidden/hidden" + to_string(i) + ".png";
        Image img = LoadImage(path.c_str());// load image
        resTexture[i] = LoadTextureFromImage(img);// load texture from image
        UnloadImage(img);// unload image after load
    }

    return resTexture;
}

//Shuffle the 1D pokemon array
void shuffle1D(Pokemon* Po1D, const short& size) {
    short i, j;
    srand(time(0));
    for (i = 0; i < size; i ++) {
        j = rand() % size;
        swapPokemon (Po1D[i], Po1D[j]);
    }
}

//Shuffle the 2D pokemon array
void shuffle2D(Pokemon** Po2D, const short& row, const short& col) {
    short i, j;
    for (i = 1; i < row - 1; i ++)
        for (j = 1; j < col - 1; j ++) {
            srand(time(0));
            swapPokemon(Po2D[i][j], Po2D[rand() % (row - 2) + 1][rand() % (col - 2) + 1]);
        }
}

bool GameBoard::checkMatchAble () {
    short i, j, x, y;
    Node* temp = NULL;
    for (i = 1; i < row - 1; i ++)
        for (j = 1; j < col - 1; j ++)
            for (y = 1; y < row - 1; y ++)
                for (x = 1; x < col - 1; x ++) {
                    checkMatch1 = {j, i}, checkMatch2 = {x, y};
                    if (checkMatching (pokemons, checkMatch1, checkMatch2, row, col, temp) != None) {
                        removePath (temp);
                        return 1;
                    }
                }
    return 0;
}

MatchingType makeHint (Pokemon** pokemons, const short& row, const short& col, Selector2D& hint1, Selector2D& hint2, Node*& path) {
    MatchingType res = None;

    for (hint1.y = 1; hint1.y < row - 1; hint1.y ++)
        for (hint1.x = 1; hint1.x < col - 1; hint1.x ++)
            for (hint2.y = 1; hint2.y < row - 1; hint2.y ++)
                for (hint2.x = 1; hint2.x < col - 1; hint2.x ++) {
                    res = checkMatching (pokemons, hint1, hint2, row, col, path);
                    if (res != None)
                        return res;
                }
    
    return res;
}

//Check if GameBoard is empty
bool GameBoard::isEmpty() {
    short i, j;
    for (i = 1; i < row - 1; i ++)
        for (j = 1; j < col - 1; j ++)
            if (pokemons[i][j].shown)
                return 0;
    return 1;
}

//Setup the Gameboard
void GameBoard::createTable (const short& quantity) {
    srand(time(0));
    short int randNum, i, j, size = (row - 2) * (col - 2), pos = 0;
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

    selector = {1,1};
    selected = {0,0};
    player2 = {1,1};
    selected2 = {0,0};

    delete[] temp;
}

//Draw the GameBoard
void GameBoard::draw(const bool& isDual) {
    short i, j;
    for (i = 0; i < row; i ++)
        for (j = 0; j < col; j ++) {
            if (
                (selector.y == i && selector.x == j) ||
                (isDual && player2.y == i && player2.x == j)
            ) {
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

//Store game result in file .txt if that player won
void storeResult (const ScoreBoard& scoreboard, const Level& level) {
    ofstream fout;
    string stage;

    if (level == EASY)
        stage = "Easy";
    if (level == MEDIUM)
        stage = "Medium";
    if (level == HARD)
        stage = "Hard";

    fout.open("resources/file/Result.txt", ios::app);
    if (!fout.is_open()) {
        cout << "Can't open file to store\n";
        return;
    }

    fout << stage << ',' << scoreboard.Player[0].content << ',' << scoreboard.ScoreText[0].content << ',' << scoreboard.TimeText.content << endl;

    fout.close();
}

//Set up required data for Game Play
void GameScene::setup() {
    //Get Background
    srand (time(0));
    background = backgrounds[rand() % 11];

    //Get random Gameboard hidden background
    srand (time(0));
    gameboard.HiddenBackground = gameboard.Hiddens[rand() % 6];

    //Get pokemons
    gameboard.createTable(50);

    //size of gameboard
    gameboard.width = (gameboard.pokemons[0][0].size + gameboard.pokemons[0][0].size / 30) * (gameboard.col - 2);
    gameboard.height = (gameboard.pokemons[0][0].size + gameboard.pokemons[0][0].size / 30) * (gameboard.row - 2);

    EndTime = 0;
}

//Manage Game scene
Scene GameScene::draw(GameAction& action, bool& isDual, Level& level, GameModeScene& GameModeScreen, LevelScene& LevelScreen, const char* username, gameMusic& musicAndSound) {
    //Choose the Level before playing
    //Level Screen loaded already so just draw the scene for level choosing
    if (action == ChooseGameMode) {
        isDual = GameModeScreen.draw(action, musicAndSound);
        return PLAY; 
    }
    
    if (action == ChooseLevel) {
        level = LevelScreen.draw(action, musicAndSound); 
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
        scoreboard.setup(isDual, username);

        //Done choosing level and loading game, now play the game
        action = PlayGame;
        return PLAY;
    }

    if (action == ShowResult) {
        if (!ResultScreen.isSet)
            ResultScreen.setup(isDual);
        ResultScreen.draw (action, isDual, musicAndSound);
        return PLAY;
    }

    //This happen when Back to menu was selected, back to the Menu screen
    if (action == End) {
        //The next time, the player would be asked to choose Gamemode again
        action = ChooseGameMode;
        return MENU;
    }

    //Now action == PlayGame
    PauseMusicStream(musicAndSound.themeMusic);
    //Draw main background
    DrawTexturePro (background, {0, 0, float(background.width), float(background.height)}, {0, 0, float(WinWdith), float(WinHeight)}, {0, 0}, 0, WHITE);
    //Draw hidden background
    DrawTexturePro (gameboard.HiddenBackground, {0, 0, float(gameboard.HiddenBackground.width), float(gameboard.HiddenBackground.height)}, {gameboard.pokemons[1][1].pos.x - 2, gameboard.pokemons[1][1].pos.y, gameboard.width, gameboard.height}, {0, 0}, 0, WHITE);

    //Selector Dealing
    moveSelector2D (gameboard.selector, 1, 1, gameboard.col - 2, gameboard.row - 2, musicAndSound);

    //Selected Pokemons player1
    if (IsKeyPressed(KEY_ENTER)) {
        gameboard.pokemons[gameboard.selector.y][gameboard.selector.x].selected = 1;
        
        //If one pokemon has been selected before
        if (gameboard.selected.x != 0) {
            //Then check matching
            gameboard.MatchType = checkMatching (gameboard.pokemons, gameboard.selector, gameboard.selected, gameboard.row, gameboard.col, gameboard.path);
            //Correct Matching => add score
            if (gameboard.MatchType != None) {
                PlaySound(musicAndSound.correctMatching);
                switch (gameboard.MatchType) {
                    case I:
                        scoreboard.ScoreNum += 2;
                        break;
                    case L:
                        scoreboard.ScoreNum += 4;
                        break;
                    
                    default:
                        scoreboard.ScoreNum += 6;
                        break;
                }
                //Mark the matching time to delay the disappearance of the path
                gameboard.MatchingTime = GetTime();

                scoreboard.updateMessage1 (gameboard.selector, gameboard.selected, gameboard.MatchType);

                //Unshow pokemon == delete
                gameboard.pokemons[gameboard.selector.y][gameboard.selector.x].unSeen();
                gameboard.pokemons[gameboard.selected.y][gameboard.selected.x].unSeen();
            }

            //Wrong matching => minus 2
            else {
                PlaySound(musicAndSound.wrongMatching);
                scoreboard.ScoreNum -= 2;
                scoreboard.health --;
            }
            //After check matching, stop selecting
            gameboard.pokemons[gameboard.selector.y][gameboard.selector.x].selected = 0;
            gameboard.pokemons[gameboard.selected.y][gameboard.selected.x].selected = 0;

            //Move Selection to the border => Mark that no pokemon is selected
            gameboard.selected.x = 0;
        }

        //Nếu trước đó chưa có cái nào được chọn thì Selection tạm (Selected) sẽ lưu vị trí Selector
        else {
            gameboard.selected.x = gameboard.selector.x;
            gameboard.selected.y = gameboard.selector.y;
        }
        
    }

    //Press 'O' to shuffe player 1
    if (IsKeyPressed(KEY_O)) {
        PlaySound(musicAndSound.pressButton);
        scoreboard.ScoreNum -= 2;
        shuffle2D (gameboard.pokemons, gameboard.row, gameboard.col);
    }

    //Press 'P' to makehint player 1
    if (IsKeyPressed(KEY_P)) {
        PlaySound(musicAndSound.pressButton);
        scoreboard.ScoreNum -= 4;
        gameboard.MatchType = makeHint (gameboard.pokemons, gameboard.row, gameboard.col, gameboard.hint1_1, gameboard.hint1_2, gameboard.path);
        gameboard.MatchingTime = GetTime();
        scoreboard.updateMessage1 (gameboard.hint1_1, gameboard.hint1_2, gameboard.MatchType);
        gameboard.pokemons[gameboard.hint1_1.y][gameboard.hint1_1.x].unSeen();
        gameboard.pokemons[gameboard.hint1_2.y][gameboard.hint1_2.x].unSeen();
    }

    //Draw path for 0.5 secs
    if (GetTime() - gameboard.MatchingTime < 0.5)
        drawPath (gameboard.path, gameboard.pokemons[0][0]);
    else
        removePath (gameboard.path);

    if (isDual) {
        //Selector Dealing
        moveSelector2DPlayer2 (gameboard.player2, 1, 1, gameboard.col - 2, gameboard.row - 2, musicAndSound);

        //Selected Pokemons player2
        if (IsKeyPressed(KEY_SPACE)) {
            gameboard.pokemons[gameboard.player2.y][gameboard.player2.x].selected = 1;
            
            //If one pokemon has been selected before
            if (gameboard.selected2.x != 0) {
                //Then check matching
                gameboard.MatchType2 = checkMatching (gameboard.pokemons, gameboard.player2, gameboard.selected2, gameboard.row, gameboard.col, gameboard.path2);
                //Correct Matching => add score
                if (gameboard.MatchType2 != None) {
                    PlaySound(musicAndSound.correctMatching);
                    switch (gameboard.MatchType2) {
                        case I:
                            scoreboard.ScoreNum2 += 2;
                            break;
                        case L:
                            scoreboard.ScoreNum2 += 4;
                            break;
                        
                        default:
                            scoreboard.ScoreNum2 += 6;
                            break;
                    }
                    //Mark the matching time to delay the disappearance of the path
                    gameboard.MatchingTime2 = GetTime();

                    scoreboard.updateMessage2 (gameboard.player2, gameboard.selected2, gameboard.MatchType2);

                    //Unshow pokemon == delete
                    gameboard.pokemons[gameboard.player2.y][gameboard.player2.x].unSeen();
                    gameboard.pokemons[gameboard.selected2.y][gameboard.selected2.x].unSeen();
                }

                //Wrong matching => minus 2
                else {
                    PlaySound(musicAndSound.wrongMatching);
                    scoreboard.ScoreNum2 -= 2;
                    scoreboard.health2 --;
                }
                //After check matching, stop selecting
                gameboard.pokemons[gameboard.player2.y][gameboard.player2.x].selected = 0;
                gameboard.pokemons[gameboard.selected2.y][gameboard.selected2.x].selected = 0;

                //Move Selection to the border => Mark that no pokemon is selected
                gameboard.selected2.x = 0;
            }

            //Nếu trước đó chưa có cái nào được chọn thì Selection tạm (Selected) sẽ lưu vị trí Selector
            else {
                gameboard.selected2.x = gameboard.player2.x;
                gameboard.selected2.y = gameboard.player2.y;
            }
            
        }
        
        //Press 'R' to shuffle player 2
        if (IsKeyPressed(KEY_R)) {
            PlaySound(musicAndSound.pressButton);
            scoreboard.ScoreNum2 -= 2;
            shuffle2D (gameboard.pokemons, gameboard.row, gameboard.col);
        }

        //Press 'H' to makehint player 2
        if (IsKeyPressed(KEY_H)) {
            PlaySound(musicAndSound.pressButton);
            scoreboard.ScoreNum2 -= 4;
            gameboard.MatchType2 = makeHint (gameboard.pokemons, gameboard.row, gameboard.col, gameboard.hint2_1, gameboard.hint2_2, gameboard.path2);
            gameboard.MatchingTime2 = GetTime();
            scoreboard.updateMessage2 (gameboard.hint2_1, gameboard.hint2_2, gameboard.MatchType2);
            gameboard.pokemons[gameboard.hint2_1.y][gameboard.hint2_1.x].unSeen();
            gameboard.pokemons[gameboard.hint2_2.y][gameboard.hint2_2.x].unSeen();
        }

        //Draw path for 0.5 secs    
        if (GetTime() - gameboard.MatchingTime2 < 0.5)
            drawPath (gameboard.path2, gameboard.pokemons[0][0]);
        else
            removePath (gameboard.path2);
    }

    //Draw Pokemons
    gameboard.draw(isDual);
    scoreboard.draw(isDual);

    if (isDual && 
        (gameboard.isEmpty() ||
        scoreboard.ScoreNum < 0 || scoreboard.health <= 0 ||
        scoreboard.ScoreNum2 < 0 || scoreboard.health2 <= 0)
    ) {
        PlaySound(musicAndSound.winning);
        if (EndTime == 0)
            EndTime = GetTime();

        if (GetTime () - EndTime > 0.5) {
            short i;
            for (i = 0; i < gameboard.row; i ++)
                delete[] gameboard.pokemons[i];
            delete[] gameboard.pokemons;
            action = ShowResult;

            ResultScreen.time.content = scoreboard.TimeText.content;

            if (scoreboard.ScoreNum > scoreboard.ScoreNum2)
                addText (ResultScreen.result.content, "Player 1 won!");
            else if (scoreboard.ScoreNum < scoreboard.ScoreNum2)
                addText (ResultScreen.result.content, "Player 2 won!");
            else
                addText (ResultScreen.result.content, "DRAW!");

            ResultScreen.player[0].content = scoreboard.Player[0].content;
            ResultScreen.player[1].content = scoreboard.Player[1].content;

            ResultScreen.score[0].content = scoreboard.ScoreText[0].content;
            ResultScreen.score[1].content = scoreboard.ScoreText[1].content;
        }

        return PLAY;
    }

    //Player won
    if (gameboard.isEmpty()) {
        PlaySound(musicAndSound.winning);
        if (EndTime == 0)
            EndTime = GetTime();

        if (GetTime () - EndTime > 0.5) {
            short i;
            for (i = 0; i < gameboard.row; i ++)
                delete[] gameboard.pokemons[i];
            delete[] gameboard.pokemons;
            action = ShowResult;

            ResultScreen.time.content = scoreboard.TimeText.content;
            ResultScreen.player[0].content = scoreboard.Player[0].content;
            ResultScreen.score[0].content = scoreboard.ScoreText[0].content;
            storeResult (scoreboard, level);
            ResultScreen.isVictory = 1;
        }

        return PLAY;
    }

    //Score < 0 or health back to 0 => Player lost
    if (scoreboard.ScoreNum < 0 || scoreboard.health <= 0) {
        PlaySound(musicAndSound.losing);
        short i;
        for (i = 0; i < gameboard.row; i ++)
            delete[] gameboard.pokemons[i];
        delete[] gameboard.pokemons;
        action = ShowResult;
        ResultScreen.isVictory = 0;

        return PLAY;
    }

    //If it isn't matchable anymore, shuffle the gameboard
    if (!gameboard.checkMatchAble()) 
        shuffle2D (gameboard.pokemons, gameboard.row, gameboard.col);

    return PLAY;
}