������������ n �� k������ 1 ... n �����п��ܵ� k ��������ϡ�

ʾ�� :

���� : n = 4, k = 2
��� :
   [
	   [2, 4],
	   [3, 4],
	   [2, 3],
	   [1, 2],
	   [1, 3],
	   [1, 4],
   ]

//����˼·��
//����ȡֵ����ȡn����ȡn - 1...���1
//��֦��˼·
//��ʣ�µ����֣�����˳��ȡ���ǵ���ȡ��С����Ҫ��ĸ���ʱ������Ҫ��ȡ2�������γ�һ���������ʱ������1����n����ֻ��һ�����ֿ�ȡ�ģ���û�취�γ���ϣ��Ϳ���ֱ�Ӽ�ȥ��
//1 �ڵ���ȡ��ʱ��ʹ��i < k ��Ϊ��֦������������һ�£��ٶ�����5 - 10��
//2 ˳��ȡ�ļ�֦˼·��ע����

private List<List<Integer>> res;
public List<List<Integer>> combine(int n, int k) 
	 {

		 res = new ArrayList<>();
		 if (k == 0 || n < k)
			 return res;
		 LinkedList<Integer> list = new LinkedList<>();
		 dfs(n, k, list);
		 return res;
	 }

	 private void dfs(int n, int k, LinkedList<Integer> path)
	 {
		 if (k == 0)
		 {
			 res.add(new LinkedList<>(path));
			 return;
		 }

		 for (int i = n; i > 0; i--)
		 {
			 if (i < k)//�Ż�������i<k�������������
				 break;
			 path.addLast(i);
			 dfs(i - 1, k - 1, path);
			 path.removeLast();

		 }
}

