#include <iostream>
#include <vector>
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

    int n, x = 0;
    input >> n;
    vector <int> a(n);

    for (int i = 0; i < n; i++)
    {
        input >> a[i];
    }

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                x = a[i + 1];
                a[i + 1] = a[i];
                a[i] = x;
            }
        }
    }

    for (auto i : a)
        output << i << " ";

    input.close();
    output.close();
}

