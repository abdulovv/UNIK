using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _353503_ABDULOV_LAB3.Entities{
    public class Call{
        int time;
        string city;
        Client client;

        public Call(string city, int time, Client client) { 
            this.city = city;
            this.time = time;
            this.client = client;
        }

        public int getTime() { return time; }
        public string GetCity() { return city; } 
        public Client getClient() { return client; }
    }
}
