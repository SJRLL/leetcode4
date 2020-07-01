给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。

示例 1 :

输入 :
	[
		[1, 1, 1],
		[1, 0, 1],
		[1, 1, 1]
	]
输出 :
	[
		[1, 0, 1],
		[0, 0, 0],
		[1, 0, 1]
	]
示例 2 :

输入 :
   [
	   [0, 1, 2, 0],
	   [3, 4, 5, 2],
	   [1, 3, 1, 5]
   ]
 输出 :
	 [
		 [0, 0, 0, 0],
		 [0, 4, 5, 0],
		 [0, 3, 1, 0]
	 ]

//解题思路：重点：只标记单个的0为MODIFIED,不用整行整列标记为MODIFIED，最后遇到MODIFIED，//再整行整列变为零（同时记得越过MODIFIED标记点。）

class Solution {
		public void setZeroes(int[][] matrix) {
			int MODIFIED = -1000000;
			int row = matrix.length;
			int col = matrix[0].length;
			for (int i = 0; i<row; i++){//是0的，全部标记完成，不替换
				for (int j = 0; j<col; j++){
					if (matrix[i][j] == 0){
						matrix[i][j] = MODIFIED;
					}
				}
			}
			for (int i = 0; i<row; i++){
				for (int j = 0; j<col; j++){
					if (matrix[i][j] == MODIFIED){//找到一个标记
						matrix[i][j] = 0;
						for (int m = 0; m<col; m++){//整行变成0
							if (matrix[i][m] != MODIFIED){//其中，跳过MODIFIED标记
								matrix[i][m] = 0;
							}
						}
						for (int n = 0; n<row; n++){//整列变成0
							if (matrix[n][j] != MODIFIED){//其中，跳过MODIFIED标记
								matrix[n][j] = 0;
							}
						}
					}
				}
			}
		}
	}

