using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace c4
{
    class MyClass
    {
         static int var;

        public static int _var
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
            MyClass._var = 30;
            Console.WriteLine("Var: " + MyClass._var);
            Console.ReadLine();

        }
    }
}
