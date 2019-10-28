/**
 *   Modified Date: 9/12/2018    DD/MM/YYYYY
 *   Description:
 **/
#include<stdio.h>
#include<string.h>

typedef struct{
    float price;
    char  author[50];
    char  name[50];
}book;

int main() {
    book book1; //the typedef means you no longer have to write struct all over the palace
    book1.price = 15.6;
    strcpy(book1.author, "Zed A. Shaw");
    strcpy(book1.name ,"Learn C the hard way");
    book book2 = {12.5, "Zed A. Shaw", "Learn C the hard way"};
    book *ptr;
    ptr = &book2;

    printf("price = %f $,\nauthor = %s,\nname = %s\n",book1.price,book1.author,book1.name);
    // use '->'' to access the element of sturcture
    printf("price = %f,\nauthor = %p,\nname = %p\n",ptr->price,ptr->author, ptr->name);
    printf("price = %f,\nauthor = %s,\nname = %s\n",ptr->price,ptr->author, ptr->name);

    return 0;
}
