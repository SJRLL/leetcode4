
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

(例如，数组[0, 0, 1, 2, 2, 5, 6] 可能变为[2, 5, 6, 0, 0, 1, 2])。

编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。

示例 1:

输入 : nums = [2, 5, 6, 0, 0, 1, 2], target = 0
输出 : true
	 示例 2 :

 输入 : nums = [2, 5, 6, 0, 0, 1, 2], target = 3
  输出 : false

//解题思路：判断mid左侧右侧是否单调前，增加判断和左右边界是否相等，相等的话收缩边界
/**
* 执行用时 :1 ms, 99.69%
* 内存消耗 :38.4 MB, 36.61%
*/
public boolean search(int[] nums, int target) {
	int start = 0;
	int end = nums.length - 1;
	int mid;
	while (start <= end) 
	{
		mid = (end + start) / 2;
		if (nums[mid] == target)
			return true;
		/* 比33题多的 begin */
		if (nums[mid] == nums[start]) 
		{  //KEYPOINT
			start++;
			continue;
		}
		else if (nums[mid] == nums[end]) 
		{  //KEYPOINT
			end--;
			continue;
		}
		/* 比33题多的 end */
		if (nums[end] > nums[mid]) // mid右侧单调递增
		if (nums[mid] < target && target <= nums[end]) //在单调递增区间内
			start = mid + 1;
		else
			end = mid - 1;
		else { // mid左侧单调递增
			if (nums[start] <= target && target <= nums[mid]) //在单调递增区间内
				end = mid - 1;
			else
				start = mid + 1;
		}
	}
	return false;
}
