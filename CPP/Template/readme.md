```sh
$ g++ -Wall stack.cpp action.cpp
```

It went wrong!!!

## Template usage
> A templating language basically is a language which allows defining placeholders that should later on be replaced for the purpose of implementing designs. Obviously modern template languages not only support placeholders, but also loops and conditions which are often necessary for designing a web page. Some even support more advanced but still useful techniques like template inheritance, macros and sandboxing.

* function template
  ```cpp
  //模板类，实例化模板类必须指定参数类型，编译器无法为模板类自动推导类型
  template<typename T> 
  class Test_class{
  public:
      explicit A(T val){ }
          T add(T x){ 
              return t+y;
          }

  private:
      T t;
  };

  int main(){
      A<int> a(10)；
      std::cout<<a.add(5)<<std::endl;
      return 0;
  }
  ```

* function template

  You don't need to specify the type of 2 numbers, whether the caparison is between the 2 float or 2 integers.Because we create a template function with `myType` as its template argument. This template arguments represent a type that yet has been specified, but that can be used in the template function as if it were a regular type.

  ```c++
  Template <class myType>
  myType getMax(myType a, myType b){
      return(a > b ? a : b);
  }
  ```

## How template argument deduction works
[How class template argument deduction works?](https://youtu.be/STJExxBU54M)

```c++
// C+98:
std::pair<std::string, int> p1("THX", 1138);

// C+11:
auto p2 = std::make_pair("THX", 1138);
// deduces std::pair<const char*, int>

// C++14:
using namespace std::literals::string_literals;
auto p3 = std::make_pair("THX"s, 1138);
//deduces std::make_pair<std::string, int>

// C+17
std::pair p4{"THX"s, int};
// deduces std::pair<std::string, int>
```

## What's more?
1. `inline` function
   * http://www.cplusplus.com/articles/2LywvCM9/
2. `const` function
