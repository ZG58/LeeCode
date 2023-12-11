#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//	int maxSubArray(vector<int>& nums) {
//		int result = INT32_MIN;
//		int count = 0;
//		for (int i = 0; i < nums.size(); i++) {
//			count = 0;
//			for (int j = i; j < nums.size(); j++) {
//				count += nums[j];
//				result = count > result ? count : result;
//			}
//		}
//		return result;
//	}
//};

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int result = INT32_MIN;
		int count = 0;
		for (int i = 0; i < nums.size(); i++) {
			count += nums[i];
			if (count > result) {
				result = count;
			}
			if (count <= 0) count = 0;
		}
		return result;
	}
};

int main() {
	Solution solution;
	vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };

	int result = solution.maxSubArray(nums);

	cout << "最大子数组和为：" << result << endl;

	return 0;
}
