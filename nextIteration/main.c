#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void swap(int* first, int* second) { int temp = *first; *first = *second; *second = temp; }

void reverse(int * values, size_t size) { for (size_t i = 0; i < size/2; i++) swap(&values[i], &values[size-i-1]); }

void next_iter(int* values, size_t size) {

    if (values[size-2] < values[size-1]) {
        int temp = values[size-1];
        values[size-1] = values[size-2];
        values[size-2] = temp;
        return;
    };

    for (size_t i = 3; i <= size; i++) {
        if (values[size-i] < values[size-i+1]) {
            size_t j = size-i+1;
            while( j < size ) {
                if (values[size-i] > values[j]) { break;}
                j++;
            }
            j--;
            swap(&values[size-i], &values[j]);
            reverse(&values[size-i+1], i-1);
            return;
        }
    }

    reverse(values, size);
}

void print_array(int* values, size_t size) {
    for (int i = 0; i < size; i++) printf("%d ", values[i]);
}
int main() {
    int values[] = { 1, 2, 3, 4 };

    for (int i = 0; i < 10; i++) {
        print_array(values, _countof(values));
        puts("");
        next_iter(values, _countof(values));
    }
}
