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
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace TicketControl
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        private static userSurface user = new userSurface();

        public MainWindow()
        {
            InitializeComponent();
        }

        private void signInButton_Click(object sender, RoutedEventArgs e)
        {
            if(WhoMainWindow.isAdministor)
                user.AdLogItem.Visibility = Visibility.Visible;
            user.Show();
            this.Close();
        }
    }
}
