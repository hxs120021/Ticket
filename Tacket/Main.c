#include<stdio.h>
#include<stdlib.h>
#include"Show.h"

int main()
{
	Tickets *allTickets = newTicekts();
	Tickets *myHistory = newTickets();
	Tickets *myTickets = newTicekts();
	ShowStartMenu(allTickets, myHistory, myTickets );
	return 0;
}
