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
    string ticketID;//车票号 自动生成
    string startTime;//发车时间 手动
    string startPlease;//起始地点 手动
    string endTime;//预计结束时间 手动
    string endPlease;//终点站
    int maxPeople;//最大搭载人数
    int earlyPeople;//已经买了票的人数
    int nightPeople;//还剩下的座位
    RookState rookState;//现在车的状况
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
    Tickets *myTickets;
    Tickets *allTickets;
}NeedTickets;


string ConvertToRookState(RookState rookState)
{
    string work = NULL;
    switch(rookState)
    {
        case RookStart:
//            strcpy(work, "RookStart");
			work = "RookStart";
            break;
       case NotStart:
			work = "NotStart";
//            strcpy(work, "NotStart");
            break;
       case Delay:
			work = "Delay";
//	        strcpy(work, "Delay");
			break;
	   case Trouble:
			work = "Trouble";
//			strcpy(work, "Trouble");		
			break;								
	}
	return work;
}


