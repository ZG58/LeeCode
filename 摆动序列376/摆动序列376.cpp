#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		if (nums.size() <= 1) return nums.size();
		int curDiff = 0;
		int preDiff = 0;
		int result = 1;
		for (int i = 0; i < nums.size() - 1; i++) {
			curDiff = nums[i + 1] - nums[i];
			if ((preDiff <= 0 && curDiff > 0) || (preDiff >= 0 && curDiff < 0)) {
				result++;
				preDiff = curDiff;
			}
		}
		return result;
	}
};

int main() {
	Solution solution;
	vector<int> nums = { 1, 2, 2, 2, 3, 4 };

	int result = solution.wiggleMaxLength(nums);

	// 期望输出：6，因为摆动序列可以是 [1, 7, 4, 9, 2, 5]
	cout << "摆动序列的最大长度为：" << result << endl;

	return 0;
}