#include <iostream>
using namespace std;

void printPrevSmaller(int arr[], int n)
{
	cout << "-1 ";

	for (int i = 1; i < n; i++) {
		int j;
		for (j = i - 1; j >= 0; j--) {
			if (arr[j] < arr[i]) {
				cout << arr[j] << " ";
				break;
			}
		}

		if (j == -1)
			cout << "-1 ";
	}
}

int main()
{
	int arr[] = { 3, 1, 4, 5, 2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printPrevSmaller(arr, n);
	return 0;
}

