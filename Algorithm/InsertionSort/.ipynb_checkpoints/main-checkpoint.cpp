/*

eg 1:
input: nums = [-1,0,3,5,9,12], target = 9
output: 4
explanation: 9 in nums and index is 4


eg 2:
input: nums = [-1,0,3,5,9,12], target = 2
output: -1
explanation: 2 not in nums
 
hint
assume that nums elements are unrepeated
n in [1, 10000]
nums element in [-9999, 9999]

*/
// time complexity：O(n^2)
// space complexity：O(1)

class Solution {
  public:
  int search(vector<int>& nums, int target) {
		int pivot, left = 0, right = nums.size() - 1;
    	while (left <= right) {
      		pivot = left + (right - left) / 2;
      		if (nums[pivot] == target) return pivot;
      		if (target < nums[pivot]) right = pivot - 1;
      		else left = pivot + 1;
    	}
    	return -1;
  }
};
// time：O(logn)
// space：O(n)