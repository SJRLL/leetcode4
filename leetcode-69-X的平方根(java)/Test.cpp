实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:
输入 : 4
输出 : 2

示例 2 :
输入 : 8
输出 : 2
说明 : 8 的平方根是 2.82842...,
由于返回类型是整数，小数部分将被舍去。


//解题思路
//二分法, 不断的取区间中间值, 同时更新新的区间,

class Solution {
  public:
		 int mySqrt(int x) {
			 int low = 0;
			 int high = x;

			 if (x == 0) return 0;
			 if (x == 1) return 1;
			 while (high - low != 1) {
				 int mid = (high + low) / 2;
				 if (mid == x / mid) return mid;
				 if (mid > x / mid) high = mid;
				 else low = mid;
				 /*下面是我一开始的做法, 很容易看懂思路
				 if(mid * mid == x) return mid;//等于直接返回
				 if(mid * mid > x) high = mid;//大于说明mid比要求的解大, 需要再次二分
				 else low = mid;//同理
				 这种写法溢出了, 所以替换成上面的写法, 那么为什么上面的解法能得到答案,看代码之后的证明
				 */
			 }
			 return low;
		 }
	 };
