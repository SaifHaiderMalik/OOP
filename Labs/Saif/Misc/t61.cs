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
            
            byte var1;
            short var2;
            int var3;
            uint var4;
            double var5;
            decimal var6;

            var3 = Int32.Parse(Console.ReadLine());
            var3 = Convert.ToInt32(Console.ReadLine());

            Console.WriteLine(var3);
            
        }
    }
}