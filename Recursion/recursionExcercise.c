#include <stdio.h>
#include <limits.h>

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

int reverse_number(int num, int rev)
{
    // write your logic
    if(num == 0)
	    return rev;

    rev = rev * 10 + (num % 10);
    return reverse_number(num / 10, rev);
}

int find_remainder(int a, int b)
{
    // write your logic
    if(b == 0)
	    return INT_MIN;

    if(a < b)
	    return a;


    return find_remainder(a - b, b);
}

int find_quotient(int a, int b)
{
    // write your logic
    if(b == 0)
	    return INT_MIN;

    if(a < b)
	    return 0;

    return 1 + find_quotient(a - b, b);
}

int power(int a, int n)
{
    // write your logic
    if(n == 0)
	    return 1;

    if(n % 2 == 0)
	return power(a * a, n / 2);
    else
	return a * power(a * a, n / 2);
}

int russian_multiply(int a, int b)
{
    // write your logic
    if(a == 1)
	    return b;

    if(a % 2 == 0)
	    return russian_multiply(a / 2, b * 2);
    else
	    return b + russian_multiply(a / 2, b * 2);

}

int log2_rec(int n)
{
    // write your logic
    if(n < 2)
	    return 0;

    return 1 + log2_rec(n / 2);
}


int logb_rec(int n, int b)
{
    // write your logic
    if(n < b)
	    return 0;

    return 1 + logb_rec(n / b, b);
}

int binomial(int n, int k)
{
    // write your logic
    if(k == 0 || k == n)
	    return 1;

    return binomial(n - 1, k - 1) + binomial(n - 1, k);
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
	/*
    	printf("===== Test Case 1 =====\n");
    	print_in_words(123);   // One Two Three

    	printf("\n===== Test Case 2 =====\n");
   	print_in_words(405);   // Four Zero Five

    	printf("\n===== Test Case 3 =====\n");
    	print_in_words(7);     // Seven

    	printf("\n===== Test Case 4 =====\n");
    	print_in_words(1002);  // One Zero Zero Two
	printf("\n");
	*/
	/*
 	printf("%d\n", reverse_number(1234, 0));   // 4321
    	printf("%d\n", reverse_number(405, 0));    // 504
    	printf("%d\n", reverse_number(7, 0));      // 7
    	printf("%d\n", reverse_number(1000, 0));   // 1
	*/
	/*
	printf("%d\n", find_remainder(17, 5));  // 2
    	printf("%d\n", find_remainder(10, 3));  // 1
    	printf("%d\n", find_remainder(25, 5));  // 0
    	printf("%d\n", find_remainder(7, 8));   // 7
	*/
/*
 	printf("%d\n", find_quotient(17, 5));  // 3
    	printf("%d\n", find_quotient(10, 3));  // 3
    	printf("%d\n", find_quotient(25, 5));  // 5
   	printf("%d\n", find_quotient(7, 8));   // 0
*/
/*
 	printf("%d\n", power(2, 8));   // 256
    	printf("%d\n", power(2, 5));   // 32
    	printf("%d\n", power(3, 4));   // 81
    	printf("%d\n", power(5, 0));   // 1	
*/
/*
   	printf("%d\n", russian_multiply(13, 12)); // 156
    	printf("%d\n", russian_multiply(7, 5));   // 35
    	printf("%d\n", russian_multiply(10, 0));  // 0
    	printf("%d\n", russian_multiply(1, 9));   // 9
*/
/*
   	printf("%d\n", log2_rec(8));    // 3
    	printf("%d\n", log2_rec(10));   // 3

    	printf("%d\n", logb_rec(27, 3)); // 3
    	printf("%d\n", logb_rec(20, 2)); // 4
*/
	printf("%d\n", binomial(5, 2));  // 10
    	printf("%d\n", binomial(6, 3));  // 20
    	printf("%d\n", binomial(4, 0));  // 1
    	printf("%d\n", binomial(4, 4));  // 1
				     
	return 0;
}
