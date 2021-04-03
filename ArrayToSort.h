#pragma once
#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

static const int  PIVOT = 0;

namespace Sort
{
	class ArrayToSort
	{
	private:
		int _size;
		int _index;
		double* _arrayToSort;
	public:
		ArrayToSort(int n, int i, double* array);
		ArrayToSort() { delete[]_arrayToSort;}

		void InsertionSort();

		void Insertion_SortPrintTimeMeasure(ofstream& myfile);
		void Selection_SelectPrintTimeMeasure(ofstream& myfile);
		void Quintuplet_SortPrintTimeMeasure(ofstream& myfile);

		double Selection(int left, int right, int i);
		int Partition(int left, int right);

		void PrintSortedArrayNumberInIndex();
	};
}