#include <vector>
#include <iostram>
#include <algorithm>
class Solution1 {
    void heap(vector<int>& nums, int p){ // 调整堆
       for (int parent=p; parent*2+1<nums.size();){
           int child = parent*2+1;
           if (child+1<nums.size() && nums[child] < nums[child+1]) // 找最大子节点
                child++;
            if (nums[child] < nums[parent])  // 子节点比父节点值小，不用交换
                break;
            swap(nums[child], nums[parent]); // 子节点与父节点值交换
            parent = child;
       }
    }
    void buildheap(vector<int>& nums){ // 建堆
        for (int i=nums.size()/2; i>=0; i--)
            heap(nums, i);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.empty()) return {};
        buildheap(nums); // 建堆
        vector<int> temp(nums.size(), 0);
        for (int i=0; i<temp.size(); i++){
            temp[i] = nums[0]; nums[0] = nums.back(); nums.pop_back();  // 破坏堆
            heap(nums, 0); // 调整堆
        }
        return temp;
    }
};
// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)，这里复制了一个数组，如果是在原数组基础上直接排序，那么空间复杂度为O(1)

// build heap by queue
class Solution2 {
public:
    vector<int> sortArray(vector<int>& nums) {
        //降序队列，大顶堆
        priority_queue<int,vector<int>,less<int> > que;
        //greater和less是std实现的两个仿函数，less是降序队列，大顶堆
        vector<int> temp;
        for (int i=0; i<nums.size(); i++)
            que.push(nums[i]);
        while (!que.empty()){
            temp.push_back(que.top());
            que.pop();
        }
        return temp;
    }
};
