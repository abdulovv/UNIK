using _353503_ABDULOV_LAB5.Domain;
using Microsoft.Extensions.Configuration;
using Microsoft.Extensions.Configuration.Json;
using SerializerLib;
using System.Collections;

namespace _353503_ABDULOV_LAB5 {
    public class Program() {

        public static IEnumerable<Building> GetBuildingsList() {
            Heating heating1 = new Heating(28, 110);
            Heating heating2 = new Heating(32, 120);
            Heating heating3 = new Heating(30, 100);
            Heating heating4 = new Heating(25, 120);
            Heating heating5 = new Heating(27, 80);


            Building building1 = new Building("Дом1", 12, heating1);
            Building building2 = new Building("Дом2", 15, heating2);
            Building building3 = new Building("Дом3", 18, heating3);
            Building building4 = new Building("Дом4", 20, heating4);
            Building building5 = new Building("Дом5", 9,  heating5);

            IEnumerable<Building> list = new List<Building>() { building1, 
                                                                building2,
                                                                building3,
                                                                building4,
                                                                building5 };

            return list;
        }

        public static void Main(string[] args) {
            
            string path = "D:\\C#\\353503_ABDULOV_LAB5\\Files\\";

            var builder = new ConfigurationBuilder()
            .SetBasePath(Directory.GetCurrentDirectory())
            .AddJsonFile("appsettings.json", optional: true, reloadOnChange: true);

            IConfigurationRoot configuration = builder.Build();
            string fileName = configuration["FileSettings:FileName"];

            IEnumerable<Building> list = GetBuildingsList();

            Serializer serializer = new Serializer(path);

            serializer.SerializeByLINQ(list, fileName);

            serializer.SerializeXML(list, fileName);

            serializer.SerializeJSON(list, fileName);

            IEnumerable<Building> readedBuildings = serializer.DeSerializeXML(fileName);

            bool areEqual = list.SequenceEqual(readedBuildings, new BuildingComparer());
            Console.WriteLine("are equal:" + areEqual+"\n");


            foreach (Building building in readedBuildings){
                Console.WriteLine(building);
            }



        }
    }
}