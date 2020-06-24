一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？


示例 1:

输入 :
	[
		[0, 0, 0],
		[0, 1, 0],
		[0, 0, 0]
	]
输出 : 2
解释 :
   3x3 网格的正中间有一个障碍物。
   从左上角到右下角一共有 2 条不同的路径：
   1. 向右->向右->向下->向下
   2. 向下->向下->向右->向右

//解题思路
//这道题跟1的区别只是多了障碍，我们可以认为，障碍所处格子，到达路径为0，即我们要优先判断是否有障碍，如果有，直接在dp数组中置位0即可。
//因为dp的核心就是查表，我们在表记录中将障碍位置置位0，那么这个依赖这个格子的路径必然为0，所以自然而然就实现了，经过障碍的格子到达路径数都为0。
//所以代码实现即为在最初加个判断即可。

	 class Solution {
		 public int uniquePathsWithObstacles(int[][] obstacleGrid) {
			 int m = obstacleGrid.length;
			 int n = obstacleGrid[0].length;
			 if (obstacleGrid[0][0] != 0) return 0;

			 for (int i = 0; i < m; i++) 
			 {
				 for (int j = 0; j < n; j++) 
				 {
					 if (obstacleGrid[i][j] != 0) 
					 {
						 obstacleGrid[i][j] = 0;
					 }
					 else if (i == 0 && j == 0) 
					 {
						 obstacleGrid[0][0] = 1;
					 }
					 else if (i == 0) 
					 {
						 obstacleGrid[i][j] = obstacleGrid[i][j - 1];
					 }
					 else if (j == 0) 
					 {
						 obstacleGrid[i][j] = obstacleGrid[i - 1][j];
					 }
					 else 
					 {
						 obstacleGrid[i][j] = obstacleGrid[i][j - 1] + obstacleGrid[i - 1][j];
					 }
				 }
			 }
			 return obstacleGrid[m - 1][n - 1];
		 }
	 }
