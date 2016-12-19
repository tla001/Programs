/*
 * SomeSolution.cpp
 *
 *  Created on: 2016年11月24日
 *      Author: tla001
 *
 *      一些小的编程片段总结
 */
/*
 * 不使用加法运算符实现均值
 */
int ave(int x, int y) {
	return (x & y) + ((x ^ y) >> 1);
}

/*
 * 不使用加法运算符实现加法
 */
int add(int a, int b) {
	if (b == 0) //没有进位时完成运算
		return a;
	int sum, carry;
	sum = a ^ b; //完成第一步没有进位的加法
	carry = (a & b) << 1; //完成第二步进位并左移
	return add(sum, carry); //进行递归
}

