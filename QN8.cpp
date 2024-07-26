// 8. A parking garage charges a $2.00 minimum fee to park for up to three
// hours. The garage charges an additional $0.50 per hour for each hour or
// part thereof in excess of three hours. People who park their cars for
// longer than 24 hours will pay $8.00 per day. Write a program that
// calculates and prints the parking charges. The inputs to your program
// are the date and time when a car enters the parking garage, and the date
// and time when the same car leaves the parking garage. Keep track of
// number of cars in the garage overloading ++ and -- operators. this is question
#include <iostream>
#include<iomanip>
using namespace std;
class garage
{
  int year, month, day, hour, minute, second ;

  double totalhr,charges;

public:
  static int carno;
  garage()    //DEFAULT CONSTRUCTOR
  {
    carno = 0;
  }
  void setdataforenter()
  {
    cout << "Enter the date of car entered in garage in YY:MM:DD format." << endl;
    cin >> year >> month >> day;
    cout << "Enter the time of car entered in garage in HH:MM:SS format." << endl;
    cin >> hour >> minute >> second;
  }
  void setdataforexit()
  {
    cout << "Enter the date of car exited the garage in YY:MM:DD format." << endl;
    cin >> year >> month >> day;
    cout << "Enter the time of car exited the garage in HH:MM:SS format." << endl;
    cin >> hour >> minute >> second;
  }
  void calculation(garage &o1, garage &o2)
  {
    garage obj;
    obj.hour = o2.hour - o1.hour;
    obj.minute = o2.minute - o1.minute;
    obj.second = o2.second - o1.second;
    if (obj.minute < 0)
    {
      obj.hour -= 1;
      obj.minute += 60;
    }
    if (obj.second < 0)
    {
      obj.minute -= 1;
      obj.second += 60;
    }
    totalhr = obj.hour + obj.minute / 60.0 + obj.second / 3600.0;
    if (totalhr <= 3)
    {
      obj.charges = 2.00;
    }
    else if (totalhr > 3 && totalhr <= 24)
    {
      totalhr = (int)totalhr - 3;
      obj.charges = 2 + totalhr * 0.5;
    }
    else if (totalhr > 24)
    {
      do
      {
        obj.charges += 8;
        totalhr -= 24;
      } while (totalhr < 0);
      cout << "Your total charges is : " << endl;
    cout << o1.charges;
    }
  }
  garage operator++(int) // OVERLOADING INCREMENT OPERATOR
  {
    garage demo(*this); 
    carno += 1;
    return demo;
  }
  garage operator --(int) // OVERLOADING DECREMENT OPERATOR
  {
    garage demo(*this); 
    carno -= 1;
    return demo;
  }
  void display(garage o1)
  {
    cout << "Your total charges is : " << endl;
    cout << o1.charges;
  }
};
int garage :: carno =0;
int main()
{
  char clarify, check;
  garage KTMIN,KTMOUT;
  do
  {
    cout << "Enter 'i' for entering veichle and 'o' for exiting veichle. "<< endl;
    
    do
    {
      KTMIN.setdataforenter();
      KTMIN++;
      cout<<"Enter your choice:";
      cin >> clarify;
    } while (clarify == 'i' || clarify == 'I');
    do
    {
      KTMOUT.setdataforexit();
      KTMOUT.calculation(KTMIN, KTMOUT );
      KTMOUT.display(KTMOUT);
        KTMIN--;
         cout<<"Enter your choice:";
      cin >> clarify;
    } while (clarify == 'o' || clarify == 'O');

    cout << "do you want to continue? press 'y' for yes and any other character for no." << endl;

    cin>>check;
  }

  while (check == 'y' || check == 'Y');
  cout<<"The total number of car in garage is: "<<garage :: carno;
  return 0;
}