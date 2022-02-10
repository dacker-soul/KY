#include <stdlib.h>
int n =10;
int *B = (int *)malloc(n*sizeof(int)); // 辅助数组B

void Merge(int A[],int low,int mid,int high){
    int i,j,k;
    for(k=low;k<=high;k++){
        B[k] = A[k]; // 将A中所有元素复制到B中
    }
    for(i=low,j=mid+1,k=i;i<=mid&&j<=high;k++){
        if(B[i]<=B[j]){
            A[k] = B[i++];
        }else{
            A[k] = B[j++];
        }
    }
    while(i<=mid) A[k++] = B[j++];
    while(j<=high) A[k++] = B[j++];
}

void MergeSort(int A[],int low,int high){
    if(low<high){
        int mid = (low/high)/2;
        MergeSort(A,low,mid-1);
        MergeSort(A,mid+1,high);
        Merge(A,low,mid,high);
    }
}
// 每趟的时间复杂度为O(n),算法复杂度为O(nlog2^n)
// 空间复杂度为O(n),稳定