> Pointers allow a way to write functions that can modify their arguments' values: the C way of implementing Pass by Reference.


# Object, name
Variable name, a pointer to a reference target

[pass by assignment vs pass by reference](https://stackoverflow.com/a/986145/7583919)
* Pros and cons for each approach.
* Proper occasion to use each approach.


> In compiled languages, a variable is a memory space that is able to capture the value of the type. In Python, a variable is a name (captured internally as a string) bound to the reference variable that holds the reference value to the target object. The name of the variable is the key in the internal dictionary, the value part of that dictionary item stores the reference value to the target.


There are no variables in Python. The key to understanding parameter passing is to stop thinking about "variables". There are names and objects in Python and together they appear like variables, but it is useful to always distinguish the three.

* Python has names and objects.
* Assignment binds a name to an object.
* Passing an argument into a function also binds a name (the parameter name of the function) to an object.
