
#include<Windows.h>
#include<stdio.h>
#if 0
//���ַ���ʹ������ָ�����������飬��������forѭ����ʱ�临�Ӷ�ΪO��n^2��,�ռ临�Ӷ�ΪO(1)
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
#if 0
//���ַ�������ͨ��ð��������������ʱ�临�Ӷ�ΪO(n^2),�ռ临�Ӷ�ΪO(1);
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
#endif
//���ַ���ʹ���۰��������������������
//�Ƚϴ�����ȻΪnlog(n)(��2Ϊ��),����ʱ�临�Ӷ���ȻΪO(N^2);

void test()
{
	int array[7] = { 0, 3, 1, 0, 2, 5, 3 };
	int i = 2;
	for (i = 2; i < sizeof(array) / sizeof(array[0]); i++)
	{
		int low = 1; int high = i - 1;
		int temp = array[i];
		while (low <= high)
		{
			int mid = (high - low) / 2 + low;
			if (temp < array[mid])
				high = mid - 1;
			else
				low = mid + 1;
		}
		//�ƶ�Ԫ��
		int j = 0;
		for (j = i - 1; j>=low; j--)
		{
			array[j + 1] = array[j];
		}
		array[low] = temp;
	}
	for (i = 0; i < sizeof(array)/sizeof(array[0])-1; i++)
	{
		if (array[i] == array[i + 1])
		{
			printf("�ظ����ֵ�����Ϊ��");
			printf("%d ", array[i]);
		}
	}
}
//����һ��˼·����������е�Ԫ���Ѿ��ź����ˣ�������Ԫ��Ӧ���������±���ͬ�����Ը������
//����ʵ�ֿ��ٵ����򣬴Ӷ��ҵ��ظ������֣���Ȼ�����ַ���ֻ������������
int main()
{
	test();
	system("pause");
	return 0;
}