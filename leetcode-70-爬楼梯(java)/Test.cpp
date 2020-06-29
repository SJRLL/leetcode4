
������������¥�ݡ���Ҫ n ������ܵ���¥����

ÿ��������� 1 �� 2 ��̨�ס����ж����ֲ�ͬ�ķ�����������¥���أ�

ע�⣺���� n ��һ����������

ʾ�� 1��
���룺 2
����� 2
���ͣ� �����ַ�����������¥����
1.  1 �� + 1 ��
2.  2 ��

ʾ�� 2��
���룺 3
����� 3
���ͣ� �����ַ�����������¥����
1.  1 �� + 1 �� + 1 ��
2.  1 �� + 2 ��
3.  2 �� + 1 ��

//����˼·��ֱ���ҳ���ѧ�������

class Solution {

	public static long[][] matrixPower(long[][] x, long[][] y) {
		long a = x[0][0] * y[0][0] + x[0][1] * y[1][0];
		long b = x[0][0] * y[0][1] + x[0][1] * y[1][1];
		long c = x[1][0] * y[0][0] + x[1][1] * y[1][0];
		long d = x[1][0] * y[0][1] + x[1][1] * y[1][1];
		return new long[][]{new long[]{a, b}, new long[]{c, d}};
	}

	public long[][] power2(long[][] x, int y) {
		long[][] res = new long[2][2];
		res[0][0] = 1;
		res[1][1] = 1;
		char[] chars = Integer.toBinaryString(y).toCharArray();
		for (int i = chars.length - 1; i >= 0; i--) {
			if (chars[i] == '1') {
				res = matrixPower(x, res);
			}
			x = matrixPower(x, x);
		}
		return res;
	}

	public int climbStairs(int n) {
		if (n == 1) {
			return 1;
		}
		else if (n == 2) {
			return 2;
		}
		else {
			long[][] x = new long[][]{new long[]{1, 1}, new long[]{1, 0}};
			long[][] temp = power2(x, n - 2);
			long res = 2 * temp[0][0] + temp[1][0];
			return (int)res;
		}
	}
}

