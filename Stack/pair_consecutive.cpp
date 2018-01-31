//Wirte a program to chheck if array elements are pairwise consecutive
//The pairs can be increasing or decreasing, and if the stack has an odd 
//number of elements, the element at the top is left out of a pair. 
//The function should retain the original stack content.


#include "Stack.h"

int main () {
	std::vector <int> v;

	v.push_back(1);
	v.push_back(2);

	Stack<int> S(v.size());

	for(int i = v.size() -1; i >=0; i-- ){
		S.push(v[i]);
	}

	while(!S.isEmpty()) {

	    int temp = S.getTop();
	    S.pop();
	    if(!S.isEmpty() && (temp == S.getTop() -1 || temp == S.getTop() + 1)) {
	        std::cout <<"Pair Exists :"<<temp <<":"<<S.getTop() << "\n";
			S.pop();
	    }else {
			if(!S.isEmpty()) {
			    std::cout <<"Pair does not exist \n";
			}
			return 0;
		}
	}
}

