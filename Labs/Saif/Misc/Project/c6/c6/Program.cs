using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Threading.Tasks;

namespace c6
{
    class Program
    {
        static void Main(string[] args)
        {
            string text = "This is sample text";
            string path = "C:\\Users\\sohai\\Desktop";
            File.WriteAllText(path, text);
        }
    }
}
