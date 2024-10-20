using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace _353503_ABDULOV_LAB1_2
{
    public class OutputWriter{
        public static ATC atc;
        public static void Collection_WRITELINE<T>(MyCustomCollection<T> collection) {
            foreach (T item in collection) {
                Console.WriteLine(item);
            }
        }

        public static void Collection_WRITE<T>(MyCustomCollection<T> collection){
            foreach (T item in collection){
                Console.Write(item);
            }
        }

        public static void ClientsInfo() {
            Console.WriteLine(atc.GetClientsInfo());
        }

        public static void TotalCost(){
            Console.WriteLine("Total cost of all calls: " + atc.CalculateTotalCost());
        }

        public static void ClientCost(Client client){
            Console.WriteLine("Client " + client.GetName() + ", total cost of all calls:" + atc.CalculateClientTotalCost(client));
        }

        public static void CountOfCallsToCity(Cities city) {
            Console.WriteLine("Count of calls to " + city + ":" + atc.CountOfCallsToCity(city));
        }

        public static void Journal(Journal journal) {
            Console.WriteLine("JOURNAL:");
            Collection_WRITELINE(journal.GetEvents());
        }

    }
}
