#include<stdio.h>
#include<stdlib.h>
#include"Show.h"

int main()
{
	Tickets *allTickets = newTickets();
	Tickets *myHistory = newTickets();
	Tickets *myTickets = newTickets();
	allTickets = JsonToTickets(StreamRead("allTickets.txt"));
	myHistory = JsonToTickets(StreamRead("myHistory.txt"));
	myTickets = JsonToTickets(StreamRead("myTickets.txt"));
//	ShowStartMenu(allTickets, myHistory, myTickets );
	ShowMainMenu(allTickets, myHistory, myTickets);
	return 0;
}
