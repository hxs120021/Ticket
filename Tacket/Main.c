#include<stdio.h>
#include<stdlib.h>
#include"Show.h"

int main()
{
	Tickets *allTickets = newTickets();
	Tickets *myHistory = newTickets();
	Tickets *myTickets = newTickets();
//	ShowStartMenu(allTickets, myHistory, myTickets );
	ShowMainMenu(allTickets, myHistory, myTickets);
	return 0;
}
