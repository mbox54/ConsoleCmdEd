
////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////
#include "pch.h"
#include "ConCmdEdCore.h"


////////////////////////////////////////////////////////////
// class CConCmdEdCore
////////////////////////////////////////////////////////////
CConCmdEdCore::CConCmdEdCore()
{

}


CConCmdEdCore::~CConCmdEdCore()
{

}

BYTE CConCmdEdCore::AddCmd(st_ConsoleCmd stCmd)
{
	// check requirements
	if (v_commands.capacity() >= MAX_COMMANDS)
	{
		// [MAX_COMMANDS]

		return 1;
	}

	// proc
	v_commands.push_back(stCmd);

	// edit cmd count
	m_usCommandCount++;

	return 0;
}


BYTE CConCmdEdCore::RemoveCmd()
{
	// check requirements
	if (v_commands.capacity() < 1)
	{
		// [NO COMMANDS]

		return 1;
	}

	// proc
	v_commands.pop_back();

	// edit cmd count
	m_usCommandCount--;

	return 0;
}

BYTE CConCmdEdCore::InsertCmd(st_ConsoleCmd stCmd, WORD usIndex)
{
	// check requirements
	if (v_commands.capacity() >= MAX_COMMANDS)
	{
		// [MAX_COMMANDS]

		return 1;
	}

	if (usIndex > v_commands.capacity())
	{
		// [BAD INDEX]

		return 1;
	}

	// proc
	std::vector<st_ConsoleCmd>::iterator itCmdIndex;
	itCmdIndex = v_commands.begin() + usIndex;
	v_commands.insert(itCmdIndex, stCmd);

	// edit cmd count
	m_usCommandCount++;

	return 0;
}


BYTE CConCmdEdCore::EraseCmd(WORD usIndex)
{
	// check requirements
	if (v_commands.capacity() < 1)
	{
		// [NO COMMANDS]

		return 1;
	}

	if (usIndex >= v_commands.capacity())
	{
		// [BAD INDEX]

		return 1;
	}

	// proc
	std::vector<st_ConsoleCmd>::iterator itCmdIndex;
	itCmdIndex = v_commands.begin() + usIndex;
	v_commands.erase(itCmdIndex);

	// edit cmd count
	m_usCommandCount--;

	return 0;
}


BYTE CConCmdEdCore::Swap(WORD usIndexA, WORD usIndexB)
{
	// check requirements
	if ((usIndexA >= v_commands.capacity()) || (usIndexB >= v_commands.capacity()))
	{
		// [BAD INDEX]

		return 1;
	}

	// proc
	st_ConsoleCmd stCmdBuf;
	stCmdBuf = v_commands[usIndexA];
	v_commands[usIndexA] = v_commands[usIndexB];
	v_commands[usIndexB] = stCmdBuf;

	return 0;
}


BYTE CConCmdEdCore::EditCmd(st_ConsoleCmd stCmd, WORD usIndex)
{


	return 0;
}
