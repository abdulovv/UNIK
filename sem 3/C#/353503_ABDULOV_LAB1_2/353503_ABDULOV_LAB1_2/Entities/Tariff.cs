using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace _353503_ABDULOV_LAB1_2
{
    public class Tariff{
        Cities city;        
        int price;

        public Tariff(Cities city, int price) { 
            this.city = city;
            this.price = price;
        }

        public Cities Cities{
            get => default;
            set{}
        }

        public int GetPrice(){
            return price;
        }

        public Cities GetCity() { 
            return city;
        }

        public void SetCity(Cities city){
            this.city = city;
        }

        public void SetPrice(int price){
            this.price = price;
        }
    }
}
