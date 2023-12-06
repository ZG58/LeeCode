#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		for (int k = 0; k < nums.size(); k++) {
			if (nums[k] > target && nums[k] >= 0) {
				break;
			}
			if (k > 0 && nums[k] == nums[k - 1]) {
				continue;
			}
			for (int i = k + 1; i < nums.size(); i++) {
				if (nums[k] + nums[i] > target && nums[k] + nums[i] >= 0) {
					break;
				}
				if (i > k + 1 && nums[i] == nums[i - 1]) {
					continue;
				}
				int left = i + 1;
				int right = nums.size() - 1;
				while (left < right) {
					if ((long)nums[k] + nums[i] + nums[left] + nums[right] > target) right--;
					else if ((long)nums[k] + nums[i] + nums[left] + nums[right] < target) left++;
					else {
						result.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
						while (right > left && nums[right] == nums[right - 1]) right--;
						while (right > left && nums[left] == nums[left + 1]) left++;
						right--;
						left++;
					}

				}
			}
		}
		return result;
	}
};

int main() {
	Solution solution;

	// 测试示例
	std::vector<int> nums = { 0,2,2,3,0,1,2,3,-1,-4,2 };
	std::vector<std::vector<int>> result = solution.fourSum(nums, 4);

	// 输出结果
	for (const auto& triplet : result) {
		std::cout << "[ ";
		for (int num : triplet) {
			std::cout << num << " ";
		}
		std::cout << "]" << std::endl;
	}

	return 0;
}