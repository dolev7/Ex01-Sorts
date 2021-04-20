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
        double iNumber = this->Quintuplet();
        auto end = chrono::high_resolution_clock::now();
        cout << "Quintuplet algorithm i'th element: " << std::fixed << std::setprecision(4) << iNumber << endl;
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
    double ArrayToSort::Quintuplet()
    {
        double numInIndex = QuintupletRec(_arrayToSort, _size, _index-1);
        return numInIndex;
    }

    double ArrayToSort::QuintupletRec(double* array, int n, int i)
    {
        if (n <= 5)
        {
            bubbleSort(array, n);
            return array[i];
        }
        double* b_array = new double[n/5];
        for (int j = 0, k=0; k < n/5; j+=5, k++)
        {
            bubbleSort(array + j, 5);
            b_array[k] = array[j+2];
        }
        double pivotNum = QuintupletRec(b_array, n/5, n / 10);
        int index = findIndexInArray(array, pivotNum, _size);

        swap(array[index], array[_size-1]); // place the pivot in the last place, as partition expect to get it

        int k = Partition(0, _size-1); //maybe need to adjust partition to get an array
        
        if (i < k)
            return QuintupletRec(array, k-1, i);
        if (i > k)
            return QuintupletRec(array, n - k, i - k);
        else
            return array[k];
    }
    int ArrayToSort::findIndexInArray(double arr[], double pivotNum, int size)
    {
        for (int i = 0; i < size - 1; i++)
            if (arr[i] == pivotNum)
                return i;
    }

    void swap(double& num1, double& num2)
    {
        double temp = num1;
        num1 = num2;
        num2 = temp;
    }

    void ArrayToSort::bubbleSort(double arr[], int n)
    {
        int i, j;
        for (i = 0; i < n - 1; i++)

            for (j = 0; j < n - i - 1; j++)
                if (arr[j] > arr[j + 1])
                    swap(arr[j], arr[j + 1]);
    }
    
    
}