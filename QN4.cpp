// 4. Create a class called 'TIME' that has
// - three integer data members for hours, minutes and seconds
// - constructor to initialize the object to zero
// - constructor to initialize the object to some constant value
// - overload +,- to add and subtract two TIME objects
// - overload > function to compare two time
// - member function to display time in HH:MM:SS format
#include <iostream>
#include<iomanip>
using namespace std;
class TIME
{

    int hours, minutes, seconds;

public:
    friend TIME operator+(TIME &, TIME &);
    friend TIME operator-(TIME &, TIME &);
    friend bool operator>(TIME &, TIME &);

    TIME()
    {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }
    TIME(int a, int b, int c)
    {
        hours = a;
        minutes = b;
        seconds = c;
    }
    void setdata()
    {
        cout << "Enter time in HH:MM:SS format";
        cin >> hours >> minutes >> seconds;
    }
    void display(TIME o1)
    {
        cout << "The  entered time is:" <<setfill('0')<< setw(2)<<setfill('0')<<o1.hours <<":"<<setfill('0')<< setw(2) << o1.minutes << ":"<<setfill('0')<< setw(2) << o1.seconds << endl;
    }
};
TIME operator+(TIME &o1, TIME &o2)
{
    TIME final;
    final.hours = o1.hours + o2.hours;
    final.minutes = o1.minutes + o2.minutes;
    if (final.minutes >= 60)
    {
        final.hours = final.hours + (final.minutes / 60);
        final.minutes = final.minutes % 60;
        
    }
    final.seconds = o1.seconds + o2.seconds;
    if (final.seconds >= 60)
    {
        final.minutes = final.minutes + final.seconds / 60;
        final.seconds = final.seconds % 60;
        
    }
    cout << "After addition the resulting time is:"<<setfill('0') <<setw(2)<< final.hours << ":" <<setfill('0')<<setw(2)<< final.minutes << ":" <<setfill('0')<<setw(2)<< final.seconds << endl;
}
TIME operator-(TIME &o1, TIME &o2)
{
    TIME final;
    final.hours = o1.hours - o2.hours;
    if (final.hours < 0) {
        cout << "The resulting time is negative!" << endl;
        final.hours = 0;
        final.minutes = 0;
        final.seconds = 0;
         cout << "After subtraction the resulting time is:" <<setfill('0')<<setw(2)<< final.hours << ":" <<setfill('0')<<setw(2)<< final.minutes << ":"<<setfill('0') <<setw(2)<< final.seconds << endl;
         exit(0);
    }
    final.minutes = o1.minutes - o2.minutes;
    if (final.minutes <0){
        final.hours -= 1;
        final.minutes += 60;
    }
    final.seconds = o1.seconds - o2.seconds;
    if (final.seconds <0){
        final.minutes -= 1;
        final.seconds += 60;
    }
    cout << "After subtraction the resulting time is:" <<setw(2)<< final.hours << ":" << setw(2)<< final.minutes << ":" << setw(2)<< final.seconds << endl;
}
bool operator>(TIME &o1, TIME &o2)
{
    double a, b;
    a = o1.hours + o1.minutes / 60 + o1.seconds / 3600;
    b = o2.hours + o2.minutes / 60 + o2.seconds / 3600;
    return (a > b);
}
int main()
{
    TIME first, second(3, 40, 50), final;
    first.setdata();
    // second.setdata();
    first.display(first);
    second.display(second);
    if (first > second)
    {
        cout << "first time is more than second time." << endl;
    }
    else
    {
        cout << "Second time is more than or equal to first time." << endl;
    }
    final = first + second;
    final = first - second;
    return 0;
}