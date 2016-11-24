#ifndef JSON_H_INCLUDED
#define JSON_H_INCLUDED
#endif // JSON_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include"Collicton.h"
#include"cJSON/cJSON.c"

typedef cJSON * cJson;

void TicketAddValue(Ticket *ticket, cJson cjson)
{

	ticket -> shift = cJSON_GetObjectItem(cjson, "shift") -> valuestring;

	ticket -> ticketID = cJSON_GetObjectItem(cjson, "ticketID") -> valuestring;
	ticket -> startTime = cJSON_GetObjectItem(cjson, "startTime") -> valuestring;
	ticket -> startPlease = cJSON_GetObjectItem(cjson, "startPlease") -> valuestring;
	ticket -> endTime = cJSON_GetObjectItem(cjson, "endTime") -> valuestring;
	ticket -> endPlease = cJSON_GetObjectItem(cjson, "endPlease") -> valuestring;
	ticket -> maxPeople = cJSON_GetObjectItem(cjson, "maxPeople") -> valueint;
	ticket -> earlyPeople = cJSON_GetObjectItem(cjson, "earlyPeople") -> valueint;
	ticket -> nightPeople = cJSON_GetObjectItem(cjson, "nightPeople") -> valueint;
	ticket -> rookState = cJSON_GetObjectItem(cjson, "rookState") -> valueint;

}

void AddTicketValue(cJson cjson, Ticket *ticket)
{
	cJSON_AddStringToObject(cjson, "shift", ticket -> shift);

	cJSON_AddStringToObject(cjson, "ticketID", ticket -> ticketID);
	cJSON_AddStringToObject(cjson, "startTime", ticket -> startTime);
	cJSON_AddStringToObject(cjson, "startPlease", ticket -> startPlease);
	cJSON_AddStringToObject(cjson, "endTime", ticket -> endTime);
	cJSON_AddStringToObject(cjson, "endPlease", ticket -> endPlease);
	cJSON_AddNumberToObject(cjson, "maxPeople", ticket -> maxPeople);
	cJSON_AddNumberToObject(cjson, "earlyPeople", ticket -> earlyPeople);
	cJSON_AddNumberToObject(cjson, "nightPeople", ticket -> nightPeople);
	cJSON_AddNumberToObject(cjson, "rookState", ticket -> rookState);
}

Tickets *JsonToTickets(string json)
{
	//printf("%s\n", json);
	cJson root, arrayItem, item;
	int i = 0;// size = 0;
	root = cJSON_Parse(json);

	Tickets *tickets = newTickets();

	string p = NULL;
	while(1)
	{
		Ticket *ticket = (Ticket*)malloc(sizeof(Ticket));
		arrayItem = cJSON_GetArrayItem(root, i);
		if(arrayItem)
		{
			p = cJSON_Print(arrayItem);
			item = cJSON_Parse(p);

			TicketAddValue(ticket, item);
			Add(tickets, ticket);
			i++;
		}
		else break;
	}
	cJSON_Delete(root);

	return tickets;
}

string TicketsToJson(Tickets *tickets)
{
//	printf("%d", len);
	int len = GetLength(tickets);
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

