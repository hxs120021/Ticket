#include<stdio.h>
#include<stdlib.h>
#include"Collicton.h"
#include"cJSON/cJSON.c"
Tickets *JsonToTickets(string json)
{
	cJSON *root = cJSON_Parse(json);

//	int iSize = cJSON_Parse(root), i;
	cJSON *cShift = cJSON_GetObjectItem(root, "shift");
	Tickets *cTickets = newTickets();
	Ticket *cTicket = (Ticket*)malloc(sizeof(Ticket));
	cTicket -> shift = cShift->valuestring;
	cTicket -> next = NULL;
	cTicket -> previous = NULL;
	Add(cTickets, cTicket);
}

string TicketsToJson(Tickets *tickets)
{
	cJSON *root = cJSON_CreateObject();
	printf("1\n");
	Ticket *work = tickets->head->next;
	printf("2\n");
	string p;
	while(work != NULL)
	{
		cJSON *rootItem = cJSON_CreateObject();
		printf("3\n");
		cJSON_AddStringToObject(rootItem, "shift", work-> shift);
		cJSON_AddItemToObject(root, "rootItem", rootItem);
		printf("4\n");
		work = work -> next;
		cJSON_Delete(rootItem);
	}
	printf("5\n");
	p = cJSON_Print(root);
	printf("6\n");
	if(p == NULL)
	{
		printf("8\n");
		cJSON_Delete(root);
		return NULL;
	}
	else return p;
}

