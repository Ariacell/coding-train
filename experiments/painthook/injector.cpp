#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

char DllToLoad[] = "C:\\Users\\Aria\\Documents\\DevWork\\c++\\coding-train\\experiments\\painthook\\Dll.dll";

int main(int argc , char* argv[]) {

  // Step 1: Find LoadLibraryA inside Kernel32.dll
  HMODULE kernal_handle = GetModuleHandle("Kernel32");
  FARPROC processAddress_LLA = GetProcAddress(kernal_handle, "LoadLibraryA");

  printf("the process address is: %i", atoi(argv[1]));

  // Step 2: Open the target process
  HANDLE processHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, (DWORD)atoi(argv[1]));

  // Step 3: Allocate memory inside target process
  LPVOID memAlloc  = VirtualAllocEx(processHandle, NULL, sizeof(DllToLoad),
                                    MEM_COMMIT|MEM_RESERVE, PAGE_EXECUTE_READWRITE);

  // Step 4: Copy our DLL path into target process memory
  WriteProcessMemory(processHandle, memAlloc, DllToLoad, sizeof(DllToLoad), NULL);

  // Step 5: Create a remote thread that calls LoadLibraryA with our DLL path
  HANDLE remoteThread = CreateRemoteThread(processHandle, NULL, 0,
                          (LPTHREAD_START_ROUTINE)processAddress_LLA,
                          memAlloc, 0, NULL);

  CloseHandle(processHandle);

  return 0;
}