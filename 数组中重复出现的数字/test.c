
#include<Windows.h>
#include<stdio.h>
#if 0
//���ַ���ʹ������ָ�����������飬��������forѭ����ʱ�临�Ӷ�ΪO��n^2��,�ռ临�Ӷ�ΪO(N)
void test()
{
	int array[7] = { 0, 3, 1, 0, 2, 5, 3 };
	int i = 0;
	for (i = 0; i < 7;i++)
	{
		int j = i + 1;
		for (; j < 7; j++)
		{
			if (array[i] == array[j])
			{
				printf("�ظ�������Ϊ��%d \n", array[i]);
				return;
			}
		}
	}
	if (i>=7)
		printf("û�ҵ��ظ�������\n");
}
#endif 

void test()
{
	int array[7] = { 2, 3, 1, 0, 2, 5, 3 };
	int i = 0;
	for (i = 0; i < sizeof(array) / sizeof(array[0]); i++)
	{
		int j = 0;
		for (j = 0; j < i; j++)
		{
			if (array[j] > array[i])
			{
				int temp = array[j];
				array[j] = array[i];
				array[i] = temp;
			}
		}
	}
	for (i = 0; i < 6; i++)
	{
		if (array[i] == array[i + 1])
		{
			printf("�ظ����ֵ�����Ϊ��");
			printf("%d ", array[i]);
		}
	}
}

int main()
{
	test();
	system("pause");
	return 0;
}