#include<iostream>
#include<fstream>
#include<ctime>
int main()
{
	using namespace std;

	char input;
	time_t t;
	t = time(0);
	srand(time(0));
	ofstream outfile;
	outfile.open("password.txt",ios::app);
	for (int i = 1; i > 0;)
	{
A:		system("cls");
		cout << "N��n:����6λ����������\n"
		  	 << "M��m:����10λ�������֡���ĸ�ͷ��ŵĻ������\n";
		cout << "����q�˳�\n\n���ɵ������Զ�������password.txt�ĵ�\n\n";
		cin >> input;

		if ('n' == input || 'N' == input)
		{
			int password_o[6] = { 0 };
			for (int j = 0; j < 6; j++)
			{
				password_o[j] = rand() % 10;
				cout << password_o[j] << "  ";
				outfile << password_o[j] << "  ";
				if (5 == j)
					outfile <<endl; 
			}
			break;
		}

		else if ('m' == input || 'M' == input)
		{
			int value_n = 0;
			int value_c = 0;
			int value_s = 0;
			char password_o[10] = { 0 };
			char password_f[10] = { 0 };
			for (int k = 1; k > 0;)
			{
				for (int j = 0; j < 10; j++)
				{
					password_o[j] = rand() % 127;
					if ((password_o[j] > 34) && (password_o[j] < 39))
					{
						password_f[j] = password_o[j];
						value_s = 1;
					}
					if (((password_o[j] > 64) && (password_o[j] < 91)) || ((password_o[j]>96) && (password_o[j] < 123)))
					{
						password_f[j] = password_o[j];
						value_c = 1;
					}
					if ((password_o[j] > 47) && (password_o[j] < 58))
					{
						password_f[j] = password_o[j];
						value_n = 1;
					}
				}
				if (1 == value_c*value_n*value_s)
					break;
			}
			for (int j = 0; j < 10; j++)
			{
				if (0 == password_f[j])
				{
					cout << "0  ";
					outfile << "0  " ;
				}
				else
				{
					cout << password_f[j] << "  ";
					outfile << password_f[j] << "  ";
				}
				if (9 == j)
					outfile << endl;
			}
			break;
		}

		else
		{
			cout << "�����������������\n\n\a";
			system("pause");
		}
	}
	cout << endl;
	cout << "����c����������q�˳�\n";
	cin >> input;
	if ('c' == input || 'C' == input)
		goto A;
	if ('q' == input || 'Q' == input)
		exit(0);
	system("pause");
	return 0;	
	outfile.close();
}