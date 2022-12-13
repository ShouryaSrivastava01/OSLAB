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

    int seek_op, dist;

    seek_op = 0;
    
    for(int i=0;i<n;i++){
        dist = abs(arr[i]-head);
        seek_op += dist;

        // new position of the head
        head = arr[i];
    }

    printf("Total no of seek operations : %d", seek_op);
}