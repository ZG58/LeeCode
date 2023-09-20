#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) {
		int sum = 0;
		int subLength = 0;
		int result = INT32_MAX;
		int i = 0;
		for (int j = 0; j < nums.size(); j++) {
			sum += nums[j];
			while (sum >= target) {
				subLength = j - i + 1;
				result = subLength < result ? subLength : result;
				sum -= nums[i++];
			}
		}
		return result == INT32_MAX ? 0 : result;
	}
};

int main()
{
	Solution solution;
	vector<int> nums2 = { 2, 3, 1, 2, 4, 3 };
	int target = 7;
	int result = solution.minSubArrayLen(target, nums2);

	cout << "result:" << result << endl;

	return 0;
}