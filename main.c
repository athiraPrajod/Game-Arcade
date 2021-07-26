#include<stdio.h>
#include<stdlib.h>
#include "utils.h"
#include <unistd.h>

void main()
{
    while(1)
    {
        system("clear");
        printf("WELCOME TO OUR GAME ARCADE !\n");
        printf("Enter -\n1. to play hangman\n2. to play the text adventure\n3. to play tic tac toe\n4. to exit\n\n");

        int choice;
        scanf("%d", &choice);
        if(choice!=4)
        {
            switch (choice)
            {
            case 1:
                hangman();
                sleep(3);
                break;
            
            case 2:
                textAdv();
                break;

            case 3:
                ticTacToe();
                break;

            default:
                printf("Invalid choice");
                scanf("%d", &choice);
            }

            // printf("Do you want to play again? Enter y or n\n");
            // char ch = 'y';

        }
        else
            break;
    }

}