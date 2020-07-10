
���谴�����������������Ԥ��δ֪��ĳ�����Ͻ�������ת��

(���磬����[0, 0, 1, 2, 2, 5, 6] ���ܱ�Ϊ[2, 5, 6, 0, 0, 1, 2])��

��дһ���������жϸ�����Ŀ��ֵ�Ƿ�����������С������ڷ��� true�����򷵻� false��

ʾ�� 1:

���� : nums = [2, 5, 6, 0, 0, 1, 2], target = 0
��� : true
	 ʾ�� 2 :

 ���� : nums = [2, 5, 6, 0, 0, 1, 2], target = 3
  ��� : false

//����˼·���ж�mid����Ҳ��Ƿ񵥵�ǰ�������жϺ����ұ߽��Ƿ���ȣ���ȵĻ������߽�
/**
* ִ����ʱ :1 ms, 99.69%
* �ڴ����� :38.4 MB, 36.61%
*/
public boolean search(int[] nums, int target) {
	int start = 0;
	int end = nums.length - 1;
	int mid;
	while (start <= end) 
	{
		mid = (end + start) / 2;
		if (nums[mid] == target)
			return true;
		/* ��33���� begin */
		if (nums[mid] == nums[start]) 
		{  //KEYPOINT
			start++;
			continue;
		}
		else if (nums[mid] == nums[end]) 
		{  //KEYPOINT
			end--;
			continue;
		}
		/* ��33���� end */
		if (nums[end] > nums[mid]) // mid�Ҳ൥������
		if (nums[mid] < target && target <= nums[end]) //�ڵ�������������
			start = mid + 1;
		else
			end = mid - 1;
		else { // mid��൥������
			if (nums[start] <= target && target <= nums[mid]) //�ڵ�������������
				end = mid - 1;
			else
				start = mid + 1;
		}
	}
	return false;
}
