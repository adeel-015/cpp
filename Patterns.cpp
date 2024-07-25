#include <iostream>
using namespace std;

void print1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void print2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void print3(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        cout << endl;
    }
}
void print4(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i;
        }
        cout << endl;
    }
}
void print5(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void print6(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << j;
        }
        cout << endl;
    }
}
void print7(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // spaces
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }

        // stars
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void print8(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= 2 * n - (2 * i - 1); j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void print10(int n)
{
    for (int i = 0; i <= 2 * n - 1; i++)
    {
        int stars = i;
        if (i > n)
            stars = 2 * n - i;
        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void print11(int n)
{
    int start = 1;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            start = 1;
        }
        else
        {
            start = 0;
        }
        for (int j = 0; j <= i; j++)
        {
            cout << start;
            start = 1 - start;
        }
        cout << endl;
    }
}
void print12(int n)
{
    for (int i = 1; i <= n; i++)
    {
        int iniS = 2 * n - 2 - i;
        // num
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        // spaces
        for (int j = i; j <= 2 * n - i - 1; j++)
        {
            cout << " ";
        }
        iniS -= 2;
        // nums
        for (int j = i; j >= 1; j--)
        {
            cout << j;
        }
        cout << endl;
    }
}
void print13(int n)
{
    int num = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
}
void print14(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char ch = 'A'; ch <= 'A' + i; ch++)
        {
            cout << ch;
        }
        cout << endl;
    }
}
void print15(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (char ch = 'A'; ch <= 'A' + (n - i); ch++)
        {
            cout << ch;
        }
        cout << endl;
    }
}
void print16(int n)
{
    for (int i = 0; i < n; i++)
    {
        char ch = 'A' + i;
        for (int j = 0; j <= i; j++)
        {
            cout << ch;
        }
        cout << endl;
    }
}
void print17(int n)
{
    for (int i = 0; i < n; i++)
    {
        char ch = 'A';
        int breakpoint = (2 * i + 1) / 2;
        // spaces
        for (int j = n - i; j > 1; j--)
        {
            cout << " ";
        }
        // alphabets
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << ch;
            if (j < breakpoint)
            {
                ch++;
            }
            else
            {
                ch--;
            }
        }
        cout << endl;
    }
}
void print18(int n)
{
    for (int i = 0; i < n; i++)
    {
        // alphabets
        for (char ch = 'E' - i; ch <= 'E'; ch++)
        {
            cout << ch;
        }
        cout << endl;
    }
}
void print19(int n)
{
    for (int i = 0; i < n; i++)
    {
        int iniS = 2 * i;
        // stars
        for (int j = 1; j <= n - i; j++)
        {
            cout << "*";
        }
        // spaces
        for (int j = 1; j <= iniS; j++)
        {
            cout << " ";
        }
        iniS += 2;

        // stars
        for (int j = 1; j <= n - i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        int iniS = 2 * n - 2 * i;
        // stars
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        // spaces
        for (int j = 2; j < iniS; j++)
        {
            cout << " ";
        }

        // stars
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
        iniS -= 2;
    }
}
void print20(int n)
{
    for (int i = 0; i < n; i++)
    {
        int iniS = 2 * n - 2 * i;
        // stars
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        // spaces
        for (int j = 2; j < iniS; j++)
        {
            cout << " ";
        }

        // stars
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
        iniS -= 2;
    }
    for (int i = 1; i < n; i++)
    {
        int iniS = 2 * i;
        // stars
        for (int j = 1; j <= n - i; j++)
        {
            cout << "*";
        }
        // spaces
        for (int j = 0; j < iniS; j++)
        {
            cout << " ";
        }
        iniS += 2;

        // stars
        for (int j = 1; j <= n - i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void print21(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j == 1 || i == 1 || i == n || j == n)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}
void print22(int n)
{
    for (int i = 0; i < 2 * n - 1; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            int top = i;
            int down = j;
            int left = 2 * n - 2 - i;
            int right = 2 * n - 2 - j;
            cout << n - min(min(top, down), min(left, right)) << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    cout << endl;
    print12(n);
}
