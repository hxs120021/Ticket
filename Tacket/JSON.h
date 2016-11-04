#include<stdio.h>
#include<stdlib.h>
#include"Collicton.h"
#include"cJSON/cJSON.c"

typedef cJSON * cJson;

Tickets *JsonToTickets(string json)
{

}

string TicketsToJson(Tickets *tickets, int len)
{
//	printf("%d", len);
	cJson root, itemRoot[len];
	root = cJSON_CreateObject();
	Ticket *work = tickets -> head -> next;
	char *p;
	int i = 0;
	while(work != NULL)
	{
//		printf("%d\n", i);
		itemRoot[i] = cJSON_CreateObject();
		cJSON_AddStringToObject(itemRoot[i], "shift", work -> shift);
		cJSON_AddItemToArray(root, itemRoot[i]);
		work = work -> next;
		i++;
	}
	p = cJSON_Print(root);
	cJSON_Delete(root);
	return p;
}

string TicketToJson(Ticket *ticket)
{
	cJSON *root = cJSON_CreateObject();
	char *p;
	cJSON_AddStringToObject(root, "shift", ticket -> shift);
	p = cJSON_Print(root);
	cJSON_Delete(root);
	return p;
}
