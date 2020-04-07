

#pragma once


////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////
#include <vector>



////////////////////////////////////////////////////////////
// class CConCmdEdCore
////////////////////////////////////////////////////////////
class CConCmdEdCore
{
	// const
	#define COMMAND_NAME_MAX_LENGTH				32
	#define COMMAND_DESCRIPTION_MAX_LENGTH		128
	#define MAX_COMMANDS						512

	#define MEMORY_MODEL_TINY					0
	#define MEMORY_MODEL_MEDIUM					1
	#define MEMORY_MODEL_LARGE					2

	#define MODEL_TINY_NAMESIZE					8
	#define MODEL_TINY_DESCRIPTIONSIZE			32
	#define MODEL_MEDIUN_NAMESIZE				16
	#define MODEL_MEDIUM_DESCRIPTIONSIZE		64
	#define MODEL_MEDIUN_NAMESIZE				32
	#define MODEL_MEDIUM_DESCRIPTIONSIZE		128


// typedefs
	typedef struct 
	{
		// support /irrelevant now
		WORD usIndex;

		// parameter index
		WORD usSubcomandIndex;

		// flash store MCU
		char strName[COMMAND_NAME_MAX_LENGTH];
		char strDescription[COMMAND_DESCRIPTION_MAX_LENGTH];

		// function name
		char strFunctionName[48];
	} st_ConsoleCmd;





public:
	// standard constructor
	CConCmdEdCore();
	~CConCmdEdCore();

	// *** methods ***
	BYTE AddCmd(st_ConsoleCmd stCmd);
	BYTE RemoveCmd();
	BYTE InsertCmd(st_ConsoleCmd stCmd, WORD usIndex);
	BYTE EraseCmd(WORD usIndex);
	BYTE Swap(WORD usIndexA, WORD usIndexB);

	BYTE EditCmd(st_ConsoleCmd stCmd, WORD usIndex);


private:

	// *** properties ***
	BYTE m_ucMemoryModelIndex = 0;
	WORD m_usCommandCount = 0;

	// container
	std::vector<st_ConsoleCmd> v_commands;

};



