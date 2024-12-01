#ifndef Stack_h
#define Stack_h
#include <iostream>
template <typename T>
struct Node
{
    T data;
    Node *next;
};

template <typename T>
class Stack
{
private:
    Node<T> *top;

public:
    Stack();
    Stack(T data);
    void push(T data);
    T pop();
    T getTop() const;
    bool isEmpty() const;
    ~Stack();
};

#endif