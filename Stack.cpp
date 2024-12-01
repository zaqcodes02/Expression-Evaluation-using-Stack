#include "Stack.h"
#include <stdexcept>

template <typename T>
Stack<T>::Stack()
{
    top = nullptr;
}

template <typename T>
Stack<T>::Stack(T data)
{
    top = new Node<T>;
    top->data = data;
    top->next = nullptr;
}

template <typename T>
void Stack<T>::push(T data)
{
    Node<T> *newNode = new Node<T>;
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

template <typename T>
T Stack<T>::pop()
{
    if (isEmpty())
    {
        std::cerr << "Error: Stack is Empty!" << std::endl;
        throw std::out_of_range("Stack is empty");
    }

    Node<T> *toDelete = top;
    top = top->next;
    T data = toDelete->data;
    delete toDelete;

    return data;
}

template <typename T>
bool Stack<T>::isEmpty() const
{
    return top == nullptr;
}

template <typename T>
T Stack<T>::getTop() const
{
    if (isEmpty())
    {
        std::cerr << "Error: Stack is Empty!" << std::endl;
        throw std::out_of_range("Stack is empty");
    }

    return top->data;
}

template <typename T>
Stack<T>::~Stack()
{
    while (!isEmpty())
    {
        pop();
    }
}

template class Stack<int>;
template class Stack<double>;
template class Stack<float>;
template class Stack<char>;
