#include<sys/resource.h>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int coreNo, priority;
    coreNo = sched_getcpu();
    priority = getpriority(PRIO_PROCESS, 0);
    printf("Logical Processor: %d, Priority: %d\n", coreNo, priority);

    nice(17);

    priority = getpriority(PRIO_PROCESS, 0);
    printf("Logical Processor: %d, Priority: %d\n", coreNo, priority);

    setpriority(PRIO_PROCESS, 0, 15);

    priority = getpriority(PRIO_PROCESS, 0);
    printf("Logical Processor: %d, Priority: %d\n", coreNo, priority);
    return 0;
}
