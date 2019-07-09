#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <stdbool.h>

#define ELEMENTSNUMBER 100


int main(){
    srand(time(NULL));
    //printf("%d\n", RAND_MAX);
    int i, j, k, tem;
    bool temIsAvailable ;
    int array[ELEMENTSNUMBER]={0};
    for(i = 0; i<3; ++i)printf("%d ", array[i]);
    printf("\n");

    for(i =0; i<ELEMENTSNUMBER; ++i){

        if(i == 0){
            tem = rand()% ELEMENTSNUMBER + 1;
            array[i] = tem;
        }
        else if(i!=0 && i < 20){
            temIsAvailable =0;
            while(temIsAvailable == 0){
                tem = rand()% ELEMENTSNUMBER + 1;
                k = 0;
                for(j = 0; j < i; ++j){
                    if (tem!= array[j]) ++k;
                }
                temIsAvailable = k==i+1 ? 1 : 0;
                //if(temIsAvailable==0)printf("conflication\n");
            }
            array[i] = tem;
        }
        else{
            array[i]= rand()% ELEMENTSNUMBER + 1;
        }
    }
    for(i =0; i<ELEMENTSNUMBER; ++i)printf("%d ", array[i]);
    printf("\n");
    return 0;

}
