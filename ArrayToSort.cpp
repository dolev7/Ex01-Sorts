#include "ArrayToSort.h"

namespace Sort
{
    ArrayToSort::ArrayToSort(int n, int i, double* array)
	{
        this->_arrayToSort = new double[n];
		_size = n; 
        _index = i;
        for (int i = 0; i < _size; i++)
        {
            _arrayToSort[i] = array[i];
        }
	}
    void ArrayToSort::InsertionSort()
    {
        int j;
        double key;
        for (int i = 1; i < _size; i++)
        {
            key = _arrayToSort[i];
            j = i - 1;
            while (j >= 0 && _arrayToSort[j] > key)
            {
                _arrayToSort[j + 1] = _arrayToSort[j];
                j = j - 1;
            }
            _arrayToSort[j + 1] = key;
        }
    }
    void ArrayToSort::Insertion_SortPrintTimeMeasure(ofstream& myfile)
    {
        auto start = chrono::high_resolution_clock::now();
        ios_base::sync_with_stdio(false);
        this->InsertionSort();
        auto end = chrono::high_resolution_clock::now();
        cout << "Insertion sort i'th element: " << std::fixed << std::setprecision(4) << _arrayToSort[_index - 1] << endl;
        double time_taken = static_cast<double>(chrono::duration_cast<chrono::nanoseconds>(end - start).count());
        time_taken *= 1e-9;

        myfile << "Time taken by function <Insertion Sort> is : " << fixed
            << time_taken << setprecision(9);
        myfile << " sec" << endl;
    }
    void ArrayToSort::Selection_SelectPrintTimeMeasure(ofstream& myfile)
    {
        auto start = chrono::high_resolution_clock::now();
        ios_base::sync_with_stdio(false);
        double iNumber = this->Selection(0, _size - 1, _index);
        auto end = chrono::high_resolution_clock::now();
        cout << "Selection i'th element: " << std::fixed << std::setprecision(4) << iNumber << endl;
        double time_taken = static_cast<double>(chrono::duration_cast<chrono::nanoseconds>(end - start).count());
        time_taken *= 1e-9;

        myfile << "Time taken by function <Selection> is : " << fixed
            << time_taken << setprecision(9);
        myfile << " sec" << endl;
    }
    void ArrayToSort::Quintuplet_SortPrintTimeMeasure(ofstream& myfile)
    {
        auto start = chrono::high_resolution_clock::now();
        ios_base::sync_with_stdio(false);
        this->InsertionSort();
        auto end = chrono::high_resolution_clock::now();
        cout << "Quintuplet algorithm i'th element: " << std::fixed << std::setprecision(4) << _arrayToSort[_index - 1] << endl;
        double time_taken = static_cast<double>(chrono::duration_cast<chrono::nanoseconds>(end - start).count());
        time_taken *= 1e-9;

        myfile << "Time taken by function <Quintuplet> is : " << fixed
            << time_taken << setprecision(9);
        myfile << " sec" << endl;
    }
    double ArrayToSort::Selection(int left, int right, int i)
    {
        int pivot;
        int leftPart;

        pivot = Partition(left, right);
        leftPart = pivot - left + 1;
        if (i == leftPart)
            return _arrayToSort[pivot];
        if (i < leftPart)
            return Selection(left, pivot - 1, i);
        else
            return Selection(pivot + 1, right, i - leftPart);
    }
    int ArrayToSort::Partition(int left, int right)
    {
        double pivot = _arrayToSort[right];
        int i = (left - 1);
        for (int j = left; j < right; j++)
        {
            if (_arrayToSort[j] <= pivot)
            {
                i++;
                swap(_arrayToSort[i], _arrayToSort[j]);
            }
        }
        swap(_arrayToSort[i + 1], _arrayToSort[right]);
        return i + 1;
    }
    void swap(double& num1, double& num2)
    {
        double temp = num1;
        num1 = num2;
        num2 = temp;
    }
    
    
}