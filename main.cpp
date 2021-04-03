#include "MainHeader.h"
using namespace Sort;

int main()
{
	ofstream myfile("Measure.txt");
	int n = 0;
	int i = 0;
	bool inputOK = getNumberAndIndex(n, i);
	if (!inputOK)
		return 0;
	double* arrayToSort = new double[n];
	inputOK = getNumbersToSort(n, arrayToSort);
	if (!inputOK)
		return 0;

	ArrayToSort insertionToSort (n, i, arrayToSort);
	ArrayToSort SelectionToSort (n, i, arrayToSort);
	ArrayToSort QuintupletToSort (n, i, arrayToSort);

	insertionToSort.Insertion_SortPrintTimeMeasure(myfile);
	SelectionToSort.Selection_SelectPrintTimeMeasure(myfile);
	QuintupletToSort.Quintuplet_SortPrintTimeMeasure(myfile);

	myfile.close();
	delete[] arrayToSort;
	return 0;
}