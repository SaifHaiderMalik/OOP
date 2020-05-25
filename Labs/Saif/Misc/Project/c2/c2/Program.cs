using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace c2
{
    class MyClass
    {
        public int var;

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
            ob.var = 50;
            ob.display();
            Console.ReadLine();
        }
    }
}
