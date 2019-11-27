## Which compiler?
` g++ -Wall -std=c++11 detectCapital.cpp `

macro

1. Why are `ifndef` and `define` are used in C++ header files
  * http://www.fredosaurus.com/notes-cpp/preprocessor/ifdef.html

compile and link

2. how to separate implementation and declarations code of a simple class into a new header and cpp file?
  * https://www.learncpp.com/cpp-tutorial/89-class-code-and-header-files/

  `g++ -Wall owl.cpp detect.cpp`
## namespace
* `using namespace std` is considered bad practice

  Because you can have 2 function have same name belongs 2 namespace.

## reference vs pointer
要确切理解区别的话，需要理解它的底层实现，编译器执行时的操作。这里仅限于上层理解。

<span style="font-family: New York Times; font-size: 1.3em; color: red;">
What reference is used for?
</span> 

example
* `referenceVSPointer_0.cpp`
* `referenceVSPointer.cpp`
* `array.cpp`

In an reference variable is passed into a function, the function works on the original copy (instead of a clone copy in pass-by-value). Changes inside the function are reflected outside the function.

 ![](https://www.mathwarehouse.com/programming/images/pass-by-reference-vs-pass-by-value-animation.gif)


以常量引用来修饰函数的输入参数，input 是个输入参数，在函数内部不会被改变，此时用常量引用就是最合适的：
* 一不会在调用函数的时候拷贝一遍 input
* 二在函数内部使用方便
* 三从调用函数的地方看过去，`NormalizeBigString(string_a, &string_b)`，单凭语法就能清楚的区分输入和输出参数，可读性更好。


<span style="font-family: New York Times; font-size: 1.2em; color: red;">

</span>

Why does C++ have both pointers and references?
> C++ inherited pointers from C, so I couldn't remove them without causing serious compatibility problems. References are useful for several things, but the direct reason I introduced them in C++ was to support operator overloading.

When to use reference?


*Use reference wherever you can, pointers wherever you must.*

Moreover, the efficiency of transporting  matters
* 通过传递引用而不是整个数据–对象，可以提高程序的运行速度
* 程序员能修改调用函数中的数据对象


### Reference
* https://www.ntu.edu.sg/home/ehchua/programming/cpp/cp4_PointerReference.html
## data structure
Vectors are sequence containers which utilize continuous storage locations to store elements. They can manage storage and grow dynamically in an efficient way. These abilities come at a price: vectors consume more memory in exchange for the ability to handle storage and growing dynamically in size.

https://www.geeksforgeeks.org/advantages-of-vector-over-array-in-c/

### vector的底层实现？
> vector的数据安排以及操作方式，与array非常类似，两者唯一的区别是空间运用的灵活性，array是静态空间，一旦配置了就不能改变，如果你想要大一点的空间，就必须首先配置一块新空间，然后将原来的元素一一复制进来，再把原来的空间释放给系统。但是vector是动态空间，随着元素的增加，它的内部机制会自行扩充空间以容纳新元素，因此vector的运用对于内存的合理利用与运用的灵活性有很大的帮助，我们再也不必因为害怕空间不足而一开始要求一个大块头的array了，我们可以安心使用vector，随便使用多大空间都可以.

> vector的实现技术，关键在于其对大小的控制以及重新配置时的数据移动效率，一旦vector的旧有空间满载，如果客户端每新增一个元素，vector的内部只是扩充一个元素的空间，实为不智，因为所谓扩充空间，都是配置新空间，复制原来内容，释放旧空间所需要的时间很多，那么应该怎样配置空间呢?

> 并且vector维护的是一个连续线性空间，所以支持vector随机存取。

### map和set的底层数据结构是什么，为什么使用红黑树？
> Map是关联容器，以键值对的形式进行存储，方便进行查找，关键词起到索引的作用，值则表示与索引相关联的数据，以红黑树的结构实现，插入删除等操作都可以在O(log n)时间内完成

> Set是关联容器，set中每个元素都只包含一个关键字，set支持高效的关键字查询操作—检查每一个给定的关键字是否在set中，set是以红黑树的平衡二叉检索树结构实现的，支持高效插入删除，插如元素的时候会自动调整二叉树的结构，使得每个子树根节点键值大于左子树所有节点的键值，小于右子树所有节点的键值，另外还得保证左子树和右子树的高度相等。

## [Container](https://en.cppreference.com/w/cpp/container)
### array
* 2D array initialization.

    https://stackoverflow.com/questions/15520880/initializing-entire-2d-array-with-one-value

    Initialize all elements to a same value.

    * for an array, the compiler will initialize every value you don't specify with 0.

## [keywords](https://en.cppreference.com/w/cpp/keyword)

1. `const`,  use it as much as possible when the data-object is read-only, protect the object from being modified. 