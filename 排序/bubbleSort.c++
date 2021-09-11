
void swap(int &a,int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

void BubbleSort(int A[],int n){
    for(int i=0;i<n-1;i++){
        bool flag = false;
        for(int j=n-1;j>i;j--){
            if(A[j-1]>A[j]){
                swap(A[j-1],A[j]);
                flag = true;
            }
        }
        if(flag == false){
            return ;
        }
    }
}

// 时间复杂度，O(n) O(n^2)

