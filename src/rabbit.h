#ifndef RABBIT_H
#define RABBIT_H

    typedef struct {
        char symbol;
        int type;  //0 = null,  1= rabbit,  2= carrot,  3 = obstacle
        int x;
        int y;
    } Element;

    typedef struct{
        char name[12];
        int points;
        int size;
    }Player;

    void printGrid(Element **grid, int gridSize);

    int randomNumber(int start, int end);

    int checkSame(int x, int y, Element elementos[], int count);

    Element* crearElementos(int gridSize);

    Player startGame(int gridSize, char* nameP);

    void printPlayers(Player* pList);

#endif