给出一个无重叠的 ，按照区间起始端点排序的区间列表。

在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。

示例 1 :
输入 : intervals = [[1, 3], [6, 9]], newInterval = [2, 5]
输出 : [[1, 5], [6, 9]]

示例 2 :
输入 : intervals = [[1, 2], [3, 5], [6, 7], [8, 10], [12, 16]], newInterval = [4, 8]
输出 : [[1, 2], [3, 10], [12, 16]]
解释 : 这是因为新的区间[4, 8] 与[3, 5], [6, 7], [8, 10] 重叠。

//解题思路
//最原始暴力的解法，性能处于中位数，边界值要处理好

class Solution :
	def insert(self, intervals: List[List[int]], newInterval : List[int])->List[List[int]] :
if not intervals : return[newInterval]
left = None
right = len(intervals)
last_r = None
nl, nr = newInterval
for i, (l, r) in enumerate(intervals) :
if last_r is not None and nl > last_r: left = i
if nr < l :
	right = i
	break
	last_r = r
else :
if nl > r:
left = right
rp = intervals[left:right]
	if not rp :
	intervals[left:right] = [newInterval]
	else :
	intervals[left:right] = [[min(rp[0][0], newInterval[0]), max(rp[-1][1], newInterval[1])]]
	return intervals

