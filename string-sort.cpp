#include<iostream>
#include<string>
#include<vector>
using namespace std;


vector<string> a;
vector<string> b;
int flag = 0;
int counta = 0;
int countb = 0;

void sort(vector<string> a, vector<string> b);

int judge(int i, int j);

int main()
{
	//int inpt=0;
	string inpt;
	for (int i = 0; inpt != "end"; i++)	//a[i-1]!="end"
	{
		cin >> inpt;
		a.push_back(inpt);
		counta++;
	}
	counta--;

	//------------------------将a[i]插入b[i]中的正确位置---------------------------------//

	for (int i = 0; i < counta; i++)
	{
		//string end;
		for (int j = 0; j < countb; j++)
		{
			//如果a[i]的第一个字母小于b[j]的第一个字母
			//将a[i]插入到b[j]之前的位置
			if (a[i]<b[j])
			{
				b.insert(b.begin() + j, a[i]);
				countb++;
				flag = 1;
				//end = b[countb];
				break;
			}
		}
		if (flag == 0) {
			b.push_back(a[i]);
			countb++;
		}
		flag = 0;
	}

	//--------------------------------------------------------------------------------//

	for (int i = 0; i<(countb-1); i++)
	{
		cout << b[i] << ',';
	}
	cout << b[countb - 1] << endl;

	//a.push_back("long");
	system("pause");
	return 0;
}



int judge(int i, int j)
{
	static int  k = 1;
	if (a[1].at(k) == b[1].at(k)) {
		k++;
		judge(i, j);
	}
	else return k;
}