
#include<Windows.h>
#include<stdio.h>
#if 0
//这种方法使用两个指针来遍历数组，运用两个for循环，时间复杂度为O（n^2）,空间复杂度为O(N)
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
				printf("重复的数字为：%d \n", array[i]);
				return;
			}
		}
	}
	if (i>=7)
		printf("没找到重复的数字\n");
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
			printf("重复出现的数字为：");
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