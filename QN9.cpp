//  Create a 'MATRIX' class of size m X n. Overload the ‘+’ operator to
//  Add Two MATRIX objects. Write a main function to implement it.
#include <iostream>
using namespace std;
class matrix
{
    int a[10][10];
    int i, j, m, n;

public:

    matrix()
    {
        m = 0;
        n = 0;
    }
    void setdata()
    {

        cout << "Enter the rows and columns of the martrix." << endl;
        cin >> m >> n;
      
        cout << "Enter the member of the matrix." << endl;
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
    }
    void display()
    {
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                cout << a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    matrix operator+(matrix &o2)
{
    int i, j;
    matrix demo;
    demo.m = m;
    demo.n = o2.n;

    if (m != o2.m || n != o2.n)
    {
        cout << "Matrix addition is not possible.";
        exit(0);
    }
    for (i = 0; i < demo.m; i++)
    {
        for (j = 0; j < demo.n; j++)
        {
            demo.a[i][j] = a[i][j] + o2.a[i][j];
        }
    }
    return demo;
}
};


int main()
{
    int i, j;
    matrix first, second, result;
    first.setdata();
    second.setdata();
    result = first + second;
    cout << "After addition:" << endl;

    result.display();

    return 0;
}