给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

注意 :
不能使用代码库中的排序函数来解决这道题。

示例 :

输入 : [2, 0, 2, 1, 1, 0]
输出 : [0, 0, 1, 1, 2, 2]

//解题思路:使用三路快排，定义当前移动索引指针cur，左边放0的索引l，右边放2的索引r,依次遍历一遍数组，通过while循环将当前索引指针cur访问到的元素放到正确的位置去即可。

class Solution {
	public void sortColors(int[] nums)
	{
		int len = nums.length;
		if (len < 2) 
		{
			return;
		}
		int l = -1;//定义左边索引位置
		int r = len - 1;//定义右边索引位置
		int cur = 0;//定义当前移动索引指针

		while (cur <= r) {//当前移动索引指针位置不能超过右索引指针访问位置
			if (nums[cur] == 0) 
			{//如果当前访问元素是0
				l++;//要将一开始定义的-1变成0
				swap(nums, cur, l);
				cur++;
			}
			else if (nums[cur] == 1)
			{//如果当前访问元素是1
				cur++;
			}
			else 
			{
				swap(nums, cur, r);//如果当前访问元素是2
				r--;
			}
		}
	}

	private void swap(int[] nums, int index1, int index2)
	{
		int temp = nums[index1];
		nums[index1] = nums[index2];
		nums[index2] = temp;
	}
}
