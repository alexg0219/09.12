#include <iostream>
#include <string>
#include <set>
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

    string s, s1;
    int k = 0;
    input >> s >> s1;
    set<string> a;
    for (int i = 0; i < s1.size(); ++i) 
        a.insert(s1.substr(s1.size() - i - 1) + s1.substr(0, s1.size() - i - 1));
    
    for (auto i : a) 
    {
        int pos = s.find(i);
        while (pos + 1) {
            ++k;
            pos = s.find(i, pos + 1);
        }
    }
    output << k;
    
    input.close();
    output.close();
}
