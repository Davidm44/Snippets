#include "CommandProcessor.h"

vector<COMMAND> commands;

vector<string> Split(string str)
{
	vector<string> tokens;

	char* buffer;
	buffer = strtok((char*)str.c_str()," ");
	while(buffer != NULL)
	{
		tokens.push_back(buffer);
		buffer = strtok(NULL," ");
	}

	return tokens;
}

void AddCommand(char* name,CommandFunc function)
{
	COMMAND c;
	c.command = name;
	c.func = function;

	if(commands.size() == 0)
		commands.push_back(c);
	else
		for(int i=0;i<commands.size();i++)
		{
			if(strcmp(commands[i].command,name)==0)
			{
				cout <<"Command: " << name << " has already been defined" << endl;
				break;
			} else {
				commands.push_back(c);
				break;
			}
		}
}

void ProcessCommand(char* cmd)
{
	vector<string> arguments = Split(cmd);
	string c = arguments.at(0); //save command before we remove it from argument list
	arguments.erase(arguments.begin()); //remove first token so we only pass arguments of the command to the function

	for(int i=0;i<commands.size();i++)
	{
		if(strcmp(c.c_str(),commands[i].command)==0)
		{
			commands[i].func(arguments);
			return;
		}
	}
	cout <<"Command not recognized"<<endl;
}