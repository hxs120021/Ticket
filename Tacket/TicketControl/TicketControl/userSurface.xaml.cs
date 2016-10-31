using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace TicketControl
{
    /// <summary>
    /// userSurface.xaml 的交互逻辑
    /// </summary>
    public partial class userSurface : Window
    {
        //List<Ticket> tickteList = new List<Ticket>();
        public userSurface()
        {
            InitializeComponent();
            InitializeTacket();
        }

        private void AdministorButton_Click(object sender, RoutedEventArgs e)
        {
            WhoMainWindow.isAdministor = true;
            MainWindow m = new MainWindow();
            m.Title = "管理员--登录";
            m.tileBlockBox.Text = "车票--管理端";
            m.logonTextBlock.Visibility = Visibility.Hidden;
            m.findTextBlock.Visibility = Visibility.Hidden;
            m.Show();
        }
        //这里要获取MyTicket.myTickets的数据源，然后绑定
        private void InitializeTacket()
        {

            MyTicket.myTickets.Add(new Ticket("K31", "127001", "15:00", "上海", "6:00", "济南", 5000, 4000, 1000, RookState.NotStart));
            MyTicket.myTickets.Add(new Ticket("K32", "127001", "15:00", "上海", "6:00", "济南", 5000, 4000, 1000, RookState.NotStart));
            MyTicket.myTickets.Add(new Ticket("K33", "127001", "15:00", "上海", "6:00", "济南", 5000, 4000, 1000, RookState.NotStart));
            MyTicket.myTickets.Add(new Ticket("K34", "127001", "15:00", "上海", "6:00", "济南", 5000, 4000, 1000, RookState.NotStart));
            MyTicket.myTickets.Add(new Ticket("K35", "127001", "15:00", "上海", "6:00", "济南", 5000, 4000, 1000, RookState.NotStart));
            MyTicket.myTickets.Add(new Ticket("K36", "127001", "15:00", "上海", "6:00", "济南", 5000, 4000, 1000, RookState.NotStart));
            MyTicket.myTickets.Add(new Ticket("K37", "127001", "15:00", "上海", "6:00", "济南", 5000, 4000, 1000, RookState.NotStart));
            MyTicket.myTickets.Add(new Ticket("K38", "127001", "15:00", "上海", "6:00", "济南", 5000, 4000, 1000, RookState.NotStart));
            MyTicket.myTickets.Add(new Ticket("K39", "127001", "15:00", "上海", "6:00", "济南", 5000, 4000, 1000, RookState.NotStart));
            MyTicket.myTickets.Add(new Ticket("K30", "127001", "15:00", "上海", "6:00", "济南", 5000, 4000, 1000, RookState.NotStart));
            this.TicketlistBox.ItemsSource = MyTicket.myTickets;
        }

        private void AddButton_Click(object sender, RoutedEventArgs e)
        {
            string shiftA = this.AddShiftBox.Text;
            string startPlease = this.AddStartPleaseBox.Text;
            string startTime = this.AddStartTimeBox.Text;
            string endPelase = this.AddEndPleaseBox.Text;
            string endTime = this.AddEndTimeBox.Text;
            int maxPlease = Convert.ToInt32(this.AddMaxPeopleBox.Text);

            //MyTicket.ticketHistory.Add()
        }
    }
}
