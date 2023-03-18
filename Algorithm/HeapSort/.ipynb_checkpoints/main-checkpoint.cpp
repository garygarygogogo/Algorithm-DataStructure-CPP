lass Solution {
    void heap(vector<int>& nums, int p){ // sort heap
       for (int parent=p; parent*2+1<nums.size();){
           int child = parent*2+1;
           if (child+1<nums.size() && nums[child] > nums[child+1])
                child++;
            if (nums[child] > nums[parent])
                break;
            swap(nums[child], nums[parent]);
            parent = child;
       }
    }
    void buildheap(vector<int>& nums){ // build heap
        for (int i=nums.size()/2; i>=0; i--)
            heap(nums, i);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.empty()) return {};
        buildheap(nums); // build heap
        vector<int> temp(nums.size(), 0);
        for (int i=0; i<temp.size(); i++){
            temp[i] = nums[0]; nums[0] = nums.back(); nums.pop_back();  // pop heap maximum/minimum
            heap(nums, 0); // sort heap
        }
        return temp;
    }
};
// time complexity：O(nlogn)
// space complexity：O(n)