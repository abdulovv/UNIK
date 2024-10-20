using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _353503_ABDULOV_LAB4{
    public class Comparer<T> : IComparer<T> where T : Tenant{
        public int Compare(T firstPerson, T secondPerson){

            return String.CompareOrdinal(firstPerson.GetName().ToLower(), secondPerson.GetName().ToLower()); 
        }
    }
}