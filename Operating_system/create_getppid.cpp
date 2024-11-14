#include <windows.h>
#include <iostream>
#include "cciss_defs.h"

using namespace std;

DWORD getppid() {
    DWORD parent_pid = 0;
    HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, GetCurrentProcessId());
    if (hProcess!= NULL) {
        if (!GetProcessId(GetParentProcess(hProcess), &parent_pid)) {
            parent_pid = 0;
        }
        CloseHandle(hProcess);
    }
    return parent_pid;
}

int main() {
    DWORD parent_pid = getppid();
    cout << "Parent PID: " << parent_pid << endl;
    return 0;
}