#include<stdio.h>

int main(int mw, char *wm[]){
/* mainly is main function, so argc *argv[] can be replaced */      
    
    int ages[] = {28, 43, 12, 89, 2};
    char * names[] = {"Alan", "Frank", "Mary", "John", "Lisa"};

    int count = sizeof (ages) / sizeof(int);
    int i;
    for(i = 0; i < count ; i++){
        printf("%s has %d years alive.\n", names[i],ages[i]);
    }

    printf("_________________________\n");
    
    int *cur_age = ages;
    char ** cur_name = names;
    for(i = 0; i < count; i++){
        printf("%s is %d years old\n",*(cur_name+i),*(cur_age+i));
    }
/* cur_age 整个是计算机内存地址的具体地址，给它加一之后指向下一个地址 
* cur_age表示地址中所存放的内容，这里存放的内容整型数据。 * cur_name 中存
放的是 字符型数组的地址。 ** cur_name 才指向所存储地址对应的内容  */
    printf("________________________\n");
    int number[] = {28, 43, 12, 89, 2};
    printf(": %p\n", (void*)&number);
    int p = 0;
    int b = 6;
    for(p = 0; p < b; p++){
         printf(":%p\n%d\n",(void*)&number+p,number[p]);
    }
    char array[16];
    printf("%p\t%p\n",(void*)&array, (void*)(&array+1));
    return 0;
}
