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

void Add(Tickets *tickets, Ticket *ticket)
{
	
	ticket->previous = tickets->last;
	tickets->last->next = ticket;
	tickets->last = ticket;
	
	/*
	&(ticket -> previous) = &(tickets->last);
	&(tickets -> last -> next) = &(ticket);
	&(tickets -> last) = &ticket;
	*/
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
		printf("change function. eg:AddAt\n");
	else
	{
		Ticket *work = tickets -> head -> next;
		int i;
		for(i = 0; i < index; i++)
			work = work -> next;
		Ticket *workp = work -> previous;
		ticket -> previous = workp;
		ticket -> next = work;
		work -> previous = ticket;
		workp -> next = ticket;
	}

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
		printf("change function. eg:Reomve.\n");
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
