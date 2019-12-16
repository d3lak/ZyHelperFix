#include <Windows.h>
#include <tchar.h>

#include "Debug.h"
#include "wiz_macro.h"



WizMacro::WizMacro()
{
	LowerBound = 32000;
	UpperBound = 32000;
	TimeShift = 0;
	AdjustedTime = 0;
	BlackholeCheck = false;
	MacroIsRunning = false;
	DooingArcane = false;
	SavedBlackHole = false;
	AutoMacro = false;
	OutsideSaved = false;
	Channeling = false;
	Shooting = false;
}

void WizMacro::GetCoe(clipboard_reader* clipboard_reader)
{
	DWORD OldDistance = (UpperBound - LowerBound + 16000) % 16000;
	DWORD Time = GetTickCount() % 16000;
	DWORD Distance = 0;
	int BoundDistance;

	if (LowerBound == 32000)
	{
		OldDistance = 100000;
	}
	if (UpperBound == 32000)
	{
		OldDistance = 100000;
	}


	if (clipboard_reader->ConventionLight())
	{
		BoundDistance = abs((int)UpperBound - (int)LowerBound);

		if (BoundDistance > 8000)
		{
			TimeShift = (UpperBound + LowerBound + 16000) / 2;
		}
		else
		{
			TimeShift = (UpperBound + LowerBound) / 2;
		}
		AdjustedTime = (GetTickCount() - TimeShift) % 16000;
		if (AdjustedTime > (4000 + 1000) && AdjustedTime < (1600 - 1000))
		{
			DEBUG_MSG("11" << std::endl);
			UpperBound = (Time + 32000) % 16000;
		}
		//0-4000 lightning


		Distance = (Time - LowerBound + 32000) % 16000;
		if (Distance < OldDistance)
		{
			DEBUG_MSG("12" << UpperBound << std::endl);
			UpperBound = (Time + 32000) % 16000;
		}

		Distance = (UpperBound + 4000 - Time + 32000) % 16000;
		if (Distance < OldDistance)
		{
			DEBUG_MSG("13" << LowerBound << std::endl);
			LowerBound = (Time - 4000 + 32000) % 16000;
		}
	}
	else if (clipboard_reader->ConventionArcane())
	{
		BoundDistance = abs((int)UpperBound - (int)LowerBound);

		if (BoundDistance > 8000)
		{
			TimeShift = (UpperBound + LowerBound + 16000) / 2;
		}
		else
		{
			TimeShift = (UpperBound + LowerBound) / 2;
		}
		AdjustedTime = (GetTickCount() - TimeShift) % 16000;
		if (AdjustedTime > (8000 + 1000) || AdjustedTime < (4000 - 1000))
		{
			DEBUG_MSG("21" << std::endl);
			UpperBound = (Time + 32000) % 16000;
		}
		//4000-8000 Arcane

		Distance = (Time - LowerBound - 4000 + 32000) % 16000;
		if (Distance < OldDistance)
		{
			DEBUG_MSG("22" << UpperBound << std::endl);
			UpperBound = (Time - 4000 + 32000) % 16000;
		}

		Distance = (UpperBound + 8000 - Time + 32000) % 16000;
		if (Distance < OldDistance)
		{
			DEBUG_MSG("23" << LowerBound << std::endl);
			LowerBound = (Time - 8000 + 32000) % 16000;
		}
	}
	else if (clipboard_reader->ConventionCold())
	{
		BoundDistance = abs((int)UpperBound - (int)LowerBound);

		if (BoundDistance > 8000)
		{
			TimeShift = (UpperBound + LowerBound + 16000) / 2;
		}
		else
		{
			TimeShift = (UpperBound + LowerBound) / 2;
		}
		AdjustedTime = (GetTickCount() - TimeShift) % 16000;
		if (AdjustedTime > (12000 + 1000) || AdjustedTime < (8000 - 1000))
		{
			DEBUG_MSG("31" << std::endl);
			UpperBound = (Time + 32000) % 16000;
		}
		//8000-12000 Cold

		Distance = (Time - LowerBound - 8000 + 32000) % 16000;
		if (Distance < OldDistance)
		{
			DEBUG_MSG("32" << UpperBound << std::endl);
			UpperBound = (Time - 8000 + 32000) % 16000;
		}

		Distance = (UpperBound + 12000 - Time + 32000) % 16000;
		if (Distance < OldDistance)
		{
			DEBUG_MSG("33" << LowerBound << std::endl);
			LowerBound = (Time - 12000 + 32000) % 16000;
		}
	}
	else if (clipboard_reader->ConventionFire())
	{
		BoundDistance = abs((int)UpperBound - (int)LowerBound);

		if (BoundDistance > 8000)
		{
			TimeShift = (UpperBound + LowerBound + 16000) / 2;
		}
		else
		{
			TimeShift = (UpperBound + LowerBound) / 2;
		}
		AdjustedTime = (GetTickCount() - TimeShift) % 16000;
		if (AdjustedTime < (12000 - 1000) && AdjustedTime > (0 + 1000))
		{
			DEBUG_MSG("41" << std::endl);
			UpperBound = (Time + 32000) % 16000;
		}
		//12000-16000 Cold

		Distance = (Time - LowerBound - 12000 + 32000) % 16000;
		if (Distance < OldDistance)
		{
			DEBUG_MSG("42" << UpperBound << std::endl);
			UpperBound = (Time - 12000 + 32000) % 16000;
		}

		Distance = (UpperBound - Time + 32000) % 16000;
		if (Distance < OldDistance)
		{
			DEBUG_MSG("43" << LowerBound << std::endl);
			LowerBound = (Time + 32000) % 16000;
		}
	}

	BoundDistance = abs((int)UpperBound - (int)LowerBound);

	if (BoundDistance > 8000)
	{
		TimeShift = (UpperBound + LowerBound + 16000) / 2;
	}
	else
	{
		TimeShift = (UpperBound + LowerBound) / 2;
	}

	AdjustedTime = (GetTickCount() - TimeShift) % 16000;
}

void WizMacro::DoMacro(InputSimulator* input_simulator, clipboard_reader* clipboard_reader)
{
	if (WaveOfForceHotkey == 'L' || WaveOfForceHotkey == 'R')
	{
		::MessageBox(NULL, _T("WARNING atm WaveOfForce cant be on the mouse"),
			_T("WARNING"), MB_OK | MB_ICONEXCLAMATION);
		return;
	}
	if (ElectrocuteHotkey == 'L' || ElectrocuteHotkey == 'R')
	{
		::MessageBox(NULL, _T("WARNING atm Electrocute cant be on the mouse"),
			_T("WARNING"), MB_OK | MB_ICONEXCLAMATION);
		return;
	}
	if (DisintegrateHotkey == 'L' || DisintegrateHotkey == 'R')
	{
		::MessageBox(NULL, _T("WARNING atm Disintegrate cant be on the mouse"),
			_T("WARNING"), MB_OK | MB_ICONEXCLAMATION);
		return;
	}
	if (WaveOfForceHotkey == MacroHotkey || ElectrocuteHotkey == MacroHotkey || MeteorHotkey == MacroHotkey || DisintegrateHotkey == MacroHotkey)
	{
		::MessageBox(NULL, _T("WARNING cant have macro key the same as a skill"),
			_T("WARNING"), MB_OK | MB_ICONEXCLAMATION);
		return;
	}

	if (BlackholeCheck && !ArchonCheck)
	{
		if(GetAsyncKeyState(input_simulator->CharToVK(MacroHotkey)) < 0)
		{
			if (!MacroIsRunning)//just started
			{
				input_simulator->SendKeyDown(ElectrocuteHotkey);
			}
		}
		else
		{
			if (!AutoMacro)

			{
				if (MacroIsRunning)//just stopped
				{
					input_simulator->SendKeyUp(ElectrocuteHotkey);
					MacroIsRunning = false;
					return;
				}
				else
				{
					return;
				}
			}
		}

		MacroIsRunning = true;

		DWORD Convention = AdjustedTime;
		DooingArcane = false;
		SavedBlackHole = false;
	
		if (Convention > 1150 && Convention < 1900)
		{
			DooingArcane = true;
			input_simulator->SendKey(WaveOfForceHotkey);

			if (clipboard_reader->BlackholeBuffActive())
			{
				SavedBlackHole = true;
				//got blackhole from ES so dont use it
			}
			else
			{
				if (BlackholeCheck)
				{
					input_simulator->SendKeyOrMouseWithoutMove(BlackholeHotkey);
				}
			}
			Sleep(200);
			input_simulator->SendKeyDown(ElectrocuteHotkey);
			Sleep(1400);
			input_simulator->SendKeyOrMouseWithoutMove(MeteorHotkey);
			Sleep(1200);

			if (!(GetAsyncKeyState(input_simulator->CharToVK(MacroHotkey)) < 0) && !AutoMacro)
			{
				Stop(input_simulator);
				return;
			}

			if (SavedBlackHole)
			{
				input_simulator->SendKeyUp(ElectrocuteHotkey);
			}

			input_simulator->SendKeyDown(DisintegrateHotkey);
			Sleep(400);
			input_simulator->SendKeyUp(DisintegrateHotkey);

			if (!(GetAsyncKeyState(input_simulator->CharToVK(MacroHotkey)) < 0) && !AutoMacro)
			{
				Stop(input_simulator);
				return;
			}

			if (SavedBlackHole && BlackholeCheck)
			{
				Sleep(300);
				input_simulator->SendKey(WaveOfForceHotkey);
				input_simulator->SendKeyOrMouseWithoutMove(BlackholeHotkey);
				input_simulator->SendKeyDown(ElectrocuteHotkey);
			}
			else
			{
				input_simulator->SendKeyDown(WaveOfForceHotkey);
				Sleep(100);
				input_simulator->SendKeyUp(WaveOfForceHotkey);
				Sleep(200);
			}
			Sleep(1500);
			if (!(GetAsyncKeyState(input_simulator->CharToVK(MacroHotkey)) < 0) && !AutoMacro)
			{
				Stop(input_simulator);
				return;
			}
			input_simulator->SendKeyOrMouseWithoutMove(MeteorHotkey);
			Sleep(1200);
			input_simulator->SendKeyDown(DisintegrateHotkey);
			Sleep(400);
			input_simulator->SendKeyUp(DisintegrateHotkey);
			input_simulator->SendKeyDown(WaveOfForceHotkey);
			Sleep(100);
			input_simulator->SendKeyUp(WaveOfForceHotkey);
		}
		if (Convention > 4000 && Convention < 7000 && !DooingArcane)
		{
			input_simulator->SendKeyOrMouseWithoutMove(MeteorHotkey);
			Sleep(1200);
			if (!(GetAsyncKeyState(input_simulator->CharToVK(MacroHotkey)) < 0) && !AutoMacro)
			{
				Stop(input_simulator);
				return;
			}

			input_simulator->SendKeyDown(DisintegrateHotkey);
			Sleep(400);
			input_simulator->SendKeyUp(DisintegrateHotkey);
			input_simulator->SendKeyDown(WaveOfForceHotkey);
			Sleep(100);
			input_simulator->SendKeyUp(WaveOfForceHotkey);
		}
		else if (Convention > 9300 && Convention < 10300)
		{
			input_simulator->SendKeyOrMouseWithoutMove(MeteorHotkey);
			Sleep(1200);
			if (!(GetAsyncKeyState(input_simulator->CharToVK(MacroHotkey)) < 0) && !AutoMacro)
			{
				Stop(input_simulator);
				return;
			}
			input_simulator->SendKeyDown(DisintegrateHotkey);
			Sleep(400);
			input_simulator->SendKeyUp(DisintegrateHotkey);
			input_simulator->SendKeyDown(WaveOfForceHotkey);
			Sleep(100);
			input_simulator->SendKeyUp(WaveOfForceHotkey);
		}
		else if (Convention > 12200 && Convention < 13200)
		{
			input_simulator->SendKeyOrMouseWithoutMove(MeteorHotkey);
			Sleep(1200);
			if (!(GetAsyncKeyState(input_simulator->CharToVK(MacroHotkey)) < 0) && !AutoMacro)
			{
				Stop(input_simulator);
				return;
			}
			input_simulator->SendKeyDown(DisintegrateHotkey);
			Sleep(400);
			input_simulator->SendKeyUp(DisintegrateHotkey);
			input_simulator->SendKeyDown(WaveOfForceHotkey);
			Sleep(100);
			input_simulator->SendKeyUp(WaveOfForceHotkey);
		}
		else if (Convention > 15100)
		{
			input_simulator->SendKeyOrMouseWithoutMove(MeteorHotkey);
			Sleep(1200);
			if (!(GetAsyncKeyState(input_simulator->CharToVK(MacroHotkey)) < 0) && !AutoMacro)
			{
				Stop(input_simulator);
				return;
			}
			input_simulator->SendKeyDown(DisintegrateHotkey);
			Sleep(400);
			input_simulator->SendKeyUp(DisintegrateHotkey);
			input_simulator->SendKeyUp(ElectrocuteHotkey);
		}
	}
	else if (ArchonCheck)
	{
		DWORD Convention = AdjustedTime;

		if (!Shooting)
		{
			if (GetAsyncKeyState(input_simulator->CharToVK(ChannelHotkey)) < 0)//pressed
			{
				if (!Channeling)
				{
					input_simulator->SendKeyDown(DisintegrateHotkey);
					Sleep(50);
					input_simulator->SendKeyOrMouseWithoutMove(WaveOfForceHotkey);
					Sleep(150);
					input_simulator->SendKey(input_simulator->CharToVK(ForcemoveHotkey));
					Channeling = true;
				}
				else
				{
					if (Convention % 1000 <= 400)
					{
						Sleep(100);
						input_simulator->SendKey(WaveOfForceHotkey);
						Sleep(50);
						input_simulator->SendKey(input_simulator->CharToVK(ForcemoveHotkey));
						Sleep(150);
						input_simulator->SendKeyUp(DisintegrateHotkey);
						input_simulator->SendKeyDown(DisintegrateHotkey);
				
					}
				}
			}

			else
			{
				if (Channeling)
				{
					input_simulator->SendKeyUp(DisintegrateHotkey);
					Channeling = false;
				}
			}
			
		}

		if (Convention > 9000 && Convention < 10000)//out of archon
		{
			if (!Shooting)
			{
				if (GetAsyncKeyState(input_simulator->CharToVK(ChannelHotkey)) < 0)//pressed
				{
					input_simulator->SendKeyUp(DisintegrateHotkey);
					input_simulator->SendKeyDown(DisintegrateHotkey);
					Sleep(100);
				}
			}
		}
		
		if (GetAsyncKeyState(input_simulator->CharToVK(MacroHotkey)) < 0)
		{
			if (Convention > 11500 && Convention < 12500)//occu
			{
				Shooting = true;
				if (Channeling)
				{
					input_simulator->SendKeyUp(DisintegrateHotkey);
					Channeling = false;
				}
				input_simulator->SendKeyOrMouseWithoutMove(WaveOfForceHotkey);
				if (BlackholeCheck)
				{
					input_simulator->SendKeyOrMouseWithoutMove(BlackholeHotkey);
				}
				input_simulator->SendKeyDown(ElectrocuteHotkey);
				Sleep(2300);
				input_simulator->SendKeyUp(ElectrocuteHotkey);
			
			
			
				input_simulator->SendKeyOrMouseWithoutMove(MeteorHotkey);
				Sleep(1250);
			
			
			
				input_simulator->SendKeyDown(DisintegrateHotkey);
				Sleep(50);
				input_simulator->SendKeyOrMouseWithoutMove(WaveOfForceHotkey);
				Sleep(150);
				input_simulator->SendKey(input_simulator->CharToVK(ForcemoveHotkey));
				input_simulator->SendKeyUp(DisintegrateHotkey);
				input_simulator->SendKeyDown(DisintegrateHotkey);
				Channeling = true;
				Shooting = false;
			}
			
			if (Convention > 2000 && Convention < 2800) // rota
			{
				Shooting = true;
				if (Channeling)
				{
					input_simulator->SendKeyUp(DisintegrateHotkey);
					Channeling = false;
				}
				input_simulator->SendKeyOrMouseWithoutMove(WaveOfForceHotkey);
				if (BlackholeCheck)
				{
					input_simulator->SendKeyOrMouseWithoutMove(BlackholeHotkey);
				}
				input_simulator->SendKeyDown(ElectrocuteHotkey);
				Sleep(2300);
				input_simulator->SendKeyUp(ElectrocuteHotkey);


				input_simulator->SendKeyOrMouseWithoutMove(MeteorHotkey);


				if (PositionSaved)
				{
					Sleep(50);
					input_simulator->MoveMouse(SavedPosition);
					Sleep(100);
					input_simulator->SendKey(input_simulator->CharToVK(ForcemoveHotkey));	
					PositionSaved = false;
				}
				else
				{
					Sleep(150);
				}

				Sleep(MacroDelay - 150);

				input_simulator->SendKeyDown(DisintegrateHotkey);	
				Sleep(1);
				input_simulator->SendKeyOrMouseWithoutMove(ArchonHotkey);
				input_simulator->SendKeyUp(DisintegrateHotkey);

				Sleep(200);
				Shooting = false;
			}
		}
	}
	else
	{
		if (GetAsyncKeyState(input_simulator->CharToVK(MacroHotkey)) < 0)
		{
			input_simulator->SendKeyOrMouseWithoutMove(MeteorHotkey);
			Sleep(1200);
			input_simulator->SendKeyDown(DisintegrateHotkey);
			Sleep(500);
			input_simulator->SendKeyDown(WaveOfForceHotkey);
			input_simulator->SendKeyUp(DisintegrateHotkey);
			Sleep(100);
			input_simulator->SendKeyUp(WaveOfForceHotkey);
			Sleep(800);
		}
	}
}

void WizMacro::Stop(InputSimulator* input_simulator)
{
	if (MacroIsRunning)
	{
		input_simulator->SendKeyUp(ElectrocuteHotkey);
		MacroIsRunning = false;	
	}
	return;
}

WizMacro::~WizMacro()
{
}
