/****************************************************************
 * @file name    : InsertSort.c
 * @Description  : Test file of Insert Sort.
 * @Version      : 0.1
 * @Author       : M1kanN
 * @Date         : 2022-12-10 20:22:44
 * @LastEditTime : 2022-12-10 20:27:39
 ****************************************************************/
#include <stdio.h>
#include <stdlib.h>

// 交换函数, 交换数组中的两个元素
void Exchange(int array[], int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}


/*********************插入排序函数****************************/ 
void InsertSort(int array[], int length) {
    for(int j = 1; j < length; j++) {
        int i;
        int key = array[j];
        for(i = j - 1; i >= 0 && array[i] > key; i--) {
            array[i + 1] = array[i];
        }
        array[i + 1] = key;
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

    InsertSort(array, 15);

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
    printf("After Bubble Sorting, your Array is :  \n");

    InsertSort(MyArray, N);

    for(int i = 0; i < N; i++)
        printf("%d ", MyArray[i]);
}
