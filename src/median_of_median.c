#include <stdio.h>

// 素数
#define N 2999

int A[N];

// *p と *q の値を入れ替える関数
void swap(int *p, int *q){
  int tmp;
  tmp = *p;
  *p = *q;
  *q = tmp;
}

int sp(int A[], int n){
    int i, B[(n+4)/5];
    if(n<=5){return quick_selectA(A,n,n/2,0,0);}
    else {
        for(i = 0 ; i < n/5 ; i++){
            B[i] = quick_selectA(A+5*i, 5, 2, 0, 0);
        }
        if(n%5 != 0){B[i] = quick_selectA(A+5*i, n%5, (n%5)/2, 0, 0);}
        return sp(B, (n+4)/5);
    }
}

int quick_selectA(int A[], int n, int k, int p, int o){
    int i, j, pivot;
    if(p == 0){
        pivot = A[n/2];
        A[n/2] = A[0];
        A[0] = pivot;
    }else if(i == 1){
        for(i=0;i<n;i++){
            if(A[i] == o){
                pivot = A[i];
                A[i] = A[0];
                A[0] = pivot;
            }
        }
    }
    
    for(i = j = 1; i < n; i++){
        if(A[i] <= pivot){
            swap(A+i, A+j);
            j++;
        }
    }
    
    if(j == k+1) return pivot;
    else if(j < k+1) return quick_select(A+j, n-j, k-j);
    else return quick_select(A+1, j-1, k);
}

int quick_select(int A[], int n, int k){
    if(n <= 5){
        return quick_selectA(A,n,k,0,0);
    }else{
        int pivot = sp(A,n);
        return quick_selectA(A,n,k,1,pivot);
    }
}

int main(){
  int i;
  A[0] = 0;
  A[1] = 17; //原始元
  for(i=2;i<N;i++){
    A[i] = (long long int) A[i-1] * A[1] % N;
  }
  for(i=0;i<N;i++){
//    if(quick_select(A, N, i) != i) printf("ERROR %d %d\n", i, quick_select(A, N, i));
    printf("%d th element is %d\n", i, quick_select(A, N, i));
  }
}
