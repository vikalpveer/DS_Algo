#include "Stack.h"
#include <iostream>
#include <vector>

// 1 2 3 
//
// 3 2 1
template <class T>
class Queue {
    Stack <T> S;
    public:
         Queue(int size);
         void enqueue(const T val);
         T dequeue();
};

template <class T>
Queue<T>::Queue(int size) :S(size){}

template <class T>
void Queue<T>::enqueue(T val) {
    S.push(val);
}

template <class T>
T Queue<T>::dequeue() {

    if(S.isEmpty()) {
        std::cout<<"Empty Queue \n";
        return -1;
    }

    T val = S.getTop();
    S.pop();
    if(!S.isEmpty()) {
        T temp = dequeue();
        S.push(val);
        return temp;
    }
    return val;
}


int main() {

    std::cout<<"\n";

    Queue<int> q(10);
    q.enqueue(2);
    q.enqueue(1);
    int t = q.dequeue();
    std::cout <<"Q entry is "<< t <<"\n";
}
