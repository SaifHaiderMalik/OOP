/*
Note: We need to add "Ws2_32.lib" to the linker settings instead
we have added "-lws2_32" to the "tasks.json" compiler arguments.
*/
#pragma comment(lib, "-lws2_32")

//STD Console Header Files
#include <sdkddkver.h>
#include <conio.h>
#include <stdio.h>

//SOCKET Header Files
#include <WinSock2.h>
#include <Windows.h>
#include <iostream>

/*
We should specify the version of WinSock we wish to use
#define SCK_VERSION1 0x0101    OR    #define SCK_VERSION2 0x0202
Here we have defined WinSock Version 2
*/
#define SCK_VERSION2 0x0202