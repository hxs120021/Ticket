#include<stdio.h>
#include"JSON.h"
#include<stdlib.h>
string StreamRead(const string filePath)
{
	char json[1024];
	string jsonString = json;
	FILE *fp;
	fp = fopen(filePath, "r");
	if(fp == NULL)
	{
		printf("file open is failed\n");
		return NULL;
	}
	fgets(jsonString,1024,fp);
	
	fclose(fp);
	return jsonString;
}

void StreamWrite(const string filePath, string jsonString)
{
	FILE *fp;
	fp = fopen(filePath, "w");
	if (fp == NULL)
	{
		printf("file open is failed\n");
		exit(0);
	}
	
	fputs(jsonString, fp);
	 fclose(fp);
	return;
}


