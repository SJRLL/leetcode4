����һ�����ܰ����ظ�Ԫ�ص��������� nums�����ظ��������п��ܵ��Ӽ����ݼ�����

˵�����⼯���ܰ����ظ����Ӽ���

ʾ�� :

���� : [1, 2, 2]
��� :
   [
	   [2],
	   [1],
	   [1, 2, 2],
	   [2, 2],
	   [1, 2],
	   []
   ]

//����˼·������+ȥ��

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
