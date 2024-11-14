#include<bits/stdc++.h>
#include<sys/stat.h>
#include <fcntl.h>
#include <c++/12/bits/locale_facets_nonio.h>
using namespace std;

int main(){
    char *pipePath;
    int pipeFlag, fd;
    pipePath = "/home/miju_chowdhury/Documents/Class-3.2/Operating System/Code/28.02.24/miju";
    if(access(pipePath, F_OK)==0)
        cout<<pipePath<<" is already created"<<endl;
    else{
        pipeFlag = mkfifo(pipePath, 0666);//mkfifo(path,permission)
        if(pipeFlag<0){
            cout<<"Error is creating"<<endl;
            exit(-1);
        }else{
            cout<<"File has been created"<<endl;
        }
    }

    //int  fd = open("miju",O_WRONLY);
    //cout<<fd<<endl;
    return 0;
}
