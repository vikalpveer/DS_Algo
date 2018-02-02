//C++ program to check if the given string is a palindrome or not.
//https://github.com/vikalpveer/DS_Algo.git
//
//
//
#include <iostream>
#include <string>
#include <map>
class Palindrome {
    std::string S;
    public:
        Palindrome(std::string s);
        bool isPalindrome();
        bool ifPalindrome(std::string s, int start, int end);
};


Palindrome::Palindrome(std::string s):S(s){}

bool Palindrome::isPalindrome() {
    int s_size = S.size();
    if(s_size == 0) {
        return true;
    }
    return ifPalindrome(S, 0, s_size -1);
}

bool Palindrome::ifPalindrome(std::string S, int start, int end) {
    if(end <= start ) {
        return true;
    }
    if(S.at(start) != S.at(end)) {
        return false;
    }
    return ifPalindrome(S,start + 1, end - 1);
}


int main() {
    std::string S  = "AACAA";
    Palindrome P(S);
    bool t = P.isPalindrome();
    std::cout <<"Result : "<<t <<"\n";
}

