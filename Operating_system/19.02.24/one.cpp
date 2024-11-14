//Round Robin Alogrithm

#include<bits/stdc++.h>
using namespace std;
int main(){
    pid_t myPID, childPID;
	int x = 5;
	pid_t mypPID = getpid();
	childPID = fork();
	if(childPID == 0){//Child Process
        cout<<"=========Child Process ========"<<endl;
		mypPID = getpid();
        for(int i=0; i<20000; i++){
            cout<<"Child "<<mypPID<<" i : "<<i<<" x : "<<x<<endl;
            x = x+i;
            cout<<"Child "<<mypPID<<" i : "<<i<<" x : "<<x<<endl;
        }
	}else{//Parent Process
        cout<<"=========Parent Process============"<<endl;
		for(int i=0; i<20000; i++){
            cout<<"Child "<<mypPID<<" i : "<<i<<" x : "<<x<<endl;
            x = x+i;
            cout<<"Child "<<mypPID<<" i : "<<i<<" x : "<<x<<endl;
        }
	}
}

