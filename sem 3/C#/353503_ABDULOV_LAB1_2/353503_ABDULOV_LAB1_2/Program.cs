using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _353503_ABDULOV_LAB1_2
{

    public class Program{
        static void Main(string[] args){
        /////////////////////////////////////////////////////////////////////////////////////////////
            Journal journal = new Journal();
            ATC atc = new ATC();

            //Action<string> setTariffAction = journal.LogEvent;
            //Action<string> addClientAction = journal.LogEvent;

            atc.ConnectClient += (Client newClient) => { //привязка события вызова к новому клиенту через событие
                newClient.ClientCalled += (string name, Cities city) => {
                    Console.WriteLine("Client " + name + " called to " + city + "!"); 
                };
            };

            atc.TariffChanged += journal.LogEvent; ;
            atc.ClientAdded += journal.LogEvent;          

            //MyCustomCollection<Client> clients = atc.GetClients();

        /////////////////////////////////////////////////////////////////////////////////////////////
            

            atc.AddClient("sasha", "+375296734423");
            atc.AddClient("zahar", "+54234423");
            atc.AddClient("vlad", "+7236734423");
            atc.AddClient("marmelad", "+9876522442");
            atc.AddClient("pelix", "+111234334");

            atc.AddCall("375296734423", Cities.Mogilev);

            clients[0].AddCall(10, Cities.Minsk); 
            clients[1].AddCall(10, Cities.Mogilev); 
            clients[1].AddCall(10, Cities.Grodno); 
            clients[3].AddCall(55, Cities.Grodno);

            OutputWriter.atc = atc;

            OutputWriter.ClientCost(clients[1]);

            OutputWriter.TotalCost();

            OutputWriter.CountOfCallsToCity(Cities.Grodno);

            OutputWriter.ClientsInfo();

            atc.AddClient("dyadka", "+7788");

            OutputWriter.TotalCost();

            clients[1].AddCall(33,Cities.Mogilev);

            atc.SetTariff(Cities.Grodno, 344);

            OutputWriter.Journal(journal);

            OutputWriter.TotalCost();

        }
    }
}
