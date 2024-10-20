using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _353503_ABDULOV_LAB6{
    public class Employee{
        public string Name { get; set; }
        public int age { get; set; }
        public bool isKind { get; set; }

        public Employee() { }

        public Employee(string name, int age, bool isKind) { 
            this.Name = name;
            this.age = age;
            this.isKind = isKind;
        }







    }
}
