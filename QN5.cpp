// Modify above class to work with compile time memory allocation i.e. with
// char [].
#include <iostream>
#include <cstring>
using namespace std;
class STRING
{
   char *str;
   int length;

public:
   STRING()
   {
      str = nullptr;
      length = 0;
   }
   STRING(const char *input)
   {
      length = strlen(input);
      str = new char[length + 1]; // dynamic memeory allocation
      strcpy(str, input);
   }
   STRING(const STRING &o1)
   { 
      length = strlen(o1.str);
      str = new char[length + 1];
      strcpy(str, o1.str);
   }
   ~STRING()
   {
      delete[] str;
   }
   STRING operator+(STRING &o1)
   {
      STRING demo;
      demo.length = length + o1.length;
      demo.str = new char[demo.length + 1];
      strcpy(demo.str, str);
      strcat(demo.str, o1.str);
      return demo;
   }
   STRING operator=(const STRING &o1)
   {
      if (this != &o1) { 
         delete[] str;}
   length = o1.length;
      str = new char[length + 1];
      strcpy(str, o1.str);
      return *this;
   }
   bool operator == (STRING &o1){
      return ( strcmp(str, o1.str)== 0);
   }
   void display ( ){
     
      cout<<str<<endl;
   }
};

int main()
{
   STRING first("swayam ");
   STRING second ("shrestha");
   STRING third,fourth;
   third = first + second; 
   first.display();
   second.display();
   third.display();
   if (first == second){
     cout<<"They are equal."<<endl;
   }else
   {
    cout<<"They are unequal."<<endl;
   }
   fourth = first;
   cout<<"after assesmenting the string."<<endl;
   fourth.display();
   return 0;
}
