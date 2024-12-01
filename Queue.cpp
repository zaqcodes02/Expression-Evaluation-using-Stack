#include "Queue.h"

template <typename T>
Queue<T>::Queue()
{
    front = nullptr;
    tail = nullptr;
}

template <typename T>
void Queue<T>::enqueue(T data)
{
    Node<T> *newNode = new Node<T>;
    newNode->data = data;
    newNode->next = nullptr;
    if (isNull())
    {
        front = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

template <typename T>
T Queue<T>::dequeue()
{
    if (isNull())
    {
        throw std::underflow_error("Queue is empty!");
    }

    Node<T> *toDelete = front;
    T deleteVal = toDelete->data;
    front = front->next;

    if (front == nullptr)
    {
        tail = nullptr;
    }

    delete toDelete;
    return deleteVal;
}

template <typename T>
bool Queue<T>::isNull()
{
    return front == nullptr;
}

template <typename T>
Queue<T>::~Queue()
{
    while (!isNull())
    {
        dequeue();
    }
}

template class Queue<int>;
template class Queue<char>;
template class Queue<float>;
template class Queue<double>;