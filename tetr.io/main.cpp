#include <SFML/Graphics.hpp>

#include <sstream>
#include <math.h>

using namespace sf;
using namespace std;

#define HEIGHT_FIELD 600
#define WIDHT_FIELD  300

#define SIZE_BLOCK   30

// класс блоков
class Block {
public:
    Block(){
        textur.loadFromFile("img/blocks.png");
        for(int i = 0; i < 8; i++){
            blockSprite[i].setTexture(textur);
            // вырезаем из текстуры тот цвет, который нам необходим
            blockSprite[i].setTextureRect(IntRect(SIZE_BLOCK * i, 0, SIZE_BLOCK, SIZE_BLOCK));
        }
    }

    Sprite getSprite(int index){
        return blockSprite[index];
    }

private:
    Texture textur;
    Sprite  blockSprite[8];
};

struct Point{
    int x;
    int y;
};

// global
Block blocks;

class Figure{
public:
    Figure(RenderWindow *pWindow, int offsetX, int offsetY){
        this->pWindow = pWindow;
        this->offsetX = offsetX;
        this->offsetY = offsetY;
    }

    // инициализация фигуры по индексу (I, J, L, O, S, T, Z)
    void init(int index, int iColor){
        this->iColor = iColor;
        iType = index;
        xPos = 4;
        yPos = 0;

        if(index == 0){ // I
            blocksFigure[0].x = 1;
            blocksFigure[0].y = 0;
            blocksFigure[1].x = 1;
            blocksFigure[1].y = 1;
            blocksFigure[2].x = 1;
            blocksFigure[2].y = 2;
            blocksFigure[3].x = 1;
            blocksFigure[3].y = 3;
        } else if(index == 1){ //J
            blocksFigure[0].x = 1;
            blocksFigure[0].y = 0;
            blocksFigure[1].x = 1;
            blocksFigure[1].y = 1;
            blocksFigure[2].x = 1;
            blocksFigure[2].y = 2;
            blocksFigure[3].x = 0;
            blocksFigure[3].y = 2;
        } else if(index == 2){ //L
            blocksFigure[0].x = 0;
            blocksFigure[0].y = 0;
            blocksFigure[1].x = 0;
            blocksFigure[1].y = 1;
            blocksFigure[2].x = 0;
            blocksFigure[2].y = 2;
            blocksFigure[3].x = 1;
            blocksFigure[3].y = 2;
        } else if(index == 3){ //O
            blocksFigure[0].x = 0;
            blocksFigure[0].y = 0;
            blocksFigure[1].x = 0;
            blocksFigure[1].y = 1;
            blocksFigure[2].x = 1;
            blocksFigure[2].y = 0;
            blocksFigure[3].x = 1;
            blocksFigure[3].y = 1;
        } else if(index == 4){ //S
            blocksFigure[0].x = 0;
            blocksFigure[0].y = 1;
            blocksFigure[1].x = 1;
            blocksFigure[1].y = 1;
            blocksFigure[2].x = 1;
            blocksFigure[2].y = 0;
            blocksFigure[3].x = 2;
            blocksFigure[3].y = 0;
        } else if(index == 5){ //T
            blocksFigure[0].x = 0;
            blocksFigure[0].y = 0;
            blocksFigure[1].x = 1;
            blocksFigure[1].y = 0;
            blocksFigure[2].x = 2;
            blocksFigure[2].y = 0;
            blocksFigure[3].x = 1;
            blocksFigure[3].y = 1;
        } else if(index == 6){ //Z
            blocksFigure[0].x = 0;
            blocksFigure[0].y = 0;
            blocksFigure[1].x = 1;
            blocksFigure[1].y = 0;
            blocksFigure[2].x = 1;
            blocksFigure[2].y = 1;
            blocksFigure[3].x = 2;
            blocksFigure[3].y = 1;
        }
    }

    // движение фигуры вниз
    bool move(){
        ++yPos;
    }

    // движение в лево
    void moveLeft(){
        if(xPos > 0)
            --xPos;
    }

    // движение в право
    void moveRight(){
        int offset = 0;
        for(int i = 0; i < 4; i++){
            if(offset < blocksFigure[i].x)
                offset = blocksFigure[i].x;
        }

        if(xPos + offset < 9)
            ++xPos;
    }

    // вращение
    void rotate(){
        if(iType == 3) // O - не вращаем
            return;

        // вращаем
        if(iType == 0){ // I - свое вращение
            int pointRotate[4][4] = {0};
            int pointTemp[4][4] = {0};

            for(int i = 0; i < 4; i++){
                pointRotate[blocksFigure[i].x][blocksFigure[i].y] = 1;
            }

            for(int i = 0; i < 4; i++){
                for(int j = 0; j < 4; j++){
                    pointTemp[j][4 - i - 1] = pointRotate[i][j];
                }
            }

            // переносим
            int iItem = 0;
            for(int i = 0; i < 4; i++){
                for(int j = 0; j < 4; j++){
                    if(pointTemp[i][j] == 1){
                        blocksFigure[iItem].x = i;
                        blocksFigure[iItem].y = j;
                        ++iItem;
                    }
                }
            }
        } else {
            int pointRotate[3][3] = {0};
            int pointTemp[3][3] = {0};

            for(int i = 0; i < 4; i++){
                pointRotate[blocksFigure[i].x][blocksFigure[i].y] = 1;
            }

            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    pointTemp[j][3 - i - 1] = pointRotate[i][j];
                }
            }

            // переносим
            int iItem = 0;
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    if(pointTemp[i][j] == 1){
                        blocksFigure[iItem].x = i;
                        blocksFigure[iItem].y = j;
                        ++iItem;
                    }
                }
            }
        }
    }

    void draw() const{
        for(int i = 0; i< 4; i++){
            Sprite blockSprite = blocks.getSprite(iColor);
            blockSprite.setPosition(xPos * SIZE_BLOCK + blocksFigure[i].x * SIZE_BLOCK  + offsetX, yPos * SIZE_BLOCK + blocksFigure[i].y * SIZE_BLOCK + offsetY);
            pWindow->draw(blockSprite);
        }
    }

    Point *position(){
        Point *pos = new Point[4];

        for(int i = 0; i < 4; i++){
            pos[i].x = blocksFigure[i].x + xPos;
            pos[i].y = blocksFigure[i].y + yPos;
        }

        return pos;
    }

    int color() { return iColor; }

private:
    RenderWindow *pWindow;

    int offsetX;
    int offsetY;
    int xPos;
    int yPos;

    Point blocksFigure[4];
    int   iColor;
    int   iType;
};

// класс поле
class Field {
public:
    Field(RenderWindow *pWindow, int xPos, int yPos){
        this->pWindow = pWindow;
        offsetX = xPos;
        offsetY = yPos;

        Image bgImg;
        bgImg.loadFromFile("img/bg.png");

        bgTexture.loadFromImage(bgImg);

        bgSprite.setTexture(bgTexture);
        bgSprite.setTextureRect(IntRect(0, 0, WIDHT_FIELD, HEIGHT_FIELD));
        bgSprite.setPosition(offsetX, offsetY);

        // обнуляем массив поля
        for(int x = 0; x < 10;  x++){
            for(int y = 0; y < 20; y++){
                map[x][y] = 0;
            }
        }
    }

    void draw() const{
        // фон
        pWindow->draw(bgSprite);

        // заполняем уложенные кирпичи
        for(int x = 0; x < 10; x++){
            for(int y = 0; y < 20; y++){
                if(map[x][y] != 0){
                    Sprite blockSprite = blocks.getSprite(map[x][y] - 1);
                    blockSprite.setPosition(x * SIZE_BLOCK + offsetX, y * SIZE_BLOCK + offsetY);
                    pWindow->draw(blockSprite);
                }
            }
        }
    }

    bool isNextMove(Point *blocksFigure){
        for(int i = 0; i < 4; i++){
            if(blocksFigure[i].y + 1 >= 20)
                return false;

            int call = map[blocksFigure[i].x][blocksFigure[i].y + 1];
            if(call != 0)
                return false;
        }

        return true;
    }

    bool isLeftMove(Point *blocksFigure){
        for(int i = 0; i < 4; i++){
            if(blocksFigure[i].x <= 0)
                return false;

            int call = map[blocksFigure[i].x - 1][blocksFigure[i].y];
            if(call != 0)
                return false;
        }

        return true;
    }

    bool isRightMove(Point *blocksFigure){
        for(int i = 0; i < 4; i++){
            if(blocksFigure[i].x >= 9)
                return false;

            int call = map[blocksFigure[i].x + 1][blocksFigure[i].y];
            if(call != 0)
                return false;
        }

        return true;
    }

    int findFullLine(){
        int iCountFullLine = 0;

        for(int y = 0; y < 20; y++){
            int countCheck = 0;
            for(int x = 0; x < 10; x++){
                if(map[x][y] != 0 && map[x][y] != 8)
                    ++countCheck;
                else
                    break;
            }

            if(countCheck == 10){
                for(int iLine = y; iLine > 0; iLine--){
                    for(int z = 0; z < 10; z++){
                        if(iLine == 0)
                            map[z][0] = 0;
                        else
                            map[z][iLine] = map[z][iLine - 1];
                    }
                }

                ++iCountFullLine;
            }
        }

        return iCountFullLine;
    }

    void figureSetMap(Point *blocksFigure, int iColor){
        for(int i = 0; i < 4; i++){
            map[blocksFigure[i].x][blocksFigure[i].y] = iColor;
        }
    }

    void addLine(int countLine){
        for(int y = 0; y < 20; y++){
            for(int x = 0; x < 10; x++){
                if(y + countLine < 20)
                    map[x][y] = map[x][y + countLine];
                else
                    map[x][y] = 8;
            }
        }
    }

private:
    Texture bgTexture;
    Sprite  bgSprite;

    int     map[10][20];

    int     offsetX;
    int     offsetY;

    RenderWindow *pWindow;
};

int main(){
    // размер окна для размешения 2-х полей 10 на 20 клеток (30x30 pix)
    RenderWindow window(VideoMode(660, 620), "Tetr.io");

    Clock clock;
    float timeFirst, timeSecond;

    // Включаем вертикальную синхронизацию (для плавной анимации)
    window.setVerticalSyncEnabled(true);

    // создаем поля
    Field *pFieldFirstPlayer = new Field(&window, 10, 10);
    Field *pFieldSecondPlayer = new Field(&window, 50 + WIDHT_FIELD, 10);

    //  создаем движущиеся фигуры для игроков
    Figure *pFigureFirstPlayer = new Figure(&window, 10, 10);
    Figure *pFigureSecondPlayer = new Figure(&window, 50 + WIDHT_FIELD, 10);
    pFigureFirstPlayer->init(rand() % 7, rand() % 7);
    pFigureSecondPlayer->init(rand() % 7, rand() % 7);

    int iSpeedMoveFirst = 500;
    int iSpeedMoveSecond = 500;
    int isPlayGame = 0;

    while (window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if(event.type == Event::Closed)
                window.close();
            if(event.type == Event::KeyPressed){
                if(event.key.code == Keyboard::Up){
                    pFigureFirstPlayer->rotate();
                } else if (event.key.code == Keyboard::Left || event.key.code == Keyboard::Right){
                    Point *pFigureMove = pFigureFirstPlayer->position();

                    if(event.key.code == Keyboard::Left){
                        if(pFieldFirstPlayer->isLeftMove(pFigureMove))
                            pFigureFirstPlayer->moveLeft();
                    } else {
                        if(pFieldFirstPlayer->isRightMove(pFigureMove))
                            pFigureFirstPlayer->moveRight();
                    }

                    delete pFigureMove;
                } else if(event.key.code == Keyboard::Down){ // опускаем фигуру по нажатию вниз
                    iSpeedMoveFirst = 20;

                    // второй игрок
                } else if(event.key.code == Keyboard::W){
                    pFigureSecondPlayer->rotate();
                } else if(event.key.code == Keyboard::A || event.key.code == Keyboard::D){
                    Point *pFigureMove = pFigureSecondPlayer->position();

                    if(event.key.code == Keyboard::A){
                        if(pFieldSecondPlayer->isLeftMove(pFigureMove))
                            pFigureSecondPlayer->moveLeft();
                    } else {
                        if(pFieldSecondPlayer->isRightMove(pFigureMove))
                            pFigureSecondPlayer->moveRight();
                    }

                    delete pFigureMove;
                } else if(event.key.code == Keyboard::S){
                    iSpeedMoveSecond = 20;
                }
            }
            if(event.type == Event::KeyReleased){
                if(event.key.code == Keyboard::S)
                    iSpeedMoveSecond = 500;
                else if(event.key.code == Keyboard::Down)
                    iSpeedMoveFirst = 500;
            }
        }

        // очистка экрана
        window.clear();

        // отрисовываем поля
        pFieldFirstPlayer->draw();
        pFieldSecondPlayer->draw();

        // получаем время в мсек
        timeFirst += clock.getElapsedTime().asMilliseconds();
        timeSecond += clock.getElapsedTime().asMilliseconds();
        clock.restart();

        if(isPlayGame == 0){
            // отрисовываем движущую фигуру
            pFigureFirstPlayer->draw();
            pFigureSecondPlayer->draw();

            // движение фигуры 1-го игрока
            if(timeFirst >= iSpeedMoveFirst){
                timeFirst = 0;

                // проверяем положение фигуры и если достигла низа фиксируем
                Point *pFigure = pFigureFirstPlayer->position();
                if(pFieldFirstPlayer->isNextMove(pFigure)){     // есть куда двигатся
                    pFigureFirstPlayer->move();
                } else {                                        // опустилась
                    pFieldFirstPlayer->figureSetMap(pFigure, pFigureFirstPlayer->color() + 1);
                    pFigureFirstPlayer->init(rand() % 7, rand() % 7);

                    // проверяем на целые линии
                    int countLine = pFieldFirstPlayer->findFullLine();
                    if(countLine != 0){
                        pFieldSecondPlayer->addLine(countLine);
                    }

                    // проверяем можно еще запускать фигуру
                    Point *pFigureNew = pFigureFirstPlayer->position();
                    if(!pFieldFirstPlayer->isNextMove(pFigureNew)){
                        // игра завершина
                        isPlayGame = 1;
                    }
                    delete pFigureNew;
                }
                delete pFigure;
            }

            // движение фигуры 2-го игрока
            if(timeSecond >= iSpeedMoveSecond){
                timeSecond = 0;

                // проверяем положение фигуры и если достигла низа фиксируем
                Point *pFigure = pFigureSecondPlayer->position();
                if(pFieldSecondPlayer->isNextMove(pFigure)){     // есть куда двигатся
                    pFigureSecondPlayer->move();
                } else {                                        // опустилась
                    pFieldSecondPlayer->figureSetMap(pFigure, pFigureSecondPlayer->color() + 1);
                    pFigureSecondPlayer->init(rand() % 7, rand() % 7);

                    // проверяем на целые линии
                    int countLine = pFieldSecondPlayer->findFullLine();
                    if(countLine != 0){
                        pFieldFirstPlayer->addLine(countLine);
                    }

                    // проверяем можно еще запускать фигуру
                    Point *pFigureNew = pFigureSecondPlayer->position();
                    if(!pFieldSecondPlayer->isNextMove(pFigureNew)){
                        // игра завершина
                        isPlayGame = 2;
                    }
                    delete pFigureNew;
                }
                delete pFigure;
            }
        } else {
            // вывод сообщения о завершении игры
            Font font;
            font.loadFromFile("font.ttf");

            Text text("", font, 50);
            text.setColor(Color::Red);
            text.setStyle(sf::Text::Bold | sf::Text::Underlined);

            std::ostringstream playerString;
            playerString << isPlayGame;

            text.setString("Player " + playerString.str() + " Game Over");
            text.setPosition(100 , 200);
            window.draw(text);
        }

        window.display();
    }

    return 0;
}
