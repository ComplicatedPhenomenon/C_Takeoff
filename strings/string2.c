#include<stdio.h>

int main()
{
    char arrayofstring[5][50];
    int i;
    for(i = 0; i < 3; i++){
	scanf("%s\n",arrayofstring[i]);
    }

    for(i = 0; i < 3; i++){
	printf(">%s\n",arrayofstring[i]);
    }

	return 0;
}

