#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {
		if (nums.size() == 1) return 0;
		int curDistance = 0;
		int ans = 0;
		int nextDistance = 0;
		for (int i = 0; i < nums.size(); i++) {
			nextDistance = max(nums[i] + i, nextDistance);
			if (i == curDistance) {
				ans++;
				curDistance = nextDistance;
				if (nextDistance >= nums.size() - 1) break;
			}
		}
		return ans;
	}
};

int main()
{
	Solution solution;
	cout << "请输入一个整数数组（回车键结束）：" << endl;

	vector<int> nums;
	int num;

	while (cin >> num && cin.get() != '\n') {
		nums.push_back(num);
	}

	int result = solution.jump(nums);
	cout << "跳到终点的最小步数是：" << result << endl;

	return 0;
}