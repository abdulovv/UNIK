using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _353503_ABDULOV_LAB3.Entities{
    public class Client{
        string name;
        string number;
        List<Tariff> tariffs;

        public Client(string name, string number, List<Tariff> tariffs) { 
            this.name = name;
            this.number = number;       
            this.tariffs = tariffs;
        }

        public string GetName() { return name; }
        public string GetNumber() { return number; }
    }
}
