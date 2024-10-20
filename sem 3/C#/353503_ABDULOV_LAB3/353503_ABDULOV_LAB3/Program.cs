using _353503_ABDULOV_LAB3.Entities;

namespace _353503_ABDULOV_LAB3
{

    
    public class Program {

        static private void printAction(string s){
            Console.WriteLine(s);
        }
        static void Main(string[] args) {
            Journal journal = new Journal();
            ATC atc = new ATC(9, 3, 2, 5, 1);

            atc.callAction += journal.LogEvent;
            atc.action += printAction;

            atc.AddClient("dyadya", "+375297752332");
            atc.AddClient("zaharyamba", "+375290457135");

            atc.RemoveClient("dyadya");

            atc.AddClient("milana", "+37544963932");
            atc.AddClient("sanyok", "+375297766242");

            atc.SetTarrif("Minsk", 10);
            atc.SetTarrif("Brest", 10);
            atc.SetTarrif("Mogilev", 10);
            atc.SetTarrif("Vitebsk", 10);
            atc.SetTarrif("Gomel", 10);

            atc.AddCall("milana", 10, "Minsk");
            atc.AddCall("milana", 10, "Brest");
            atc.AddCall("sanyok", 10, "Brest");
            atc.AddCall("zaharyamba", 10, "Gomel");

            atc.CalculateAllClientsPayments();

            atc.CalculateClientPayments("milana");

            atc.AddCall("zaharyamba", 5, "Minsk");

            Console.WriteLine(atc.GetCountOfClientsPayMore(104));

            atc.AddCall("sanyok", 8, "Gomel");
            atc.AddCall("sanyok", 8, "Gomel");
            atc.AddCall("sanyok", 5, "Minsk");
            atc.AddCall("sanyok", 5, "Minsk");
            atc.AddCall("sanyok", 5, "Minsk");
            atc.AddCall("sanyok", 2, "Vitebsk");
            atc.AddCall("sanyok", 2, "Vitebsk");
            atc.AddCall("sanyok", 2, "Vitebsk");


            List<int> l = atc.GetClientPaymentsByTarif("sanyok");

            foreach (int i in l)
            {

                Console.WriteLine(i);
            }

            Console.WriteLine();
            atc.CalculateClientPayments("sanyok");

            journal.printJournal();
        }
    }
}