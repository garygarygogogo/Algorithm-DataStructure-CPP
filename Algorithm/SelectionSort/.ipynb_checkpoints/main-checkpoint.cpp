# include<vector>
class Solution {
    void selectSort(vector<int> &arr){
        int N = arr.size();
        for (int i=0; i<N-1; i++){
            int min = i;
            for (int j=i+1; j<N; j++){ // find minimun in the unsorted array
                if (arr[j] < arr[min])
                    min = j;
            }
            swap(arr[i], arr[min]); // swap minimun with the first element of unsorted array
        }    
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        selectSort(nums);
        return nums;
    }
};
// time complexity：O(n^2)
// space complexity：O(1)