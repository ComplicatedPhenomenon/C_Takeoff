#ifndef _object_h
#define _object_h

typedef enum {
    NORTH, SOUTH, EAST, WEST
} Direction;

typedef struct {
    char *description;
    int (*init)(void *self);
    void (*describe)(void *self);
    void (*destroy)(void *self);
    void *(*move)(void *self, Direction direction);
    int (*attack)(void *self, int damage);
} Object;

int Object_init(void *self);          /* self is pointer pointing to void type */
void Object_destroy(void *self);
void Object_describe(void *self);
void *Object_move(void *self, Direction direction);  /* Object_move is a pointer poining to a function??? */
int Object_attack(void *self, int damage);
void *Object_new(size_t size, Object proto, char *description);

#define NEW(T,N) Object_new(sizeof(T), T##Proto, N)
/*****
 * #define new(T,N) This statement construct a macro.  What you write on the RHS will expand as LHS
 *                                                                                              ****/

#define _(N) proto.N   
/***********
 *  It can simplify obj->proto.blah 
 *  as obj->_(blah). Just an abstract 
 *  prototype. different but similar 
 *  with `typedef`
 *                                    ********/
#endif

