
// 大根堆：完全二叉树中，根>=左右孩子

// 建立大根堆
void BuildMaxHeap(int A[],int len){
    for(int i=len/2;i>0;i--){
        HeadAdjust(A,i,len);
    }
}

// 将以K为根的子树调整为大根堆
void HeadAdjust(int A[],int k,int len){
    // 函数HeadAdjust将元素k为根的子树进行调整
    A[0] = A[k];                    // A[0]暂存子树的根节点
    for(int i=2*k;i<=len;i*=2){     // 沿着key较大的子结点向下筛选
        if(i<len && A[i] < A[i+1]){  
            i++;                    // 取key较大的子节点的下标
        }
        if(A[0]>=A[i]){
            break;                  // 筛选借书
        }else{
            A[k]=A[i];              // 将A[i]调整到双亲结点上
            k=i;                    // 修改k值，以便继续向下筛选
        }
    }
    A[k] = A[0];                    //被筛选结点的值放入最终位置
}

void swap(int &a,int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

// 堆排序的完整逻辑
void HeapSort(int A[],int len){
    BuildMaxHeap(A,len);    // 初始建堆
    for(int i=len;i>1;i--){ // n-1趟的交换和建堆过程
        swap(A[i],A[1]);    // 堆顶元素和堆底元素交换
        HeadAdjust(A,1,i-1);// 把剩余的待排序元素整理成堆
    }
}