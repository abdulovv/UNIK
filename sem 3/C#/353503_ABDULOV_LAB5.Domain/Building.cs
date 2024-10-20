using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using _353503_ABDULOV_LAB5;

namespace _353503_ABDULOV_LAB5.Domain{
    public class Building : IEquatable<Building>{

        public string name { get; set; }
        public int floors { get; set; }

        public Heating heating { get; set; }

        public Building(){}
        public Building(string name, int floors, Heating heating) { 
            this.name = name;
            this.floors = floors;
            this.heating = heating;
        }

        public string GetName() {return name;}

        public int GetFloors(){ return floors;}

        public Heating GetHeating() { return heating; }

        public override string ToString(){
            return "name:" + name + "\n  floors:" + floors + "\n    heating:\n" + heating;
        }

        public bool Equals(Building? other){
            return (other != null && name == other.GetName() 
                                  && floors == other.floors
                                  && heating.Equals(other.heating));
        }
    }
}
