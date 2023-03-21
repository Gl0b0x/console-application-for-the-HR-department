#include "Header.h"
#include <string.h>
void writeNzap(fstream& p, int n) // ������ n ������� � ����� �����
{
	p.clear(); // ������� ������
	p.seekg(0, ios::end); // ������ � ����� �����
	for (int i = 0; i < n; i++)
	{
		INFO zap; // ���� ������
		zap = vvod(); // ���� ������
		write(p, zap); // ������ � ����
	}
}
void write(fstream& p, INFO zap, int num) // �������� ������ � �����
{
	if (num) // ����������������
		p.seekg((num - 1) * len, ios::beg);
	p.write((char*)&zap, len);
}
void print(INFO zap) // ����� ����� ������
{
	cout << endl << setw(5) << zap.workshop_code << setw(2) << ' ';
	cout << setw(15) << zap.workshop_name << setw(2) << ' ';
	cout << setw(17) << zap.specialists[0];
	cout << setw(25) << zap.specialists[1];
		cout << setw(25) << zap.specialists[2];
	cout << setw(15) << zap.metka;
}
void readAll(fstream& p) // ������ ���� ������� � �����
{
	p.clear(); // ������� ������
	p.seekg(0, ios::beg); // ��������� �� ������ �����
	INFO zap;
	cout << shapka; // ����� ����� �������
	while (read(p, zap))
		print(zap); // ����� ����� ������
	cout << endl << FinishL; // ����� ��������� �����
}
fstream& read(fstream& p, INFO& zap, int num) // ������ ������ �� �����
{
	p.clear(); //������� ������
	if (num) //����������������
		p.seekg((num - 1) * len, ios::beg);
	p.read((char*)&zap, len);
	return p;
}
INFO vvod() // ���� ����� ������
{
	INFO zap;
	setlocale(LC_ALL, "ru");
	cout << endl << "������� ��� ����" << endl;
	cin >> zap.workshop_code;
	cout << endl << "������� �������� ����" << endl;
	cin >> zap.workshop_name;
	cout << "������� ������������������ � ��������� ����������� ���������" << endl;
	cin >> zap.specialists[0];
	cout << "������� ������������������ � ��������� ����������������� �������" << endl;
	cin >> zap.specialists[1];
	cout << "������� ������������������ � ��������� ��������� �������" << endl;
	cin >> zap.specialists[2];
	strcpy_s(zap.metka, "+");
	return zap;
}
void readN(fstream& p, int N) // ������ ����� ������
{
	p.clear();
	p.seekg(0, ios::beg);
	INFO zap;
	if (read(p, zap, N))
	{
		cout << shapka;
		print(zap);
		cout << endl << FinishL;
	}
	else cout << endl << "����� ������ ���" << endl;
}
int metkaDel(fstream& p, char* name) // ����� �� ��������
{
	int kol = 0;
	p.clear();
	p.seekg(0, ios::beg);
	INFO zap;
	for (int i = 1; read(p, zap, i); i++)
	{
		if (strcmp(zap.workshop_name, name) == 0) // ���� �������� ���� ������� � ���������� ������ � ����������,
			// �� ������� strcmp ������ ����
		{
			strcpy_s(zap.metka, "-"); // �������� ������ - � ���������� � ���� zap.metka
			write(p, zap, i); // ���������� � ���� �� i �����
			kol++;
		}
	}
	return kol;
}
void UNmetkaDel(fstream& p) // ������ ����� �� ��������
{
	p.clear();
	p.seekg(0, ios::beg);
	INFO zap;
	for (int i = 1; read(p, zap, i); i++)
	{
		if (strcmp(zap.metka, "-") == 0) // ���� � zap.metka ��������� 0, ��
		{
			strcpy_s(zap.metka, "+"); // �������� ������ + � ���������� � ���� zap.metka
			write(p, zap, i); // ���������� � ���� �� i �����
		}
	}
}
int Delete(fstream& p) // ������� ������
{
	int kol = 0;
	fstream p1("temp.txt", ios::app); // ������� ����� ����
	p.clear();
	p.seekg(0, ios::beg);
	INFO zap;
	for (int i = 1; read(p, zap, i); i++)
	{
		if (strcmp(zap.metka, "+") == 0) // ���� ���� zap.metka ����� +, �� ��� ���������
			// ������ � ����� ����
		{
			write(p1, zap);
			kol++;
		}
	}
	// ������� �������
	p.close();
	p1.close();
	remove(fname); // ������� ���� � ������ fname
	rename("temp.txt", fname); // ��������������� ����� ���� �� fname
	p.open(fname, ios::in | ios::out | ios::ate | ios::binary); // ��������� �� ������ � ������� � �������� ������, ������ � ���� �����,
	// �� ����� ������ ���������
	return kol;
}
void spravka(fstream& p)
{
	INFO zap;
	p.clear();
	float min_spec[3][2]; // ��������������� ������
	// � 0-�� �������� ����� ���������, ���������� ����� ������ � �����, � � 1-�� �������� ����������� ����������������� ��
	// ������ �������������
	p.seekg(0, ios::beg);
	for (int i = 1; read(p, zap, i); i++)
	{
		// ������ ������, ����� ��� �� ������� �� ���� ��������������
		if (i == 1)
		{
			min_spec[0][0] = zap.specialists[0];
			min_spec[1][0] = zap.specialists[1];
			min_spec[2][0] = zap.specialists[2];
			min_spec[0][1] = 1;
			min_spec[1][1] = 1;
			min_spec[2][1] = 1;
		}
		// ����� ���� ����, ��� ���� ���������� ��������������� �������������
		else
		{
			if (zap.specialists[0] < min_spec[0][0])
			{
				min_spec[0][0] = zap.specialists[0];
				min_spec[0][1] = i;
			}
			if (zap.specialists[1] < min_spec[1][0])
			{
				min_spec[1][0] = zap.specialists[1];
				min_spec[1][1] = i;
			}
			if (zap.specialists[2] < min_spec[2][0])
			{
				min_spec[2][0] = zap.specialists[2];
				min_spec[2][1] = i;
			}
		}
	}
	cout << shapka_spravka << endl; // ����� ����� �������
	// ����� �������, ������� �������� ����������� ������������������ �� ������ �������������
	for (int i = 0; i < 3; i++)
	{
		read(p, zap, min_spec[i][1]);
		print2(zap, i);
	}
	cout << FinishL;
}

void print2(INFO zap, int i) // ����� ����� ������
{
	cout << setw(10) << zap.workshop_name << setw(2) << ' ';
	if (i == 0) cout << setw(40) << "�����������";
	else if (i == 1) cout << setw(40) << "�����������������";
	else cout << setw(40) << "���������";
	cout << setw(42) << zap.specialists[i] << endl;
}