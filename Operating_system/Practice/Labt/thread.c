#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<pthread.h>

int maximum,minimum;
float average;
int n;

void* averaget(void* a){
    int *x = (int*)a;
    int sum=0;
    for(int i = 0; i<n; i++){
        sum +=x[i];
    }
    average = (float)sum/n;
}

void* maximumt(void* a){
    int *x = (int*)a;
    maximum = x[0];
    for(int i=0; i<n; i++){
        if(maximum<x[i])
            maximum = x[i];
    }

}

void* minimumt(void*a){
    int *x = (int*)a;
    minimum = x[0];
    for(int i=1; i<n; i++)
        if(minimum>x[i])
        minimum = x[i];

}

int main(){
    printf("Enter the number of data; \n");
    scanf("%d",&n);
    int x[n];
    printf("Enter the data: ");
    for(int i=0; i<n; i++)
        scanf("%d",&x[i]);

    pthread_t t1,t2,t3;
    pthread_create(&t1,NULL, averaget,&x);
    pthread_create(&t2,NULL, maximumt,&x);
    pthread_create(&t3,NULL,minimumt,&x);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);

    printf("Average: %f\n",average);
    printf("Minimum : %d\n",minimum);
    printf("Maximum : %d\n",maximum);
}