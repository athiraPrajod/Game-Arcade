// #include "object.h"

// static void swapLocations(OBJ *obj1, OBJ *obj2)
// {
//    OBJ *tmp = obj1->location;
//    obj1->location = obj2->location;
//    obj2->location = tmp;
// }

// const char *cannotBeOpened(OBJ *obj)    { return "That cannot be opened.\n";    }
// const char *cannotBeClosed(OBJ *obj)    { return "That cannot be closed.\n";    }
// const char *cannotBeLocked(OBJ *obj)    { return "That cannot be locked.\n";    }
// const char *cannotBeUnlocked(OBJ *obj)  { return "That cannot be unlocked.\n";  }

// const char *isAlreadyOpen(OBJ *obj)     { return "That is already open.\n";     }
// const char *isAlreadyClosed(OBJ *obj)   { return "That is already closed.\n";   }
// const char *isAlreadyLocked(OBJ *obj)   { return "That is already locked.\n";   }
// const char *isAlreadyUnlocked(OBJ *obj) { return "That is already unlocked.\n"; }

// const char *isStillOpen(OBJ *obj)       { return "That is still open.\n";       }
// const char *isStillLocked(OBJ *obj)     { return "That is still locked.\n";     }

// const char *toggleBackdoor(OBJ *obj)
// {
//    swapLocations(openDoorToBackroom, closedDoorToBackroom);
//    swapLocations(openDoorToCave, closedDoorToCave);
//    return "OK.\n";
// }

// const char *toggleBox(OBJ *obj)
// {
//    swapLocations(openBox, closedBox);
//    return "OK.\n";
// }

// const char *toggleBoxLock(OBJ *obj)
// {
//    if (keyForBox->location == player)
//    {
//       swapLocations(closedBox, lockedBox);
//       return "OK.\n";
//    }
//    else
//    {
//       return "You don't have a key.\n";
//    }
// }