#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int cover = 0;
		if (nums.size() == 1) return true;
		for (int i = 0; i <= cover; i++) {
			cover = max(i + nums[i], cover);
			if (cover >= nums.size() - 1) return true;
		}
		return false;
	}
};

int main()
{
	Solution solution;
	cout << "请输入一个整数数组（以空格分割，回车键结束）：" << endl;

	vector<int> nums;
	int num;

	while (cin >> num && cin.get() != '\n') {
		nums.push_back(num);
	}

	cout << "能否跳到最后：" << boolalpha << solution.canJump(nums) << endl;

	return 0;
}