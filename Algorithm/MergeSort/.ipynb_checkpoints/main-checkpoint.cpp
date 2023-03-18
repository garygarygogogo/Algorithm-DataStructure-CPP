class Solution {
    void mergeSort(vector<int>& nums, vector<int>& temp, int l, int r){
        if (l >= r) return;
        int mid = (l + r) / 2;
        mergeSort(nums, temp, l, mid);     // recurrence
        mergeSort(nums, temp, mid+1, r);
        int i=l,j=mid+1; int t = 0;       
        while (i<=mid && j<=r){
            if (nums[i] <= nums[j]) temp[t++] = nums[i++];
            else temp[t++] = nums[j++];
        }
        while (i <= mid) temp[t++] = nums[i++];
        while (j <= r) temp[t++] = nums[j++];
        
        for (int i=l,t=0; i<=r; i++)
            nums[i] = temp[t++];
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.empty()) return {};
        vector<int> temp(nums.size(), 0);
        mergeSort(nums, temp, 0, nums.size()-1);
        return nums;
    }
};
// time complexity：O(nlogn)
// space complexity：O(n)