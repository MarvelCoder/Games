#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

#define MAX_ROW 3
#define MAX_COL 3
#define HUMAN 'X'
#define CPU 'O'
#define GAMESPEED 2

void drawemptygrids(); // On start draws an empty grid
void gameengine();// Controls the whole game
void printgamestate();// Prints the current board
char checkgamestate();// Checks for winner/loser
int whowon(char ch);// Reports who won
void playermove();// Player Chance
void cpumove();// CPU Chance

char arr[MAX_ROW][MAX_COL]={};
char wonby='\0';

void main(){

    drawemptygrids();
    gameengine();
    if(wonby==HUMAN){
        printf("Congratulations On Your Lucky Win, Human.");
    }else if(wonby==CPU){
        printf("You Lose Human.");
    }
}

void drawemptygrids(){

    for(int row=0;row<MAX_ROW;row++){
        printf("  ");
        for(int col=0;col<MAX_COL;col++){
            if(col==MAX_COL-2){
                printf("|%d %d|",row,col);
            }else{
                printf("%d %d",row,col);
            }
        }
        printf("\n");
        printf("  ");
        if(row<MAX_ROW-1){
            printf("---+---+---");
        }
        printf("\n");
    }

}

void gameengine(){

    while(checkemptygrids()){
        playermove();
        if(checkgamestate()!='\0'){
            break;
        }
        printgamestate();
        sleep(GAMESPEED);
        cpumove();
        if(checkgamestate()!='\0'){
            break;
        }
        printgamestate();
    }

    printgamestate();
}

void playermove(){

    int row,col,keepasking=1;

    while(keepasking){
        printf("Enter your move human = ");

        scanf("%d%d",&row,&col);

        if(arr[row][col]!='\0'){
            printf("Please enter another move as this location is already filled.\n");
        }else{
            arr[row][col]=HUMAN;
            break;
        }
    }
}

void cpumove(){

    int row,col,lower=0,upper=2,cputhinking=1;

 /*   for(int row=0;row<MAX_ROW;row++){
        for(int col=0;col<MAX_COL;col++){
            if(arr[row][col]=='\0'){
                arr[row][col]=CPU;
                return 0;
            }
        }
    }
*/
    // AI LOGIC
    while(cputhinking){
        row = (rand() % (upper - lower + 1)) + lower;
        col = (rand() % (upper - lower + 1)) + lower;

        if(arr[row][col]!='\0'){
            printf("CPU thinking another move as [%d][%d] is already filled.\n",row,col);
        }else{
            printf("CPU makes move on [%d][%d].\n",row,col);
            arr[row][col]=CPU;
            break;
        }
    }
}

int checkemptygrids(){

    int emptygridnum=0;

    for(int row=0;row<MAX_ROW;row++){
        for(int col=0;col<MAX_COL;col++){
            if(arr[row][col]=='\0'){
                //printf("[%d][%d] is empty\n",row,col);
                emptygridnum++;
            }
        }
    }
    return emptygridnum;
}

void printgamestate(){

    for(int row=0;row<MAX_ROW;row++){
        printf("  ");
        for(int col=0;col<MAX_COL;col++){
            if(col==MAX_COL-1){
                printf("%c",arr[row][col]);
            }else{
                printf("%c|",arr[row][col]);
            }
        }
        printf("\n");
        printf("  ");
        if(row<MAX_ROW-1){
            printf("-+-+-");
        }
        printf("\n");
    }

}

char checkgamestate(){

    if(whowon(HUMAN)){
        wonby = HUMAN;
        return wonby;
    }else if(whowon(CPU)){
        wonby = CPU;
        return wonby;
    }

    return wonby;
}


int whowon(char ch){

    int gamefinished = 0;

    for(int row=0;row<MAX_ROW;row++){
        for(int col=0;col<MAX_COL;col++){
            if(row==0 && col==0){
                if(arr[row][col]==ch && arr[row][col+1]==ch && arr[row][col+2]==ch){
                    gamefinished=1;
                    return gamefinished;
                }else if(arr[row][col]==ch && arr[row+1][col]==ch && arr[row+2][col]==ch){
                    gamefinished=1;
                    return gamefinished;
                }else if(arr[row][col]==ch && arr[row+1][col+1]==ch && arr[row+2][col+2]==ch){
                    gamefinished=1;
                    return gamefinished;
                }
            }else if(row==0 && col==1){
                if(arr[row][col]==ch && arr[row+1][col]==ch && arr[row+2][col]==ch){
                    gamefinished=1;
                    return gamefinished;
                }
            }else if(row==0 && col==2){
                if(arr[row][col]==ch && arr[row+1][col]==ch && arr[row+2][col]==ch){
                    gamefinished=1;
                    return gamefinished;
                }else if(arr[row][col]==ch && arr[row+1][col-1]==ch && arr[row+2][col-2]==ch){
                    gamefinished=1;
                    return gamefinished;
                }
            }else if(row==1 && col==0){
                if(arr[row][col]==ch && arr[row][col+1]==ch && arr[row][col+2]==ch){
                    gamefinished=1;
                    return gamefinished;
                }
            }else if(row==2 && col==0){
                if(arr[row][col]==ch && arr[row][col+1]==ch && arr[row][col+2]==ch){
                    gamefinished=1;
                    return gamefinished;
                }
            }
        }
    }

    return gamefinished;
}
