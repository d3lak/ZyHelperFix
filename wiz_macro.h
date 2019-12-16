#pragma once

#ifndef WIZ_MACRO_H_
#define WIZ_MACRO_H_

#include "clipboard_reader.h"
#include "input_simulator.h"

class WizMacro
{
public:
	WizMacro();
	void GetCoe(clipboard_reader* clipboard_reader);
	void DoMacro(InputSimulator* input_simulator, clipboard_reader* clipboard_reader);
	void Stop(InputSimulator* input_simulator);
	~WizMacro();

	DWORD LowerBound;
	DWORD UpperBound;
	DWORD TimeShift;
	DWORD AdjustedTime;
	DWORD MacroDelay;

	wchar_t WaveOfForceHotkey;
	wchar_t ElectrocuteHotkey;
	wchar_t MeteorHotkey;
	wchar_t DisintegrateHotkey;
	wchar_t BlackholeHotkey;
	wchar_t MacroHotkey;
	wchar_t ArchonHotkey;
	wchar_t ChannelHotkey;
	wchar_t ForcemoveHotkey;

	bool BlackholeCheck;
	bool ArchonCheck;
	bool MacroIsRunning;

	bool DooingArcane;
	bool SavedBlackHole;

	bool AutoMacro;
	bool PositionSaved;
	bool OutsideSaved;
	bool Channeling;
	bool Shooting;
	POINT SavedPosition;
	POINT Outside;
};

#endif  // WIZ_MACRO_H_