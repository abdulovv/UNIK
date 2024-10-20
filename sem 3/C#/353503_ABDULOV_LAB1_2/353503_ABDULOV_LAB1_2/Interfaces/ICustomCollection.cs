using System;
using _353503_ABDULOV_LAB1_2;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _353503_ABDULOV_LAB1_2
{
    public interface ICustomCollection<T> : IEnumerable<T>{
        T this[int index]{
            get; set;
        }
        void Reset();
        void Next();

        T Current();

        int Count { get; }

        void Add(T item);

        void Remove(T item);

        T RemoveCurrent();
    }
}
