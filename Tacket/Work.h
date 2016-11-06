#include<stdio.h>
#include<stdlib.h>
#include "JSON.h"

void Work_AddMy(Tickets *tickets,  string jsonString)
{
	Tickets *t = JsonToTickets(jsonString);
	AddAll(tickets, t);
	StreamWrite("my.txt", TicketsToJson(tickets));
	
	
}
