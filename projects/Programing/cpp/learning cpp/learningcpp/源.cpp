#include "pch.h"
#include <iostream>

int a = 10;

void increase(int n) {
	int b = n; // n����Ϊ�����Ĳ�����������, ���ǳ�nΪ�α���, b��n����ͬһ����ַ, ֻ��ֵ��ͬ, ��Ϊ��ֵ����.
	a += b; // aΪȫ�ֱ���, bΪ�ֲ��������������ڶ�.
}

int main()
{
	int a = 0x1654F;
	// ��ֵ����ʱ���
	int b = a;
	a = a + b;
	int arr[] = { 1, 2, 3, 5 };
	char crr[5][3] = {
		{91, 92, 93},
	{0},
	{31,32, 33},
	{11, 12, 13},
	{2, 3, 5}
	};

	int uu = 1;
	switch (uu) {
	case 1:
		printf("one \n");
		break; // break��Ҫ��ӣ�switch�൱���Զ����������ת���е�������goto����Ҫ���Զ�break
	case 2:
		printf("two \n");
	case 3:
		printf("three \n");
	default: // default��ʾû�з���������switch���ʱ���еĲ���, Ҳ���Բ���
		printf("default");
	}
	// ע�⣺ 
	// 1)switch�����������������Ǹ�����
	// 2)�����ǳ���
	// 3)switch�ܱ�if..else..��ȫ����


	//char c = 'a';
	//char cuu[] = "abc";

	//printf("this is a test file %s \n", cuu);

	// �ֲ���������
	//int a = 10;
	//goto inhalve;

 /*inhalve:
	a = 9;
	goto add;
newt:
	a = 11;
	if(a >0)
		add:
			a = 12;
			return a;
	goto inhalve;

	printf("a is");
	cout << "a ��ֵ��" << a << endl;*/
}