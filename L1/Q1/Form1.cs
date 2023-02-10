﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Q1
{
    public partial class Form1 : Form
    {
        string v1 = string.Empty;
        string v2 = string.Empty;
        string input = string.Empty;
        char op;
        double res;
        public Form1()
        {
            InitializeComponent();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = string.Empty;
            this.textBox1.Text += "";
            input += "8";
            this.textBox1.Text += input;
        }

        private void button14_Click(object sender, EventArgs e)
        {
            v1 = input;
            input = string.Empty;
            op = '/';
            this.textBox1.Text = string.Empty;
        }

        private void button16_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = string.Empty;
            input = string.Empty;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = string.Empty;
            this.textBox1.Text += "";
            input += "1";
            this.textBox1.Text += input;
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button4_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = string.Empty;
            this.textBox1.Text += "";
            input += "2";
            this.textBox1.Text += input;
        }

        private void button7_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = string.Empty;
            this.textBox1.Text += "";
            input += "3";
            this.textBox1.Text += input;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = string.Empty;
            this.textBox1.Text += "";
            input += "4";
            this.textBox1.Text += input;
        }

        private void button5_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = string.Empty;
            this.textBox1.Text += "";
            input += "5";
            this.textBox1.Text += input;
        }

        private void button8_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = string.Empty;
            this.textBox1.Text += "";
            input += "6";
            this.textBox1.Text += input;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = string.Empty;
            this.textBox1.Text += "";
            input += "7";
            this.textBox1.Text += input;
        }

        private void button9_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = string.Empty;
            this.textBox1.Text += "";
            input += "9";
            this.textBox1.Text += input;
        }

        private void button10_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = string.Empty;
            this.textBox1.Text += "";
            input += "0";
            this.textBox1.Text += input;
        }

        private void button11_Click(object sender, EventArgs e)
        {
            v1 = input;
            input = string.Empty;
            op = '+';
            this.textBox1.Text = string.Empty;
        }

        private void button12_Click(object sender, EventArgs e)
        {
            v1 = input;
            input = string.Empty;
            op = '-';
            this.textBox1.Text = string.Empty;
        }

        private void button13_Click(object sender, EventArgs e)
        {
            v1 = input;
            input = string.Empty;
            op = '*';
            this.textBox1.Text = string.Empty;
        }

        private void button15_Click(object sender, EventArgs e)
        {
            v1 = input;
            input = string.Empty;
            op = '%';
            this.textBox1.Text = string.Empty;
        }

        private void button17_Click(object sender, EventArgs e)
        {
            v2 = input;
            this.textBox1.Text = string.Empty;
            this.textBox1.Text += "";
            double num1, num2;
            double.TryParse(v1, out num1);
            double.TryParse(v2, out num2);
            if (op == '+')
            {
                res = num1 + num2;
                this.textBox1.Text = res.ToString();
            }
            else if (op == '-')
            {
                res = num1 - num2;
                this.textBox1.Text = res.ToString();
            }
            else if (op == '*')
            {
                res = num1 * num2;
                this.textBox1.Text = res.ToString();
            }
            else if (op == '/')
            {
                res = num1 / num2;
                this.textBox1.Text = res.ToString();
            }
            else if (op == '%')
            {
                res = num1 % num2;
                this.textBox1.Text = res.ToString();
            }
            input = string.Empty;
        }

        private void button18_Click(object sender, EventArgs e)
        {
            v1 = input;
            this.textBox1.Text = string.Empty;
            this.textBox1.Text += "";
            double num1;
            double.TryParse(v1, out num1);
            res = Math.Sin(num1);
            this.textBox1.Text = res.ToString();
            input = string.Empty;
        }

        private void button19_Click(object sender, EventArgs e)
        {
            v1 = input;
            this.textBox1.Text = string.Empty;
            this.textBox1.Text += "";
            double num1;
            double.TryParse(v1, out num1);
            res = Math.Cos(num1);
            this.textBox1.Text = res.ToString();
            input = string.Empty;
        }

        private void button21_Click(object sender, EventArgs e)
        {
            v1 = input;
            this.textBox1.Text = string.Empty;
            this.textBox1.Text += "";
            double num1;
            double.TryParse(v1, out num1);
            res = Math.Exp(num1);
            this.textBox1.Text = res.ToString();
            input = string.Empty;
        }

        private void button20_Click(object sender, EventArgs e)
        {
            v1 = input;
            this.textBox1.Text = string.Empty;
            this.textBox1.Text += "";
            double num1;
            double.TryParse(v1, out num1);
            res = 1 / num1;
            this.textBox1.Text = res.ToString();
            input = string.Empty;
        }

        private void button22_Click(object sender, EventArgs e)
        {
            v1 = input;
            this.textBox1.Text = string.Empty;
            this.textBox1.Text += "";
            double num1;
            double.TryParse(v1, out num1);
            res = Math.Tan(num1);
            this.textBox1.Text = res.ToString();
            input = string.Empty;
        }

        private void button23_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = string.Empty;
            this.textBox1.Text += "";
            input += ".";
            this.textBox1.Text += input;
        }
    }
}
