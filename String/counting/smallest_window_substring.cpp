//Find the smallest window in a string containing all characters of another string
//Given two strings string1 and string2, find the smallest substring in string1 containing all characters of string2 efficiently.
//https://www.geeksforgeeks.org/find-the-smallest-window-in-a-string-containing-all-characters-of-another-string/
//
//


// this is a test string 
// pattern : tist
// Brute Force :  

#include <iostream>
#include <string>
#include <map>

bool compare(std::map<char, int> s, std::map<char, int> p) {
    std::map<char, int>::iterator it = s.begin();

    for(it; it != s.end(); it++) {

        while(p[it->first] && s[it->first]) {
            p[it->first]--;
            s[it->first]--;
        }
    }
    for(it = p.begin(); it != p.end(); it++) {
        if(p[it->first] != 0) {
            return false;
        }
    }
    return true;
}
    
void find_smallest_window(const std::string s, const std::string p, int &max_length, std::string &res) {
    int s_size = s.size();
    int p_size = p.size();

    if(s_size == 0 || p_size == 0) {
        return;
    }
    std::map<char, int> p_map;

    for (int i = 0; i < p_size; i++) {
        p_map[p.at(i)]++;
    }

    bool init = false;
    int start_index = 0;
    int end_index = 0;

    std::map<char, int> s_map;

    // first matching index;
    for(int i = 0; i < s_size; i++) {
        if(p_map.find(s.at(i)) == p_map.end()) {
            continue;
        }else {
            if(!init) {
                init = true;
                start_index = i;
            }
            s_map[s.at(i)]++;
            if(compare(s_map, p_map)) {
                end_index = i; 
                break;
            }
        }
    }
    if(end_index == 0 || start_index == s_size - 1) {
        return;
    }
    if(end_index - start_index + 1 < max_length) {
        max_length = end_index - start_index + 1;
        res = s.substr(start_index, max_length);
        std::cout <<"String found :"<< res <<" of len :"<< max_length <<"\n";
    }

    find_smallest_window(s.substr(start_index + 1), p, max_length, res);
    return;
}

int main() {
    //std::string s = "this is a test string";
    //std::string p = "tist";
    std::string s = "geeksforgeeks";
    std::string p = "ork";
    int max_length = 999999;
    std::string res ;
    find_smallest_window(s, p, max_length, res);
    std::cout <<"The smallest string windows is:"<< res <<"\n";

}
