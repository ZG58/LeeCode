#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    bool isAnagram1(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }

    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        int charCount[26] = {};

        for (char c : s) {
            charCount[c - 'a']++;
        }

        for (char c : t) {
            if (charCount[c - 'a'] > 0) {
                charCount[c - 'a']--;
            }
            else {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;

    assert(solution.isAnagram("anagram", "nagaram") == true);
    assert(solution.isAnagram("rat", "car") == false);
    assert(solution.isAnagram("listen", "silent") == true);
    assert(solution.isAnagram("hello", "world") == false);

    cout << "All test cases passed!" << endl;

    return 0;
}