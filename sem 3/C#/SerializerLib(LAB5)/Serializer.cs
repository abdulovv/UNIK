using _353503_ABDULOV_LAB5.Domain;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.Encodings.Web;
using System.Text.Json;
using System.Text.Unicode;
using System.Xml.Linq;
using System.Xml.Serialization;

namespace SerializerLib{
    public class Serializer : ISerializer{
        string path;

        public Serializer(string path){
            this.path = path;
        }

        public void SerializeByLINQ(IEnumerable<Building> buildings, string fileName){
            var xml = new XElement("Buildings",
                from building in buildings
                select new XElement("Building",
                    new XElement("Name", building.GetName()),
                    new XElement("Floors", building.GetFloors()),
                    new XElement("Heating",
                        new XElement("Temperature", building.GetHeating().getTemperature()),
                        new XElement("EnergyConsumption", building.GetHeating().getEnergyConsumption())))
            );

            fileName = path + fileName + "LINQ.xml";
            xml.Save(fileName);
        }

        public void SerializeXML(IEnumerable<Building> buildings, string fileName){
            XmlSerializer serializer = new XmlSerializer(typeof(List<Building>));
            fileName = path + fileName + "XML.xml";

            using (StreamWriter writer = new StreamWriter(fileName)){
                serializer.Serialize(writer, buildings.ToList());
            }
        }

        public void SerializeJSON(IEnumerable<Building> buildings, string fileName){
            var options = new JsonSerializerOptions{
                WriteIndented = true,
                Encoder = JavaScriptEncoder.Create(UnicodeRanges.All) // для строк
            };

            string jsonString = JsonSerializer.Serialize(buildings, options);
            fileName = path + fileName + "JSON.json";

            File.WriteAllText(fileName, jsonString);
        }

        public IEnumerable<Building> DeSerializeJSON(string fileName){
            fileName = path + fileName + "JSON.json";
            string jsonString = File.ReadAllText(fileName);
            return JsonSerializer.Deserialize<List<Building>>(jsonString);
        }

        public IEnumerable<Building> DeSerializeByLINQ(string fileName){
            fileName = path + fileName + "LINQ.xml";
            XDocument xmlDoc = XDocument.Load(fileName);

            var buildings = from building in xmlDoc.Descendants("Building")
                            select new Building(
                                building.Element("Name").Value,
                                int.Parse(building.Element("Floors").Value),
                                new Heating(
                                    int.Parse(building.Element("Heating").Element("Temperature").Value),
                                    int.Parse(building.Element("Heating").Element("EnergyConsumption").Value)
                                )
                            );

            return buildings;
        }

        public IEnumerable<Building> DeSerializeXML(string fileName){
            XmlSerializer serializer = new XmlSerializer(typeof(List<Building>));
            fileName = Path.Combine(path, fileName + "XML.xml");

            using (StreamReader reader = new StreamReader(fileName)){
                return (List<Building>)serializer.Deserialize(reader);
            }
        }
    }
}
