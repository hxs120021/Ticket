#include<stdio.h>
#include<stdlib.h>
#include"Show.h"

int main()
{
//	Tickets *allTickets = newTickets();
//	Tickets *myHistory = newTickets();
//	Tickets *myTickets = newTickets();
	//printf("wwwhello\n");
	Tickets	*allTickets = JsonToTickets(StreamReadB("allTickets.txt"));
//	printf("wwwhello\n");
	Tickets *myHistory = JsonToTickets(StreamReadB("myHistory.txt"));
	Tickets *myTickets = JsonToTickets(StreamReadB("myTickets.txt"));
//	ShowStartMenu(allTickets, myHistory, myTickets );
	ShowMainMenu(allTickets, myHistory, myTickets);
	return 0;
}
