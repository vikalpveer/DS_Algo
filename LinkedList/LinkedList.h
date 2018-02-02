#include <iostream>

// Link list consist of nodes.
template <class T>
class Node {
    const T data;
    Node <T> *next;
    public:
        Node(T val);
        Node<T>* getNext()const ;
        void setNext(Node<T> *n);
        const T getData()const;
};

template <class T>
class LinkedList {
     Node<T> *HEAD;
    public:
        LinkedList();
        void appendEnd(const T &val);
        void print() const;
};
