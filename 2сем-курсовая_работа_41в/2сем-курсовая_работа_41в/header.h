#pragma once
#include <conio.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
using namespace std;
extern int len;
extern char fname[20]; // ���������� ��� ��� ����
struct INFO
{
	char workshop_code[20]; // ��� ����
	char workshop_name[20]; // �������� ����
	float specialists[3]; // ����������� ���������, ����������������� �������, ��������� �������
	char metka[2]; // ����� �� ��������
};
ostream& FinishL(ostream& stream); // ����� �����
ostream& shapka(ostream& stream); // ����� �����
ostream& shapka_spravka(ostream& stream); // ����� ����� �������
void write(fstream& p, INFO zap, int num = 0); // ������ � ����
void print(INFO zap); // ����� ����� ������
void print2(INFO zap, int i); // ����� ����� ������
INFO vvod(); // ���� ����� ������
void writeNzap(fstream& p, int n); // ������ N ������� � ����� �����
fstream& read(fstream& p, INFO& zap, int num = 0); // ������ ����� ������
void readAll(fstream& p); // ������ ���� ������� �� �����
void readN(fstream& p, int N); // ������ ����� ������ �� �����
int metkaDel(fstream& p, char* shifr); // ����� �� ��������
void UNmetkaDel(fstream& p); // ����� ����� �� ��������
void spravka(fstream& p); // ����� ������� �� �����
int Delete(fstream& p); // ������� ������, ���������� �� ��������

