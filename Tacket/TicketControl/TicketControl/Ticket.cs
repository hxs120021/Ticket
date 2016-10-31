using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TicketControl
{
    class Ticket : TicketBase
    {
        public Ticket(string shift, string ticketID, string startTime, string startPlease, string endTime, 
            string endPlease    , int maxPeople, int earlyPeople, int nightPeople, RookState rookStake)
        {
            this.shift = shift;
            this.ticketID = ticketID;
            this.startTime = startTime;
            this.startPlease = startPlease;
            this.endTime = endTime;
            this.endPlease = endPlease;
            //this.needTime = needTime;
            this.maxPeople = maxPeople;
            this.earlyPeople = earlyPeople;
            this.nightPeople = nightPeople;
            this.rookState = rookStake; 
        }

        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();
            sb.Append("shift:"); sb.Append(this.shift); 
            sb.Append("\n tickteID:"); sb.Append(ticketID);
            sb.Append("\n startTime"); sb.Append(startTime);
            sb.Append("\n startPlease:"); sb.Append(startPlease);
            sb.Append("\n endTime:");sb.Append(endTime);
            sb.Append("\n needPlase:"); sb.Append(endPlease);
            //sb.Append("\n needTime:"); sb.Append(needTime);
            sb.Append("\n maxPeople:"); sb.Append(maxPeople.ToString());
            sb.Append("\n earlyPeople"); sb.Append(earlyPeople.ToString());
            sb.Append("\n nightPeople"); sb.Append(nightPeople.ToString());
            sb.Append("\n rookState"); sb.Append(rookState);
            return sb.ToString();
        }
    }

    class TicketSource : ObservableCollection<Ticket>
    {
        public void AddSource(Ticket ticket)
        {
            base.Add(ticket);
        }

        public void RemoveSource(Ticket ticket)
        {
            base.Remove(ticket);
        }
        public void RemoveAtSource(int index)
        {
            base.RemoveAt(index);
        }
        public void RemoveItemSource(int index)
        {
            base.RemoveItem(index);
        }
    }

    
}
