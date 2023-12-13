#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int result = 0;
		for (int i = 1; i < prices.size(); i++) {
			result += max(prices[i] - prices[i - 1], 0);
		}
		return result;
	}
};

// 测试代码
int main() {
	Solution solution;
	vector<int> prices = { 7, 1, 5, 3, 6, 4 };

	int result = solution.maxProfit(prices);

	// 期望输出：7，因为可以在第2天买入（价格为1），第3天卖出（价格为5），第4天买入（价格为3），第5天卖出（价格为6），总利润为7
	cout << "最大利润为：" << result << endl;

	return 0;
}