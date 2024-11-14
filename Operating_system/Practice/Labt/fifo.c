#include<stdio.h>

int fifo(int page[], int n, int frame){
    Queue q = createQueue(frame);
    int pf = 0;
    for(int i=0; i<n; i++){
        if(!isInQueue(q,page[i])){
            if(isFull(q))
                dequeue(q);
            enqueue(q,page[i]);
            pf++;
        }
    }
    return pf;
}

int main(){
    int page = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5}
    int n = sizeof(page)/sizeof(page[0]);
    int f = fifo(page,n,3);
    printf("%d\n",f);
}