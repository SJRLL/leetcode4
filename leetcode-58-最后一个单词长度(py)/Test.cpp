给定一个仅包含大小写字母和空格 ' ' 的字符串 s，返回其最后一个单词的长度。如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词。

如果不存在最后一个单词，请返回 0 。

说明：一个单词是指仅由字母组成、不包含任何空格字符的 最大子字符串。



示例 :

输入 : "Hello World"
输出 : 5

//解题思路
//1.对极端情况进行处理，比如 字符串为空。2.对字符串循环检验，检测到不是字母就直接检验下一个
//3.检测到是字母时，从当前位置继续向后检验，查看是不是字母，是的话，计数器加1   
//4.向后检验发现不再是字母将计数器的值保存到另一个变量并跳出循环！

class Solution :
	def lengthOfLastWord(self, s: str) -> int :
# for i in range(0, len(s)) :
#对空字符串进行判断
if len(s) == 0:
return 0
k = 0
maxlenth = 0
while k < len(s) :
	l = 0
#当不是字符时，进行的处理
if not s[k].isalpha() :
# print("wobushi")
k += 1
continue
else:
#当检测的字符是字母时，l为计数器
for i in range(k, len(s)) :
if s[i].isalpha() :
l += 1
maxlenth = l

# print(maxlenth)
else:

# print(k)
break
k = k + l
return maxlenth

