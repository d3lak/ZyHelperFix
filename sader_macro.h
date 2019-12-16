#pragma once

#ifndef SADER_MACRO_H_
#define SADER_MACRO_H_

#include "clipboard_reader.h"
#include "input_simulator.h"

class sader_macro
{
public:
	sader_macro();
	void GetCoe(clipboard_reader* clipboard_reader);
	void DoMacro(InputSimulator* input_simulator, clipboard_reader* clipboard_reader);
	void Stop(InputSimulator* input_simulator);
	~sader_macro();

	DWORD LowerBound;
	DWORD UpperBound;
	DWORD TimeShift;
	DWORD AdjustedTime;

	wchar_t MacroHotkey;
	wchar_t FistOfTheHeavensHotkey;
	wchar_t HeavensFuryHotkey;
	wchar_t JudgmentHotkey;
	wchar_t ForcemoveHotkey;

	bool JudgmentCheck;

};

#endif
