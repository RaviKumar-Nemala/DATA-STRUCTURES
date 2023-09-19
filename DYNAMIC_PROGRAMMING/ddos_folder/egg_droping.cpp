#include <bits/stdc++.h>
using namespace std;

// A utility function to get
// maximum of two integers
int max(int a, int b)
{
	return (a > b) ? a : b;
}

// Function to get minimum
// number of trials needed in worst
// case with n eggs and k floors
int eggDrop(int n, int k)
{
	// If there are no floors,
	// then no trials needed.
	// OR if there is one floor,
	// one trial needed.
	if (k == 1 || k == 0)
		return k;

	// We need k trials for one
	// egg and k floors
	if (n == 1)
		return k;

	int min = INT_MAX, x, res;

	// Consider all droppings from
	// 1st floor to kth floor and
	// return the minimum of these
	// values plus 1.
	for (x = 1; x <= k; x++) {
		res = max(
			eggDrop(n - 1, x - 1), //IF THE EGG BREAKS THEN THE NO OF EGGS ARE REMAINING IS TOTAL EGGS -1 SINCE IF WE DROP THE EGG FROM THAT FLOOR IT IS GOING TO BREAK THEN WE WIL DECREMENT THE FLOOR BY ONE//

			eggDrop(n, k - x));//IF THE EGG DOES NOT BREAK THEN NO OF EGGS REMAINS SAME AND NO OF ATTEMPT THAT WE NEED TO DO IN WORST CASE = TOTAL FLOORS - CURRENT FLOOR//
		if (res < min)//WE NEED A MINIMUM NO OF ATTEMPTS IN WORST CASE 
			min = res;
	}

	return min + 1;
}

// Driver program to test
// to print printDups
int main()
{
	int n = 3, k = 3;
	cout << "Minimum number of trials "
			"in worst case with "
		<< n << " eggs and " << k
		<< " floors is "
		<< eggDrop(n, k) << endl;
	return 0;
}

// This code is contributed
// by Akanksha Rai
