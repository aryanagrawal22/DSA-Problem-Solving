// O(n^2) Solution
// Soultion is Merge sort with O(nlogn) and O(n)

#include <stdio.h>
#include <stdlib.h>

long long int inversionCount(long long arr[], long long N)
{
    int inversion = 0;
    for(int i = 0; i<N; i++){
        for(int j = i+1; j<N; j++){
            if(arr[i]>arr[j]){
                inversion++;
            }
        }
    }
    return inversion;
}



// { Driver Code Starts.

int main() {
    
    long long T;
    scanf("%ld", &T);
    
    while(T--){
        long long N;
        scanf("%ld", &N);
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            scanf("%ld", &A[i]);
        }
        
        printf("%ld\n", inversionCount(A,N) );
    }
    
    return 0;
}