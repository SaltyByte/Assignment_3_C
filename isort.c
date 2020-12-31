#include <stdio.h>

// define size of array
#define SIZE 50

void shift_element(int *arr, int i);
void print_arr(int *arr, int len);
void insertion_sort(int *arr, int len);

int main() {
    int array[SIZE] = {0};
    int num;
    // Get the input from the user
    for (int i = 0; i < SIZE; ++i) {
        scanf("%d", &num);
        *(array + i) = num;
    }
    insertion_sort(array, SIZE);
    // Print array
    print_arr(array,SIZE);
    return 0;
}

void print_arr(int *arr, int len) {
    // Loop over the array and print elements
    for (int i = 0; i < len - 1; ++i) {
        printf("%d,", *(arr + i));  
    }
    printf("%d\n",*(arr + len - 1));
}

void shift_element(int *arr, int i) {
    // Loop the array, shift from the start of the point i times
    for (int j = 0; j < i; ++j) {
        *(arr + i - j) = *(arr + i - j - 1);
    }
}

void insertion_sort(int *arr, int len) {
    // Loop the array, starts from place 1
    for (int i = 1; i < len; i++) {
        // If array[i] < array[i-1] then we need to sort
        if (*(arr + i) < *(arr + i - 1)) {
            int temp = *(arr + i);
            int j = i-1;
            // Search for the place to insert the unsorted number
            while (temp != *(arr) && *(arr + j) > temp && *(arr + j - 1) > temp){
                j--;
            }
            // After all shift array and insert the number
            shift_element(arr + j, i - j);
            *(arr + j) = temp;
        }
    }
}
