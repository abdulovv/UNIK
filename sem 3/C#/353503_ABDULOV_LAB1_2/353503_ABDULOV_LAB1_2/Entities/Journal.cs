using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _353503_ABDULOV_LAB1_2
{
    public class Journal{
        MyCustomCollection<string> events;

        public Journal() { 
            events = new MyCustomCollection<string>();
        }

        public MyCustomCollection<string> GetEvents() { return events; }

        public void LogEvent(string info) {
            events.Add(info);
        }
    }
}
