using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _353503_ABDULOV_LAB1_2
{
    public class Call{
        Cities city;
        int time;

        public Call(Cities city, int time){
            this.city = city;
            this.time = time;
        }

        public Cities Cities{
            get => default;
            set{}
        }

        public Cities GetCity(){
            return city;
        }

        public int GetTime(){
            return time;
        }
    }
}
