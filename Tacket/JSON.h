#include<stdio.h>
#include<stdlib.h>
#include"Collicton.h"
#include"cJSON/cJSON.c"

typedef cJSON * cJson;

void TicketAddValue(Ticket *ticket, cJson cjson)
{
	ticket -> shift = cJSON_GetObjectItem(cjson, "shift") -> valuestring;
	//more
}

void AddTicketValue(cJson cjson, Ticket *ticket)
{
	cJSON_AddStringToObject(cjson, "shift", ticket -> shift);
	//more
}

Tickets *JsonToTickets(string json)
{
	cJson root, arrayItem, item;
	int i = 0, size = 0;
	root = cJSON_Parse(json);
	size = cJSON_GetArraySize(root);
	Tickets *tickets = newTickets();
//	cJSON_Delete(root);
	string p = NULL;
	while(1)
	{
		Ticket *ticket = (Ticket*)malloc(sizeof(Ticket));
		arrayItem = cJSON_GetArrayItem(root, i);
		if(arrayItem)
		{
			p = cJSON_Print(arrayItem);
			item = cJSON_Parse(p);
//			ticket -> shift = cJSON_GetObjectItem(item, "shift") -> valuestring;
			TicketAddValue(ticket, item);
			Add(tickets, ticket);
			i++;
		}
		else break;
	}
	return tickets;
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
//		cJSON_AddStringToObject(itemRoot[i], "shift", work -> shift);
		AddTicketValue(itemRoot[i], work);
		cJSON_AddItemToArray(root, itemRoot[i]);
		work = work -> next;
		i++;
	}
	p = cJSON_Print(root);
	cJSON_Delete(root);
	return p;
}

