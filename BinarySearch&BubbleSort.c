#include <stdio.h>

int main() {
    int n, num, i, j, temp;
    int low, high, mid;
    
    printf("Enter the number of elements you want to insert: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the values you want to insert in the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Bubble Sort
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Your sorted array is:\n");
    for (i = 0; i < n; i++) {
        printf(" %d ", arr[i]);
    }

    printf("\nEnter the element you want to search in the array: ");
    scanf("%d", &num);

	//Binary Search   
	
    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (arr[mid] == num) {
            printf("Value %d is present at index %d.\n", num, mid);
            break;
        } else if (num > arr[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (low > high) {
        printf("Value %d is not present in the array.\n", num);
    }

    return 0;
}
