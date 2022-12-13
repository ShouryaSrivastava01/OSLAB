#include<stdio.h>



int main(){
    int n;
    printf("Enter the size of the string :" );
    scanf("%d", &n);

    int pages[n];
    for(int i=0;i<n;i++) 
        scanf("%d", &pages[i]);
    
    int size ;
    printf("Enter the size of the frame : ");
    scanf("%d", &size);

    int present[size];
    int distance[size];
    for(int i=0;i<size;i++)
        present[i] = -1;
    
    int pagefault = 0;
    int flag = 0;
    for(int i=0;i<size;i++){
        printf("\t\tFrame%d", i+1);
    }
    for(int i=0;i<n; i++){
        flag = 0;
        // check the page in available in the main memory
        for(int j=0;j<size;j++){
            if(pages[i]==present[j]){
                flag = 1;
                pagefault--;
            }
        }
        pagefault++;

        // frame is not filled and page is not present 
        if((pagefault<=size) && flag==0){
            present[i] = pages[i];
        }
        
        // frame is full
        else if( flag == 0){
            int max = -100;
            int index;

            // find the least recent used page
            for(int j=0;j<size;j++){
                distance[j]=0;
                for(int k=i-1; k>=0;k--){
                    distance[j]++;

                    if(present[j]==pages[k])
                        break;
                }

                if(distance[j]>max){
                    max = distance[j];
                    index = j;
                }
            }
            // replace the LRU page
            present[index] = pages[i];
            
        }

        printf("\n%d", pages[i]);
        for(int k = 0;k<size;k++){
            if(present[k]==-1)
                printf("\t\t-");
            else 
                printf("\t\t%d", present[k]);
        }


    }
    printf("\nTotal page fault %d", pagefault);

}