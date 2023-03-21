#include "Header.h"
ostream& shapka(ostream& stream) // шапка для таблицы
{
	setlocale(LC_ALL, "rus");
	stream << endl << FinishL << endl;
	stream << setw(5) << "Код цеха"
		<< setw(18) << " Название цеха";
	stream << setw(24) << "Технические работники";
	stream << setw(28) << "Квалифицированные рабочие";
	stream << setw(20) << "Подсобные рабочие";
	stream << setw(10) << " Метка";
	stream << endl << FinishL;
	return stream;
}
ostream& FinishL(ostream& stream) // Вывод финальной линии таблицы
{
	stream << setfill('-') << setw(110) << '|' << setfill(' ');
	return stream;
}


ostream& shapka_spravka(ostream& stream) // шапка для справки
{
	setlocale(LC_ALL, "rus");
	stream << endl << FinishL << endl;
	stream << setw(20) << "\tСправка о трех цехах наименее укомплектованных по каждой из трех категорий работников" << endl;
	stream << endl << FinishL << endl;
	stream << setw(8) << "Название цеха";
	stream << setw(60) << "Тип рабочих, который наименее укомплектованный в цеху";
	stream << setw(35) << "Укомплектованность в процентах";
	stream << endl << FinishL;
	return stream;
}