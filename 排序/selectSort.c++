

void swap(int &a,int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

void SelectSort(int A[],int n){
    for(int i=0;i<n-1;i++){
        int min = i;
        for(int j=i+1;i<n;j++){
            if(A[j]<A[min]) min = j;
        }
        if (min !=i){
            swap(A[i],A[min]);
        }
    }
}
// 不稳定
// O(n^2)