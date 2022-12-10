/****************************************************************
 * @file name    : MergeSort.c
 * @Description  : Test File of Merge Sort.
 * @Version      : 0.1
 * @Author       : M1kanN
 * @Date         : 2022-12-10 20:28:07
 * @LastEditTime : 2022-12-10 20:35:59
 ****************************************************************/
#include <stdio.h>
#include <stdlib.h>

// 交换函数, 交换数组中的两个元素
void Exchange(int array[], int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}


/*********************归并排序函数****************************/ 
// 合并函数
void Merge(int array[], int p, int q, int r) {
    // 两个子数组的长度
    int n1 = q - p + 1;
    int n2 = r - q;
    // 设置两个子数组
    int L[n1 + 1];
    int R[n2 + 1];	
    L[n1] = INT_MAX, R[n2] = INT_MAX;   // 哨兵，末尾设为无穷大
    // 拷贝两个子数组
    for(int i = 0; i < n1; i++) {
        L[i] = array[p + i];
    }
    for(int i = 0; i < n2; i++) {
        R[i] = array[q + 1 + i];
    }

    int i = 0, j = 0;
    for(int k = p; k <= r; k++) {
        if(L[i] < R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
    } 
}

// 归并排序
void MergeSort(int A[], int p, int r) {
    if(p < r) {
        int q = (p + r) / 2;
        MergeSort(A, p, q);
        MergeSort(A, q+1, r);
        Merge(A, p, q, r);
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

    MergeSort(array, 0, 14);

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

    MergeSort(MyArray, 0, N - 1);

    for(int i = 0; i < N; i++)
        printf("%d ", MyArray[i]);
}

