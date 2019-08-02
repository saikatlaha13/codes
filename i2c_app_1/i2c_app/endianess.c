#include<stdio.h>
int main()
{
	int value=0x12345678;
	char *addr=(char*)&value;

	if(*addr==0x78)
	{
		printf("little endian\n");
	}
	else
	{
		printf("big endian\n");
	}
}
