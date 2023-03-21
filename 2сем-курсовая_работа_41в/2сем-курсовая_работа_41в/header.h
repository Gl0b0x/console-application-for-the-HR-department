#pragma once
#include <conio.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
using namespace std;
extern int len;
extern char fname[20]; // переменная под наш файл
struct INFO
{
	char workshop_code[20]; // Код цеха
	char workshop_name[20]; // Название цеха
	float specialists[3]; // технические работники, квалифицированные рабочие, подсобные рабочие
	char metka[2]; // Метка на удаление
};
ostream& FinishL(ostream& stream); // Вывод линии
ostream& shapka(ostream& stream); // Вывод шапки
ostream& shapka_spravka(ostream& stream); // Вывод шапки справки
void write(fstream& p, INFO zap, int num = 0); // Запись в файл
void print(INFO zap); // Вывод полей записи
void print2(INFO zap, int i); // Вывод полей записи
INFO vvod(); // Ввод полей записи
void writeNzap(fstream& p, int n); // Запись N записей в конец файла
fstream& read(fstream& p, INFO& zap, int num = 0); // Чтение одной записи
void readAll(fstream& p); // Чтение всех записей из файла
void readN(fstream& p, int N); // Чтение одной записи из файла
int metkaDel(fstream& p, char* shifr); // Метка на удаление
void UNmetkaDel(fstream& p); // Снять метку на удаление
void spravka(fstream& p); // Вызов справки по цехам
int Delete(fstream& p); // Удалить записи, помеченные на удаление

