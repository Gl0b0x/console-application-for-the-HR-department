#include "Header.h"
ostream& shapka(ostream& stream) // ����� ��� �������
{
	setlocale(LC_ALL, "rus");
	stream << endl << FinishL << endl;
	stream << setw(5) << "��� ����"
		<< setw(18) << " �������� ����";
	stream << setw(24) << "����������� ���������";
	stream << setw(28) << "����������������� �������";
	stream << setw(20) << "��������� �������";
	stream << setw(10) << " �����";
	stream << endl << FinishL;
	return stream;
}
ostream& FinishL(ostream& stream) // ����� ��������� ����� �������
{
	stream << setfill('-') << setw(110) << '|' << setfill(' ');
	return stream;
}


ostream& shapka_spravka(ostream& stream) // ����� ��� �������
{
	setlocale(LC_ALL, "rus");
	stream << endl << FinishL << endl;
	stream << setw(20) << "\t������� � ���� ����� �������� ���������������� �� ������ �� ���� ��������� ����������" << endl;
	stream << endl << FinishL << endl;
	stream << setw(8) << "�������� ����";
	stream << setw(60) << "��� �������, ������� �������� ���������������� � ����";
	stream << setw(35) << "������������������ � ���������";
	stream << endl << FinishL;
	return stream;
}