using _353503_ABDULOV_LAB3.Contracts;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.Numerics;
using System.Reflection;
using System.Text;
using System.Threading.Channels;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace _353503_ABDULOV_LAB3.Entities{
    public class ATC : IATC{
        Dictionary<string, Tariff> tariffs;
        List<Client> clients;
        List<Call> calls;


        public event Action<string> callAction;
        public event Action<string> action;

        public ATC(int minskPrice, int gomelPrice, int mogilevPrice, int vitebskPrice, int brestPrice)
        {
            tariffs = new Dictionary<string, Tariff>();
            clients = new List<Client>();
            calls = new List<Call>();
            

            tariffs.Add("Minsk", (new Tariff("MinskTariff", minskPrice)));  
            tariffs.Add("Gomel", (new Tariff("GomelTariff", gomelPrice)));
            tariffs.Add("Mogilev", (new Tariff("MogilevTariff", mogilevPrice)));
            tariffs.Add("Vitebsk", (new Tariff("VitebskTariff", vitebskPrice)));
            tariffs.Add("Brest", (new Tariff("BrestTariff", vitebskPrice)));
        }

        private List<Tariff> GetTariffList() {
            List<Tariff> tariffList = new List<Tariff>();
            tariffList.Add(tariffs["Minsk"]);
            tariffList.Add(tariffs["Gomel"]);
            tariffList.Add(tariffs["Mogilev"]);
            tariffList.Add(tariffs["Vitebsk"]);
            tariffList.Add(tariffs["Brest"]);

            return tariffList;
        }

        private int GetIndexClientByName(string name) {
            int index = 0;
            foreach (var cl in clients){

                if (cl.GetName().Equals(name))
                    return index;

                index++;
            }

            throw new ArgumentException();
        }

        public void SetTarrif(string city, int newPrice) {
            int lastPrice = tariffs[city].GetPrice();
            string info = "";

            if (lastPrice > newPrice){
                info += ("- " + tariffs[city].GetName() + " " + lastPrice + " --> " + newPrice);
            }else if (lastPrice < newPrice){
                info += ("+ " + tariffs[city].GetName() + " " + lastPrice + " --> " + newPrice);
            }else {
                info += ("= " + tariffs[city].GetName() + " " + lastPrice + " --> " + newPrice);
            }

            tariffs[city].SetPrice(newPrice);
            action?.Invoke(info);
        }

        public void AddClient(string name, string number){
            clients.Add(new Client(name, number, GetTariffList()));
            action?.Invoke("+ Client " + name);
        }

        public void RemoveClient(string name){
            action?.Invoke("- Client " + name);

            try{
                int index = GetIndexClientByName(name);
                clients.RemoveAt(index);
            }catch{
                Console.WriteLine("CLIENT NOT FOUND (" + name + ")");
                Environment.Exit(1);
            }
        }

        public void RemoveClient(int index){
            action?.Invoke("- Client " + clients[index].GetName());
            try{
                clients.RemoveAt(index);
            }catch{
                Console.WriteLine("CLIENT NOT FOUND (ind:" + ")");
                Environment.Exit(2);
            }
        }

        public List<Client> GetClients() { return clients; }

        public Dictionary<string, Tariff> GetTariffs() { return tariffs; }

        public void AddCall(string city, int time, int index) {
            try{
                calls.Add(new Call(city, time, clients[index]));        
            }catch{
                Console.WriteLine("CLIENT NOT FOUND (ind:" + ")");
                Environment.Exit(3);
            }
            callAction?.Invoke("  Call " + clients[index].GetName() + ", time:" + time + ", -> " + city);
        }

        public void AddCall(string name, int time, string city){
            try{
                int index = GetIndexClientByName(name);
                calls.Add(new Call(city, time, clients[index]));
            }catch{
                Console.WriteLine("CLIENT NOT FOUND (" + name + ")");
                Environment.Exit(4);
            }
            action?.Invoke("  Call " + name + ", time:" + time + ", -> " + city);
        }

        public int CalculateAllClientsPayments() {
            int total = 0;

            total += (from call in calls where call.GetCity() == "Minsk" select call.getTime() * tariffs[call.GetCity()].GetPrice()).Sum();
            total += (from call in calls where call.GetCity() == "Gomel" select call.getTime() * tariffs[call.GetCity()].GetPrice()).Sum();
            total += (from call in calls where call.GetCity() == "Mogilev" select call.getTime() * tariffs[call.GetCity()].GetPrice()).Sum();
            total += (from call in calls where call.GetCity() == "Vitebsk" select call.getTime() * tariffs[call.GetCity()].GetPrice()).Sum();
            total += (from call in calls where call.GetCity() == "Brest" select call.getTime() * tariffs[call.GetCity()].GetPrice()).Sum();

            action?.Invoke("  All clients payments: " + total);
            return total;
        }
        public int CalculateClientPayments(int index) {
            int total = 0;

            try{
                total += (from call in calls where call.getClient().Equals(clients[index]) select call.getTime() * tariffs[call.GetCity()].GetPrice()).Sum();
            }catch{
                Console.WriteLine("CLIENT NOT FOUND (ind:" + index + ")");
                Environment.Exit(5);
            }

            action?.Invoke("  Client " + clients[index].GetName() + " payments: " + total);
            return total;
        }
        public int CalculateClientPayments(string name) {
            int total=0;

            IEnumerable<int> query;

            try{
                int index = GetIndexClientByName(name);
                query = (from call in calls
                         where call.getClient().Equals(clients[index])
                         select call.getTime() * tariffs[call.GetCity()].GetPrice()
                          );
                total= query.Sum();

                //

                total=query.Sum();  
            }catch{
                Console.WriteLine("CLIENT NOT FOUND (" + name + ")");
                Environment.Exit(6);
            }

            action?.Invoke("  Client " + name + " payments: " + total);
            return total;
        }

        public List<Tariff> GetSortTariffList(){
            var tariffList = from tariff in GetTariffList()
                             orderby tariff.GetPrice() descending
                             select tariff;

            return tariffList.ToList();
        }

        public string GetClientMaxPayment() {
            var clientList = from cl in clients
                             orderby CalculateClientPayments(cl.GetName()) descending
                             select cl;

            List<Client> l = clientList.ToList();
            return l[0].GetName();
        }

        public int GetCountOfClientsPayMore(int price) {
            int count = clients.Aggregate(0, (tmp, client) => CalculateClientPayments(client.GetName()) > price? tmp+1 : tmp);
            return count;
        }

        public void printCalls() {
            foreach (var call in calls) {
                Console.WriteLine(call.getClient().GetName() + " " + call.getTime() + " price:" + (call.getTime() * tariffs[call.GetCity()].GetPrice()));
            }
        }

        public List<int> GetClientPaymentsByTarif(string name) {
            List<int> res = new List<int>();

            Client client = clients[GetIndexClientByName(name)];

            var listOfCallsByClient = from call in calls where call.getClient().Equals(client) select call;

            var groupOfCallsByTariff = (listOfCallsByClient.GroupBy(call => call.GetCity()));

            foreach (var group in groupOfCallsByTariff) {
                int totalAmount = group.Sum(call => call.getTime() * tariffs[call.GetCity()].GetPrice());
                res.Add(totalAmount);
            }

            return res;
        }
    }
}
