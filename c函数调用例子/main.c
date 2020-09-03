/*
 * main.c
 * Copyright (C) 2020 kalipy <kalipy@debian>
 *
 * Distributed under terms of the MIT license.
 */
void swap(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

int main(void)
{
    int a, b;
    a = 16;
    b = 32;
    swap(&a, &b);

    return (a - b);
}
