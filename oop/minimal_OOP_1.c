#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef struct phone
{
    char   *company;
    char    *series;
    float     cost;
    void (*word)(void);  /* Detail1: void * word (void) */
} Phone;

void method(void)
{
    printf("Hello!!!\n");
}

// Why pointer is used so often?
Phone  * phone_create(char *cp, char *ba, float cs)
/* A pointer which store the address of function <creat_phone> */
{
    Phone *p1 = malloc(sizeof(Phone));
    assert(p1 != NULL);
    p1->company = cp;
    printf("%s Made it\n", cp);
    p1->series  = ba;
    p1->cost    = cs;
    p1->word    = &method;

    return p1;
}

void destroy_phone(Phone *a_phone){
    assert(a_phone != NULL);
    free(a_phone);
}


int main(int argc, char *argv[])
{
    Phone *HW=phone_create("Huawei Technologies","Mate 10", 2999);
    HW->word();
    free(HW);

    return 0;
}
