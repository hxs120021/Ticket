#include<stdio.h>
#include<stdlib.h>
#include "JSON.h"

void Work_Add(Tickets *tickets,  string jsonString, const string path)
{
	Tickets *t = JsonToTickets(jsonString);
	AddAll(tickets, t);
	StreamWrite(path, TicketsToJson(tickets));
}

void Wrok_Remove(Tickets *tickets, int index, const string path)
{
	RemoveAt(tickets, index);
	streamWrite(path, TicketsToJson(ticktes));
}

string Work_Find(Tickets *tickets, string end)
{
	Tickets *ts = Find(tickets, end);
	if (ts -> head -> next == NULL)
		return "NULL";
	else
		return TicketsToJson(ts);
}
