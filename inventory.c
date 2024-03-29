#include <stdio.h>
#include "object.h"
#include "misc.h"
#include "inventory.h"

static void moveObject(const char *noun, OBJ *from, OBJ *to)
{
   OBJ *obj = parseObject(noun);
   if (obj == NULL)
   {
      printf("I don't understand what item you mean.\n");
   }
   else if (from != obj->location)
   {
      switch (distanceTo(obj))
      {
      case distPlayer:
         printf("You should not be doing that to yourself.\n");
         break;

      case distHeld:
         printf("You already have %s.\n", obj->description);
         break;

      case distLocation:
      case distOverthere:
         printf("That's not an item.\n");
         break;

      case distHere:
         if (from == player)
         {
            printf("You have no %s.\n", noun);
         }
         else
         {
            printf("Sorry, %s has no %s.\n", from->description, noun);
         }
         break;
      case distHeldContained:
      case distHereContained:
         printf("Sorry, %s is holding it.\n", obj->location->description);
         break;
         
      default:
         printf("You don't see any %s here.\n", noun);
      }
   }
   else if (to == NULL)
   {
      printf("There is nobody here to give that to.\n");
   }
   else
   {
      obj->location = to;
      printf("OK.\n");
   }
}

void executeGet(const char *noun)
{
   moveObject(noun, player->location, player);
}

void executeDrop(const char *noun)
{
   moveObject(noun, player, player->location);
}

void executeGive(const char *noun)
{
   moveObject(noun, player, personHere());
}

void executeAsk(const char *noun)
{
   moveObject(noun, personHere(), player);
}

void executeInventory(void)
{
   if (listObjectsAtLocation(player) == 0)
   {
      printf("You are empty-handed.\n");
   }
}





