#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//	int minCostClimbingStairs(vector<int>& cost) {
//		vector<int> dp(cost.size() + 1);
//		dp[0] = 0;
//		dp[1] = 0;
//		for (int i = 2; i <= cost.size(); i++) {
//			dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
//		}
//		return dp[cost.size()];
//	}
//};

class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		int dp0 = 0;
		int dp1 = 0;
		for (int i = 2; i <= cost.size(); i++) {
			int dpi = min(dp1 + cost[i - 1], dp0 + cost[i - 2]);
			dp0 = dp1;
			dp1 = dpi;
		}
		return dp1;
	}
};

int main()
{
	Solution solution;
	vector<int> cost = { 10, 15, 20 };

	int result = solution.minCostClimbingStairs(cost);

	cout << "爬到楼顶的最小花费是:" << result << endl;

	return 0;
}