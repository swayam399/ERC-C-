// Modify all member operator functions to friend functionl

#include <iostream>
using namespace std;
class matrix
{
    int a[10][10];
    int i, j, m, n;
    friend matrix operator+(matrix &o1, matrix &o2);

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
};
matrix operator+(matrix &o1, matrix &o2)
{
    int i, j;
    matrix demo;
    demo.m = o1.m;
    demo.n = o2.n;

    if (o1.m != o2.m || o1.n != o2.n)
    {
        cout << "Matrix addition is not possible.";
        exit(0);
    }
    for (i = 0; i < demo.m; i++)
    {
        for (j = 0; j < demo.n; j++)
        {
            demo.a[i][j] = o1.a[i][j] + o2.a[i][j];
        }
    }
    return demo;
}

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
   