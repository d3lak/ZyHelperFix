#pragma once

#ifndef CLIPBOARD_READER_H_
#define CLIPBOARD_READER_H_

#include <Windows.h>
#include <string>
#include "Debug.h"

#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")


class clipboard_reader
{
public:
	clipboard_reader();

	int Read();
	
	bool IsReady();
	DWORD StartupTime;
	~clipboard_reader();

	//bool () { return ElementAt(, 4); };


	bool Active() { return ElementAt(1, 0); };
	bool ImBarb() {	return ElementAt(2, 0); };
	bool ImMonk() { return ElementAt(3, 0); };
	bool ImWizard() { return ElementAt(4, 0); };
	bool ImNecro() { return ElementAt(5, 0); };
	bool ImDh() { return ElementAt(6, 0); };


	bool ConventionLight() { return ElementAt(1, 1); };
	bool ConventionArcane() { return ElementAt(2, 1); };
	bool ConventionCold() { return ElementAt(3, 1); };
	bool ConventionFire() { return ElementAt(4, 1); };
	bool BlackholeBuffActive() { return ElementAt(5, 1); };
	bool CastArcaneBlast() { return ElementAt(6, 1); };

	bool InARift() { return ElementAt(1, 2); };
	bool DontCastLand() { return ElementAt(2, 2); };
	bool CastBlindingFlash() { return ElementAt(3, 2); };
	bool CastCommandSkeletons() { return ElementAt(4, 2); };
	bool ImSader() { return ElementAt(5, 2); };


	bool CastIp() { return ElementAt(1, 3); };
	bool CastSim() { return ElementAt(2, 3); };
	bool DontCastSim() { return ElementAt(3, 3); };
	bool CastFalter() { return ElementAt(4, 3); };
	bool CastBerserker() { return ElementAt(5, 3); };
	bool CastSprint() { return ElementAt(6, 3); };
	
	
	bool CastWc() { return ElementAt(1, 4); };
	bool CastMantraHealing() { return ElementAt(2, 4); };
	bool CastSweepingWind() { return ElementAt(3, 4); };
	bool CastBoh() { return ElementAt(4, 4); };
	bool CastMantraConviction() { return ElementAt(5, 4); };
	bool CastLotd() { return ElementAt(6, 4); };

	bool CastPotion() { return ElementAt(1, 5); };
	bool CastStormArmor() { return ElementAt(2, 5); };
	bool CastMagicWeapon() { return ElementAt(3, 5); };
	bool CastVengeance() { return ElementAt(4, 5); };
	bool CastRainOfVengeance() { return ElementAt(5, 5); };
	bool CastPreparation() { return ElementAt(6, 5); };

	bool NeedToMove() { return ElementAt(1, 6); };
	bool CastExplosiveBlast() { return ElementAt(2, 6); };
	bool CastBloodNova() { return ElementAt(3, 6); };
	bool CastFistOfHeavens() { return ElementAt(2, 6); };
	bool CastJudgment() { return ElementAt(3, 6); };
	bool CastAkarat() { return ElementAt(4, 6); };
	bool CastIronSkin() { return ElementAt(5, 6); };
	bool CastLaw() { return ElementAt(6, 6); };

	bool CastBattleRage() { return ElementAt(1, 7); };
	bool CastCOTA() { return ElementAt(2, 7); };
	bool CastEpiphany() { return ElementAt(3, 7); };
	bool CastBoneArmor() { return ElementAt(4, 7); };
	bool CastSkeleMages() { return ElementAt(5, 7); };
	bool ConventionHoly() { return ElementAt(5, 7); };
	bool ConventionPhysical() { return ElementAt(6, 7); };

	bool ElementAt(unsigned  i, unsigned j);
	std::string content;
	bool Running;

private:

};


#endif  // CLIPBOARD_READER_H_