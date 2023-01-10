/****************************************************************
 * @file name    : QuickSort.c
 * @Description  : 快速排序
 * @Version      : 0.0
 * @Author       : M1kanN
 * @Date         : 2022-12-30 13:05:35
 * @LastEditTime : 2023-01-07 14:20:14
 ****************************************************************/
#include<stdio.h>
#include <stdlib.h>


// 交换函数, 交换数组中的两个元素
void Exchange(int array[], int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

/*********************快速排序函数****************************/ 
// Paritition 函数
int Partition(int A[], int p, int r) {
    int x = A[r];
    int i = p - 1;  // i是用来分割两个区域的
    for(int j = p; j < r; j++) {
        if(A[j] <= x) {
            i = i + 1;
            Exchange(A, i, j);
        }
    }
    Exchange(A, i + 1, r);
    return (i + 1);
}

// 快速排序
void QuickSort(int A[], int p, int r) {
    if(p < r) {
        int q = Partition(A, p, r);
        QuickSort(A, p, q - 1);
        QuickSort(A, q + 1, r);
    }
}

/************************************************************/ 

// 测试主函数
int main() {
    printf("==================== Start default Testing ====================\n");
    int array[] = {3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48};
    printf("Original Array is: ");
    for(int i = 0; i < 15; i++) {
        printf("%d ",  array[i]);
    }

    QuickSort(array, 0, 14);

    printf("\nAfter Insert Sort: ");
    for(int i = 0; i < 15; i++) {
        printf("%d ", array[i]);
    }
    printf("\n==================== Default Test End ====================");

    printf("\nPlease Write the Array's Length you want to sort:  ");
    int N;
    scanf("%d", &N);
    int *MyArray = (int *)malloc(N * sizeof(int));
    printf("Please Write your Array's elements: \n");
    for(int i = 0; i < N; i++)
        scanf("%d", &MyArray[i]);
    printf("After Quick Sorting, your Array is :  \n");

    QuickSort(MyArray, 0, N - 1);

    for(int i = 0; i < N; i++)
        printf("%d ", MyArray[i]);
}



