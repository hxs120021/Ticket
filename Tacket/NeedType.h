#include <string.h>
#include <stdlib.h>
#include <stdio.h>
typedef char * string;

typedef enum
{
	    RookStart = 1,//出发
		NotStart = 2,//没出发
	    Delay = 3,//延班
	    Trouble = 4//故障
}RookState;
typedef struct T
{
	string shift;//车次 手动
//    string ticketID;//车票号 自动生成
//    string startTime;//发车时间 手动
//    string startPlease;//起始地点 手动
//    string endTime;//预计结束时间 手动
//    string endPlease;//终点站
//    string maxPeople;//最大搭载人数
//    string earlyPeople;//已经买了票的人数
//    string nightPeople;//还剩下的座位
//    RookState rookState;//现在车的状况
    struct T *next;	
	struct T *previous;
}Ticket;


typedef struct HeadAndLast
{
    Ticket *head;
    Ticket *last;
}Tickets;

typedef struct
{
    Tickets *myTicket;
    Tickets *ticketHistory;
}MyTicket;


string ConvertToRookState(RookState rookState)
{
    string work = NULL;
    switch(rookState)
    {
        case RookStart:
            strcpy(work, "RookStart");
            break;
       case NotStart:
            strcpy(work, "NotStart");
            break;
       case Delay:
	        strcpy(work, "Delay");
			break;
	   case Trouble:
			strcpy(work, "Trouble");		
			break;								
	}
		return work;
}


string toString(Ticket *ticket)
{
	string work = " ";
	strcat(work, ticket->shift);
	return work;
}

/*
string toString(Ticket *ticket)
{
    string work = NULL;
    strcpy(work, ticket->shift );
    strcpy(work, ticket->ticketID);
    strcpy(work, ticket->startTime);
    strcpy(work, ticket->startPlease);
    strcpy(work, ticket->endTime);
    strcpy(work, ticket->endPlease);
    strcpy(work, ticket->maxPeople);
    strcpy(work, ticket->earlyPeople);
    strcpy(work, ticket->nightPeople);
    strcpy(work, ConvertToRookState(ticket->rookState));
    return work;
}
*/
