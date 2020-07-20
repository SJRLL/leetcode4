给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例 :

输入 : [1, 2, 2]
输出 :
   [
	   [2],
	   [1],
	   [1, 2, 2],
	   [2, 2],
	   [1, 2],
	   []
   ]

//解题思路：排序+去重

	 class Solution {
	 public:
		 vector<vector<int>> res;
		 void dfs(vector<int> &cc, vector<int>& nums, int start)
		 {
			 res.push_back(cc);
			 for (int i = start; i<nums.size(); i++)
			 {
				 if (i>start&&nums[i] == nums[i - 1]) 
					 continue;
				 cc.push_back(nums[i]);
				 dfs(cc, nums, i + 1);
				 cc.pop_back();
			 }

		 }
		 vector<vector<int>> subsetsWithDup(vector<int>& nums) 
		 {
			 sort(nums.begin(), nums.end());
			 vector<int>cc;
			 dfs(cc, nums, 0);
			 return res;


		 }
	 };
