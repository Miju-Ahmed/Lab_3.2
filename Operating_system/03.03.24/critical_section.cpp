
#include<bits/stdc++.h>
#include<stdlib.h>
#include<pthread.h>
using namespace std;
int x=0;
pthread_mutex_t key;
void* sum(void*){
    for(int i=0; i<200; i++){
        pthread_mutex_lock(&key);
        x = x+1;//Critical Section
        
        printf("After Summation i: %d x : %d\n",i,x);
        pthread_mutex_unlock(&key);
    }
    return 0;
}

void* sub(void*){
    for(int j=0; j<200; j++){
        pthread_mutex_lock(&key);
        x = x-1;//Critical Section
        
        printf("After Subtraction j: %d x : %d\n",j,x);
        pthread_mutex_unlock(&key);
    }
    return 0;
}

int main(){
    //Initialize mutex before using
    pthread_mutex_init(&key, NULL);
    pthread_t t1,t2;
    pthread_create(&t1, NULL, sum, NULL);
    pthread_create(&t2, NULL, sub, NULL);

   // cout<<t1<<" "<<t2<<endl;
    
    pthread_join(t1,NULL);
    pthread_join(t2, NULL);
    cout<<"Main Thread will terminate now"<<endl;
    exit(EXIT_SUCCESS);
}
