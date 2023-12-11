#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//class Solution {
//public:
//	int findContentChildren(vector<int>& g, vector<int>& s) {
//		sort(g.begin(), g.end());
//		sort(s.begin(), s.end());
//
//		int index = 0;
//		for (int i = 0; i < s.size(); i++) {
//			if (index < g.size() && g[index] <= s[i]) {
//				index++;
//			}
//		}
//		return index;
//	}
//};

class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());

		int index = s.size() - 1;
		int result = 0;
		for (int i = g.size() - 1; i >= 0; i--) {
			if (index >= 0 && s[index] >= g[i]) {
				index--;
				result++;
			}
		}
		return result;
	}
};

int main() {
	Solution solution;
	vector<int> g = { 1, 2, 3 };
	vector<int> s = { 1, 1 };

	int result = solution.findContentChildren(g, s);

	// 期望输出：1，因为只有第一个孩子的胃口可以被满足
	cout << "满足孩子的数量为：" << result << endl;

	return 0;
}