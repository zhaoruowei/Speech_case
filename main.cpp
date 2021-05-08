#include<iostream>
using namespace std;
#include"SysManager.h"

int main()
{
	SysManager sys;
	system("pause");
	system("cls");

	while (true)
	{
		sys.ShowUI();
		cout << "请输入您的选择：" << endl;
		int select = 0;
		cin >> select;
		switch (select)
		{
		case 1:
			sys.PlayGame();
			system("pause");
			system("cls");
			break;	
		case 2:
			sys.Query();
			system("pause");
			system("cls");
			break;
		case 3:
			sys.Clear();
			system("pause");
			system("cls");
			break;
		case 0:
			sys.exitSys();
			break;
		default:
			cout << "请按提示输入！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	
	return 0;
}