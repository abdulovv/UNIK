using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace _353503_ABDULOV_LAB1_2
{
    public interface IATC{
        int CalculateTotalCost();
        int CalculateClientTotalCost(Client client);     
        void SetTariff(Cities city, int price);
        string GetClientsInfo();
        int CountOfCallsToCity(Cities city);

    }
}
