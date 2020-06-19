给出一个区间的集合，请合并所有重叠的区间。

示例 1:
输入 : [[1, 3], [2, 6], [8, 10], [15, 18]]
输出 : [[1, 6], [8, 10], [15, 18]]
解释 : 区间[1, 3] 和[2, 6] 重叠, 将它们合并为[1, 6].

示例 2 :
输入 : [[1, 4], [4, 5]]
输出 : [[1, 5]]
解释 : 区间[1, 4] 和[4, 5] 可被视为重叠区间。

//解题思路
//1先对区间按照左端点升序排序，然后遍历。
//2：如果当前遍区间的左端点 <= 结果集中最后一个区间的右端点，说明它们有交集，此时把区间添加到结果集；
//3:否则没有交集

class Solution :
	def merge(self, intervals: List[List[int]])->List[List[int]] :
	length = len(intervals)
if not intervals :
return[]
intervals.sort(key = lambda x : x[0])  #排序
res = []
start = intervals[0][0]
end = intervals[0][1]
	while intervals:
	cur_start, cur_end = intervals.pop(0)
	if cur_start <= end : #如果重合既合并
		end = max(end, cur_end)
	else :
	res.append([start, end])
	start = cur_start
	end = cur_end
	res.append([start, end])   #将最后一个加进去
	return res
