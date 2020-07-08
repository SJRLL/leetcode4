给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。



示例 :

board =
[
	['A', 'B', 'C', 'E'],
	['S', 'F', 'C', 'S'],
	['A', 'D', 'E', 'E']
]

给定 word = "ABCCED", 返回 true
给定 word = "SEE", 返回 true
给定 word = "ABCB", 返回 false

//解题思路
//思路基本如下：当前局面下，有若干种选择，所以对每一种选择进行尝试。如果发现某种选择违反了某些限定条件，
//此时 return；如果尝试某种选择到了最后，发现该选择是正确解，那么就将其加入到解集中。


class Solution {
	boolean[][] flag;
	char[] words;
	char[][] boards;
	int row, col;
	boolean result = false;
	public boolean exist(char[][] board, String word) {
		this.row = board.length;
		this.col = board[0].length;
		this.words = word.toCharArray();
		this.boards = board;
		for (int i = 0; i<row; i++){
			for (int j = 0; j<col; j++){
				if (board[i][j] == words[0]){
					this.flag = new boolean[row][col];
					this.flag[i][j] = true;
					helper(i, j, 1);
					if (result){
						return true;
					}
				}
			}
		}
		return false;
	}

	private void helper(int i, int j, int count) {
		if (count == words.length){
			result = true;
			return;
		}
		if (i - 1 >= 0 && !flag[i - 1][j] && words[count] == boards[i - 1][j] && !result){
			flag[i - 1][j] = true;
			helper(i - 1, j, ++count);
			count--;
			flag[i - 1][j] = false;
		}
		if (j + 1<col&&!flag[i][j + 1] && words[count] == boards[i][j + 1] && !result){
			flag[i][j + 1] = true;
			helper(i, j + 1, ++count);
			count--;
			flag[i][j + 1] = false;
		}
		if (i + 1<row&&!flag[i + 1][j] && words[count] == boards[i + 1][j] && !result){
			flag[i + 1][j] = true;
			helper(i + 1, j, ++count);
			count--;
			flag[i + 1][j] = false;
		}
		if (j - 1 >= 0 && !flag[i][j - 1] && words[count] == boards[i][j - 1] && !result){
			flag[i][j - 1] = true;
			helper(i, j - 1, ++count);
			count--;
			flag[i][j - 1] = false;
		}
	}
}
