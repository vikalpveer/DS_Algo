#include "Stack/Stack.h"

int main() {
	Stack<int> S(2);
	S.push(1);
	std::cout <<S.getTop() <<"\n";
}
