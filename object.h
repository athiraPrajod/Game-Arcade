typedef struct object {
   const char    *description;
   const char    **tags;
   struct object *location;
   struct object *destination;
   const char  *(*open)(struct object *);
   const char  *(*close)(struct object *);
   const char  *(*lock)(struct object *);
   const char  *(*unlock)(struct object *);
}OBJ;

extern OBJ objs[];

#define field      (objs + 0)
#define cave       (objs + 1)
#define silver     (objs + 2)
#define gold       (objs + 3)
#define guard      (objs + 4)
#define player     (objs + 5)
#define intoCave   (objs + 6)
#define exitCave   (objs + 7)
#define wallField  (objs + 8)
#define wallCave   (objs + 9)
#define backroom   (objs + 10)
#define openDoorToBackroom   (objs + 11)
#define closedDoorToBackroom   (objs + 12)

#define endOfObjs  (objs + 10)