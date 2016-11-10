#include <stdio.h>
#include <stdlib.h>
#include "NeedType.h"

typedef enum{
	first,last
}RemoveMode;

void Add(Tickets *tickets, Ticket *ticket);
void WritLine(Tickets *tickets);
void AddAt(Tickets *tickets, Ticket *ticket, int index);
int GetLength(Tickets *tickets);
Tickets *newTickets();

Tickets *newTickets()
{
	Tickets *tickets = (Tickets*)malloc(sizeof(Tickets));
	tickets->head = (Ticket*)malloc(sizeof(Ticket));
	tickets->last = tickets->head;
	tickets->head->next = NULL;
    tickets->head->previous= NULL;
	return tickets;
}

NeedTickets *newNeedTicekts()
{
	NeedTickets *needTickets = (NeedTickets*)malloc(sizeof(NeedTickets));
	needTickets -> myTickets = newTickets();
	needTicekts -> allTickets = newTickets();
	return needTickets;
}

void Add(Tickets *tickets, Ticket *ticket)
{
	
	ticket->previous = tickets->last;
	tickets->last->next = ticket;
	tickets->last = ticket;
}

void WritLine(Tickets *tickets)
{
	Ticket *work = tickets -> head -> next;
	while(work != NULL)
	{
		printf("%s\n",work -> shift);
		work = work -> next;
	}
	return;
}

void AddAt(Tickets *tickets, Ticket *ticket, int index)
{
	if(index > GetLength(tickets) || index < 0)
	{
		printf("index is error, you need change index\n");
		return;
	}
	else if(index == GetLength(tickets))
//		printf("change function. eg:AddAt\n");
		Add(tickets, ticket);
	else
	{
		Ticket *work = tickets -> head -> next;
		int i;
		for(i = 0; i < index; i++)
			work = work -> next;
		Ticket *workp = work -> previous;
		ticket -> previous = work;
		ticket -> next = work;
		work -> previous = ticket;
		work -> next = ticket;
	}

}

void AddAll(Tickets *tickets, Tickets *ts)
{
	tickets -> last -> next = ts -> head;
	ts -> head -> previous = tickets -> last;
	tickets -> last = ts -> last;
}

int GetLength(Tickets *tickets)
{
	int length = 0;
	Ticket *work = tickets -> head -> next;
	while(work != NULL)
	{
		length++;
		work = work -> next;
	}
	return length;
}

Ticket *Remove(Tickets *tickets, RemoveMode rmode)
{
	Ticket *work, *p;
	switch(rmode)
	{
		case first:
			p = tickets->head->next;
			work = p->next;
			tickets->head->next = work;
			work->previous = tickets -> head;
			p->next = NULL;
			p->previous = NULL;
			break;
		case last:
			p = tickets -> last;
			tickets -> last = p -> previous;
			tickets -> last -> next = NULL;
			p -> previous = NULL;
			break;
	}
	return p;
}

Ticket *RemoveAt(Tickets *tickets, int index)
{
//	index = index + 1;
	if(index > GetLength(tickets) || index < 0)
	{
		printf("index is error, you need change index,in RemoveAt\n");
		exit(0);
	}
	else if(index == GetLength(tickets))
	{
		printf("change function. eg:Reomve.\n");
		return NULL;
	}
	else
	{
		Ticket *work = tickets -> head ->next, *p;
		int i;
		for(i = 0; i < index; i++)
			work = work -> next;
		Ticket *work1 = work -> previous;
		p = work;
		work = work -> next;
		work -> previous = work1;
		work1 -> next = work;
		p -> next = NULL;
		p -> previous = NULL;
		return p;
	}
}

int Equal(Ticket *t1, Ticket *t2)
{
	int n = 0;
	switch(n)
	{
		case 0:
			if(strcmp(t1 -> shift, t2 -> shift) != 0)
				break;
			else{}
		case 1:
			if(strcmp(t1 -> ticketID, t2 -> ticketID) != 0)
				break;
			else{}
		case 2:
			if(strcmp(t1 -> startTime, t2 -> startTime) != 0)
				break;
			else {}
		case 3:
			if(strcmp(t1 -> startPlease, t2 -> startPlease) != 0)
				break;
			else{}
		case 4:
			if(strcmp(t1 -> endTime, t2 -> endTime) != 0)
				break;
			else{}
		case 5:
			if(strcmp(t1 -> endPlease, t2 -> endPlease) != 0)
				break;
			else{}
		case 6:
			if(t1 -> maxPeople == t2 -> maxPeople)
				break;
			else{}
		case 7:
			if(t1 -> earlyPeople == t2 -> earlyPeople)
				break;
			else{}
		case 8:
			if(t1 -> nighitPeople == t2 -> nightPeople)
				break;
			else{}
		default:
			return 1;
	}
	return 0;
}

Tickets *Find(Tickets *tickets, string end)
{
	Tickets *ts = newTickets();
	Ticket *work = tickets -> head -> next;
	while(work =! NULL)
	{
		if(strcmp(work -> endPlease, end) == 0)
			Add(ts, work);
		work = work -> next;
	}
	return ts;
}
