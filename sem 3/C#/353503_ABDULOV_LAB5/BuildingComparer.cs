using _353503_ABDULOV_LAB5.Domain;
using System.Collections.Generic;

public class BuildingComparer : IEqualityComparer<Building>{
    public bool Equals(Building x, Building y)
    {
        if (x == null || y == null) return false;
        return x.GetName() == y.GetName() && x.GetFloors() == y.GetFloors() && x.GetHeating().Equals(y.GetHeating());
    }

    public int GetHashCode(Building obj){
        if (obj == null) return 0;
        return obj.GetName().GetHashCode() ^ obj.GetFloors().GetHashCode() ^ obj.GetHeating().GetHashCode();
    }
}
