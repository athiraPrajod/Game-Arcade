#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "inventory.h"
#include "location.h"
#include "utils.h"

static char input[100];

static int getInput()
{
   printf("\n--> ");
   return fgets(input, sizeof(input), stdin) != NULL;
}

static int parseAndExecute()
{
   char *verb = strtok(input, " \n");
   char *noun = strtok(NULL, " \n");
   //printf("|%s|   |%s|\n ", verb,noun);
   if (verb != NULL)
   {
      if (strcmp(verb, "quit") == 0)
        return 0;

      else if (strcmp(verb, "look") == 0)
        executeLook(noun);

      else if (strcmp(verb, "go") == 0)
        executeGo(noun);

      else if (strcmp(verb, "get") == 0)
         executeGet(noun);

      else if (strcmp(verb, "drop") == 0)
         executeDrop(noun);

      else if (strcmp(verb, "give") == 0)
         executeGive(noun);

      else if (strcmp(verb, "ask") == 0)
         executeAsk(noun);

      else if (strcmp(verb, "inventory") == 0)
         executeInventory();

      else if (strcmp(verb, "open") == 0)
         executeOpen(noun);
         
      else if (strcmp(verb, "close") == 0)
      {
         executeClose(noun);
      }
      else if (strcmp(verb, "lock") == 0)
      {
         executeLock(noun);
      }
      else if (strcmp(verb, "unlock") == 0)
      {
         executeUnlock(noun);
      }

      else
        printf("I don't know how to '%s'.\n", verb);
   }
   return 1;
}

void textAdv()
{
  system("clear");
  printf("Welcome to The Cave Adventure !!\n Instructions: This is a text adventure game. Navigate your way around using a verb, followed by a noun. Eg - go building (and not go to building)\n\n");
  executeLook("around");
  while (getInput() && parseAndExecute());
  printf("\nBye!\n");
}