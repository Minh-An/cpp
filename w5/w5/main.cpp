#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

template <class MyIterator>
void square(MyIterator first, MyIterator last)
{
	for (; first != last; first++)
	{
		*first = (*first) * (*first);
	}
}
	

int main()
{
	cout << "Enter 5 numbers: " << endl;
	int x;
	vector<int> v;
	for (int i = 0; i < 5; i++)
	{
		cin >> x;
		v.push_back(x);
	}
	square(v.begin(), v.end());
	cout << "Squared Numbers: " << endl;
	for (auto i: v)
	{
		cout << i << "\t";
	}
	cout << endl;

	cout << "Enter any key to quit: ";
	cin >> x;
	return 0;
}