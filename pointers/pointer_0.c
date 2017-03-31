#  define a pointer point to an array instead of integer

#include<stdio.h>

int main(){
	char names[] = {"Frank","Rogen","Alan","Mary","Lisa"};
	int ages[] = {12, 5, 3, 9, 2};

	int i;
	for(i = 0;i < 5; i++){
		printf("%s is %d years old\n",names[i],ages[i]);
	}
	
	return 0;
}

