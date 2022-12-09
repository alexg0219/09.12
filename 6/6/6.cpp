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

    int k, max, pl,nk,ok;
    input >> k;

    nk = k / 107;
    ok = k % 107;

    max = nk * 100;
    pl = nk * 7;
    if (ok >= 8)
    {
        max += ok - 7;
        pl += 7;
    }

    output << max << " " << pl;

    input.close();
    output.close();
}