using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;
using System.Xml.Serialization;

namespace _353503_ABDULOV_LAB5.Domain{
    public class Heating : IEquatable<Heating> {
        public int temperature { get; set; }
        public int energyConsumption { get; set; }

        public Heating() { }
        public Heating(int temperature, int energyConsumption) {
            this.temperature = temperature;
            this.energyConsumption = energyConsumption;
        }

        public int getTemperature() { return temperature; }
        public int getEnergyConsumption() { return energyConsumption; }

        public override string ToString(){
            return "temperature:" + temperature + "\nenergyConsumption:" + energyConsumption + "\n\n";
        }

        public bool Equals(Heating? other){
            return (other != null && temperature == other.temperature 
                                  && energyConsumption == other.energyConsumption);
        }
    }
}
