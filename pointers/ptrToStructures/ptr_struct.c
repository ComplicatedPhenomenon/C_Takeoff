#include<stdio.h>
#include<string.h>

typedef struct{
    float price;
    char  author[50];
    char  name[50];
}book;

int main()
{
    book book1; //the typedef means you no longer have to write struct all over the palace 

    book1.price = 15.6;
    strcpy(book1.author, "Zed A. Shaw");
    strcpy(book1.name ,"Learn C the hard way");

    printf("price = %f,\nauthor = %s,\nname = %s\n",book1.price,book1.author,book1.name);

    return 0;
}
