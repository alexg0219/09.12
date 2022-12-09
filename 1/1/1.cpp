#include <iostream>
#include <fstream>

using namespace std;

int nod(int a, int b)
{
	while (b!=0)
	{
		int t = a % b;
		a = b;
		b = t;
	}
	return a;
}

int ct(int c)
{
	if (c == 1)
		return 0;
	int d=2;
	int count=0;
	while (d*d <= c)
	{
		if (c % d == 0)
		{
			count++;
			c = c / d;
		}
		else
			d++;
	}
	return count + 1;
}

int main()
{
	ifstream input("input.txt");
	ofstream output("output.txt");

	if (!input)
	{
		cout << "error";
		return 0;
	}

    int n,m,g,a,b;
    input >> n >> m;

	g = nod(n, m);

	a = ct(n / g);
	b = ct(m / g);

	output << a + b;

	input.close();
	output.close();
}

