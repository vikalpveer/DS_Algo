#include "LinkedList.h"

template <class T>
Node<T>::Node(T val):data(val), next(NULL){}

template <class T>
Node<T>* Node<T>::getNext() const {
    return this->next;
}

template <class T>
const T Node<T>::getData() const{
    return this->data;
}

template <class T>
void Node<T>::setNext(Node<T>*n) {
    this->next = n;
}


template <class T>
LinkedList<T>::LinkedList():HEAD(NULL){}

template <class T>
void LinkedList<T>::appendEnd(const T &val) {
    Node <T>*temp = new Node<int>(val);

    if(HEAD == NULL) {
        HEAD = temp;
        return;
    }

    Node<T> *plist = HEAD;
    Node<T> *nnode = plist;

    while(plist) {
        nnode = plist->getNext();
        if(nnode) {
            plist = nnode;
        }else {
            plist->setNext(temp);
            break;
        }
    }
}

template <class T>
void LinkedList<T>::print() const {
    const Node<T> *plist = HEAD;
    while(plist) {
        std::cout << plist->getData() << "->";
        plist = plist->getNext();
    }
    std::cout <<"NULL \n";
}


int main() {
    LinkedList<int> list;
    list.appendEnd(1);
    list.appendEnd(2);
    list.appendEnd(3);
    list.appendEnd(4);
    list.print();
}    


