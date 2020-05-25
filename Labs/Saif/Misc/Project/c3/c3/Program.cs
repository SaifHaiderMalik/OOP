using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace c3
{
    class MyClass {
        int var;

        public int _var
        {
            set
            {
                var = value;
            }
            get
            {
                return var;
            }
        }

        public void display()
        {
            Console.WriteLine("Var: " + var);
        }
            
    }
    class Program
    {
        static void Main(string[] args)
        {
            MyClass ob = new MyClass();
            ob._var = 50;
            Console.WriteLine("Var: " + ob._var);
            string s = Console.ReadLine();
        }
    }
}
