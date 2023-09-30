#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
	int getSum(int n) {
		int sum = 0;
		while (n) {
			sum += (n % 10) * (n % 10);
			n /= 10;
		}
		return sum;
	}
	bool isHappy(int n) {
		unordered_set<int> set;
		while (1) {
			int sum = getSum(n);
			if (sum == 1) {
				return true;
			}
			if (set.find(sum) != set.end()) {
				return false;
			}
			else {
				set.insert(sum);
			}
			n = sum;
		}
	}
};

int main()
{
	int n = 2;
	Solution solution;
	
	if (solution.isHappy(n)) {
		cout << n << " is a happy number" << endl;
	}
	else {
		cout << n << " is not a happy number" << endl;
	}

	return 0;
}