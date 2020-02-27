# Genetic algorithm
* Generate a random string from `geneSet`

* A string in to a list

  `char list = " string"`
* generate a random number range from 0 to `lenOfGeneSet`

Behind every program, there should be a big framework for the algorithm, and small fractions.


## Lesson learned

* Better to know principles of compiler as much as possible.
  * compiling time and execution time
    ```c
    char geneSet[] = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!.";
    char password[] = "Hello World!";
    size_t lenOfPW = strlen(password);
    size_t lenOfGeneSet = strlen(geneSet);
    ```
    > The reason is that global variables are initialized in compiling time, and you are trying to initialize `lenOfPW` and `lenOfGeneSet` as an operation that must be done in execution time.

* `gcc -Wall`
