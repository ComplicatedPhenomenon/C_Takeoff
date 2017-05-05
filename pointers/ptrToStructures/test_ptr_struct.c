#include<stdio.h>
#include<string.h>

typedef struct{
    float price;
    char  author[50];
    char  name[50];
}book;

int main()
{
    book book1 = {12.5, "Zed A. Shaw", "Learn C the hard way"};
    //the typedef means you no longer have to write struct all over the palace 
    book *ptr;

    ptr = &book1;
 
    /*use -> to access the element of sturcture*/
    printf("price = %f,\nauthor = %p,\nname = %p\n",ptr->price,ptr->author, ptr->name);
    printf("price = %f,\nauthor = %s,\nname = %s\n",ptr->price,ptr->author, ptr->name);
    /*indentation is not sensitive (\nname)*/

    return 0;
}
