/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.
*/
#include<vector>
#include<algorithm>

using std::vector;

class Solution {
public:
	int jump(vector<int>& nums) {
		if (nums.size() < 2)
			return 0;
		int n = nums.size(), steps = 0;
		int start = 0, end = 0;
		while (end < n - 1) {
			++steps;
			int max_end = end;
			for (int i = start; i <= end; ++i) {
				if (i + nums[i] >= n - 1)
					return steps;
				max_end = std::max(max_end, i + nums[i]);
			}
			start = end + 1;
			end = max_end;
		}
		return steps;
	}
};