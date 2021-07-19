#include <stdio.h>
// 数组循环左移p个位置
// 例如  0,1,2,3,4,5,6 循环左移3个位置
// 结果  3,4,5,6,0,1,2

void Print(int str[], int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        printf("%d ", str[i]);
    }
    printf("\n");
}

void reverse(int a[], int left, int right, int p)
{
    int temp;
    for (int i = left, j = right; i < left + p && i < j; ++i, --j)
    {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}

void moveP(int a[], int arr_len, int p)
{
    reverse(a, 0, p - 1, p);
    reverse(a, p, arr_len - 1, arr_len - p);
    reverse(a, 0, arr_len - 1, arr_len);
}

int main()
{
    int a[] = {0, 1, 2, 3, 4, 5, 6};
    int arr_len = sizeof(a) / sizeof(a[0]);
    Print(a, arr_len);
    moveP(a, 7, 3);
    printf("------------over------------\n");
    Print(a, arr_len);
    return 0;
}