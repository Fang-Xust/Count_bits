# Count_bits

面试题：如何最快求出一个数的二进制序列中有几个1。

#include<stdio.h>
#include<windows.h>
int Count_1_bits1(int x)
{
	int count = 0;
	while (x)
	{                       //模2取余
		if (x % 2 == 1)
		{
			count++;
		}
		x /= 2;
	}
	return count;
}
int Count_1_bits2(int x)
{                           //将目标数和1按位与&
	int count = 0;
	int i = 0;
	while (i < sizeof(int)*8 - 1)//第一次按位与时左移0次，检测最高位时左移32次，所以这里 比特位-1
	{
		if (x & (1<<i))        //如果按位与为真，说明与1按位与的那一位数字也是1，count++
		{
			count++;
		}
		i++;
	}
	return count;
}
int Count_1_bits3(int x)
{                             //面试题最佳答案，用自己本身x去按位与x-1
	int count = 0;
	while (x)
	{
		x = x & (x - 1);
		count++;
	}
	return count;
}
int main()
{
	int x = 0;
	printf("输入一个数：");
	scanf("%d",&x);
	int result = Count_1_bits3(x);
	printf("此数的二进制中有%d个1\n",result);
	system("pause");
	return 0;
}
