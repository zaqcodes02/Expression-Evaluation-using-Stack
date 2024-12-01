#ifndef Queue_h
#define Queue_h
#include <iostream>

template <typename T>
struct Node
{
    T data;
    Node *next;
};

template <typename T>
class Queue
{
private:
    Node<T> *front;
    Node<T> *tail;

public:
    Queue();
    void enqueue(T);
    T dequeue();
    bool isNull();
    ~Queue();
};

#endif