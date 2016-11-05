#include<stdio.h>
#include<stdlib.h>
//#include"Collicton.h"
#include"FileIO.h"
int main()
{
	//Tickets *tickets = (Ticktes*)malloc(sizeof(Tickets));
	Tickets *tickets = newTickets();
	
	Ticket *t = (Ticket*)malloc(sizeof(Ticket));
	t->shift = "KW123";
	t->next = NULL;
	t->previous = NULL;

	Ticket *t2 = (Ticket*)malloc(sizeof(Ticket));
	t2 -> shift = "kw456";
	t2 -> next = NULL;
	t2 -> previous = NULL;


	Add(tickets, t);
	AddAt(tickets, t2, 0);
	WritLine(tickets);

//	printf("%s\n", Remove(tickets, first)->shift);
//	printf("%s\n", RemoveAt(tickets, 0)->shift);

	StreamWrite("1.txt", "hello, world");
	printf("%s\n",StreamRead("1.txt"));
	string s = TicketsToJson(tickets, GetLength(tickets));
//	printf("%s\n", TicketsToJson(tickets, GetLength(tickets)));
	printf("%s\n", s);
	printf("hello\n");
	
//	printf("%s\n", JsonToTickets(s) -> shift);
	WritLine(JsonToTickets(s));
	return 0;
}

