#ifndef STACK_H
#define STACK_H
#include "Stack.h"

template <class T>
void Stack<T>::push(const T&item) {
	 if(top == max_size - 1) {
		 std::cout <<"Stack Overflow\n";
		 return;
	 }
	 v[++top] = item;
}


template <class T>
void Stack<T>::pop() {
	if (top == -1) {
		std::cout <<"Stack underflow \n";
		return;
	}
	top--;
}
template <class T>
const T Stack<T>::getTop() {
    return v[top];
}

template <class T>
bool Stack<T>::isEmpty() {
	if(top == -1) {
		return true;
	}else {
		return false;
	}
}
template class Stack<int>;
#endif
