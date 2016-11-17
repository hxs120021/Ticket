#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
//#include "JSON.h"
#include "FileIO.h"
//#include "Collicton.h"
#define BOOL_BACKTICKET 0
#define BOOL_DONTBACKTICKET 1
#define ADDTICKET 2

char *Passwd();
void ShowStartMenu(Tickets *all, Tickets *myH, Tickets *myT);
void ShowMainMenu(Tickets *all ,Tickets *myH, Tickets *myT);
void ShowAdminiMenu(Tickets *all);
void ShowUserMenu(Tickets *all, Tickets *myH, Tickets *myT);
void ShowFindMenu(Tickets *tickets);
void Show_Tickets(Tickets *tickets, int isRefund);
void Show_FindTickets_End(Tickets *tickets);
void Show_FindTickets_Shift(Tickets *tickets);
void Show_AddTickets(Tickets *tickets);


char *Passwd()
{
	char *p = NULL;
	int i;
	for(i = 0; ; i++)
	{
		p[i] = getchar();
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

	char user[10], passwd[20];
	printf("deng lu:\n");
	printf("log on :");
	scanf("%s", user);
//	gets(user);
	printf("passwd :");
//	passwd = Passwd();
//	gets(passwd);
	scanf("%s", passwd);
	if(strcmp(user, "admin") == 0 && strcmp(passwd, "123") == 0)
		ShowAdminiMenu(all);
	else if(strcmp(user, "user") == 0 && strcmp(passwd, "456") == 0)
		ShowUserMenu(all, myH, myT);
	else
		printf("log in is false\n");
	StreamWrite("allTickets.txt", TicketsToJson(all));
	StreamWrite("myTickets.txt", TicketsToJson(myT));
	StreamWrite("myHistory.txt", TicketsToJson(myH));
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
			char isRefund[10];
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
			Show_FindTickets_Shift(tickets);
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
		ShowTickets(tickets);
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
	char sh[12], ti[12], sT[20], sP[12], eT[12], eP[12];
	int max;
	Ticket *ticket = newTicket();
	printf("enter shift:");
	scanf("%s", sh);
//	gets(sh);
	printf("enter ticketID:");
	scanf("%s", ti );
//	gets(ti);
	printf("enter startTime:");
	scanf("%s", sT);
//	gets(sT);
	printf("enter startPlease:");
	scanf("%s", sP);
//	gets(sP);
	printf("enter endTime:");
	scanf("%s", eT);
//	gets(eT);
	printf("enter endPlease:");
	scanf("%s", eP);
//	gets(eP);
	printf("enter maxPeople:");
	scanf("%d", &max);
	ticket -> shift = sh;
	ticket -> ticketID = ti;
	ticket -> startTime = sT;
	ticket -> startPlease = sP;
	ticket -> endTime = eT;
	ticket -> endPlease = eP;
	ticket -> maxPeople = max;
	ticket -> earlyPeople = 999;
	ticket -> nightPeople = 999;
	ticket -> rookState = 1;
	printf("hello----%s",ticket -> shift);
	Add(tickets, ticket);
	return;
}
