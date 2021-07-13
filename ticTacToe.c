#include<stdio.h>
#include<stdlib.h>
#include "utils.h"

char square[10] = {'0', '1', '2', '3', '4', '5', '6', '7','8','9'};
int choice, player;

int checkForWin();
void displayBoard();
void markBoard(char mark);

//check for draw must be included

void ticTacToe()
{
    int gameStatus;
    
    char mark;     //holds a variable character

    player = 1;
    do
    {
     displayBoard();

     //this is for changing turns
     player = (player%2) ? 1 : 2;

     //we need to get the input from the user
     printf("Player %d, enter a number:", player);
     scanf("%d", &choice);

     mark = (player == 1) ? 'X' : 'O';
    // set board on user choice or an invalid choice
     markBoard(mark);

     gameStatus = checkForWin ();
     if(gameStatus == 1)
     {
         printf("\nYou have won the game\n");
     }
     player ++;

     
    } while (gameStatus == -1);
}
/*FUNCTION TO RETURN GAME STATUS
1 FOR GAME IS OVER WITH RESULT
-1 FOR GAME IS IN PROGRESS
0/O GAME IS OVER AND NO RESULT*/

int checkForWin()
{
    char returnValue;

    if (square[1]== square[2] && square[2]== square[3])
    {
        returnValue = square[1];
    }
    else if (square[4]== square[5] && square[5]== square[6])
        returnValue = square[4];

    else if (square[7]== square[8] && square[8]== square[9])
        returnValue = square[7];

    else if (square[1]== square[4] && square[4]== square[7])
        returnValue = square[1];

    else if (square[2]== square[5] && square[5]== square[8])
    
        returnValue = square[2];

    else if (square[3]== square[6] && square[6]== square[9])
        returnValue = square[3];

    else if (square[3]== square[5] && square[5]== square[7])
        returnValue =square[3];

    else if (square[1]== square[5] && square[5]== square[9])
        returnValue =square[1];

    else if (square[1]!= '1' && square[2]!= '2' && square[3]!= '3' &&
    square[4]!= '4' && square[5]!= '5' && square[6]!='6' && square[7]!= '7'
    && square[8]!= '8' && square[9]!= '9')

        returnValue = 0;

    else
        returnValue = -1;
    return returnValue;                      
}

/* FUNCTION TO DRAW BOARD OF TIC TAC GAME WITH PLAYERS MARK*/

void displayBoard()
{
    //system("cls");
    printf("\n\n Tic Tac Toe\n\n");

    printf("Player 1 (X)- Player 2 (O)\n\n\n");

    printf("    |      |      \n");
    printf("  %c |  %c   |   %c\n", square[1], square[2], square[3]);

    printf("____|______|______\n");
    printf("    |      |      \n");

    printf(" %c  |  %c   |   %c \n", square[4], square[5], square[6]);

    printf("____|______|______\n");
    printf("    |      |      \n");

    printf(" %c  |  %c   |   %c \n", square[7], square[8], square[9]);

    printf("    |      |      \n\n");

}

/* set the board with the character, X or O in the correct sport in the array*/

void markBoard(char mark)
{
    if (choice==1 && square[1]== '1')
        square[1]= mark;

    else if (choice==2 && square[2]== '2')
        square[2]= mark;

    else if (choice==3 && square[3]== '3') 
        square[3]= mark;

    else if (choice==4 && square[4]== '4')
        square[4]= mark;

    else if (choice==4 && square[4]== '4')
        square[4]= mark;

    else if (choice==5 && square[5]== '5')
        square[5]= mark;
                     
    else if (choice==6 && square[6]== '6')
        square[6]= mark;

    else if (choice==7 && square[7]== '7')
        square[7]= mark;

    else if (choice==8 && square[8]== '8')
        square[8]= mark;

    else if (choice==9 && square[9]== '9')
        square[9]= mark;
    else
    {
        printf("Inavlid move\n");

        player--;
        getc(stdin);

    }    
        
} 

