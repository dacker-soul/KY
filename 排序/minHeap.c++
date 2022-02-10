void swap(int &a,int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

// 建立小根堆
void BuidMinHeap(int A[],int len){
    for(int i=len/2;i>0;i--){
        HeadAdjust(A,i,len);
    }
}

// 将以K为根的子树调整为小根堆
void HeadAdjust(int A[],int k,int len){
    A[0] = A[k];
    for (int i =2*k; i < len; i=i*2)
    {
        if (i<len && A[i]>A[i+1]){
            i++;
        }
        if (A[k] < A[i]){
            break;
        }else{
            A[k] = A[i];
            k=i;
        }
    }
    A[k] = A[0];
}

void MiniHeap(int A[], int len){
    BuidMinHeap(A,len);
    for(int i=len;i>0;i--){
        swap(A[1],A[i]);
        HeadAdjust(A,1,i-1);
    }
}