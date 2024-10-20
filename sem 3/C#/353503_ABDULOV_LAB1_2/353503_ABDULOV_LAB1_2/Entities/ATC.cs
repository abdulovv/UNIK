using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using System.Data.SqlTypes;
using static System.Runtime.InteropServices.JavaScript.JSType;

namespace _353503_ABDULOV_LAB1_2
{
    public class ATC : IATC{

        private MyCustomCollection<Client> clients;
        private MyCustomCollection<Tariff> tariffs;

        public event Action<string> TariffChanged;
        public event Action<string> ClientAdded;

        public event Action<Client> ConnectClient;//

        public ATC(){
            clients = new MyCustomCollection<Client>();
            tariffs = new MyCustomCollection<Tariff>();

            Tariff tariffMinsk = new Tariff(Cities.Minsk, 5);
            Tariff tariffBrest = new Tariff(Cities.Brest, 10);
            Tariff tariffMogilev = new Tariff(Cities.Mogilev, 15);
            Tariff tariffGomel = new Tariff(Cities.Gomel, 20);
            Tariff tariffVitebsk = new Tariff(Cities.Vitebsk, 25);
            Tariff tariffGrodno = new Tariff(Cities.Grodno, 30);


            tariffs.Add(tariffMinsk);
            tariffs.Add(tariffBrest);
            tariffs.Add(tariffGrodno);
            tariffs.Add(tariffMogilev);
            tariffs.Add(tariffVitebsk);
            tariffs.Add(tariffGomel);
        }

        private int GetPriceByCall(Call call)
        {
            int res = 0;
            for (int i = 0; i < tariffs.Count; i++)
            {
                Tariff tariff = tariffs[i];
                if (tariffs[i].GetCity().Equals(call.GetCity()))
                {
                    res += call.GetTime() * tariff.GetPrice();
                    break;
                }
            }
            return res;
        }
        public int CalculateTotalCost(){
            int totalPrice = 0;
            for (int i = 0; i < clients.Count; i++)
            {
                Client client = clients[i];
                MyCustomCollection<Call> listOfCalls = client.GetCalls();

                for (int j = 0; j < listOfCalls.Count; j++)
                {
                    Call call = listOfCalls[j];
                    totalPrice += GetPriceByCall(call);
                }
            }

            return totalPrice;

        }
        public int CalculateClientTotalCost(Client client){
            int res = 0;
            MyCustomCollection<Call> listOfCalls = client.GetCalls();

            for (int j = 0; j < listOfCalls.Count; j++)
            {
                Call call = listOfCalls[j];
                res += GetPriceByCall(call);
            }

            return res;
        }


        public void AddClient(string name, string number){
            Client newClient = new Client(name, number);
            clients.Add(newClient);

            ClientAdded.Invoke("Client " + name + " was added, number:" + number);
            ConnectClient.Invoke(newClient);
        }

        public void SetTariff(Cities city, int price){
            for (int i = 0; i < tariffs.Count; i++){
                if (tariffs[i].GetCity().Equals(city)){
                    tariffs[i].SetPrice(price);
                }
            }
            TariffChanged.Invoke("Tattif " + city + ", new price:" + price);
        }
        public int CountOfCallsToCity(Cities city){
            int count = 0;

            for (int i = 0; i < clients.Count; i++)
            {
                Client client = clients[i];
                MyCustomCollection<Call> listOfCalls = client.GetCalls();

                for (int j = 0; j < listOfCalls.Count; j++){
                    Call call = listOfCalls[j];
                    if (call.GetCity().Equals(city))
                    {
                        count++;
                    }
                }
            }

            return count;
        }

        public string GetClientsInfo() {
            string info = "";
            for (int i = 0; i < clients.Count; i++) { 
                Client client = clients[i];
                MyCustomCollection<Call> calls = client.GetCalls();
                info += ((i + 1) + ") Name:" + client.GetName() + "\n  number:" + client.GetNumber() + "\n    calls:\n");
                for (int j = 0; j < calls.Count; j++) {
                    Call call = calls[j];
                    info += ("    "+(j + 1) + ")time:" + call.GetTime() + ", City:" + call.GetCity().ToString()+ " price:" + GetPriceByCall(call)+"\n");
                }
                info += "\n\n";

            }
            return info;
        }

        public MyCustomCollection<Client> GetClients(){
            return clients;
        }

        internal void AddCall(string v, Cities mogilev)
        {
            throw new NotImplementedException();
        }
    }
}
