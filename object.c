#include <stdio.h>
#include "object.h"


static const char *tags0[] = {"field", NULL};
static const char *tags1[] = {"cave", NULL};
static const char *tags2[] = {"silver", "coin", "silver coin", NULL};
static const char *tags3[] = {"gold", "coin", "gold coin", NULL};
static const char *tags4[] = {"guard", "burly guard", NULL};
static const char *tags5[] = {"yourself", NULL};
static const char *tags6[] = {"east", "entrance", NULL};
static const char *tags7[] = {"west", "out", NULL};
static const char *tags8[] = {"west", "north", "south", "forest", NULL};
static const char *tags9[] = {"east", "north", "south", "rock", NULL};
static const char *tags10[] = {"backroom", NULL};
static const char *tags11[] = {"south", "door", "doorway", NULL};
static const char *tags12[] = {"south", "door", "doorway", NULL};

OBJ objs[] = 
{
   {"an open field"              , tags0, NULL , NULL, "The field is a nice and quiet place under a clear blue sky.\n"},
   {"a little cave"              , tags1, NULL , NULL, "The cave is just a cold, damp, rocky chamber.\n" },
   {"a silver coin"              , tags2, field, NULL, "The shiny coin seems to be a rare and priceless artefact.\n" },
   {"a gold coin"                , tags3, cave , NULL, "The shiny coin seems to be a rare and priceless artefact.\n" },
   {"a burly guard"              , tags4, field, NULL, "The guard is a really big fellow.\n" },
   {"yourself"                   , tags5, field, NULL, "You would need a mirror to look at yourself.\n" },
   {"a cave entrance to the east", tags6, field, cave, "You would need a mirror to look at yourself.\n" },
   {"a way out to the west"      , tags7, cave , field, "Sunlight pours in through an opening in the cave's wall.\n" },
   {"dense forest all around"    , tags8, field, NULL, "The field is surrounded by trees and undergrowth.\n" },
   {"solid rock all around"      , tags9, cave , NULL, "Carved in stone is a secret password 'abcba'.\n" },
   {"a backroom", tags10, NULL, NULL, "The room is dusty and messy\n"},
   {"an open door to the south", tags11, backroom, NULL, "The door is open"},
   {"a closed door to the south", tags12, cave, NULL, "The door is closed\n"}
   
};