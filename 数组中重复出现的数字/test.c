
#include<Windows.h>
#include<stdio.h>
#if 0
//这种方法使用两个指针来遍历数组，运用两个for循环，时间复杂度为O（n^2）,空间复杂度为O(1)
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
#if 0
//这种方法是先通过冒泡排序将数组排序，时间复杂度为O(n^2),空间复杂度为O(1);
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
#endif
//这种方法使用折半插入排序对数组进行排序
//比较次数虽然为nlog(n)(以2为底),但是时间复杂度任然为O(N^2);

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
		//移动元素
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
			printf("重复出现的数字为：");
			printf("%d ", array[i]);
		}
	}
}
//在提一种思路，如果数组中的元素已经排好序了，则它的元素应该与它的下标相同，可以根据这个
//方法实现快速的排序，从而找到重复的数字，当然，这种方法只针对特殊情况。
int main()
{
	test();
	system("pause");
	return 0;
}