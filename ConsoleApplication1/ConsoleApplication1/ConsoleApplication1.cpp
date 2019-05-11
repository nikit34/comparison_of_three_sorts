#include <stdio.h>
#include <iostream>
//#include <xatomic.h>
#include <time.h>
using std::cout;
using std::cin;
using std::endl;
#include <intrin.h>
#pragma intrinsic(__rdtsc)






template<class T>
void bubble(T p_darr[], int& num) {
	cout << "\nbubble sort: \n";

	int i, j, b;
	//for (i = 0; i < num; i++) {
		//printf("%3d", p_darr[i]);
	//}
	//printf("\n");

	for (i = 0; i < num - 1; i++) {
		for (j = 0; j < num - i - 1; j++) {
			if (p_darr[j] > p_darr[j + 1]) {
				b = p_darr[j];
				p_darr[j] = p_darr[j + 1];
				p_darr[j + 1] = b;
			}
		}
	}

//	for (i = 0; i < num; i++)
	//	printf("%3d", p_darr[i]);
	//printf("\n");


}






// Функция "просеивания" через кучу - формирование кучи
void siftDown(int* numbers, int root, int bottom)
{
	int maxChild; // индекс максимального потомка
	int done = 0; // флаг того, что куча сформирована
	// Пока не дошли до последнего ряда
	while ((root * 2 <= bottom) && (!done))
	{
		if (root * 2 == bottom)    // если мы в последнем ряду, 
			maxChild = root * 2;    // запоминаем левый потомок
		  // иначе запоминаем больший потомок из двух
		else if (numbers[root * 2] > numbers[root * 2 + 1])
			maxChild = root * 2;
		else
			maxChild = root * 2 + 1;
		// если элемент вершины меньше максимального потомка
		if (numbers[root] < numbers[maxChild])
		{
			int temp = numbers[root]; // меняем их местами
			numbers[root] = numbers[maxChild];
			numbers[maxChild] = temp;
			root = maxChild;
		}
		else // иначе
			done = 1; // пирамида сформирована
	}
}
// Функция сортировки на куче
void heapSort(int* numbers, int array_size)
{
	// Формируем нижний ряд пирамиды
	for (int i = (array_size / 2) - 1; i >= 0; i--)
		siftDown(numbers, i, array_size - 1);
	// Просеиваем через пирамиду остальные элементы
	for (int i = array_size - 1; i >= 1; i--)
	{
		int temp = numbers[0];
		numbers[0] = numbers[i];
		numbers[i] = temp;
		siftDown(numbers, 0, i - 1);
	}
}
template<class T>
void pyramidal(T p_darr[], int& num) {
	cout << "\npyramidal sorting\n";
	// Вывод элементов массива до сортировки
//	for (int i = 0; i < num; i++)
	//	printf("%3d", p_darr[i]);
//	printf("\n");
	heapSort(p_darr, num); // вызов функции сортировки
	// Вывод элементов массива после сортировки
	//for (int i = 0; i < num; i++)
		//printf("%3d", p_darr[i]);
//	printf("\n");
}











#define MAXSTACK 2048		// максимальный размер стека

template<class T>
void qSortI(T a[], long size) {
	cout << "\nfast sorting\n";
	// Вывод элементов массива до сортировки
//	for (int i = 0; i < size; i++)
	//	printf("%3d", a[i]);
	//printf("\n");

	long i, j;   			// указатели, участвующие в разделении

	long lb, ub;  		// границы сортируемого в цикле фрагмента

	long lbstack[MAXSTACK], ubstack[MAXSTACK]; // стек запросов
						  // каждый запрос задается парой значений,
						  // а именно: левой(lbstack) и правой(ubstack) 
						  // границами промежутка

	long stackpos = 1;   	// текущая позиция стека
	long ppos;            // середина массива
	T pivot;              // опорный элемент
	T temp;

	lbstack[1] = 0;
	ubstack[1] = size - 1;

	do {

		// Взять границы lb и ub текущего массива из стека.

		lb = lbstack[stackpos];
		ub = ubstack[stackpos];
		stackpos--;

		do {
			// Шаг 1. Разделение по элементу pivot

			ppos = (lb + ub) >> 1;
			i = lb; j = ub; pivot = a[ppos];

			do {
				while (a[i] < pivot) i++;
				while (pivot < a[j]) j--;

				if (i <= j) {
					temp = a[i]; 
					a[i] = a[j]; 
					a[j] = temp;
					i++; j--;
				}
			} while (i <= j);

			// Сейчас указатель i указывает на начало правого подмассива,
			// j - на конец левого (см. иллюстрацию выше), lb ? j ? i ? ub.
			// Возможен случай, когда указатель i или j выходит за границу массива

			// Шаги 2, 3. Отправляем большую часть в стек  и двигаем lb,ub

			if (i < ppos) {     // правая часть больше

				if (i < ub) {     //  если в ней больше 1 элемента - нужно 
					stackpos++;       //  сортировать, запрос в стек
					lbstack[stackpos] = i;
					ubstack[stackpos] = ub;
				}
				ub = j;             //  следующая итерация разделения
									//  будет работать с левой частью

			}
			else {       	    // левая часть больше

				if (j > lb) {
					stackpos++;
					lbstack[stackpos] = lb;
					ubstack[stackpos] = j;
				}
				lb = i;
			}

		} while (lb < ub);        // пока в меньшей части более 1 элемента

	} while (stackpos != 0);    // пока есть запросы в стеке
	
	// Вывод элементов массива после сортировки
//	for (int i = 0; i < size; i++)
	//	printf("%3d", a[i]);
//	printf("\n");
}






int main() {
	unsigned __int64 a, b, delta, res;
	while (true) {
		int num; // размер массива
		cout << "Enter integer value: ";
		cin >> num; // получение от пользователя размера массива
		int* p_darr = new int[num];
		// Заполнение массива случайными числами
		for (int i = 0; i < num; i++)
			p_darr[i] = rand() % 100;



		
		a = 0; b = 0; delta = 0; res = 0;

		int* c_darr1 = new int[num];
		for (int i = 0; i < num; i++)
			c_darr1[i] = p_darr[i];
		a = __rdtsc();
		delta = __rdtsc() - a;
		a = __rdtsc();
		bubble(p_darr, num);
		b = __rdtsc();
		if (b - a >= delta)
		{
			res = b - a - delta;
		}
		else
		{
			res = b - a;
		}
		cout << "\nTacts of execution: " << res << endl;
		delete[] p_darr; // очистка памяти
		


		a = 0; b = 0; delta = 0; res=0;

		int* c_darr2 = new int[num];
		for (int i = 0; i < num; i++)
			c_darr2[i] = c_darr1[i];
		a = __rdtsc();
		delta = __rdtsc() - a;
		a = __rdtsc();
		pyramidal(c_darr1, num);
		b = __rdtsc();
		if (b - a >= delta)
		{
			res = b - a - delta;
		}
		else
		{
			res = b - a;
		}
		cout << "\nTacts of execution: " << res << endl;
		delete[] c_darr1; // очистка памяти
		
		
		
		a = 0; b = 0; delta = 0; res = 0;

		a = __rdtsc();
		delta = __rdtsc() - a;
		a = __rdtsc();
		qSortI(c_darr2, num);
		b = __rdtsc();
		if (b - a >= delta)
		{
			res = b - a - delta;
		}
		else
		{
			res = b - a;
		}
		cout << "\nTacts of execution: " << res << endl;
		delete[] c_darr2; // очистка памяти

	}
	return 0;
}