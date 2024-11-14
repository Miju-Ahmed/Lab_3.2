#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<signal.h>

#define SIGM SIGQUIT

sigset_t s;

void* reciver(void* arg){
    printf("Signal Reciver\n");
    int sig;
    sigwait(&s,&sig);
    printf("Recived Signal: %d\n",sig);

}
void* sender(void *arg){
    sleep(2);
    printf("Sending signal %d\n",SIGM);
    pthread_kill(*(pthread_t*)arg, SIGM);
}

int main(){
    pthread_t t1,t2;
    sigemptyset(&s);
    sigaddset(&s, SIGM);
    pthread_sigmask(SIG_BLOCK, &s,NULL);
    pthread_create(&t1,NULL,reciver,NULL);
    pthread_create(&t2,NULL,sender,&t1);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

}