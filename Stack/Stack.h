#include <iostream>
#include <vector>

template <class T>
class Stack {
	std::vector <T> v;
    int top;
    const int max_size;
    public :
	    Stack(const int &size):v(size),top(-1),max_size(size){}
	    //push
		void push(const T &item);
		//pop
		void pop();
		//getTop
		const T getTop();
		//isEmpty
		bool isEmpty();
};

