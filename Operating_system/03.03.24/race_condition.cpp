#include<bits/stdc++.h>
#include<stdlib.h>
#include<pthread.h>
using namespace std;
int x;
void* sum(void*){
    for(int i=0; i<200; i++){
        x = x+1;
        printf("After Summation i: %d x : %d\n",i,x);
        //cout<<"After summation i : "<<i<< " x : "<<x<<endl;
    }
    return 0;
}

void* sub(void*){
    for(int j=0; j<200; j++){
        x = x-1;
        printf("After Subtraction j: %d x : %d\n",j,x);
        //cout<<"After subtraction j : "<<j<< " x : "<<x<<endl;
    }
    return 0;
}

int main(){
    pthread_t t1,t2;
    pthread_create(&t1, NULL, sum, NULL);
    pthread_create(&t2, NULL, sub, NULL);

   // cout<<t1<<" "<<t2<<endl;
    
    pthread_join(t1,NULL);
    pthread_join(t2, NULL);
    cout<<"Main Thread will terminate now"<<endl;
    exit(EXIT_SUCCESS);
}
