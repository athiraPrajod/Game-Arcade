typedef enum {
   distPlayer,
   distHeld,
   distHeldContained,
   distLocation,
   distHere,
   distHereContained,
   distOverthere,
   distNotHere,
   distUnknownObject,
   distNoObjectSpecified
} DISTANCE;

extern DISTANCE distanceTo(OBJ *obj);   
extern OBJ *parseObject(const char *noun);
extern OBJ *personHere(void);
extern int listObjectsAtLocation(OBJ *location);
extern OBJ *getPassageTo(OBJ *targetLocation);