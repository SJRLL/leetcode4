
��������[1, 2, 3, ��, n]��������Ԫ�ع��� n!�����С�

����С˳���г����������������һһ��ǣ��� n = 3 ʱ, �����������£�

"123"
"132"
"213"
"231"
"312"
"321"
���� n �� k�����ص� k �����С�

˵����

���� n �ķ�Χ��[1, 9]��
���� k �ķ�Χ��[1, n!]��

ʾ�� 1:
���� : n = 3, k = 3
��� : "213"

ʾ�� 2 :
���� : n = 4, k = 9
��� : "2314"

//����˼·��
//�����λ����ʼ����������1λ���ֲ���ʱ��ʣ�µ������������(n - 1)!�֣�����2λ���ֲ���ʱ��ʣ�µ������������(n - 2)!��... �Դ����ơ�
//��k�ܱ�ĳ���ײ�����ʱ��˵���Ѿ�����������ֵ����һ�����У�ʣ�µ����ֵ�������ˡ���һ��list��¼û���õ������֡�

public String getPermutation(int n, int k) {
	StringBuilder sb = new StringBuilder();
	List<Integer> list = new ArrayList<>();
	for (int i = 1; i <= n; i++) list.add(i);

	// ���� (n-1)!
	int s = 1;
	for (int i = 1; i < n; i++) s *= i;

	while (n > 1) {
		int j = k / s;
		k = k % s;
		s = s / --n;
		if (k == 0) {
			sb.append(list.get(j - 1));
			list.remove(j - 1);
			break;
		}
		else {
			sb.append(list.get(j));
			list.remove(j);
		}
	}

	for (int i = list.size() - 1; i >= 0; i--) {
		sb.append(list.get(i));
	}
	return sb.toString();
}

