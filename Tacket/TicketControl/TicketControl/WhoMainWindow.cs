using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TicketControl
{
    enum RookState
    {
        Start = 0,//出发
        NotStart = 1,//未出发
        Delay = 2,//延班
        Trouble = 4//故障
    }


    class WhoMainWindow
    {
        public static bool isAdministor = false;
    }

    abstract class TicketBase
    {
        public string shift { get; set; }//车次 手动
        public string ticketID { get; set; }//车票号 由后台生成
        public string startTime { get; set; }//发车时间 手
        public string startPlease { get; set; }//起始地点 手
        public string endTime { get; set; }//预计结束时间 手
        public string endPlease { get; set; }//终点站 手
        //public string needTime { get; set; }//需要时间
        public int maxPeople { get; set; }//最大承载人数 手
        public int earlyPeople { get; set; }//已经买票的人数 后台计算
        public int nightPeople { get; set; }//还剩的座位 后台计算
        public RookState rookState { get; set; }//车现在的情况 按照时间计算
    }

    class MyTicket
    {
        public static List<Ticket> myTickets = new List<Ticket>();
        public static List<Ticket> ticketHistory = new List<Ticket>();
    }

}
