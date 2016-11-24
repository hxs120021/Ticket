#ifndef FILEIO_H_INCLUDED
#define FILEIO_H_INCLUDED
#endif // FILEIO_H_INCLUDED

#include<stdio.h>
//#include"JSON.h"
//#include "Collicton.h"
#include<stdlib.h>

string StreamRead(const string filePath);
void StreamWrite(const string fliePath, string jsonString);

string StreamRead(const string filePath)
{
//	printf("%s\n", filePath);

	char json[1024];
	string jsonString = json;
	FILE *fp;
	fp = fopen(filePath, "rb");
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
	//printf("%s\n", jsonString);
	FILE *fp;
	fp = fopen(filePath, "wb");
	if (fp == NULL)
	{
		printf("file open is failed\n");
		return;
	}

	fputs(jsonString, fp);
	fclose(fp);
	return;
}

string StreamReadB(const string filePath)
{
	FILE *fp;
	fp = fopen(filePath, "rb");
	fseek(fp, 0, SEEK_END);
	int file_size;
	file_size = ftell(fp);
	string tmp;
	fseek(fp, 0, SEEK_SET);
	tmp = (string)malloc(sizeof(char) * file_size);
	fread(tmp, file_size, sizeof(char), fp);
	return tmp;
}

