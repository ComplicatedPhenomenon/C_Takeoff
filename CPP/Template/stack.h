#ifndef STACK_H
#define STACK_H
#include <vector>
template <typename T>
class Stack{
private:
    std::vector<T> elems;
public:
    void push(T const &);
    void pop();
    T top()const;
    bool empty()const;
};
#endif
