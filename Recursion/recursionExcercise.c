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

int is_strictly_ascending(int arr[], int n, int index)
{
    // write your logic
    if(index == n - 1)
	    return 1;
    else if(arr[index] >= arr[index + 1])
	    return 0;

    return is_strictly_ascending(arr, n, index + 1);
}

void print_in_words(int num)
{
    // write your logic
    char *numArr[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    if(num == 0)
	    return;

    print_in_words(num / 10);
    printf("%s ", numArr[num % 10]);

}

int main(void) {
	/*
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	reverseArray(arr, 0, 9);
	for(int i = 0; i < 10; i++)
		printf(" %d", arr[i]);
	*/
	/*
	int arr1[] = {1, 2, 3, 4};
    	int arr2[] = {1, 2, 2, 4};
    	int arr3[] = {5};
    	int arr4[] = {10, 20, 15, 30};

    	printf("%d\n", is_strictly_ascending(arr1, 4, 0)); // 1
    	printf("%d\n", is_strictly_ascending(arr2, 4, 0)); // 0
    	printf("%d\n", is_strictly_ascending(arr3, 1, 0)); // 1
    	printf("%d\n", is_strictly_ascending(arr4, 4, 0)); // 0
	*/

    	printf("===== Test Case 1 =====\n");
    	print_in_words(123);   // One Two Three

    	printf("\n===== Test Case 2 =====\n");
   	print_in_words(405);   // Four Zero Five

    	printf("\n===== Test Case 3 =====\n");
    	print_in_words(7);     // Seven

    	printf("\n===== Test Case 4 =====\n");
    	print_in_words(1002);  // One Zero Zero Two
	printf("\n");

	return 0;
}
