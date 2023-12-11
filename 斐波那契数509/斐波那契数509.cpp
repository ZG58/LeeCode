#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//	int fib(int n) {
//		if (n <= 1) return n;
//		int dp[2];
//		dp[0] = 0;
//		dp[1] = 1;
//		for (int i = 2; i <= n; i++) {
//			int sum = dp[0] + dp[1];
//			dp[0] = dp[1];
//			dp[1] = sum;
//		}
//		return dp[1];
//	}
//};

class Solution {
public:
	int fib(int n) {
		if (n < 2) return n;
		return fib(n - 1) + fib(n - 2);
	}
};

// 测试代码
int main() {
	Solution solution;

	// 测试1
	int result1 = solution.fib(5);
	// 期望输出：5，对应斐波那契数列的第5个数为 5
	cout << "第5个斐波那契数为：" << result1 << endl;

	// 测试2
	int result2 = solution.fib(10);
	// 期望输出：55，对应斐波那契数列的第10个数为 55
	cout << "第10个斐波那契数为：" << result2 << endl;

	return 0;
}