#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

#define BOOL_BACKTICKET 0
#define BOOL_DONTBACKTICKET 1
#define ADDTICKET 2
void Passwd()
void ShowStartMenu();
void ShowMainMenu();
void ShowAdminiMenu();
void ShowUserMenu();
void ShowFindMenu();
void Show_Ticekts(Tickets *ticekts, int bool_BackTicket);
Show_FindTickets(Tickets *ticekts);
Show_AddTickets(Tickets *tickets);



Tickets *allTickets = newTicekts();
Tickets *myHistory = newTickets();
Tickets *myTickets = newTicekts();

void Passwd()
{
	char *p = NULL;
	int i;
	for(i = 0; ; i++)
	{
		a[i] = getch();
		if(a[i] == '\r')
			break;
		printf("*");
	}
	p[i] = '\0';
	return p;
}

void ShowStartMenu()
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
	ShowMainMenu();
	return;
}

void ShowMainMenu()
{	
	char *user, *passwd;
	printf("deng lu:\n");
	printf("log on :");
	scanf("%s", user);
	printf("passwd :");
	passwd = Passwd();
	if(strcmp(user, "admin") == 0 && strcmp(passwd, "123") == 0)
		ShowAdminiMenu();
	else if(strcmp(user, "user") == 0 && strcmp(passwd, "456") == 0)
		ShowUserMenu();
	else
		printf("log in is false\n");
	return;
}

void ShowAdminiMenu()
{
	int index;
	printf("select one:\n");
	printf("1.Add information;\n");
	printf("2.Show all;\n");
	printf("3.Remove;\n");
	scanf("%d", &index);
	switch(index);
	{
		case 1:
			//Show_Tickets();
			Show_AddTickets(allTickets);
			break;
		case 2:
			Show_Tickets(allTickets, BOOL_DONTBACKTICKET);
			break;
		case 3:
			Show_Remove();
			break;
	}
	return;
}

void ShowUserMenu()
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
			char *isRefund = NULL;
			printf("tui piao me?(yes/no)")
			scanf("%s", isRefund);
			if(strcmp(isRefund, "yes") == 0)
				Show_Tickets(myTickets, BOOL_BACKTICKET);
			else Show_Tickets(myTickets, BOOL_DONTBACKTICKET);
		case 2:
			Show_Tickets(myHistory, BOOL_DONTBACKTICKET);
			break;
		case 3:
			Show_Tickets(allTickets, BOOL_DONTBACKTICKET);
			break;
		case 4:
			ShowFindMenu();
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
			Show_FindTickets(tickets)
			break;
		case 2:
			break;
	}
}

void Show_Tickets(Tickets *ticekts, int isRefund)
{
	Show_Tickets(tickets);
	if(isRefund == BOOL_BACKTICKET)
	{
		int index;
		printf("select refund ticket\n");
		scanf("%d", &index);
		RemoveAt(tickets, index);
		Show_Ticekts(tickets);
	}
}

void Show_findTickets(Ticekts * tickets)
{
	printf("you want to please:")
	char *end = NULL;
	scanf("%s", end);
	//Tickets *result = Find(tickets, end);
	ShowTickets(FindEnd(tickets, end));
}

Show_AddTickets(Tickets *tickets)
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
	scanf("%d", &ticket -> maxPeople)
	Add(tickets, ticket);
	return;
}
