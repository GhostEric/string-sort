#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> a;
vector<string> b;


int judge()
{
	static int  k = 1;
	if (a[1].at(k) == b[1].at(k)) {
		k++;
		judge();
	}
	else return k;
}


int main()
{
	a.push_back("aa");
	a.push_back("abcdegg");
	b.push_back(" ");
	b.push_back("abcdfww");
	int x = judge();
	cout << x << endl;
	system("pause");
	return 0;
}