#include "Header.h"
using namespace std;
char fname[20] = "file1.bin"; // ���������� ��� �������� �����
int len = sizeof(INFO); // ���������� ��� ����� ������ � ������
char menu()
{
	setlocale(LC_ALL, "ru");
	cout << endl << "\n\t1-> �������� ������"
		<< endl << "\t2-> ������ ���� �������"
		<< endl << "\t3-> ������ ������ � N �������"
		<< endl << "\t4-> �������� �� ��������"
		<< endl << "\t5-> ����� ������� �� ��������"
		<< endl << "\t6-> ������� ��������� ������"
		<< endl << "\t7-> ������� � ���� ����� �������� ���������������� �� ������ �� ���� ��������� ����������"
		<< endl << "\t0-> EXIT" << endl;
	char s;
	cin >> s;
	return s;
}
int main()
{
	setlocale(LC_ALL, "ru");
	fstream p(fname, ios::app); // �������� ����� �� ������ � ������
	// ���� ������� ������� ����
	if (p)
	{
		p.close(); // ��������� ����
		p.open(fname, ios::in | ios::out | ios::ate | ios::binary); // ��������� �� ������ � ������� � �������� ������, ������ � ���� �����,
		// �� ����� ������ ���������
	}
	int n;
	do
	{
		char s = menu();
		switch (s)
		{
		case'0':
			p.close(); // �������� �����
			exit(0);
		case'1':
			cout << "������� ���-�� �������\n";
			cin >> n;
			writeNzap(p, n);
			break;
		case'2':
			readAll(p);
			break;
		case'3':
			int nom;
			cout << "������� ����� ������\n";
			cin >> nom;
			readN(p, nom);
			break;
		case'4':
			int a;
			char name[10];
			cout << "\n\t������� �������� ����: ";
			cin >> name;
			a = metkaDel(p, name);
			break;
		case '5':
			UNmetkaDel(p);
			system("cls");
			break;
		case '6':
			Delete(p);
			cout << ("\n\tDone!");
			break;
		case '7':
			spravka(p);
			break;
		default:
			cout << "������� ������������ ��������\n���������� ��� ���!" << endl;
		}
	} while (1);
	p.close(); // �������� �����
	return 0;
}