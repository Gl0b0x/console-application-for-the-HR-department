#include "Header.h"
#include <string.h>
void writeNzap(fstream& p, int n) // Запись n записей в конец файла
{
	p.clear(); // очистка потока
	p.seekg(0, ios::end); // запись в конец файла
	for (int i = 0; i < n; i++)
	{
		INFO zap; // куда читать
		zap = vvod(); // Ввод записи
		write(p, zap); // запись в файл
	}
}
void write(fstream& p, INFO zap, int num) // сохрание записи в файле
{
	if (num) // позиционирование
		p.seekg((num - 1) * len, ios::beg);
	p.write((char*)&zap, len);
}
void print(INFO zap) // Вывод полей записи
{
	cout << endl << setw(5) << zap.workshop_code << setw(2) << ' ';
	cout << setw(15) << zap.workshop_name << setw(2) << ' ';
	cout << setw(17) << zap.specialists[0];
	cout << setw(25) << zap.specialists[1];
		cout << setw(25) << zap.specialists[2];
	cout << setw(15) << zap.metka;
}
void readAll(fstream& p) // Чтение всех записей в файле
{
	p.clear(); // очистка потока
	p.seekg(0, ios::beg); // указатель на начало файла
	INFO zap;
	cout << shapka; // вывод шапки таблицы
	while (read(p, zap))
		print(zap); // вывод полей записи
	cout << endl << FinishL; // вывод финальной линии
}
fstream& read(fstream& p, INFO& zap, int num) // чтение записи из файла
{
	p.clear(); //очистка потока
	if (num) //позиционирование
		p.seekg((num - 1) * len, ios::beg);
	p.read((char*)&zap, len);
	return p;
}
INFO vvod() // Ввод полей записи
{
	INFO zap;
	setlocale(LC_ALL, "ru");
	cout << endl << "Введите код цеха" << endl;
	cin >> zap.workshop_code;
	cout << endl << "Введите название цеха" << endl;
	cin >> zap.workshop_name;
	cout << "Введите укомплектованность в процентах технические работники" << endl;
	cin >> zap.specialists[0];
	cout << "Введите укомплектованность в процентах квалифицированные рабочие" << endl;
	cin >> zap.specialists[1];
	cout << "Введите укомплектованность в процентах подсобные рабочие" << endl;
	cin >> zap.specialists[2];
	strcpy_s(zap.metka, "+");
	return zap;
}
void readN(fstream& p, int N) // Чтение одной записи
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
	else cout << endl << "Такой записи нет" << endl;
}
int metkaDel(fstream& p, char* name) // Метка на удаление
{
	int kol = 0;
	p.clear();
	p.seekg(0, ios::beg);
	INFO zap;
	for (int i = 1; read(p, zap, i); i++)
	{
		if (strcmp(zap.workshop_name, name) == 0) // Если название цеха совпало с введенными даннми с клавиатура,
			// то функция strcmp вернет нуль
		{
			strcpy_s(zap.metka, "-"); // Копируем строку - и записываем в поле zap.metka
			write(p, zap, i); // записываем в файл на i место
			kol++;
		}
	}
	return kol;
}
void UNmetkaDel(fstream& p) // Убрать метки на удаление
{
	p.clear();
	p.seekg(0, ios::beg);
	INFO zap;
	for (int i = 1; read(p, zap, i); i++)
	{
		if (strcmp(zap.metka, "-") == 0) // Если в zap.metka записанно 0, то
		{
			strcpy_s(zap.metka, "+"); // Копируем строку + и записываем в поле zap.metka
			write(p, zap, i); // записываем в файл на i место
		}
	}
}
int Delete(fstream& p) // Удалить записи
{
	int kol = 0;
	fstream p1("temp.txt", ios::app); // Создаем новый файл
	p.clear();
	p.seekg(0, ios::beg);
	INFO zap;
	for (int i = 1; read(p, zap, i); i++)
	{
		if (strcmp(zap.metka, "+") == 0) // Если поле zap.metka равна +, то эту сохраняем
			// запись в новый файл
		{
			write(p1, zap);
			kol++;
		}
	}
	// очистка потоков
	p.close();
	p1.close();
	remove(fname); // Удаляем файл с именем fname
	rename("temp.txt", fname); // Переименовываем новый файл на fname
	p.open(fname, ios::in | ios::out | ios::ate | ios::binary); // Открываем на чтение и зазпись в двоичном режиме, запись в конц файла,
	// но можно менять указатель
	return kol;
}
void spravka(fstream& p)
{
	INFO zap;
	p.clear();
	float min_spec[3][2]; // Вспомогательный массив
	// в 0-ых столбцах будет храниться, порядковый номер записи в файле, а в 1-ых столбцах минимальная укомлектованность по
	// каждой специальности
	p.seekg(0, ios::beg);
	for (int i = 1; read(p, zap, i); i++)
	{
		// Первую запись, берем как за минимум по всем специальностям
		if (i == 1)
		{
			min_spec[0][0] = zap.specialists[0];
			min_spec[1][0] = zap.specialists[1];
			min_spec[2][0] = zap.specialists[2];
			min_spec[0][1] = 1;
			min_spec[1][1] = 1;
			min_spec[2][1] = 1;
		}
		// Затем ищем цеха, где есть минимальна укомплектованые специальности
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
	cout << shapka_spravka << endl; // вывод шапки справки
	// Вывод записей, которые содержат минимальную укомплектованность по каждой специальности
	for (int i = 0; i < 3; i++)
	{
		read(p, zap, min_spec[i][1]);
		print2(zap, i);
	}
	cout << FinishL;
}

void print2(INFO zap, int i) // Вывод полей записи
{
	cout << setw(10) << zap.workshop_name << setw(2) << ' ';
	if (i == 0) cout << setw(40) << "Технические";
	else if (i == 1) cout << setw(40) << "Квалифицированные";
	else cout << setw(40) << "Подсобные";
	cout << setw(42) << zap.specialists[i] << endl;
}