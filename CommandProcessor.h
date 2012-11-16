#ifndef COMMANDPROC
#define COMMANDPROC

#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef void(*CommandFunc)(vector<string>);

struct COMMAND {
	char* command;
	CommandFunc func;
};

extern vector<COMMAND> commands;

void AddCommand(char*,CommandFunc);
void ProcessCommand(char*);

#endif