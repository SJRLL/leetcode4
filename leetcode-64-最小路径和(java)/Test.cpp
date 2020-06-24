
给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

示例 :

输入 :
	[
		[1, 3, 1],
		[1, 5, 1],
		[4, 2, 1]
	]
输出 : 7
解释 : 因为路径 1→3→1→1→1 的总和最小。

//解题思路：动态规划

   class Solution {
	   public int minPathSum(int[][] grid) {
		   //        return minPathSum(0, 0, grid);
		   for (int i = 0; i < grid.length; i++) {
			   for (int i1 = 0; i1 < grid[i].length; i1++) 
			   {
				   if (i == 0 && i1 == 0) 
				   {
					   continue;
				   }
				   if (i == 0)
				   {
					   grid[i][i1] += grid[i][i1 - 1];
				   }
				   else if (i1 == 0) 
				   {
					   grid[i][i1] += grid[i - 1][i1];
				   }
				   else if (grid[i - 1][i1] <= grid[i][i1 - 1])
				   {
					   grid[i][i1] += grid[i - 1][i1];
				   }
				   else 
				   {
					   grid[i][i1] += grid[i][i1 - 1];
				   }
			   }
		   }
		   return grid[grid.length - 1][grid[0].length - 1];
	   }

	   private int minPathSum(int startLine, int startColumn, int[][] grid) {
		   if (startLine == grid.length - 1) 
		   {
			   int result = 0;
			   for (int i = startColumn; i < grid[startLine].length; i++) 
			   {
				   result += grid[startLine][i];
			   }
			   return result;
		   }

		   if (startColumn == grid[0].length - 1) 
		   {
			   int result = 0;
			   for (int i = startLine; i < grid.length; i++) 
			   {
				   result += grid[i][startColumn];
			   }
			   return result;
		   }

		   if (startLine == grid.length - 2 && startColumn == grid[0].length - 2) 
		   {
			   //位于示例图中5的位置
			   if (grid[startLine][startColumn + 1] <= grid[startLine + 1][startColumn]) 
			   {
				   return grid[startLine][startColumn] + grid[startLine][startColumn + 1] + grid[startLine + 1][startColumn + 1];
			   }
			   else 
			   {
				   return grid[startLine][startColumn] + grid[startLine + 1][startColumn] + grid[startLine + 1][startColumn + 1];
			   }
		   }

		   return Math.min(minPathSum(startLine, startColumn + 1, grid), minPathSum(startLine + 1, startColumn, grid)) + grid[startLine][startColumn];
	   }
   }
