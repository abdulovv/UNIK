using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _353503_ABDULOV_LAB4{
    interface IFileService<T>{
        IEnumerable<string> ReadFile(string fileName);
        void SaveData(IEnumerable<Tenant> data, string fileName);
    }
}
