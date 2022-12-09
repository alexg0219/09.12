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

    int n, k,f=0,t,c=0;
    input >> n >> k;

    for (int i = 1;f != n ;i++)
    {
        f = 0;
        for (int d = i; d > 0; f++) 
        {
            if (f > n) 
                break;
            t = d;
            d -= d / n;
            d -= t % n;
            if (t % n != k) 
                break;
        }
        c++;
    }

    output << c;

    input.close();
    output.close();
}
