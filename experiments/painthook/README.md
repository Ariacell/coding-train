


build dll
```sh
g++ -shared .\dllmain.cpp -o Dll.dll
```

build injector
```
 g++ .\injector.cpp -o injector.exe
```

Then run the target process and grab the pid and run 
```sh
.\injector.exe 44020
```