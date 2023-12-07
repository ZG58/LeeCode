#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void replaceNumbers(string& s) {
        int count = 0;
        int sOldSize = s.size();
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                count++;
            }
        }
        s.resize(s.size() + count * 5);
        int sNewSize = s.size();
        for (int i = sNewSize - 1, j = sOldSize - 1; j < i; i--, j--) {
            if (s[j] > '9' || s[j] < '0') {
                s[i] = s[j];
            }
            else {
                s[i] = 'r';
                s[i - 1] = 'e';
                s[i - 2] = 'b';
                s[i - 3] = 'm';
                s[i - 4] = 'u';
                s[i - 5] = 'n';
                i -= 5;
            }
        }
    }
};

int main() {
    Solution solution;

    string testString;
    while (cin >> testString) {
        solution.replaceNumbers(testString);
        cout << testString << endl;
    }

    return 0;
}