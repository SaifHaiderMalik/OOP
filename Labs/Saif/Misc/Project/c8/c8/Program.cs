using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;
using System.Threading.Tasks;

namespace CSDemo
{
    [Serializable]
    class Employee
    {
        string empName;
        float empSal;

        public Employee(string name, float value)
        {
            empName = name;
            empSal = value;
        }
        public Employee()
        {

        }

        public string _empName
        {
            get { return empName; }
            set { empName = value; }
        }

        public float _empsal
        {
            get {return empSal; }
            set { empSal = value; }
        }

        public void display()
        {
            Console.WriteLine("Employee Name: " + empName);
            Console.WriteLine("Employee Salary: " + empSal);
        }
    }
    class Program
    {
        public static void Main(string[] args)
        {
            Employee e1 = new Employee("Sensei", 1200.45f);
            Employee e2 = new Employee("Nobita", 13400.50f);
            string path = "C:\\projects\\1.bin";

            IFormatter formatter = new BinaryFormatter();
            Stream stream = new FileStream(path, FileMode.Create, FileAccess.Write);

            formatter.Serialize(stream, e1);
            formatter.Serialize(stream, e2);
            stream.Close();

            stream = new FileStream(path, FileMode.Open , FileAccess.Read);
            Employee e3 = (Employee) formatter.Deserialize(stream);
            Employee e4 = (Employee)formatter.Deserialize(stream);

            e3.display();
            e4.display();
        }
    }
}
