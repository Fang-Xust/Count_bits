# Count_bits
//整形提升的例子1：

#include<stdio.h>
int main()
{
	char a = 0xb6;
	short b = 0xb600;
	int c = 0xb6000000;         //程序执行后只打印C
	if (a == 0xb6)
		printf("a");
	if (b == 0xb600)
		printf("b");
	if (c == 0xb6000000)
		printf("c");
	return 0;
}
//a,b要进行整形提升,但是c不需要整形提升，a,b整形提升之后,变成了负数,
//所以表达式 a==0xb6 , b==0xb600 的结果是假,但是c不发生整形提升,则表达式 c==0xb6000000 的结果是真，最后只打印C。

//整型提升的例子2：

int main() 
{
    char c = 1;
    printf("%u\n", sizeof(c));
    printf("%u\n", sizeof(+c));
    printf("%u\n", sizeof(!c));    
    return 0; 
//c只要参与表达式运算,就会发生整形提升,表达式 +c ,就会发生提升,
//所以 sizeof(+c) 是4个字节。表达式 -c 也会发生整形提升,所以 sizeof(-c) 是4个字节,但是 sizeof(！c) ,就是1个字节。
