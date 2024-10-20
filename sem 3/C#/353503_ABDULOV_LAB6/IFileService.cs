using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _353503_ABDULOV_LAB6{
    public interface IFileService<T>{
        IEnumerable<Employee> ReadFile(string fileName);
        void SaveData(IEnumerable<Employee> data, string fileName);
    }
}
