int Partition(int A[],int low,int high){
    int pivot=A[low]; //第一个元素作为枢纽轴心
    while(low<high){
        while(low<high && A[high]>=pivot) --high;
        A[low] = A[high]; //比枢纽轴心小，移动到左边
        while(low<high && A[low] <= pivot) ++low;
        A[high] = A[low]; //比枢纽轴心大，移动到右边
    }
    A[low] = pivot; //枢纽轴心放到最终位置
    return low;     //返回枢纽轴心位置
}

// 快速排序
void QuickSort(int A[],int low,int high){
    if(low<high){
        int pivotpos = Partition(A,low,high);
        QuickSort(A,low,pivotpos-1);
        QuickSort(A,pivotpos+1,high);
    }
}

// 最好的时间复杂度 O(nlog2^n)
// 最坏的时间复杂度 O(n^2)

// 最好的空间复杂度 O(log2^n)
// 最坏的空间复杂度 O(n)

// 不稳定