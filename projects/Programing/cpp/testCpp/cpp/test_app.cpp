#include "pch.h"
#include <iostream>

int a = 10;

void increase(int n) {
	int b = n; // n����Ϊ�����Ĳ�����������, ���ǳ�nΪ�α���, b��n����ͬһ����ַ, ֻ��ֵ��ͬ, ��Ϊ��ֵ����.
	a += b; // aΪȫ�ֱ���, bΪ�ֲ��������������ڶ�.
}

int main()
{
	increase(1);

}