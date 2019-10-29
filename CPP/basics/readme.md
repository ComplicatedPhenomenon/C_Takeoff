## Which compiler?
` g++ -Wall detectCapital.cpp `

## namespace
* `using namespace std` is considered bad practice

  Because you can have 2 function have same name belongs 2 namespace.
## ` std::string`
parameters of class `string`
* member function (method)
  * operator =
  * assign
  * get_allocator
  * Element access
    * ...
  * Iterators
    * ...
  * capacity
    * ...
  * Operations
    * clear clears the contents (public member function)
    * insert inserts characters (public member function)
    * erase
    * push_back

    * pop_back
    * append
    * operator+=
  * Search
    * ...

After comparing the way of OOP in with C, which has a more explicit style, don't you see that our efficiency for production goes high under one programming paradigm? It wraps up the universal operations and expand the library, so you don't need to do it again.

## `std::basic_string`

  The templated class `std::basic_string` generalizes how sequences of characters are manipulated and stored. String creation, manipulation, and destruction are all handled by a convenient set of class methods and related functions.

  Several specializations of std::basic_string are provided for commonly-used types:
  * `std::string`
  * `std::wstring`
  * `std::U16stsring`
  * ...

-------
1. Why are `ifndef` and `define` are used in C++ header files
  * http://www.fredosaurus.com/notes-cpp/preprocessor/ifdef.html

2. how to separate implementation and declarations code of a simple class into a new header and cpp file?
  * https://www.learncpp.com/cpp-tutorial/89-class-code-and-header-files/

  `g++ -Wall owl.cpp detect.cpp`

## data structure
Vectors are sequence containers which utilize continuous storage locations to store elements. They can manage storage and grow dynamically in an efficient way. These abilities come at a price: vectors consume more memory in exchange for the ability to handle storage and growing dynamically in size.

https://www.geeksforgeeks.org/advantages-of-vector-over-array-in-c/

### vector的底层实现？
> vector的数据安排以及操作方式，与array非常类似，两者唯一的区别是空间运用的灵活性，array是静态空间，一旦配置了就不能改变，如果你想要大一点的空间，就必须首先配置一块新空间，然后将原来的元素一一复制进来，再把原来的空间释放给系统。但是vector是动态空间，随着元素的增加，它的内部机制会自行扩充空间以容纳新元素，因此vector的运用对于内存的合理利用与运用的灵活性有很大的帮助，我们再也不必因为害怕空间不足而一开始要求一个大块头的array了，我们可以安心使用vector，随便使用多大空间都可以

> vector的实现技术，关键在于其对大小的控制以及重新配置时的数据移动效率，一旦vector的旧有空间满载，如果客户端每新增一个元素，vector的内部只是扩充一个元素的空间，实为不智，因为所谓扩充空间，都是配置新空间，复制原来内容，释放旧空间所需要的时间很多，那么应该怎样配置空间呢?

> 并且vector维护的是一个连续线性空间，所以支持vector随机存取。

### map和set的底层数据结构是什么，为什么使用红黑树？
> Map是关联容器，以键值对的形式进行存储，方便进行查找，关键词起到索引的作用，值则表示与索引相关联的数据，以红黑树的结构实现，插入删除等操作都可以在O(log n)时间内完成

> Set是关联容器，set中每个元素都只包含一个关键字，set支持高效的关键字查询操作—检查每一个给定的关键字是否在set中，set是以红黑树的平衡二叉检索树结构实现的，支持高效插入删除，插如元素的时候会自动调整二叉树的结构，使得每个子树根节点键值大于左子树所有节点的键值，小于右子树所有节点的键值，另外还得保证左子树和右子树的高度相等。
