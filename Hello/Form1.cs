using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO.Ports;
using System.Linq;
using System.Media;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Hello
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {

        }
       
        private void serialPort1_DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {


        }

        private void Form1_Load(object sender, EventArgs e)
        {
            backgroundWorker1.RunWorkerAsync();
        }
        protected override void OnClosing(CancelEventArgs e)
        {
            base.OnClosing(e);
           
        }
 char[] tt = new char[2] { '*', '*' };
        private void backgroundWorker1_DoWork(object sender, DoWorkEventArgs e)
        {
           
            using (SerialPort port = new SerialPort("COM5", 115200))
            {
                port.Open();
                int b = -1;
                while (!backgroundWorker1.CancellationPending)
                {

                    b = port.ReadByte();

                    if ((b >= 0x30) && (b <= 0x39))
                    {
                        tt[0] = tt[1];
                        tt[1] = (b - 0x30).ToString()[0];
                        backgroundWorker1.ReportProgress(1);
                    }
                    else if (b == 0x23)
                    {
                        backgroundWorker1.ReportProgress(2);
                       

                    }
                    else
                    {
                        Thread.Sleep(100);
                    }
                    
                }
                port.Close();
            }
        }

        private void backgroundWorker1_ProgressChanged(object sender, ProgressChangedEventArgs e)
        {
            if (e.ProgressPercentage == 1)
            {
                label1.ForeColor = Color.Salmon;
                label1.Text = new string(tt);
            }
            else if (e.ProgressPercentage == 2)
            {
                label1.ForeColor = Color.MidnightBlue;
                tt[1] = '*';
            }
        }
    }
}
