#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (nums[fastIndex] != val) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }
};

int main() {
    vector<int> nums = { 1, 2, 3, 3, 4, 3, 6 };
    int target = 3;
    Solution sloution;
    int result = sloution.removeElement(nums, target);

    cout << "New Length: " << result << endl;

    cout << "Modified Vector: ";
    for (int i = 0; i < result; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}