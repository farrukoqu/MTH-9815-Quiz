#pragma once
#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <vector>
#include <iostream>
#include <forward_list>

using namespace std;

#include <vector>
#include <forward_list>

using namespace std;

class quickSort {
private:

	int pivot(vector<int>& v, int r, int l)
	{
		int pivot_value = v[r];
		int i = l - 1;

		for (int j = l; j < r; ++j)
		{
			if (v[j] <= pivot_value)
			{
				i++;
				int temp = v[j];
				v[j] = v[i];
				v[i] = temp;
			}
		}

		int temp = v[i + 1];
		v[i + 1] = v[r];
		v[r] = temp;
		return i + 1;
	}


	void QuickSort_helper(vector<int>& v, int l, int r)
	{
		if (l < r)
		{
			int p = pivot(v, l, r);
			QuickSort_helper(v, l, p - 1);
			QuickSort_helper(v, p + 1, r);
		}
		return;
	}

	void QuickSort(vector<int>& v)
	{
		int l = 0;
		int r = v.size() - 1;
		QuickSort_helper(v, l, r);
		return;
	}

public:

	void operator()(vector<int>& v)
	{
		QuickSort(v);
		return;
	}

};


#endif // !QUICKSORT_HPP

