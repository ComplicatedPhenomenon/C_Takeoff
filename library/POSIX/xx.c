// Necessarity of return
#include<stdio.h>

void *print_message_func_1(void *ptr);
void print_message_func_2(void *ptr);

int main(){
    char *x = "String"; // 'String' is wrong!
    print_message_func_1(x);
    print_message_func_2(x);
    return 0;

}
void *print_message_func_1(void *ptr){
    for(int i=0;i<5;++i){
        printf("%s:%d\n",(char*)ptr,i);
    }
    return NULL;
}

void print_message_func_2(void *ptr){
    for(int i=0;i<5;++i){
        printf("%s:%d\n",(char*)ptr,i);
    }
}
