#include "rabbit.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

void printGrid(Element **grid, int gridSize){
    for(int i = 0; i< gridSize; i++){
        for(int j = 0; j< gridSize; j++){
            printf(" %c ", grid[i][j].symbol );
        }
        printf("\n");
    }
}

int randomNumber(int start, int end){


    int randomNumber = rand() % ((end-1) - start + 1) + start;

    return randomNumber;
}

int checkSame(int x, int y, Element elementos[], int count) {
    for (int i = 0; i < count; i++) {
        if (elementos[i].x == x && elementos[i].y == y) {
            return 1; // Coordinates are already in the array
        }
    }
    return 0; // Coordinates are not in the array
}

Element* crearElementos(int gridSize){
    Element* elementos = malloc(6 * sizeof(Element));

    for (int i = 0; i < 6; i++)
    {
        int x, y;
        int repeated = 1;
        while(repeated){
            
            x = randomNumber(0, gridSize);
            y = randomNumber(0, gridSize);
            repeated = checkSame(x, y, elementos, i);
        }
        elementos[i].x = x;
        elementos[i].y = y;

        switch (i+1){
        case 1:
            elementos[i].symbol = 'R';
            elementos[i].type = 1;
        break;

        case 2:
            elementos[i].symbol = 'C';
            elementos[i].type = 2;
        break;
        
        default:
            elementos[i].symbol = 'O';
            elementos[i].type = 3;
        break;
        }
    }
    

    return elementos;
}


Player startGame(int gridSize, char* nameP){
    Element empty = {.symbol = '-', .type = 0};
    
    srand(time(NULL));

    //asigning grid memory
    Element **grid = malloc(gridSize * sizeof(Element *));

    for(int i = 0; i < gridSize; i++){
        grid[i] = malloc(gridSize * sizeof(Element));
    }
    //filling grid with null values
    

    Element* elementos = crearElementos(gridSize);
    /* //debugging
    for (int i = 0; i < 6; i++)
    {
        printf("%c ", elementos[i].symbol);
        printf("%d %d \n", elementos[i].x, elementos[i].y);
    }*/
    
    printf("\n");
    int puntos = 0;
    for(int turns = 0; turns < gridSize + gridSize; turns++){
        printf("Turno %d de %d: \n", turns+1, gridSize*2);

        puntos = pow(2, turns);

        for(int i = 0; i< gridSize; i++){
            for(int j = 0; j< gridSize; j++){
                grid[i][j] = empty;
            }
        }

        for (int i = 0; i < 6; i++){
            int x = elementos[i].x;
            int y = elementos[i].y;

            grid[x][y] = elementos[i];
        }

        //printing grid
        printGrid(grid, gridSize);
        printf("\n");

        int movement = 1;
        
        while (movement){
            char dir;
            scanf("%c", &dir);

            switch (dir){
            case 'w':
                if (elementos[0].y+1 <gridSize && !checkSame(elementos[0].x-1, elementos[0].y, elementos, 6)){
                    elementos[0].x--;
                    movement = 0;
                }else if(checkSame(elementos[0].x-1, elementos[0].y, elementos, 6) && grid[elementos[0].x-1][elementos[0].y].symbol == 'O'){
                    printf("colision \n");
                }else{
                    printf("carrot\n");
                    turns += gridSize*2;
                    movement = 0;
                }
                
            break;

            case 's':
                if (elementos[0].y+1 <gridSize && !checkSame(elementos[0].x+1, elementos[0].y, elementos, 6)){
                    elementos[0].x++;
                    movement = 0;
                }else if(checkSame(elementos[0].x+1, elementos[0].y, elementos, 6) && grid[elementos[0].x + 1][elementos[0].y].symbol == 'O'){
                    printf("colision \n");
                }else {
                    printf("carrot\n");
                    turns += gridSize*2;
                    movement = 0;
                }
                
            break;

            case 'a':
                if (elementos[0].y+1 <gridSize && !checkSame(elementos[0].x, elementos[0].y-1, elementos, 6)){
                    elementos[0].y--;
                    movement = 0;
                }else if(checkSame(elementos[0].x, elementos[0].y-1, elementos, 6) && grid[elementos[0].x][elementos[0].y-1].symbol == 'O'){
                    printf("colision \n");
                }else{
                    printf("carrot\n");
                    turns += gridSize*2;
                    movement = 0;
                }
                
            break;

            case 'd':
                if (elementos[0].y+1 <gridSize && !checkSame(elementos[0].x, elementos[0].y+1, elementos, 6)){
                    elementos[0].y++;
                    movement = 0;
                }else if(checkSame(elementos[0].x, elementos[0].y+1, elementos, 6) && grid[elementos[0].x][elementos[0].y+1].symbol == 'O'){
                    printf("colision \n");
                }else{
                    printf("carrot\n");
                    turns += gridSize*2;
                    movement = 0;
                }
                
            break;
            
            default:
            break;
            }
        }

        printf("puntos: %d\n", puntos);
    }

    printf("game over :b\n");
    
    //freeing memory
    for (int i = 0; i < gridSize; i++) {
        free(grid[i]);
    }
    free(grid);

    free(elementos);

    Player p = {
        .points = puntos,
        .size = gridSize,
    };
    strcpy(p.name, nameP);

    return p;
}

void printPlayers(Player* pList){
    for (int i = 0; i < 12; i++){

        if(pList[i].name[0] != '\0'){
            printf("\n--------\n");
            printf("name: %s\n", pList[i].name);
            printf("points: %d\n", pList[i].points);
            printf("grid size: %d\n", pList[i].size);
            printf("--------\n");
        }
    }
    
}

