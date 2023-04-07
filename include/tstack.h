    // Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_
#include <string>

template<typename T, int size>
class Stack {
 private:
    T arr[100];
    int top;

 public:
    Stack() :top(-1) {}
    void push(T value) {
        if (isFull()) {
            throw std::string("Stack is full");
        } else {
            arr[++top] = value;
        }
    }
    const T& Pop() {
        if (isEmpty()) {
            throw std::string("Stack is empty");
        } else {
            return arr[top--];
        }
    }
    bool isEmpty()const {
        return top == -1;
    }
    bool isFull()const {
        return top == size - 1;
    }
    const T& Get()const {
        return arr[top];
    }
};

#endif    // INCLUDE_TSTACK_H_
