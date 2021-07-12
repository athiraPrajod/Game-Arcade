#include "object.h"

extern const char *cannotBeOpened(OBJ *obj);
extern const char *cannotBeClosed(OBJ *obj);
extern const char *cannotBeLocked(OBJ *obj);
extern const char *cannotBeUnlocked(OBJ *obj);

extern const char *isAlreadyOpen(OBJ *obj);
extern const char *isAlreadyClosed(OBJ *obj);
extern const char *isAlreadyLocked(OBJ *obj);
extern const char *isAlreadyUnlocked(OBJ *obj);

extern const char *isStillOpen(OBJ *obj);
extern const char *isStillLocked(OBJ *obj);

extern const char *toggleBackdoor(OBJ *obj);
extern const char *toggleBox(OBJ *obj);
extern const char *toggleBoxLock(OBJ *obj);