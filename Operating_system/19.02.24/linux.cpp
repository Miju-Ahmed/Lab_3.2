#include<bits/stdc++.h>
using namespace std;
#define num_thread 5

int main(){
    int i, policy;
    pthread_t tid[num_thread];
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    if(pthread_attr_getschedpolicy(&attr, &policy)!=0)
            cout<<stderr<<" unable to get policy"<<endl;
    else{
        if(policy ==    SCHED_OTHER)
    }
}
