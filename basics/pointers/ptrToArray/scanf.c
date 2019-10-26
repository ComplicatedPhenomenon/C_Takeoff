#include<stdio.h>
#include<malloc.h>

int main()
{
    char *str[3];
    int i;
    int num;
    for(i=0;i<3;i++){
	      printf("No of charecters in the word : \n");
	      scanf("%d",&num);
	      str[i]=(char *)malloc((num+1)*sizeof(char));
	      scanf("%s",str[i]);
    }

    for(i=0;i<3;i++){
        printf(" %s\n",str[i]);
    }
    return 0;
}
