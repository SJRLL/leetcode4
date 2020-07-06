给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例 :

输入 : nums = [1, 2, 3]
输出 :
   [
	   [3],
	   [1],
	   [2],
	   [1, 2, 3],
	   [1, 3],
	   [2, 3],
	   [1, 2],
	   []
   ]

//解题思路：采用典型的回溯法

List<List<Integer>> lists = new ArrayList<>();
public List<List<Integer>> subsets1(int[] nums) {
		 if (nums == null || nums.length == 0){
			 return lists;
		 }
		 List<Integer> list = new ArrayList<>();
		 process(list, nums, 0);
		 return lists;

	 }

	 private void process(List<Integer>list, int[] nums, int start){

		 lists.add(new ArrayList(list));
		 for (int i = start; i < nums.length; i++){

			 list.add(nums[i]);
			 process(list, nums, i + 1);
			 list.remove(list.size() - 1);
		 }
	 }
