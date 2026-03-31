#include <iostream>

int* magic_sequence(int n, int* array_size) {
    int size = 1;
    static int* ptr = (int*)malloc(size * sizeof(int));
    ptr[0] = 1;

    int curr = 0;

    while (true) {
        curr = (2 * ptr[size-1]) % n;
        ptr = (int*)realloc(ptr, (size + 1) * sizeof(*ptr));
        size += 1;
        if (curr == ptr[0]) break;
        ptr[size-1] = curr;
    }

    *array_size = size - 1;
    return ptr;
}

int bit_length(int n) {
    int len = 0;
    while (true) {
        if (n <= (1 << len)) return len;
        len++;
    }
}

bool can_divide(int dividend, int divisor) {
    int size;
    int* sequence = magic_sequence(divisor, &size);
    int total = 0;

    int length = bit_length(dividend);
    int dividend_copy = dividend;
    for (int i = 0; i <= length; i++) {
        if ((dividend_copy | 1) == dividend_copy) {
            total += sequence[i % size];
        }
        dividend_copy = dividend_copy >> 1;
    }

    return total % divisor == 0;
}

int main() {
    int dividend, divisor;
    printf("enter a number you want divided: ");
    scanf("%i", &dividend);
    printf("enter a number you want to divide it by: ");
    scanf("%i", &divisor);
    
    if (can_divide(dividend, divisor))
        printf("%i can be divided by %i yay", dividend, divisor);
    else
        printf("%i cant be divided by %i oops", dividend, divisor);
}