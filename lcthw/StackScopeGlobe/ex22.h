#ifndef _ex22_h
#define _ex22_h

extern int THE_SIZE;
//make THE_AGE available to other .c files.

int get_age();
void set_age(int age);
//get and set an internal variable in ex22.c

//updates a static variable that's inside update_ratio
double	update_ratio(double ratio);
void	print_size();
#endif
