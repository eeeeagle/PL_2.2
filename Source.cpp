#include <cstdio>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include "Sphere.h"

int getKey()
{
	int key = _getch();
	if ((key == 0) || (key == 224))
		key = _getch();
	return key;
}

void dots()
{
	Sleep(500);
	for (int i = 3; i > 0; i--)
	{
		printf(".");
		Sleep(500);
	}
}

void message(const char* msg, const double var)
{
	system("cls");
	printf("%s%f\n   ", msg, var);
	printf("\n\n   Нажмите Enter чтобы продолжить");
	while (true)
	{
		int key = getKey();
		if (key == 13)
			return;
	}
}

void message(const char* msg)
{
	system("cls");
	printf("%s", msg);
	dots();
}

void printPointCoordinates(const Point& p)
{
	printf("(%f, %f, %f)", p.GetX(), p.GetY(), p.GetZ());
}

void printSphereInfo(const Sphere& s)
{
	printf("   Координаты центра сферы: ");
	printPointCoordinates(s.GetCenterOfSphere());
	printf("\n   Радиус сферы r = %f\n", s.GetRadius());
}

double setDouble(const double current)
{
	char string[21] = { '\0' };
	double result = 0.0;
	unsigned i = 0;
	bool flag = true;
	while (true)
	{
		system("cls");
		printf("   Введите число:\n   %s\n   _____________________________________________________\n\n"
			"   Enter:\tПринять ввод\n   Backspace:\tКоррекция ввода\n   ESC:\t\tОтмена ввода\n", string);
		int temp = getKey();
		switch (temp)
		{
		case 27:
			message("   Отмена ввода");
			return current;
		case 13:
			result = atof(string);
			return result;
		case 8:
			if (i > 0)
			{
				i--;
				if (string[i] == ',')
					flag = true;
				string[i] = '\0';
			}
			break;
		default:
		{
			if (i < 20)
			{
				if ((i == 0 && temp == '-') || isdigit(temp))
				{
					string[i] = (char)temp;
					i++;
					break;
				}
				if (flag && temp == ',' && i > 0)
				{
					string[i] = (char)temp;
					i++;
					flag = false;
				}
				break;
			}
		}
		}
	}
}

int changePointMenu(int& xyz, const Point& p)
{
	while (true)
	{
		system("cls");
		printf("   Координаты точки: ");
		printPointCoordinates(p);
		printf("\n   _____________________________________________________\n\n");
		switch (xyz)
		{
		case 0:
			printf(" > Изменить координату X\n   Изменить координату Y\n   Изменить координату Z\n\n   Вернуться назад\n");
			break;
		case 1:
			printf("   Изменить координату X\n > Изменить координату Y\n   Изменить координату Z\n\n   Вернуться назад\n");
			break;
		case 2:
			printf("   Изменить координату X\n   Изменить координату Y\n > Изменить координату Z\n\n   Вернуться назад\n");
			break;
		case 3:
			printf("   Изменить координату X\n   Изменить координату Y\n   Изменить координату Z\n\n > Вернуться назад\n");
			break;
		}
		printf("   _____________________________________________________\n\n   Вверх/вниз:\tНавигация по меню\n   Enter:\tВыбор\n");
		switch (getKey())
		{
		case 72:
			if (xyz > 0) xyz--;
			else xyz = 3;
			break;
		case 80:
			if (xyz < 3) xyz++;
			else xyz = 0;
			break;
		case 13:
			return xyz;
		}
	}
}

void changePoint(Point& p)
{
	int xyz = 0;
	while (true)
	{
		switch (changePointMenu(xyz, p))
		{
		case 0:
			p.SetX(setDouble(p.GetX()));
			break;
		case 1:
			p.SetY(setDouble(p.GetY()));
			break;
		case 2:
			p.SetZ(setDouble(p.GetZ()));
			break;
		case 3:
			return;
		}
	}
}

int changeSphereMenu(int& m, const Sphere& s)
{
	while (true)
	{
		system("cls");
		printf("   Cфера:\n");
		printSphereInfo(s);
		printf("   _____________________________________________________\n\n");
		switch (m)
		{
		case 0:
			printf(" > Изменить радиус сферы\n   Изменить координаты центра сферы\n   Вернуться в главное меню\n");
			break;
		case 1:
			printf("   Изменить радиус сферы\n > Изменить координаты центра сферы\n   Вернуться в главное меню\n");
			break;
		case 2:
			printf("   Изменить радиус сферы\n   Изменить координаты центра сферы\n > Вернуться в главное меню\n");
			break;
		}
		printf("   _____________________________________________________\n\n   Вверх/вниз:\tНавигация по меню\n   Enter:\tВыбор\n");
		switch (getKey())
		{
		case 72:
			if (m > 0) m--;
			else m = 2;
			break;
		case 80:
			if (m < 2) m++;
			else m = 0;
			break;
		case 13:
			return m;
		}
	}
}

void changeSphere(Sphere& s)
{
	int m = 0;
	while (true)
	{
		switch (changeSphereMenu(m, s))
		{
		case 0:
			s.SetRadius(setDouble(s.GetRadius()));
			break;
		case 1:
			Point temp = s.GetCenterOfSphere();
			changePoint(temp);
			s.SetCenterOfSphere(temp);
			break;
		case 2:
			return;
		}
	}
}

int menu(int& k, const Sphere& s1, const Sphere& s2, const Point& p)
{
	while (true)
	{
		system("cls");
		printf("   Cфера S1:\n");
		printSphereInfo(s1);
		printf("\n   Cфера S2:\n");
		printSphereInfo(s2);
		printf("\n   Точка P");
		printPointCoordinates(p);
		printf("\n   _____________________________________________________\n\n");
		switch (k)
		{
		case 0:
			printf(" > Изменить данные сферы S1\n   Изменить данные сферы S2\n   Изменить координаты точки P\n\n   Вычислить площадь сферы S1\n"
				"   Вычислить площадь сферы S2\n\n   Вычислить объём сферы S1\n   Вычислить объём сферы S2\n\n   Проверить, лежит ли точка P внутри сферы S1\n"
				"   Проверить, лежит ли точка P внутри сферы S2\n   Проверить наличие общих точек у сфер\n\n   Завершить работу программы\n");
			break;
		case 1:
			printf("   Изменить данные сферы S1\n > Изменить данные сферы S2\n   Изменить координаты точки P\n\n   Вычислить площадь сферы S1\n"
				"   Вычислить площадь сферы S2\n\n   Вычислить объём сферы S1\n   Вычислить объём сферы S2\n\n   Проверить, лежит ли точка P внутри сферы S1\n"
				"   Проверить, лежит ли точка P внутри сферы S2\n   Проверить наличие общих точек у сфер\n\n   Завершить работу программы\n");
			break;
		case 2:
			printf("   Изменить данные сферы S1\n   Изменить данные сферы S2\n > Изменить координаты точки P\n\n   Вычислить площадь сферы S1\n"
				"   Вычислить площадь сферы S2\n\n   Вычислить объём сферы S1\n   Вычислить объём сферы S2\n\n   Проверить, лежит ли точка P внутри сферы S1\n"
				"   Проверить, лежит ли точка P внутри сферы S2\n   Проверить наличие общих точек у сфер\n\n   Завершить работу программы\n");
			break;
		case 3:
			printf("   Изменить данные сферы S1\n   Изменить данные сферы S2\n   Изменить координаты точки P\n\n > Вычислить площадь сферы S1\n"
				"   Вычислить площадь сферы S2\n\n   Вычислить объём сферы S1\n   Вычислить объём сферы S2\n\n   Проверить, лежит ли точка P внутри сферы S1\n"
				"   Проверить, лежит ли точка P внутри сферы S2\n   Проверить наличие общих точек у сфер\n\n   Завершить работу программы\n");
			break;
		case 4:
			printf("   Изменить данные сферы S1\n   Изменить данные сферы S2\n   Изменить координаты точки P\n\n   Вычислить площадь сферы S1\n"
				" > Вычислить площадь сферы S2\n\n   Вычислить объём сферы S1\n   Вычислить объём сферы S2\n\n   Проверить, лежит ли точка P внутри сферы S1\n"
				"   Проверить, лежит ли точка P внутри сферы S2\n   Проверить наличие общих точек у сфер\n\n   Завершить работу программы\n");
			break;
		case 5:
			printf("   Изменить данные сферы S1\n   Изменить данные сферы S2\n   Изменить координаты точки P\n\n   Вычислить площадь сферы S1\n"
				"   Вычислить площадь сферы S2\n\n > Вычислить объём сферы S1\n   Вычислить объём сферы S2\n\n   Проверить, лежит ли точка P внутри сферы S1\n"
				"   Проверить, лежит ли точка P внутри сферы S2\n   Проверить наличие общих точек у сфер\n\n   Завершить работу программы\n");
			break;
		case 6:
			printf("   Изменить данные сферы S1\n   Изменить данные сферы S2\n   Изменить координаты точки P\n\n   Вычислить площадь сферы S1\n"
				"   Вычислить площадь сферы S2\n\n   Вычислить объём сферы S1\n > Вычислить объём сферы S2\n\n   Проверить, лежит ли точка P внутри сферы S1\n"
				"   Проверить, лежит ли точка P внутри сферы S2\n   Проверить наличие общих точек у сфер\n\n   Завершить работу программы\n");
			break;
		case 7:
			printf("   Изменить данные сферы S1\n   Изменить данные сферы S2\n   Изменить координаты точки P\n\n   Вычислить площадь сферы S1\n"
				"   Вычислить площадь сферы S2\n\n   Вычислить объём сферы S1\n   Вычислить объём сферы S2\n\n > Проверить, лежит ли точка P внутри сферы S1\n"
				"   Проверить, лежит ли точка P внутри сферы S2\n   Проверить наличие общих точек у сфер\n\n   Завершить работу программы\n");
			break;
		case 8:
			printf("   Изменить данные сферы S1\n   Изменить данные сферы S2\n   Изменить координаты точки P\n\n   Вычислить площадь сферы S1\n"
				"   Вычислить площадь сферы S2\n\n   Вычислить объём сферы S1\n   Вычислить объём сферы S2\n\n   Проверить, лежит ли точка P внутри сферы S1\n"
				" > Проверить, лежит ли точка P внутри сферы S2\n   Проверить наличие общих точек у сфер\n\n   Завершить работу программы\n");
			break;
		case 9:
			printf("   Изменить данные сферы S1\n   Изменить данные сферы S2\n   Изменить координаты точки P\n\n   Вычислить площадь сферы S1\n"
				"   Вычислить площадь сферы S2\n\n   Вычислить объём сферы S1\n   Вычислить объём сферы S2\n\n   Проверить, лежит ли точка P внутри сферы S1\n"
				"   Проверить, лежит ли точка P внутри сферы S2\n > Проверить наличие общих точек у сфер\n\n   Завершить работу программы\n");
			break;
		case 10:
			printf("   Изменить данные сферы S1\n   Изменить данные сферы S2\n   Изменить координаты точки P\n\n   Вычислить площадь сферы S1\n"
				"   Вычислить площадь сферы S2\n\n   Вычислить объём сферы S1\n   Вычислить объём сферы S2\n\n   Проверить, лежит ли точка P внутри сферы S1\n"
				"   Проверить, лежит ли точка P внутри сферы S2\n   Проверить наличие общих точек у сфер\n\n > Завершить работу программы\n");
			break;
		}
		printf("   _____________________________________________________\n\n   Вверх/вниз:\tНавигация по меню\n   Enter:\tВыбор\n");
		switch (getKey())
		{
		case 72:
			if (k > 0) k--;
			else k = 10;
			break;
		case 80:
			if (k < 10) k++;
			else k = 0;
			break;
		case 13:
			return k;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	printf("   Класс сферы с использованием вспомогательного класса точки.\n");
	printf("   Вычисление площади, объема сферы. Проверка нахождения точки внутри сферы. Проверка наличия общих точек сфер.\n\n\n");
	Sleep(5000);
	Sphere s1, s2;
	Point p;
	int k = 0; // k - выбор меню
	while (true)
	{
		switch (menu(k, s1, s2, p))
		{
		case 0:
			changeSphere(s1);
			break;
		case 1:
			changeSphere(s2);
			break;
		case 2:
			changePoint(p);
			break;
		case 3:
			message("   Вычисление площади сферы S1");
			message("   Площадь сферы S1: S = ", s1.Area());
			break;
		case 4:
			message("   Вычисление площади сферы S2");
			message("   Площадь сферы S2: S = ", s2.Area());
			break;
		case 5:
			message("   Вычисление объема сферы S1");
			message("   Объём сферы S1: V = ", s1.Volume());
			break;
		case 6:
			message("   Вычисление объема сферы S2");
			message("   Объём сферы S2: V = ", s2.Volume());
			break;
		case 7:
			message("   Проверка нахождения точки P внутри сферы S1");
			if (s1.PointInsideSphere(p))
				message("   Точка P находится внутри сферы S1");
			else
				message("   Точка P не находится внутри сферы S1");
			break;
		case 8:
			message("   Проверка нахождения точки P внутри сферы S2");
			if (s2.PointInsideSphere(p))
				message("   Точка P находится внутри сферы S2");
			else
				message("   Точка P не находится внутри сферы S2");
			break;
		case 9:
			message("   Проверка наличия общих точек у сфер S1 и S2");
			if (s1.IntersectionOfSpheres(s2))
				message("   Сферы S1 и S2 имеют общие точки");
			else
				message("   Сферы S1 и S2 не имеют общих точек");
			break;
		case 10:
			system("cls");
			return 0;
		}
	}
}