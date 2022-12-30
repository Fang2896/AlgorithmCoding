/****************************************************************
 * @file name    : HeapSort.c
 * @Description  : 
 * @Version      : 0.0
 * @Author       : M1kanN
 * @Date         : 2022-12-30 13:07:43
 * @LastEditTime : 2022-12-30 14:26:07
 ****************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>


// 交换函数, 交换数组中的两个元素
void Exchange(int array[], int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}


/*********************堆的基本操作****************************/ 
// 得到左孩子 / 右孩子的index。（这里是从0开始）
int Left(int i) {
    return 2 * i + 1;
}
int Right(int i) {
    return 2 * i + 2;
}

// 得到父节点的index
int Parent(int i) {
    int parent = ceil(i / 2) - 1;   // 向上取整后减一
    return parent;
}

// 维护堆的性质的函数 -- Heapify
void Heapify(int A[], int i, int length) {  // length是数组的长度
    int l = Left(i);    // 左孩子
    int r = Right(i);   // 右孩子
    int largest;    
    // 比较三者的大小
    if(l < length && A[l] > A[i])
        largest = l;
    else largest = i;
    if(r < length && A[r] > A[largest])
        largest = r;
    if(largest != i) {
        Exchange(A, i, largest);
        Heapify(A, largest, length);    // 递归调用
    }
}

// 从底向上建堆的函数
void BuildMaxHeap(int A[], int length) {
    // 注意，第一个非叶子结点的index为，最后一个结点的index / 2，然后向上取整后减一！
    int firstNotLeafNode = ceil((length - 1) / 2) - 1;
    for(int i = firstNotLeafNode; i >= 0; i--) {
        Heapify(A, i, length);
    }
}

// 堆排序函数
void HeapSort(int A[], int length) {
    BuildMaxHeap(A, length);    // 建堆
    
    printf("\nAfter BuildMaxHeap : ");
    for(int i = 0; i < length; i++) {
        printf("%d ", A[i]);    // 把建堆后的数组打印出来
    }

    int HeapSize = length;  // 用来记录堆的大小, 随着排序的进行，堆逐渐变小
    for(int i = length - 1; i > 0; i--) {
        Exchange(A, 0, i);
        HeapSize--;
        Heapify(A, 0, HeapSize);
    }
}


/************************************************************/ 

// 测试主函数：
int main() {
    printf("==================== Start default Testing ====================\n");
    int array[] = {3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48}; // 可以自行修改里面的值，来测试堆排序算法和建堆算法。
    printf("Original Array is: ");
    for(int i = 0; i < 15; i++) {
        printf("%d ",  array[i]);
    }

    

    HeapSort(array, 15);    // 堆排序
    printf("\nAfter Heap Sort : ");
    for(int i = 0; i < 15; i++) {
        printf("%d ", array[i]);
    }

    printf("\n==================== Default Test End ====================");

}

