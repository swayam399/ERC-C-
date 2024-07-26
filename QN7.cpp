// 7. Overload >> and << operators to input and display time.
#include<iostream>
using namespace std;
class time
{
    int years,months,seconds;
    public:
  friend istream &operator >> (istream &input,time &o1 ){
    
        cin>>o1.years>>o1.months>>o1.seconds;
        return input;
    }
   friend ostream &operator << (ostream &output, time &o1 ){
      cout<<"the entered time is:"<<o1.years<<":"<<o1.months<<":"<<o1.seconds;
      return output;
    }
};
int main()
{
   
    time first;
    cout<<"Enter the time in HH/MM/SS."<<endl;
    cin>>first;
    cout<< first;
return 0;
}