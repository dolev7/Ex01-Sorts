#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <chrono>
#include <fstream>
#include <iomanip>

#include "ArrayToSort.h"

static const int  ARR_MAX_SIZE = 10000;
static const int  NUM_MAX_SIZE = 1000;
using namespace std;
//using namespace Sort;
bool getNumberAndIndex(int& n, int& i);
bool getNumbersToSort(const int n, double arr[]);