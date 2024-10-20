using _353503_ABDULOV_LAB3.Entities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _353503_ABDULOV_LAB3.Contracts{
    public interface IATC{
        void AddClient(string name, string number);
        void RemoveClient(string name);
        void RemoveClient(int index);
        void AddCall(string city, int time, int index);
        void AddCall(string name, int time, string city);
        int CalculateAllClientsPayments();
        int CalculateClientPayments(int index);
        int CalculateClientPayments(string name);
        List<Tariff> GetSortTariffList();

    } 
}