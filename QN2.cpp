// To write a C++ program to overload all relational operators to compare
// US currency with Nepalese currency. Use conversion rate $1=NRs
// 101.36(Note: make two classes to represent each currency)
#include <iostream>
using namespace std;
class npcurrency
{
public:
    double rupees;

    void setdata()
    {
        cout << "Enter the nepalese currency:";
        cin >> rupees;
    }
};
class uscurrency
{
public:
    double dollar;

    void setdata()
    {
        cout << "Enter the US currency:";
        cin >> dollar;
    }
};
bool operator==(npcurrency &NRs, uscurrency &d$)
{
    return (NRs.rupees == d$.dollar * 101.36);
}
bool operator!=(npcurrency &NRs, uscurrency &d$)
{
    return (NRs.rupees != d$.dollar * 101.36);
}
bool operator>=(npcurrency &NRs, uscurrency &d$)
{
    return (NRs.rupees >= d$.dollar * 101.36);
}
bool operator<=(npcurrency &NRs, uscurrency &d$)
{
    return (NRs.rupees <= d$.dollar * 101.36);
}
bool operator>(npcurrency &NRs, uscurrency &d$)
{
    return (NRs.rupees > d$.dollar * 101.36);
}
bool operator<(npcurrency &NRs, uscurrency &d$)
{
    return (NRs.rupees < d$.dollar * 101.36);
}


int main()
{
    npcurrency paisa;
    paisa.setdata();
    uscurrency pound;
    pound.setdata();
    if( paisa == pound)
    {
        cout<<"NPs currency is Equal equal to dollar"<<endl;
    }
     if( paisa >= pound)
    {
        cout<<"NPs currency is more than or equal to dollar"<<endl;
    }
     if( paisa <= pound)
    {
        cout<<"NPs currency is less than or equal to dollar"<<endl;
    }
     if( paisa != pound)
    {
        cout<<"NPs currency is not equal to dollar"<<endl;
    }
     if( paisa > pound)
    {
        cout<<"NPs currency is mroe than dollar"<<endl;
    }
     if( paisa < pound)
    {
        cout<<"NPs currency is less than dollar"<<endl;
    }

    return 0;
}