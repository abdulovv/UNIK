using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _353503_ABDULOV_LAB3.Entities{
    public class Tariff{
        string name;
        int price;

        public Tariff(string name, int price) { 
            this.name = name;
            this.price = price;
        }

        public string GetName() { return name; }
        public int GetPrice() { return price; }
        public void SetPrice(int newPrice) {  price = newPrice; }
    }
}
