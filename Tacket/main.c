#include<stdio.h>
#include<stdlib.h>
#include"Show.h"
/*
int main()
{
	Tickets	*allTickets = newTickets();
	AddAll(allTickets, JsonToTickets(StreamRead("allTickets.txt")));
	printf("%d", GetLength(allTickets));
	Tickets *myHistory = newTickets(); //JsonToTickets(StreamRead("myHistory.txt"));
	AddAll(myHistory, JsonToTickets(StreamRead("myHistory.txt")));
	Tickets *myTickets = newTickets(); //JsonToTickets(StreamRead("myTickets.txt"));
	AddAll(myTickets, JsonToTickets(StreamRead("myTickets.txt")));
//	ShowStartMenu(allTickets, myHistory, myTickets);
	ShowMainMenu(allTickets, myHistory, myTickets);
	return 0;
}
*/
int main()
{
	printf("111111---\n\n\n\n");
	Tickets *allTickets = JsonToTickets(StreamReadB("allTickets.txt"));
	printf("111111---\n\n\n\n\n");
	Tickets *myHistory = JsonToTickets(StreamReadB("myHistory.txt"));
	Tickets *myTickets = JsonToTickets(StreamReadB("myTickets.txt"));
	ShowMainMenu(allTickets, myHistory, myTickets);
	return 0;
}
