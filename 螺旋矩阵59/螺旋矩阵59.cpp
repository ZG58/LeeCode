#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> res(n, vector<int>(n, 0));
		int startx = 0, starty = 0;
		int loop = n / 2;
		int mid = n / 2;
		int offset = 1;
		int count = 1;
		int i, j;
		while (loop--) {
			i = startx;
			j = starty;
			for (j = starty; j < n - offset; j++) {
				res[startx][j] = count++;
			}
			for (i = startx; i < n - offset; i++) {
				res[i][j] = count++;
			}
			for (; j > starty; j--) {
				res[i][j] = count++;
			}
			for (; i > startx; i--) {
				res[i][j] = count++;
			}
			startx++;
			starty++;
			offset += 1;
		}
		if (n % 2) {
			res[mid][mid] = count;
		}
		return res;
	}
};

int main()
{
	int num = 5;
	Solution solution;
	vector<vector<int>> result = solution.generateMatrix(num);

	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << "\t";
		}
		cout << endl;
	}

	return 0;
}