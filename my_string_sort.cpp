#include<iostream>
#include<string>
#include<vector>
using namespace std;

//�ݲ�֧�ִ�Сд������룬����ͬʱ����USA��Uzetabek
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
	for (int i = 0;inpt!="end" ;i++)	//a[i-1]!="end"
	{
		cin >> inpt;
		a.push_back(inpt);
		counta++;
	}
	counta--;

//------------------------��a[i]����b[i]�е���ȷλ��---------------------------------//
	
	for (int i = 0; i < counta; i++)   
	{
		//string end;
		for (int j = 0;j < countb; j++)
		{
			//���a[i]�ĵ�һ����ĸС��b[j]�ĵ�һ����ĸ
			//��a[i]���뵽b[j]֮ǰ��λ��
			if (a[i].at(0)<b[j].at(0))
			{
				b.insert(b.begin() + j, a[i]);
				countb++;
				flag = 1;
				//end = b[countb];
				break;
			}
			if (a[i].at(0) == b[j].at(0))
			{
				int x = judge(i,j);
				//���֮ǰ�ľ��ǰ���ĸ˳�����У���ô��һ��a[i]<b[j]��λ��j��Ӧ����a[i]�����λ��
				if (a[i].at(x) < b[j].at(x)) {
					b.insert(b.begin() + j, a[i]);
					countb++;
					flag = 1;
					break;
				}
				if (a[i].at(x) > b[j].at(x)) {
					//b.insert(b.begin() + j + 1, a[i]); //���b���Ѿ���abcd��abdd����ôabzn����ʱ�������
					continue;
				}
			}
		}
		if (flag == 0) {
			b.push_back(a[i]);
			countb++;
		}
		flag = 0;
	}
	
//--------------------------------------------------------------------------------//

	for (int i=0;i<countb;i++)
	{
		cout << b[i] << endl;
	}
	
	//a.push_back("long");
	system("pause");
	return 0;
}



int judge(int i, int j)
{
	static int  k = 1;
	if (a[1].at(k) == b[1].at(k)) {
		k++;
		judge(i,j);
	}
	else return k;
}