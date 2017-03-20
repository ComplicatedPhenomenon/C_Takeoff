what's the difference between debug and compile?

Compile is the act of turning human-readable codeinto the code machine can  underatand and executre.
Debug is the act of finding out where in the code the application is going  wrong (debug = get rid of bugs)
In the context of an IDE,compile (Build in Visual Studio) just builds the   code, debug (Run in Visual studio) compiles the code, launches it and       attaches a debugger.



what's the difference between following functions:
int main()
int main(void)
int main(int argc, char * *argv[] *)

the difference is :
int main()

- [] a function that expects unknow number of arguments of unknwn types. Return  an integer representing the application software status.

int main(void)

- [] a function that expects no arguments. Return an integer representing the    application software status.

int main(int argc, char *argv[])

- [] a function that expects argc number of arguments and argv[] arguments.      Return an integer representing the application software status.



About when using each of the functions
int main()

-[] you need to use this function when your program needs no initial parametes
  to run/load (parameters received from the OS - out of the program itself)

int main (int argc, char *argv[])

- [] you need to use this function when your program needs initial parameters     to load (parameters received from the OS - out of the program itself)
