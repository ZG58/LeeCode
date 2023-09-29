#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_set<int> result_set;
		unordered_set<int> num_set(nums1.begin(), nums1.end());
		for (int num : nums2) {
			if (num_set.find(num) != num_set.end()) {
				result_set.insert(num);
			}
		}
		return vector<int>(result_set.begin(), result_set.end());
	}
};

int main()
{

	Solution solution;

	vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2, 1};
    vector<int> intersection_result = solution.intersection(nums1, nums2);

    cout << "Intersection: ";
    for (int num : intersection_result) {
        cout << num << " ";
    }
    cout << endl;

	return 0;
}