/****************************************************************
 * @file name    : CountingSort.c
 * @Description  : 计数排序
 * @Version      : 0.0
 * @Author       : M1kanN
 * @Date         : 2022-12-30 14:40:34
 * @LastEditTime : 2022-12-30 14:52:58
 ****************************************************************/
#include<stdio.h>
#include <stdlib.h>


// 交换函数, 交换数组中的两个元素
void Exchange(int array[], int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

// 计数排序函数
// A[]是需要我们排序的数组，长度为n
// B[]是我们存储A数组排序后的结果的数组，长度也为n
// k表示我们元素的最大的大小
void CountingSort(int A[], int B[], int C[], int n, int k) {
    for(int i = 0; i < n; i++) {
        C[A[i]] = C[A[i]] + 1;
    }
    for(int i = 1; i < k; i++) {
        C[i] = C[i] + C[i - 1];
    }
    // 此时C数组完成了
    for(int i = n - 1; i >=0; i--) {
        C[A[i]] = C[A[i]] - 1;
        B[C[A[i]]] = A[i];
    }
}

// 测试主函数
int main() {
    printf("==================== Start default Testing ====================\n");
    int array[] = {7, 2, 1, 3, 5, 0, 6, 8, 9, 4};
    printf("Original Array is: ");
    for(int i = 0; i < 10; i++) {
        printf("%d ",  array[i]);
    }
    int result[10] = {0}; // 用来存放排序结果
    int C[10] = {0};    // 辅助数组
    CountingSort(array, result, C, 10, 10);

    printf("\nAfter Couting Sort: ");
    for(int i = 0; i < 10; i++) {
        printf("%d ", result[i]);
    }
    printf("\n==================== Default Test End ====================");
}
