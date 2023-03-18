class Solution {
    void shellSort(vector<int> &arr){
        int N = arr.size();
        //grouping, gap starts with the half array length
        for (int gap=N/2; gap>0; gap/=2){
            for (int i=gap; i<N; i++){
                for (int j=i-gap; j>=0&&arr[j+gap]<arr[j]; j-=gap){ // insertion sort
                    swap(arr[j+gap], arr[j]);
                }
            }
        }    
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        shellSort(nums);
        return nums;
    }
};
// time complexity：O(n^1.3)
// space complexity：O(1)