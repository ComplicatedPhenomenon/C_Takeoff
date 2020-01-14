* [CPP framework](https://en.cppreference.com/w/)


## Remove confusions
*  [Difference between header file and library file in c++](https://stackoverflow.com/questions/924485/whats-the-difference-between-a-header-file-and-a-library)

    > It's the fundamental difference between "interface" and "implementation"; the interface (header) tells you how to call some functionality (without knowing how it works), while the implementation (library) is the actual functionality.


## Warning from `Bjarne Stroustrup`
> A traditional set of exercises is designed to test your initiative, cleverness, or inventiveness. In contrast, a drill requires little invention from you. Typically, sequencing is crucial, and each individual step should be easy (or even trivial). Please don’t try to be clever and skip steps; on average that will slow you down or even confuse you.

> You might think you understand everything you read and everything your Mentor or instructor told you, but repetition and practice are necessary to develop programming skills. In this regard, programming is like athletics, music, dance, or any skill-based craft. Imagine people trying to compete in any of those fields without regular practice. You know how well they would perform. Constant practice — for professionals that means lifelong constant practice — is the only way to develop and maintain a high-level practical skill.

## Concepts comprehension
### `new` and `malloc` 
The main advantage of new over `malloc()` is that new doesn't just allocate memory, it constructs objects which is prime purpose of C++.

### `new` and `delete`
### usage
`new` will have the corresponding constructor called.

```cpp
double* pvalue  = NULL; // Pointer initialized with null

pvalue  = new double;   // Request memory for the variable
*pvalue = 29494.99;     // Store value at allocated address
cout << "Value of pvalue : " << *pvalue << endl;

delete pvalue;    

double** pvalue  = NULL;      // Pointer initialized with null 
pvalue  = new double [3][4];  // Allocate memory for a 3x4 array 
delete [] pvalue;            // Delete array pointed to by pvalue
```
Dynamic Memory Allocation for Objects