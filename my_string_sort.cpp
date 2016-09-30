#include<iostream>
#include<string>
#include<vector>
using namespace std;

//暂不支持大小写混合输入，例如同时输入USA和Uzetabek
vector<string> a;
vector<string> b;
int flag = 0;

int judge(int i, int j,int x);

int main()
{
//--------------------------------输入a[]-------------------------------------------//
	string inpt;
	for (int i = 0;inpt!="end" ;i++)	//a[i-1]!="end"
	{
		cin >> inpt;
		a.push_back(inpt);
	}
//------------------------将a[i]插入b[i]中的正确位置---------------------------------//
	for (int i = 0; i < (a.size()-1); i++)   
	{
		for (int j = 0;j < b.size(); j++)
		{
			//调用judge，找出a[i]和b[j]第x个字符开始不相同
			int x = 0;
			x = judge(i, j, x);
			//如果之前的均是按string大小顺序排列，那么第一个a[i]<b[j]的位置j就应该是a[i]插入的位置
			//如果成功将a[i]插入某个位置，将flag改为1，并跳出循环
			if (a[i].at(x) < b[j].at(x)) {
				b.insert(b.begin() + j, a[i]);	
				flag = 1;
				break;
			}
		}
		//flag为0说明遍历b之后没有找到一个b[j]>a[i],那么将a[i]插入b的末尾
		if (flag == 0) {
			b.push_back(a[i]);
		}
		flag = 0;
	}
//---------------------------输出b[]----------------------------------------------//

	for (int i = 0; i<(b.size() - 1); i++)
	{
		cout << b[i] << ',';
	}
	cout << b[b.size() - 1] << endl;
	
	//system("pause");
	return 0;
}


//judge,递归调用，直到找到a[i]和b[j]的第x个字符不相同，return x 
int judge(int i, int j,int x)
{
	if (a[i].at(x) == b[j].at(x)) {
		x++;
		x = judge(i, j, x);
	}
	return x;
}
