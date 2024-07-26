// Modify above class to work with compile time memory allocation i.e. with
// char [].
#include <iostream>
#include <cstring>
using namespace std;

const int len = 100;

class STRING
{
private:
    char str[len];
    int length;

public:
    STRING()
    {
        str[0] = '\0';
        length = 0;
    }

    STRING(const char *input)
    {
        length = strlen(input);
        if (length > len - 1)
        {
            cout << "Length of the string is exceeds the threshold." << endl;
            length = 0;
            str[0] = '\0';
        }
        else
        {
            strcpy(str, input);
        }
    }

    STRING(const STRING &other)
    {
        length = other.length;
        strcpy(str, other.str);
    }

    STRING operator+(const STRING &other) const
    {
        STRING demo;
        if (length + other.length > len - 1)
        {
            cout << "Concatenated string is more than threshold." << endl;
            demo.str[0] = '\0';
            demo.length = 0;
        }
        else
        {
            demo.length = length + other.length;
            strcpy(demo.str, str);
            strcat(demo.str, other.str);
        }
        return demo;
    }

    STRING &operator=(const STRING &other)
    {
        length = other.length;
        if (length > len - 1)
        {
            cerr << "Assigned string exceeds maximum length." << endl;
            length = 0;
            str[0] = '\0';
        }
        else
        {
            strcpy(str, other.str);
        }

        return *this;
    }

    bool operator==(const STRING &other) const
    {
        return (strcmp(str, other.str) == 0);
    }

    void display() const
    {
        cout << str << endl;
    }
};

int main()
{
    STRING first("swayam ");
    STRING second("shrestha");

    STRING third, fourth;
    third = first + second;
    third.display();

    fourth = first;
    cout << "After assesmenting the string:" << endl;
    fourth.display();
    return 0;
}
