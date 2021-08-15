#include <stdio.h>
#include <string.h>
#include "object.h"
#include "misc.h"

//#define numberOfLocations   (sizeof(locs) / sizeof(*locs))
//const int numberOfLocations = (sizeof(locs)/sizeof(*locs));

static unsigned locationOfPlayer = 0;

void executeLook(const char *noun)
{
   if (noun != NULL && strcmp(noun, "around") == 0)
   {
      printf("You are in %s.\n", player->location->description);
      listObjectsAtLocation(player->location);
   }
   else
   {
      printf("I don't understand what you want to see.\n");
   }
}

void executeGo(const char *noun)
{
   OBJ *obj = parseObject(noun);
   DISTANCE distance = distanceTo(obj);

   if (distance >= distUnknownObject)
   {
      printf("I don't understand where you want to go.\n");
   }
   else if (distance == distLocation)
   {
      printf("You are already there.\n");
   }
   else if (distance == distOverthere)
   {
      printf("OK.\n");
      player->location = obj;
      executeLook("around");

      //printf("*noun is %s\n", noun);
      if(strcmp(noun, "cave") == 0)
      {
         int c = 0;
         printf("A wooden box\n");
         while(1)
         {
            char input[100];
            
            printf("\n--> ");
            fgets(input, sizeof(input), stdin);
            char *verb = strtok(input, " \n");
            char *noun = strtok(NULL, " \n");
            if (strcmp(verb, "open") == 0 && strcmp(noun, "box") == 0 && c != 2)
            {
               printf("You need to give the box a gold and a silver coin to open it.");
               break;
            }
            else if(strcmp(verb, "give") == 0 && strcmp(noun, "gold") == 0)
            {
               printf("OK."); c++;
            }
            else if(strcmp(verb, "give") == 0 && strcmp(noun, "silver") == 0)
            {
               printf("OK."); c++;
            }

            if(strcmp(verb, "open") == 0 && strcmp(noun, "box") == 0 && c == 2)
            {
               printf("Congrats! You have managed to navigate this text adventure successfully!! The treasure you find here is yours to collect :)");
               printf("You have won the game. Type 'quit' to exit");
               break;
            }
         }
      }
   }
   else if (distance == distHere && obj->destination != NULL)
   {
      printf("OK.\n");
      player->location = obj->destination;
      executeLook("around");
   }
   else if (distance < distNotHere)
   {
      printf("You can't get any closer than this.\n");
   }
   else
   {
      printf("You don't see any %s here.\n", noun);
   }  
}

static int objectWithinReach(const char *verb, OBJ *obj, const char *noun)
{
   int ok = 0;
   DISTANCE distance = distanceTo(obj);
   if (distance > distNotHere)
   {
      printf("I don't understand what you want to %s.\n", verb);
   }
   else if (distance == distNotHere)
   {
      printf("You don't see any %s here.\n", noun);
   }
   else if (distance >= distHereContained)
   {
      printf("That is out of reach.\n");
   }
   else
   {
      ok = 1;
   }
   return ok;
}

void executeOpen(const char *noun)
{
   OBJ *obj = parseObject(noun);
   if (objectWithinReach("open", obj, noun))
   {
      printf("%s", (*obj->open)(obj));
   }
}

void executeClose(const char *noun)
{
   OBJ *obj = parseObject(noun);
   if (objectWithinReach("close", obj, noun))
   {
      printf("%s", (*obj->close)(obj));
   }
}

void executeLock(const char *noun)
{
   OBJ *obj = parseObject(noun);
   if (objectWithinReach("lock", obj, noun))
   {
      printf("%s", (*obj->lock)(obj));
   }
}

void executeUnlock(const char *noun)
{
   OBJ *obj = parseObject(noun);
   if (objectWithinReach("unlock", obj, noun))
   {
      printf("%s", (*obj->unlock)(obj));
   }
}
