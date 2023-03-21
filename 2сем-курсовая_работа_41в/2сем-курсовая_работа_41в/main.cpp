#include "Header.h"
using namespace std;
char fname[20] = "file1.bin"; // переменная под названия файла
int len = sizeof(INFO); // переменная под длину записи в байтах
char menu()
{
	setlocale(LC_ALL, "ru");
	cout << endl << "\n\t1-> Добавить запись"
		<< endl << "\t2-> Чтение всех записей"
		<< endl << "\t3-> Чтение записи с N номером"
		<< endl << "\t4-> Пометить на удаление"
		<< endl << "\t5-> Снять пометку на удаление"
		<< endl << "\t6-> Удалить выбранную запись"
		<< endl << "\t7-> Справка о трех цехах наименее укомплектованных по каждой из трех категорий работников"
		<< endl << "\t0-> EXIT" << endl;
	char s;
	cin >> s;
	return s;
}
int main()
{
	setlocale(LC_ALL, "ru");
	fstream p(fname, ios::app); // открытие файла на чтение и запись
	// Если удалось открыть файл
	if (p)
	{
		p.close(); // Закрываем файл
		p.open(fname, ios::in | ios::out | ios::ate | ios::binary); // Открываем на чтение и зазпись в двоичном режиме, запись в конц файла,
		// но можно менять указатель
	}
	int n;
	do
	{
		char s = menu();
		switch (s)
		{
		case'0':
			p.close(); // закрытие файла
			exit(0);
		case'1':
			cout << "Введите кол-во записей\n";
			cin >> n;
			writeNzap(p, n);
			break;
		case'2':
			readAll(p);
			break;
		case'3':
			int nom;
			cout << "Введите номер записи\n";
			cin >> nom;
			readN(p, nom);
			break;
		case'4':
			int a;
			char name[10];
			cout << "\n\tВведите название цеха: ";
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
			cout << "Введено неправильное действие\nПопробуйте ещё раз!" << endl;
		}
	} while (1);
	p.close(); // закрытие файла
	return 0;
}