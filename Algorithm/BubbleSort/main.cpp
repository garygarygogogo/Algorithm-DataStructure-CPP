class Solution {
    void bubbleSort(vector<int>& nums){
       for (int i=0; i<nums.size(); i++){
           for (int j=0; j<nums.size()-i-1; j++){
               if (nums[j] > nums[j+1])
                    swap(nums[j], nums[j+1]); // swap
           }
       }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.empty()) return {};
        bubbleSort(nums);
        return nums;
    }
};
// time complexity：O(n^2)
// space complexity：O(1)