#include <stdlib.h>
#include <stdio.h>

typedef struct BigUnsigned {
    char *end;
    char digits[100];
} BigUnsigned;

BigUnsigned *NewBigUnsigned() {
    BigUnsigned *result = malloc(sizeof(char*) + sizeof(char) * 100);
    result->end = result->digits;
    return result;
}

void SetBigUnsigned(BigUnsigned *num, unsigned value) {
    num->end = num->digits;
    if (value == 0) {
        *(num->end) = value;
        num->end++;
    }
    while (value) {
        *(num->end) = value % 10;
        num->end++;
        value /= 10;
    }
}

void ShowBigUnsigned(BigUnsigned *num) {
    char *p = num->end - 1;
    while (p >= num->digits) {
        putchar('0' + *p);
        p--;
    }
    putchar('\n');
}

void AddBigUnsigned(BigUnsigned *a, BigUnsigned *b) {
    char *p = a->digits;
    char *q = b->digits;
    char carry = 0;

    while (q < b->end) {
        if (p >= a->end) {
            *p = 0;
        }

        char sum = *p + *q + carry;
        carry = sum / 10;
        *p = sum % 10;

        p++;
        q++;
    }

    while (carry) {
        if (p >= a->end) {
            *p = 0;
        }

        char sum = *p + carry;
        carry = sum / 10;
        *p = sum % 10;

        p++;
    }

    if (p > a->end) {
        a->end = p;
    }
}

void LeftShiftBitUnsigned(BigUnsigned *a, unsigned n) {
    a->end += n;
    char *p = a->end - 1;
    while (p - n >= a->digits) {
        *p = *(p - n);
        p--;
    }
    while (p >= a->digits) {
        *p = 0;
        p--;
    }
}

void RightShiftBitUnsigned(BigUnsigned *a, unsigned n) {
    char *p = a->digits;
    while (p + n < a->end) {
        *p = *(p + n);
        p++;
    }
    a->end = p;
}

void MultBigUnsigned(BigUnsigned *a, char n) {
    char *p = a->digits;
    char carry = 0;

    while (p < a->end) {
        char sum = *p * n + carry;
        carry = sum / 10;
        *p = sum % 10;

        p++;
    }

    while (carry) {
        char sum = *p + carry;
        carry = sum / 10;
        *p = sum % 10;

        p++;
    }

    if (p > a->end) {
        a->end = p;
    }

    while (a->end - 1 > a->digits && *(a->end - 1) == 0) {
        a->end--;
    }
}

BigUnsigned *CloneBigUnsigned(BigUnsigned *a) {
    BigUnsigned *result = NewBigUnsigned();
    char *p = result->digits;
    char *q = a->digits;
    while (q != a->end) {
        *p = *q;
        q++;
        p++;
    }
    result->end = p;
    return result;
}

void Mult(BigUnsigned *a, BigUnsigned *b) {
    BigUnsigned *a0 = CloneBigUnsigned(a);
    SetBigUnsigned(a, 0);

    char *p = b->digits;
    while (p < b->end) {
        BigUnsigned *a1 = CloneBigUnsigned(a0);
        MultBigUnsigned(a1, *p);
        AddBigUnsigned(a, a1);
        LeftShiftBitUnsigned(a0, 1);
        free(a1);
        p++;
    }
    free(a0);
}

int main() {
    int n;
    scanf("%d", &n);
    BigUnsigned *sum = NewBigUnsigned();
    SetBigUnsigned(sum, 0);
    BigUnsigned *cur = NewBigUnsigned();
    SetBigUnsigned(cur, 1);
    BigUnsigned *tmp = NewBigUnsigned();
    for (int i = 1; i <= n; ++i) {
        SetBigUnsigned(tmp, i);
        Mult(cur, tmp);
        AddBigUnsigned(sum, cur);
    }
    ShowBigUnsigned(sum);
    free(tmp);
    free(sum);
    free(cur);
    return 0;
}
