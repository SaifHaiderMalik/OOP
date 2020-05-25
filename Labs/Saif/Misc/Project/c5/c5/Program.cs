using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace c5
{   
    class MyClass
    {
        public MyClass()
        {

        }

        public MyClass(int x)
        {
            Console.WriteLine(x);
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            MyClass ob1 = new MyClass(10);
            MyClass ob2 = ob1;
            Console.ReadLine();

        }
    }
}
