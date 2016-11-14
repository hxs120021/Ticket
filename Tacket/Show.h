#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "Collicton.h"
#define BOOL_BACKTICKET 0
#define BOOL_DONTBACKTICKET 1
#define ADDTICKET 2

char *Passwd();
void ShowStartMenu(Tickets *all, Tickets *myH, Tickets *myT);
void ShowMainMenu(Tickets *all ,Tickets *myH, Tickets *myT);
void ShowAdminiMenu(Tickets *all);
void ShowUserMenu(Tickets *all, Tickets *myH, Tickets *myT);
void ShowFindMenu(Tickets *tickets);
void Show_Tickets(Tickets *tickets, int _BOOL);
void Show_FindTickets_End(Tickets *tickets);
void Show_FindTickets_Shift(Tickets *tickets);
void show_AddTickets(Tickets *tickets);


char *Passwd()
{
	char *p = NULL;
	int i;
	for(i = 0; ; i++)
	{
		p[i] = getch();
		if(p[i] == '\r')
			break;
		printf("*");
	}
	p[i] = '\0';
	return p;
}

void ShowStartMenu(Tickets *all, Tickets *myH, Tickets *myT)
{
	int i;
	for(i = 0; i < 30; i++)
	{
		printf("\\\\");
		sleep(20);
	}
	for(i = 0; i < 10; i++)
	{
		printf("||");
		sleep(20);
	}
	printf(">_<");
	sleep(20);
	for(i = 0; i < 15; i++)
	{
		printf("||");
		sleep(20);
	}
	for(i = 0; i < 30; i++)
	{
		printf("//");
		sleep(20);
	}
	printf("\n");
	ShowMainMenu(all, myH, myT);
	return;
}

void ShowMainMenu(Tickets *all, Tickets *myH, Tickets *myT)
{	
	char *user, *passwd;
	printf("deng lu:\n");
	printf("log on :");
	scanf("%s", user);
	printf("passwd :");
	passwd = Passwd();
	if(strcmp(user, "admin") == 0 && strcmp(passwd, "123") == 0)
		ShowAdminiMenu(all);
	else if(strcmp(user, "user") == 0 && strcmp(passwd, "456") == 0)
		ShowUserMenu(all, myH, myT);
	else
		printf("log in is false\n");
	return;
}

void ShowAdminiMenu(Tickets *all)
{
	int index;
	printf("select one:\n");
	printf("1.Add information;\n");
	printf("2.Show all;\n");
	printf("3.Remove;\n");
	scanf("%d", &index);
	switch(index)
	{
		case 1:
			//Show_Tickets();
			Show_AddTickets(all);
			break;
		case 2:
			Show_Tickets(all, BOOL_DONTBACKTICKET);
			break;
		case 3:
			Show_Tickets(all, BOOL_BACKTICKET);
			break;
	}
	return;
}

void ShowUserMenu(Tickets *all, Tickets *myH, Tickets *myT)
{
	int index;
	printf("select one:\n");
	printf("1.My ticket:\n");
	printf("2.My history\n");
	printf("3.Show All\n");
	printf("4.Find Ticket\n");
	scanf("%d", &index);
	switch(index)
	{
		case 1:
		{
			char *isRefund = NULL;
			printf("tui piao me?(yes/no)");
			scanf("%s", isRefund);
			if(strcmp(isRefund, "yes") == 0)
				Show_Tickets(myT, BOOL_BACKTICKET);
			else Show_Tickets(myT, BOOL_DONTBACKTICKET);
		}
		case 2:
			Show_Tickets(myH, BOOL_DONTBACKTICKET);
			break;
		case 3:
			Show_Tickets(all, BOOL_DONTBACKTICKET);
			break;
		case 4:
			ShowFindMenu(all);
			//Show_FindTickets(allTickets);
	}
}

void ShowFindMenu(Tickets *tickets)
{
	int index;
	printf("find shift or endPlease(1/2)");
	scanf("%d", &index);
	switch(index)
	{
		case 1:
			Show_FindTickets_End(tickets);
			break;
		case 2:
			Show_findTickets_Shift(tickets);
			break;
	}
}


void Show_Tickets(Tickets *tickets, int isRefund)
{
	ShowTickets(tickets);
	if(isRefund == BOOL_BACKTICKET)
	{
		int index;
		printf("select eradicate a tickets\n");
		scanf("%d", &index);
		RemoveAt(tickets, index);
		Show_Ticekts(tickets);
	}
}

void Show_FindTickets_End(Tickets *tickets)
{
	printf("you want to please:");
	char *end = NULL;
	scanf("%s", end);
	//Tickets *result = Find(tickets, end);
	ShowTickets(FindEnd(tickets, end));
}

void Show_FindTickets_Shift(Tickets *tickets)
{
	printf("ni xiang zuo de che hao:");
	char *sh = NULL;
	scanf("%s", sh);
	ShowTickets(FindEnd(tickets, sh));
}

 void Show_AddTickets(Tickets *tickets)
{
	Ticket *ticket = newTicekt();
	printf("enter shift:");
	scanf("%s", ticket->shift);
	printf("enter ticketID:");
	scanf("%s", ticket->ticketID);
	printf("enter startTime:");
	scanf("%s", ticket -> startTime);
	printf("enter startPlease:");
	scanf("%s", ticket -> startPlease);
	printf("enter endTime:");
	scanf("%s", ticket -> endTime);
	printf("enter endPlease:");
	scanf("%s", ticket -> endPlease);
	printf("enter maxPeople:");
	scanf("%d", &ticket -> maxPeople);
	Add(tickets, ticket);
	return;
}
