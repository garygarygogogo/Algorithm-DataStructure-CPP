// by recurrence
class Solution1 {
    void quickSort(vector<int>& nums, int l, int r){
        if (l >= r) return;
        int mark = nums[l];        // set pivot
        int mark_ptr = l;
        for (int i=l; i<=r; i++){
            if (nums[i] < mark){
                mark_ptr++;
                swap(nums[i], nums[mark_ptr]);
            }
        }
        swap(nums[mark_ptr], nums[l]);
        quickSort(nums, l, mark_ptr-1);
        quickSort(nums, mark_ptr+1, r);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.empty()) return {};
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
};
// time complexity：O(nlogn)
// space complexity：O(logn)

// by stack, bfs
class Solution2 {
    void quickSort(vector<int>& nums, int l, int r){
        using Pair = pair<int,int>;
        stack<Pair> stk; stk.push(Pair(l, r));
        while (!stk.empty()){
            auto index = stk.top(); stk.pop();
            int l = index.first; int r = index.second;
            if (l >= r) continue;
            int mark = nums[l];
            int mark_ptr = l;
            for (int i=l; i<=r; i++){
                if (nums[i] < mark){
                    mark_ptr++;
                    swap(nums[i], nums[mark_ptr]);
                }
            }
            swap(nums[mark_ptr], nums[l]);
            stk.push(Pair(l, mark_ptr-1));
            stk.push(Pair(mark_ptr+1, r));
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.empty()) return {};
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
};
// time complexity：O(nlogn)
// space complexity：O(n)