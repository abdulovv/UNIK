using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _353503_ABDULOV_LAB4{
    [Serializable]
    public class Tenant{
        public string name;
        public int floor;
        public bool isApartmentForRent;

        public Tenant(string name, int floor, bool isApartmentForRent) { 
            this.name = name;
            this.floor = floor;
            this.isApartmentForRent = isApartmentForRent;
        }

        public Tenant() { 
            
        }

        public string GetName() { return name; }
        public int GetFloor() { return floor; }
        public bool GetIsApartmentForRent() { return isApartmentForRent; }
        public override string ToString() { return ("Name:" + name + " floor:" + floor + " isApartmentForRent:" + isApartmentForRent); }

        public static Tenant ToTenantFromString(string str) {
            string name = "";
            string floorSTR = "";
            string isApartmentForRentSTR = "";

            int pr = 0;

            bool isProperty = false;

            foreach(var ch in str) {
                if (ch.Equals(':')) {
                    pr++;
                    isProperty = true;
                    continue;
                }else if (ch.Equals(' ')) {
                    isProperty = false;
                    continue;
                }

                if (isProperty && pr == 1) {
                    name += ch;
                }else if (isProperty && pr == 2){
                    floorSTR += ch;
                }else if (isProperty && pr == 3){
                    isApartmentForRentSTR += ch;
                }
            } 
            
            return new Tenant(name, int.Parse(floorSTR) , isApartmentForRentSTR.ToLower().Equals("true") ? true : false);
        }
    }
}
