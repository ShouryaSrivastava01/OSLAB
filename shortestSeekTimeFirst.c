#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, head;
    printf("Enter the size of the input request array : ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the request : ");
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter the initial position of the head : ");
    scanf("%d", &head);

    int seek_op, dist, cnt, min, idx;

    seek_op = 0;
    cnt = 0; //  to count the number of requests completed 

    while(cnt++ != n){
        min = 10000000;
        for(int i=0;i<n;i++){
            dist = abs(arr[i]-head);

            if(min > dist){
                min = dist;
                idx = i;
            }
        }

        seek_op += min;
        head = arr[idx];

        // to mark the index as visited;
        arr[idx] = 10000000;
    }
    
    

    printf("Total no of seek operations : %d", seek_op);
}