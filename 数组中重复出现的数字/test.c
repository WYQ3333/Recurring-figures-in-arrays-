
#include<Windows.h>
#include<stdio.h>

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

int main()
{
	test();
	system("pause");
	return 0;
}