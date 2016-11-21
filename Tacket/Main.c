#include<stdio.h>
#include<stdlib.h>
#include"Show.h"

int main()
{
	printf("wwwhello\n");
	Tickets	*allTickets = StreamReadC("allTickets.txt");
	printf("wwwhellokk\n");
	Tickets *myHistory = StreamReadC("myHistory.txt");
	Tickets *myTickets = StreamReadC("myTickets.txt"); 
	ShowMainMenu(allTickets, myHistory, myTickets);
	return 0;
}
