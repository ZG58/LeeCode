#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void reverseString(vector<char>& s) {
		for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--) {
			swap(s[i], s[j]);
		}
	}
};

int main()
{
	Solution solution;

    // 声明一个空的字符向量
    std::vector<char> str1;

    std::cout << "请输入字符串（按Enter键结束输入）: ";

    // 使用cin读取用户输入的字符，直到用户按Enter键
    char ch;
    while (std::cin.get(ch) && ch != '\n') {
        // 将字符添加到向量中
        str1.push_back(ch);
    }

    solution.reverseString(str1);

    // 输出应为 "olleh"
    for (char c : str1) {
        cout << c;
    }
    cout << endl;

	return 0;
}


