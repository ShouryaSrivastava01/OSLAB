#include<stdio.h>

typedef struct Process{
    int p_no;
    int priority;
    float burst_time;
    float tat;

} Process;


int main(){
    int n;
    printf("Enter the number of process : ");
    scanf("%d", &n);

    Process arr[n];
    printf("Enter the Burst Time and Priority respectively ");
    for(int i=0;i<n;i++){
        printf("Process %d : ", i+1);
        arr[i].p_no=i+1;
        scanf("%f", &arr[i].burst_time);
        scanf("%d", &arr[i].priority);
    }

    // sort the process according to arrival time 
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j].priority < arr[j + 1].priority){
                Process temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
    }
    printf("Process\tBurst Time\tPriority\n");
    for(int i=0;i<n;i++){
        printf("%d\t%f\t%f\n",arr[i].p_no,arr[i].burst_time,arr[i].priority);
    }

    float timer = 0;
    for(int i=0;i<n;i++){
        timer += arr[i].burst_time;
        arr[i].tat = timer;
    }

    printf("Process\tTurn Around time\tWaiting Time\n");
    for(int i=0;i<n;i++){
        printf("%d\t\t%.2f\t\t%.2f\n",arr[i].p_no,arr[i].tat, arr[i].tat-arr[i].burst_time);
    }
        
}