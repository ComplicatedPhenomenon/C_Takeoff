//len(set(array1.split(" "))) = 100
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <stdbool.h>
#define NUMBER 100

int main(){
    srand(time(NULL));
    //printf("%d\n", RAND_MAX);
    int i, j, k, tem;
    bool ok ;
    int array1[NUMBER]={0};

    for(i =0; i<NUMBER; ++i){
        if(i == 0){
            tem = rand()% NUMBER + 1;
            array1[i] = tem;
        }
        else{
            ok =0;
            while(ok == 0){
                tem = rand()% NUMBER + 1;
                k = 0;
                for(j = 0; j < i; ++j) if (tem!= array1[j]) ++k;
                ok = k==i ? 1 : 0;
            }
            array1[i] = tem;
        }
    }

    for(i =0; i<NUMBER; ++i)printf("%d ", array1[i]);
    printf("\n");
    return 0;

}
