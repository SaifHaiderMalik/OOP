using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Threading.Tasks;

namespace c7
{
    class Program
    {
        static void Main(string[] args)
        {
            string text = "This is sample text";
            string path = "C:\\Users\\sohai\\Desktop\\Saif\\OOP\\Labs\\Saif\\Misc\\Project";
            string[] lines = { "line1", "line2", "line3", "line4" };

            File.WriteAllText(path, text);
            //File.WriteAllLines(path,lines);

            string InputText = File.ReadAllText(path);
            //Console.Write(InputText);

            string[] readlines = File.ReadAllLines(path);
            foreach (string line in readlines);
            Console.WriteLine(lines);

        }
    }
}
