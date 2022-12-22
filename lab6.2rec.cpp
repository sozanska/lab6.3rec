#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// Генерація значень елементів масиву
void CreateArray(int* a, const int size, const int Low, const int High, int i)
{
	// генерація випадковогозначення елементу
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1) // перевірка щоб не вийти за межі масиву
		// рекурсивний виклик функції
		CreateArray(a, size, Low, High, i + 1);
}

// Вивід елементів масиву
void PrintArray(int* a, const int size, int i)
{
	// форматований вивід елемента масиву
	cout << setw(4) << a[i];
	if (i < size - 1)                // перевірка щоб не вийти за межі масиву
		PrintArray(a, size, i + 1);  // рекурсивний виклик функції
	else
		cout << endl;
}

// Обчислення середнє значення максимального та мінімального значень
float AvgMaxMinElement(int* a, const int size, int i, int min, int max, float Avg)
{
	// перевірка чи елемент більше поточного максимуму
	if (a[i] > max)
		max = a[i]; // нове значення максимуму
	// перевірка чи елемент менше поточного мінімуму
	if (a[i] < min)
		min = a[i]; // нове значення мінімуму 
	Avg = (float)(max + min) / 2;
	if (i < size - 1)    // перевірка щоб не вийти за межі масиву				
		return AvgMaxMinElement(a, size, i + 1, min, max, Avg);
	else
		return Avg;        // повернення суми елементів
}

void SortArray(int* a, const int size, int i) // i - параметр зовнішнього циклу
{ // ітераційної версії
	int min = a[i];
	int imin = i;
	for (int j = i + 1; j < size; j++)
		if (min > a[j])
		{
			min = a[j];
			imin = j;
		}
	a[imin] = a[i];
	a[i] = min;
	if (i < size - 2)
		SortArray(a, size, i + 1);
}

int main()
{
	srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
	const int n = 26;            // розмір масиву
	int a[n];                    // масив

	int Low = -40;               // мінімальне значення генерації чисел
	int High = 20;               // максимальне значення генерації чисел   

	CreateArray(a, n, Low, High, 0);  // заповнення елементів масиву значеннями
	PrintArray(a, n, 0);              // вивід масиву
	cout << " The average value of the minimum and maximum value: " << AvgMaxMinElement(a, n, 0, a[0], a[0], 0.0) << endl;
	SortArray(a, n, 0);
	cout << " Ordered array: " << endl;
	PrintArray(a, n, 0);              // Вивід зміненого масиву
	return 0;
}