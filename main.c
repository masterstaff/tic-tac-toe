#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void display(int game[]) {
    char game2[9];
    for (int i = 0;i<9;i++){
        if (game[i] == 1)
            game2[i] = 'X';
        else if (game[i] == -1)
            game2[i] = 'O';
        else
            game2[i] = ' ';
    }
    printf("%c|%c|%c\n-----\n%c|%c|%c\n-----\n%c|%c|%c\n",game2[0],game2[1],game2[2],game2[3],game2[4],game2[5],game2[6],game2[7],game2[8]);
} 


void main() {
    int cse = 1;
    int player = 1;
    bool running = true;
    int game[9] = {0,0,0,0,0,0,0,0,0};
    while (running) {
        display(game);
        if (player == 1){
            printf("It's for X to play\n");
        } else {
            printf("It's for O to play\n");
        }
        printf("choose the case you want to play (0-8)\n");
        scanf("%d", &cse);
        if (game[cse] == 0) {
            game[cse] = player;
            player *= -1;
        }

        for (int i = 0; i<3; i++){
            if ((game[i*3] == game[i*3+1]) &&
                (game[i*3] == game[i*3+2]) &&
                (game[i*3] != 0)){
                    
                running = false;
                player = game[i*3];
            } else if ((game[i] == game[i+3]) &&
                (game[i] == game[i+6]) &&
                (game[i] != 0)){

                running = false;
                player = game[i];
            }
        }
        if (((game[0]==game[4]) &&
            (game[4] == game[8]) &&
            (game[4] != 0)) ||
            ((game[2]==game[4]) &&
            (game[4] == game[6]) &&
            (game[4] != 0))){

            running = false;
            player = game[4];
        }
        system("cls");
    }
    if (player == 1){
        printf("X wins ");
    }else{
        printf("O wins");
    }
    scanf("%d",&cse);
    
}