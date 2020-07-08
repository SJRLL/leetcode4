����һ����ά�����һ�����ʣ��ҳ��õ����Ƿ�����������С�

���ʱ��밴����ĸ˳��ͨ�����ڵĵ�Ԫ���ڵ���ĸ���ɣ����С����ڡ���Ԫ������Щˮƽ���ڻ�ֱ���ڵĵ�Ԫ��ͬһ����Ԫ���ڵ���ĸ�������ظ�ʹ�á�



ʾ�� :

board =
[
	['A', 'B', 'C', 'E'],
	['S', 'F', 'C', 'S'],
	['A', 'D', 'E', 'E']
]

���� word = "ABCCED", ���� true
���� word = "SEE", ���� true
���� word = "ABCB", ���� false

//����˼·
//˼·�������£���ǰ�����£���������ѡ�����Զ�ÿһ��ѡ����г��ԡ��������ĳ��ѡ��Υ����ĳЩ�޶�������
//��ʱ return���������ĳ��ѡ������󣬷��ָ�ѡ������ȷ�⣬��ô�ͽ�����뵽�⼯�С�


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
