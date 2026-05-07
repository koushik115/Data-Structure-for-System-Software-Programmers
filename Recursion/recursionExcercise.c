#include <stdio.h>

void reverseArray(int arr[], int i, int j) {
	int temp;

	if(i >= j)
		return;

	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;

	reverseArray(arr, ++i, --j);
}

int main(void) {
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	reverseArray(arr, 0, 9);
	for(int i = 0; i < 10; i++)
		printf(" %d", arr[i]);

	return 0;
}
