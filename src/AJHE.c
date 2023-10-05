#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rabbit.h"

int main(){
    printf("---RABBIT GAME--- \n");

    int GAME = 1;
    int gridSize;
    Player* playerList = malloc(sizeof(Player)*12);

    Player empty = {.name = '\0'};

    for (int i = 0; i < 12; i++) {
        playerList[i] = empty;
    }

    while (GAME){

        
        char playerName[12];

        printf("Insert your name: ");
        scanf("%s", playerName);
        printf("\n");
    
        Player p;

        printf("Insert the size of the grid (low numbers might end up in bugs): ");
        scanf("%d", &gridSize);
        printf("\n");

        if (gridSize == 0) {
            GAME = 0; // Exit the loop if gridSize is 0
        } else {
            p = startGame(gridSize, playerName);
            printf("%s\n", p.name);

            for (int i = 0; i < 12; i++){
                if (playerList[i].name[0] == '\0') {
                    playerList[i] = p;
                    
                    break;
                }
            }

        }

        printPlayers(playerList);
        
    }
    free(playerList);
}