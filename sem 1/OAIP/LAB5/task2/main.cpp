#include <iostream>
#include <Windows.h>
using namespace std;
int main(){
	HINSTANCE load;
	load = LoadLibrary(L"DynamicLib.dll");
	typedef void (*run)();
	run runTask;
	runTask = (run)GetProcAddress(load, "runTask");
	runTask();
}