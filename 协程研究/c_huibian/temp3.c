int g(int x)
{
    int a = 0x33333333;
    return x + 3;
}

int f(int x, int y, int z, int k, int t)
{
    int a = 0x22222222;
    return g(x);
}

int main(void)
{
    int a = 0x44444444;
    int b = 0x55555555;
    int c = 0x66666666;
    int d = 0x77777777;
    int e = 0x88888888;

    return f(8, 7, 6, 5, 4) + 1;
}
