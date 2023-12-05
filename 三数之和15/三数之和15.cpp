#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] > 0) {
				break;
			}
			if (i > 0 && nums[i] == nums[i - 1]) {
				continue;
			}
			unordered_set<int> set;
			for (int j = i + 1; j < nums.size(); j++) {
				if (j > i + 2 && nums[j] == nums[j - 1] && nums[j - 1] == nums[j - 2]) {
					continue;
				}
				int c = 0 - (nums[i] + nums[j]);
				if (set.find(c) != set.end()) {
					result.push_back({ nums[i], nums[j], c });
					set.erase(c);
				}
				else {
					set.insert(nums[j]);
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
	std::vector<std::vector<int>> result = solution.threeSum(nums);

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
