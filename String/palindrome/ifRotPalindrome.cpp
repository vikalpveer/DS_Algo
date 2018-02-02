#include <iostream>
#include <string>

class Palindrome {
    const std::string S;
    public:
        Palindrome(std::string s);
        bool isRotatedPalindrome();
        bool isPalindrome(std::string s, int start, int end);
};


Palindrome::Palindrome(const std::string s):S(s){}

bool Palindrome::isPalindrome(std::string s, int start, int end) {
    int s_size = s.size();
    if(s_size == 0 || start >= end) {
        return true;
    }
    if(s.at(start) == s.at(end)) {
        return isPalindrome(s, start + 1, end - 1);
    }else {
        return false;
    }
}


bool Palindrome::isRotatedPalindrome() {
    int s_size = S.size();

    std::string temp = S;

    for(int i = 0; i < s_size; i++) {
        if(isPalindrome(temp, 0, s_size - 1)) {
            return true; 
        }
        else {
            std::cout << temp << " is not a palindrome. Let's try ";
            temp = temp.substr(1,s_size - 1) + temp.substr(0,1);
            std::cout << temp << "\n";
        }
    }
    return false;
}


int main() {
    Palindrome P("aaaadb");
    bool t = P.isRotatedPalindrome();

    if(t) {
        std::cout << "string is rotated palindrome \n";
    }else {
        std::cout << "string is NOT a rotated palindrome \n";
    }
}
