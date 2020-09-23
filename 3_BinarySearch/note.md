1. 对于一个长度为N的数组，二分查找的时间复杂度为O(logN)
2. 我们也可以用更加数学的方式定义二分查找。给定一个在[a, b]区间内的单调函数f(x)，若f(a)和f(b) 正负性相反，那么必定存在一个解c，使得f(c) = 0。
3. 二分查找时区间的左右端取**开区间还是闭区间**在绝大多数时候都可以。
4. 这里我提供两个小诀窍:
   1. 第一是尝试熟练使用一种写法，比如左闭右开（满足 C++、Python 等语言的习惯）或左闭右闭（便于处理边界条件），尽量只保持这一种写法；
   2. 第二是在刷题时思考如果最后区间只剩下一个数或者两个数，自己的写法是否会陷入死循环，如果某种写法无法跳出死循环，则考虑尝试另一种写法。