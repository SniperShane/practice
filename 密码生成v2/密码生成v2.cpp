#include<iostream>
#include<fstream>
#include<ctime>
void password_num();
void password_ch();
void choice();
using namespace std;
ofstream outfile;

int main()
{
	choice();
	cout << endl;
	return 0;
}



void password_num()
{
	int password_o[6] = { 0 };
	for (int j = 0; j < 6; j++)
	{
		password_o[j] = rand() % 10;
		cout << password_o[j] << "  ";
		outfile << password_o[j] << "  ";
		if (5 == j)
			outfile << endl;
	}
}


void password_ch()
{
	int value_n = 0;
	int value_c = 0;
	int value_s = 0;
	char password_o[10] = { 0 };//生成的初始密码数组
	char password_f[10] = { 0 };//经过判断以后的密码数组
	for (int k = 1; k > 0;)
	{
		for (int j = 0; j < 10; j++)
		{
			password_o[j] = rand() % 127;
			if ((password_o[j] > 34) && (password_o[j] < 39)||(63==password_o[j])||(64==password_o[j]))       //生成符号
			{
				password_f[j] = password_o[j];
				value_s = 1;
			}
			if (((password_o[j] > 64) && (password_o[j] < 91)) || ((password_o[j]>96) && (password_o[j] < 123)))//生成字母
			{
				password_f[j] = password_o[j];
				value_c = 1;
			}
			if ((password_o[j] > 47) && (password_o[j] < 58))//生成数字
			{
				password_f[j] = password_o[j];
				value_n = 1;
			}
		}
		if (1 == value_c*value_n*value_s)//必须同时包含数字，字母，符号
			break;
	}
	for (int j = 0; j < 10; j++)
	{
		if (0 == password_f[j])
		{
			cout << "0  ";
			outfile << "0  ";
		}
		else
		{
			cout << password_f[j] << "  ";
			outfile << password_f[j] << "  ";
		}
		if (9 == j)
			outfile << endl;
	}
	cout << endl;
}


void choice()
{
	char input;
	while (1)
	{
		srand(time(0));
		outfile.open("password.txt", ios::app);//新建一个txt文档保存生成的密码

		system("cls");
		cout << "N或n:生成6位纯数字密码\n";
		cout << "M或m:生成10位包含数字、字母和符号的混合密码\n";
		cout << "输入q退出\n\n生成的密码自动保存在password.txt文档\n\n";
		cin >> input;
		if ('n' == input || 'N' == input)
		{
			password_num();
			cout << endl;
			cout << "输入任意字符继续，输入q退出\n";
			cin >> input;
			if ('q' == input || 'Q' == input)
				exit(0);
		}

		else if ('m' == input || 'M' == input)
		{
			password_ch();
			cout << "输入任意字符继续，输入q退出\n";
			cin >> input;
			if ('q' == input || 'Q' == input)
				exit(0);
		}
		else if ('q' == input || 'Q' == input)
			exit(0);
		else
		{
			cout << "输入错误，请重新输入\n\n\a";
			cin >> input;
			if ('q' == input || 'Q' == input)
				exit(0);
			system("pause");
		}
		cout << endl;
		outfile.close();
	}
}