/****************************************************************
 * @file name    : BubbleSort.c
 * @Description  : Test file of bubble sort.
 * @Version      : 0.1
 * @Author       : M1kanN
 * @Date         : 2022-12-10 19:59:33
 * @LastEditTime : 2022-12-10 20:27:57
 ****************************************************************/
#include <stdio.h>
#include <stdlib.h>

// 交换函数, 交换数组中的两个元素
void Exchange(int array[], int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

/*********************冒泡排序函数****************************/ 
void BubbleSort(int array[], int length) {
    for(int i = 0; i < length - 1; i++) {
        for(int j = 0; j < length - 1 - i; j++) {   // 小优化，从未排序区域最右边开始走
            if(array[j] > array[j + 1]) {
                Exchange(array, j, j+1);    // 交换数组中的两个数的函数
            }
        }
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

    BubbleSort(array, 15);

    printf("\nAfter Bubble Sort: ");
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
    BubbleSort(MyArray, N);
    for(int i = 0; i < N; i++)
        printf("%d ", MyArray[i]);
}
