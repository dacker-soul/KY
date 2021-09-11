
void InsertSort(int A[],int n){
  int i,j,temp;
  for(i=1;i<n;i++){
    if(A[i]<A[i-1]){
      temp = A[i];
      for(j=i-1;j>0 && A[j]>temp;--j){
        A[j+1] = A[j];
      } 
      A[j+1] = temp;
    }
  }
}
// A[4,5,2,16,17,5,9,7]
void InsertSort2(int A[],int n){
  int i,j,temp;
  for(i=1;i<n;i++){
    temp = A[i];
    for(j=i;j>0 && A[j-1]>temp;j--){
      A[j] = A[j-1];
    } 
    A[j] = temp;
  }
}
// 最好时间复杂度：O(n)
// 最坏时间复杂度：O(n方)
// 平均时间复杂度：O(n方)【稳定】


// 折半插入排序
void InsertSort3(int A[], int n){
  int i,j,low,hight,mid;
  for(i=2;i<=n;i++){
    A[0] = A[i];
    int low=1;
    int high=i-1;
    while(low<=high){
      mid = (low+high)/2;
      if(A[mid]>A[0]){
        high = mid -1;
      }else{
        low = mid +1;
      }
    }
    for(j=i-1;j>=high+1;j--){
      A[j+1] = A[j];
    } 
    A[high+1] = A[0];
  }
}