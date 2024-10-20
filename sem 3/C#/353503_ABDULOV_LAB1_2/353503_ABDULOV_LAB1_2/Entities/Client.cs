using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _353503_ABDULOV_LAB1_2
{
    public class Client {
        string name;
        string number; 
        MyCustomCollection<Call> calls;

        public event Action<string, Cities> ClientCalled;          

        public Client(string name, string number) {
            this.name = name;
            this.number = number;
            calls = new MyCustomCollection<Call>();
        }

        public string GetName() {
            return name;
        }

        public string GetNumber() {
            return number;
        }

        public MyCustomCollection<Call> GetCalls() {
            return calls;
        }

        public void AddCall(int time, Cities city) {
            calls.Add(new Call(city, time));
            ClientCalled.Invoke(name, city);
        }
    }
}
