#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream input("input.txt");
    ofstream output("output.txt");

    if (!input)
    {
        cout << "error";
        return 0;
    }
    
    string a, b, c;
    input >> a >> b >> c;
    int a1 = a[0] - 64 - 1;
    int a2 = a[1] - 48 - 1;

    int b1 = b[0] - 64 - 1;
    int b2 = b[1] - 48 - 1;

    int c1 = c[0] - 64 - 1;
    int c2 = c[1] - 48 - 1;

    int s[8][8] = { 0 };
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j) 
        {
            if (abs(a1 - j) == abs(a2 - i))
                s[i][j] = 1;
            else
                if (a1 == j || a2 == i)
                    s[i][j] = 1;
                else
                    if (b1 == j || b2 == i)
                        s[i][j] = 1;
                    else
                        if ((abs(c1 - j) == 1 && abs(c2 - i) == 2) || (abs(c1 - j) == 2 && abs(c2 - i) == 1))
                            s[i][j] = 1;
        }
    s[a2][a1] = 0;
    s[b2][b1] = 0;
    s[c2][c1] = 0;
    int k = 0;
    for (int i = 0; i < 8; ++i) 
    {
        for (int j = 0; j < 8; ++j)
            if (s[i][j] == 1)
                ++k;
    }

    output << k;

    input.close();
    output.close();
}