#include <stdio.h>
#include "object.h"
#include "toggle.h"


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
   {"an open field"  , tags0   , NULL , NULL  },
   {"a little cave"  , tags1    , NULL , NULL  },
   {"a silver coin"  , tags2  , field, NULL  },
   {"a gold coin"    , tags3    , cave , NULL  },
   {"a burly guard"  , tags4   , field, NULL  },
   {"yourself"       , tags5, field, NULL  },
   {"a cave entrance to the east", tags6 , field, cave, isAlreadyOpen  },
   {"a way out to the west"      , tags7     , cave , field, isAlreadyOpen },
   {"dense forest all around", tags8, field, NULL},
   {"solid rock all around", tags9, cave, NULL},
   {"a backroom", tags10, NULL,NULL, NULL},
   {"an open door to the south", tags11, backroom, NULL, NULL, NULL, NULL, NULL},
   {"a closed door to the south", tags12, cave, NULL, toggleBackdoor, isAlreadyClosed, NULL, NULL},
   {"an open door to the north", tags13, cave, NULL, isAlreadyOpen, toggleBackdoor, NULL, NULL},


};