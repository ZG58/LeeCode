#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	string reverseStr(string s, int k) {
		for (int i = 0; i < s.size(); i += (2 * k)) {
			if (i + k <= s.size()) {
				reverse(s.begin() + i, s.begin() + i + k);
			}
			else {
				reverse(s.begin() + i, s.end());
			}
		}
		return s;
	}
};

int main()
{
    Solution solution;

    // 用户输入测试字符串
	cout << "请输入字符串:";
	string testString;
	cin >> testString;

    // 用户输入 k 的值
	cout << "请输入整数:";
	int k;
	cin >> k;

    // 调用 reverseStr 函数进行测试
    string result = solution.reverseStr(testString, k);

    // 打印结果
    cout << "原始字符串: " << testString << endl;
    cout << "反转后的字符串: " << result << endl;

    return 0;
}