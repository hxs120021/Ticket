#include<stdio.h>
#include<stdlib.h>

void TiaoMu(char buf)
{
	switch(buf)
	{
		case '1':
			printf("添加\n");
			break;
		case '2':
			printf("删除\n");
			break;
		default:
			printf("爱咋咋地\n");
	}
}
