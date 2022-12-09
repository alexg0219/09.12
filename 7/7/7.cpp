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

    int n,k,t,s=0;
    input >> n;
    vector <vector<int>> a;
    a.clear();
    vector<int>x;

    for (int i = 0; i < n; i++)
    {
        x.clear();
        for (int j = 0; j < 3; j++)
        {
            input >> k;
            x.push_back(k);
        }
        a.push_back(x);
    }

    input >> t;
    
    for (int i = 1; i < t+1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[j][0] < i && i <= a[j][1])
                s += a[j][2];
        }
        
        if (s < 0)
            s = 0;
    }
    
    output << s;
}