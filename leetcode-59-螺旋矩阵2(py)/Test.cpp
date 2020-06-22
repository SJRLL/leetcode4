给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

示例 :

输入 : 3
输出 :
   [
	   [1, 2, 3],
	   [8, 9, 4],
	   [7, 6, 5]
   ]

//解题思路
//本题与数组旋转的思路是一样，不一样的地方就是需要初始化结果矩阵，然后一个一个元素的赋值即可。

class Solution :
		 def generateMatrix(self, n: int)->List[List[int]] :
	 if n == 1 :
		 return[[n]]
		 data = [elem for elem in range(1, n*n + 1)]
		 res = [[0 for i in range(n)] for elem in range(n)]
		 i = 0
		 j = -1
		 row, col = n, n
		 direction = 1
		 k = 0
	 while k<len(data) :
	 for x in range(col) :
		 j += direction
		 res[i][j] = data[k]
		 k += 1
	 for y in range(row - 1) :
		 i += direction
		 res[i][j] = data[k]
		 k += 1
		 direction *= -1
		 row, col = row - 1, col - 1
		 return res

