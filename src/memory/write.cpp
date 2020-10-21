#include <iostream>
#include <windows.h>



int main(){
    int nVal;
    std::cout << "Value to write: ";
    std::cin >> nVal;
    std::cout << std::endl;
    DWORD pointerAddress = 0x0061FF08;

    HWND hWnd = FindWindow(0, "samplegame");
    if (hWnd == 0){
        std::cerr << "Could not find window." << std::endl;
    } else {
        DWORD PID;
        GetWindowThreadProcessId(hWnd, &PID);
        HANDLE hProc = OpenProcess(PROCESS_VM_WRITE | PROCESS_VM_OPERATION, false, PID);


        if (!hProc){
            std::cerr << "Cannot open process" << std::endl;
        }  else {
            int stat = WriteProcessMemory(hProc, (LPVOID)pointerAddress, &nVal, (DWORD)sizeof(nVal), NULL);

            if (stat){
                std::clog << "Memory written to the process" << std::endl;
            } else{
                std::cerr << "Memory couldn't be written to to the process" << std::endl;
            }
            CloseHandle(hProc);

        }
    }
}