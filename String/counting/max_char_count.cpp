//Return maximum occurring character in an input string
//https://www.geeksforgeeks.org/return-maximum-occurring-character-in-the-input-string/
//

#include <iostream>
#include <string>
#include <map>


int main() {
	std::string s;
	std::cout <<"Enter the string :"; std::cin >> s;

	if (s.size() == 0) {
		std::cout << "This is an empty string \n";
	}

	std::map<char, int> m;
	int max = 0;
	char max_char;
	for(int i = 0; i < s.size(); i++) {
		m[s.at(i)]++;
		if(m[s.at(i)] > max) {
			 max = m[s.at(i)];
			 max_char = s.at(i);
		}
	}
	if(max) {
		std::cout <<"\n The max Char is : "<< max_char << "\n";
	}
}
	
