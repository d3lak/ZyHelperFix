#include "sader_macro.h"



sader_macro::sader_macro()
{
}

void sader_macro::GetCoe(clipboard_reader* clipboard_reader)
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


	if (clipboard_reader->ConventionFire())
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
		//0-4000 fire


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
	else if (clipboard_reader->ConventionHoly())
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
		//4000-8000 holy

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
	else if (clipboard_reader->ConventionLight())
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
		//8000-12000 light

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
	else if (clipboard_reader->ConventionPhysical())
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
		if (AdjustedTime < (12000 - 1000) && AdjustedTime >(0 + 1000))
		{
			DEBUG_MSG("41" << std::endl);
			UpperBound = (Time + 32000) % 16000;
		}
		//12000-16000 physical

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


void sader_macro::DoMacro(InputSimulator* input_simulator, clipboard_reader* clipboard_reader) {
	DWORD Convention = AdjustedTime;

	if (GetAsyncKeyState(input_simulator->CharToVK(MacroHotkey)) < 0) {

		if (Convention > 3000 && Convention < 4000 && clipboard_reader->CastJudgment() && JudgmentCheck) {
			// proc bracer
			input_simulator->SendKeyOrMouse(JudgmentHotkey);
		}

		if (clipboard_reader->CastFistOfHeavens()) {

			input_simulator->SendKeyOrMouse(FistOfTheHeavensHotkey);
		}
		else {
			input_simulator->SendKeyOrMouse(HeavensFuryHotkey);
			Sleep(DWORD(4.0 * (1000 / 60)));
			input_simulator->SendKeyOrMouse(ForcemoveHotkey);
		}
		

	}
}

sader_macro::~sader_macro()
{
}
