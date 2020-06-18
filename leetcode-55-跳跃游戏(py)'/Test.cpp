给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个位置。

示例 1 :

输入 : [2, 3, 1, 1, 4]
输出 : true
 解释 : 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。
  示例 2 :

输入 : [3, 2, 1, 0, 4]
输出 : false
 解释 : 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。

//解题思路
//题目要求到达最后一个元素，那么倒不了的就是False,能到的平均最差情况，就是分摊下来，一步一步走到.只要中间有一步过不去那就失败
//分析这种情况：1、nums[i] = 0  2、上一步的最远距离无法跨过去

class Solution :
	def canJump(self, nums: List[int]) -> bool :
	lenghth = len(nums)
	index = 0
for i in range(lenghth) :
if index >= lenghth - 1 : return True
if nums[i] == 0 and index <= i : return False
index = i + nums[i] if index<i + nums[i] else index


