// To write a C++ program to swap two private data members using friend 
// functions.
#include<iostream>
using namespace std;
class data
{
   int num_1, num_2;
   friend void swapping(data &obj);
   public:
   void setdata()
   {
     cout<<"Enter the 1st value:";
     cin>>num_1;
     cout<<"Enter the 2nd value:";
     cin>>num_2;
   }
   void display(){
    cout<<"1st number is:"<<num_1<<endl<<"2nd number is :"<<num_2<<endl;
   }
  
};
void swapping( data &obj )
   {
    int temp;
     temp = obj.num_1;
     obj.num_1 = obj.num_2;
     obj.num_2 = temp;
   }
int main()
{
    data swap;
    swap.setdata();
    cout<<"Before swapping :"<<endl;
    swap.display();
    swapping (swap);
    cout<<"After swapping :"<<endl;
     swap.display();
    return 0;
}