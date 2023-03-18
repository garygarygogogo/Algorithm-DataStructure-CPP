/*
给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:
输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

注：题目来源：LeetCode
*/

class Solution1 {
    vector<vector<int>> res;
    void backTrack(vector<int> nums, vector<int> temp, vector<bool>& visit){
        if (temp.size() == nums.size()){//满足的条件
            res.push_back(temp);
            return;
        }
        for (int i=0; i<nums.size(); i++){
            if (visit[i])//是否使用过
                continue;
            visit[i] = true;
            temp.push_back(nums[i]);//添加选择
            backTrack(nums, temp, visit);
            visit[i] = false;
            temp.pop_back();//去除选择
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) return {};
        vector<bool> visit(nums.size(), false);
        backTrack(nums, {}, visit);
        return res;
    }
};
// 时间复杂度：O(n x n!)
// 空间复杂度：O(n)

/*
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的数字可以无限制重复被选取。

说明：
所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 
示例 1：
输入：candidates = [2,3,6,7], target = 7,
所求解集为：
[
  [7],
  [2,2,3]
]
    
示例 2：
输入：candidates = [2,3,5], target = 8,
所求解集为：
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]

提示：
1 <= candidates.length <= 30
1 <= candidates[i] <= 200
candidate 中的每个元素都是独一无二的。
1 <= target <= 500
*/
class Solution2 {
public:
    vector<vector<int>> res;
    void backTrack(int now, int sum, int target, vector<int> temp, vector<int>& candidates){
        if(sum > target) return;//剪枝
        if(sum == target){//终止条件
            res.push_back(temp);
            return;
        }
        //注意这里的now，不是0，因为这是组合问题，不是排列
        for(int i=now; i<candidates.size(); i++){
            sum += candidates[i];//添加选择
            temp.push_back(candidates[i]);
            //这里是允许元素重复使用的,如[5,5,7]
            backTrack(i, sum, target, temp, candidates);
            sum -= candidates[i];
            temp.pop_back();//去除选择
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        vector<int> temp;
        backTrack(0, 0, target, temp, candidates);
        return res;
    }
};
// 时间复杂度：O(S)，其中 S 为所有可行解的长度之和。
// 空间复杂度：O(target)。除答案数组外，空间复杂度取决于递归的栈深度，在最差情况下需要递归 O(target) 层。