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

	int n,c=0,min=INT_MAX;
	input >> n;
	vector <int> a(n);
	vector <int> narr;

	for (int i = 0; i < n; i++)
	{
		input >> a[i];
	}

	for (int i = 0; i < n; i++)
	{
		if (count(a.begin(), a.end(), a[i]) > c)
			c = count(a.begin(), a.end(), a[i]);
	}

	for (int i = 0; i < n; i++)
	{
		if (count(a.begin(), a.end(), a[i]) == c)
			narr.push_back(a[i]);
	}


	for (int i = 0; i < narr.size(); i++)
	{
		if (narr [i] < min)
		{
			min = narr[i];
		}
	}

	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == min)
			a.erase(a.begin() + i);
	}

	for (int i = 0; i < c; i++)
		a.push_back(min);

	for (auto i : a)
		output << i << " ";

	input.close();
	output.close();
}
