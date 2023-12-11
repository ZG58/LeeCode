#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		if (n <= 1) return n;
		vector<int> dp(n + 1);
		dp[1] = 1;
		dp[2] = 2;
		for (int i = 3; i <= n; i++) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[n];
	}
};

// 测试代码
int main() {
	Solution solution;

	// 测试1
	int result1 = solution.climbStairs(5);
	cout << "第5个斐波那契数为：" << result1 << endl;

	// 测试2
	int result2 = solution.climbStairs(10);
	cout << "第10个斐波那契数为：" << result2 << endl;

	return 0;
}