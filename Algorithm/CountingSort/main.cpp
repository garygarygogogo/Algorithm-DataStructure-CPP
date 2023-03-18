void countSort(vector<int>& nums, vector<int>& temp){
	for (int i=0; i<nums.size(); i++)
		temp[nums[i]]++;
	int t = 0;
	for (int i=0; i<nums.max(); i++){
		while (temp[i]){
			nums[t++] = i;
			temp[i]--;
		}
	}
}
// time：O(n)
// space：O(n)