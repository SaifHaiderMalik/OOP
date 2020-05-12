using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSDemo
{
    class Program // Driver class
    {
        static void Main(string[] args){
            int i;
            int j;
            i = Int32.Parse(Console.ReadLine());
            j = Int32.Parse(Console.ReadLine());
            Console.WriteLine("Result: " + (i + j));
        }
    }
}