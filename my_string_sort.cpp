#include<iostream>
#include<string>
#include<vector>
using namespace std;

//暂不支持大小写混合输入，例如同时输入USA和Uzetabek
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

//------------------------将a[i]插入b[i]中的正确位置---------------------------------//
	
	for (int i = 0; i < counta; i++)   
	{
		//string end;
		for (int j = 0;j < countb; j++)
		{
			//如果a[i]的第一个字母小于b[j]的第一个字母
			//将a[i]插入到b[j]之前的位置
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
				//如果之前的均是按字母顺序排列，那么第一个a[i]<b[j]的位置j就应该是a[i]插入的位置
				if (a[i].at(x) < b[j].at(x)) {
					b.insert(b.begin() + j, a[i]);
					countb++;
					flag = 1;
					break;
				}
				//下面的if判断貌似可以不要
				if (a[i].at(x) > b[j].at(x)) {
					continue;
				}
			}
		}
		//如果遍历b之后都没有找到b[j]>a[i],那么将a[i]插入b末尾
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


//使用递归方法，找到a[i]和b[j]两个string第一个不相同的字符a[i].at(k)和b[j].at(k)，并返回k值
int judge(int i, int j)
{
	static int  k = 1;
	if (a[i].at(k) == b[j].at(k)) {
		k++;
		judge(i,j);
	}
	else return k;
}
