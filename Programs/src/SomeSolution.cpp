/*
 * SomeSolution.cpp
 *
 *  Created on: 2016��11��24��
 *      Author: tla001
 *
 *      һЩС�ı��Ƭ���ܽ�
 */
/*
 * ��ʹ�üӷ������ʵ�־�ֵ
 */
int ave(int x, int y) {
	return (x & y) + ((x ^ y) >> 1);
}

/*
 * ��ʹ�üӷ������ʵ�ּӷ�
 */
int add(int a, int b) {
	if (b == 0) //û�н�λʱ�������
		return a;
	int sum, carry;
	sum = a ^ b; //��ɵ�һ��û�н�λ�ļӷ�
	carry = (a & b) << 1; //��ɵڶ�����λ������
	return add(sum, carry); //���еݹ�
}

