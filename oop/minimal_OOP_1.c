#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef struct phone
{ 
/* field */
    char   * company; 
    char    * series;
    float       cost;
/* method */
    void (*word)(void);  /* Detail1: void * word (void) */ 
} Phone;

void method(void)
{
    printf("Hello!!!\n");
}

/* Detail1 may be affected by Phone  * creat_phone(...) */
Phone  * creat_phone(char *cp, char *ba, float cs) 
/* A pointer which store the address of function <creat_phone> */
{
    Phone *p1 = malloc(sizeof(Phone));
    assert(p1 != NULL);
    p1->company = cp;
    p1->series  = ba;
    p1->cost    = cs;
    p1->word    = &method;
    
    return p1;
}

int main(int argc, char argv[])
{
    Phone *HW=creat_phone("HUAWEI","P9",2999) ;
    HW->word();
    
    return 0;
}



	  

