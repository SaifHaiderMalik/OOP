using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e) //Event handler
        {
            //coding part here 
            string name = textBox1.Text;
            string pw = textBox2.Text;

            if(name == "zain" && pw == "oop" && checkBox1.Checked)
            {

                label3.Text = "Sucess !";

            }

            else
            {

                label3.Text = "Login Failed";
            }


        }
    }
}
