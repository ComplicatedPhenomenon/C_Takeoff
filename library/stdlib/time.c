#include<stdio.h>
#include<time.h>

int main() {  
   time_t now;
   time(&now);
   /*returns the current calendar time of the system as time since epoch*/
	 
   struct tm beg;  /*tm is a struct*/
   beg = *localtime(&now);

   printf("Constants in headerfile time.h\n");
   printf("%ld\n",CLOCKS_PER_SEC);
   printf("See the time manipulation function difftime.\n");
		 
   //set beg to the beginning of the month
   beg.tm_hour = 0;
   beg.tm_min = 0;
   beg.tm_sec = 0;
   beg.tm_mday = 1;
   double seconds = difftime(now,mktime(&beg)); 
   /**********************************************************************
    * Computes difference between two calendar times as time_t objects   *
    * (time_end - time_beg) in seconds. If time_end refers to time point *
    * before time_beg then the result is negative.                       *
    * mktime converts calendar time to time since epoch                  *
    * ********************************************************************/

   printf("%ld\n", time(NULL));
   printf("%.f seconds have passed since the beginning of the year.\n", seconds);

   return 0;
}
