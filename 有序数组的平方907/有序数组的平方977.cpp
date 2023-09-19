#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> sortedSquares(vector<int>& nums) {
		int k = nums.size() - 1;
		vector<int> result(nums.size(), 0);
		for (int i = 0, j = nums.size() - 1; i <= j;) {
			if (nums[i] * nums[i] < nums[j] * nums[j]) {
				result[k--] = nums[j] * nums[j];
				j--;
			}
			else {
				result[k--] = nums[i] * nums[i];
				i++;
			}
		}
		return result;
	}
};

int main() {
	vector<int> nums1 = { 1, 2, 3, 3, 4, 3, 6 };
	vector<int> nums2 = { 7, 8, 9, 2, 3, 3 };
	Solution solution;
	vector<int> result1 = solution.sortedSquares(nums1);
	vector<int> result2 = solution.sortedSquares(nums2);

	cout << "result1 : ";
	for (int i = 0; i < result1.size(); i++) {
		cout << result1[i] << " ";
	}
	cout << endl;
	cout << "result2 :";
	for (int i = 0; i < result2.size(); i++) {
		cout << result2[i] << " ";
	}
	cout << endl;
}