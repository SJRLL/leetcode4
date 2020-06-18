给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

示例 1 :

输入 :
	[
		[1, 2, 3],
		[4, 5, 6],
		[7, 8, 9]
	]
输出 : [1, 2, 3, 6, 9, 8, 7, 4, 5]
示例 2 :

 输入 :
	[
		[1, 2, 3, 4],
		[5, 6, 7, 8],
		[9, 10, 11, 12]
	]
 输出 : [1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]

//解题思路
//缩小范围，左走到头往下，下走到头往右，又走到头往上，上走到头往左。

class Solution :
  def spiralOrder(self, matrix: List[List[int]])->List[int] :
	 if not matrix :
	 return[]
		 res = []
		 rl, rh, cl, ch = 0, len(matrix) - 1, 0, len(matrix[0]) - 1
	 while rl <= rh and cl <= ch :
	 for i in range(cl, ch + 1) :
		 res.append(matrix[rl][i])
		 rl += 1
	 if rl <= rh :
	 for i in range(rl, rh + 1) :
		 res.append(matrix[i][ch])
		 ch -= 1
	 if rl <= rh and cl <= ch :
	 for i in range(ch, cl - 1, -1) :
		 res.append(matrix[rh][i])
		 rh -= 1
	 if rl <= rh and cl <= ch :
	 for i in range(rh, rl - 1, -1) :
		 res.append(matrix[i][cl])
		 cl += 1
		 return res


