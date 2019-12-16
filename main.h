#pragma once

#ifndef MAIN_H_
#define MAIN_H_

#define _CRT_SECURE_NO_WARNINGS
#include <afxwin.h>

#include "resource.h"
#include "wiz_macro.h"
#include "sader_macro.h"
#include "clipboard_reader.h"
#include "input_simulator.h"


class CDiabloCalcFancy : public CWinApp {
public:
	BOOL InitInstance();
};

class CDiabloCalcFancyDlg : public CDialog {
public:
	enum { IDD = IDD_DIALOG1 };
	CButton m_ctlACTIVE;
	CButton m_ctlACTIVERUNNING;
	CButton m_ctlMACROACTIVE;
	CButton m_ctlPOSITIONSAVED;

	CButton	m_ctlIPCHECK;
	CButton m_ctlWCCHECK;
	CButton m_ctlFALTERCHECK;
	CButton m_ctlBERSERKERCHECK;
	CButton m_ctlSPRINTCHECK;
	CButton m_ctlEPIPHANYCHECK;
	CButton m_ctlMANTRAHEALINGCHECK;
	CButton m_ctlSWEEPINGWINDCHECK;
	CButton m_ctlBOHCHECK;
	CButton m_ctlMANTRACONVICTIONCHECK;
	CButton m_ctlLANDOFTHEDEADCHECK;
	CButton m_ctlBONEARMORCHECK;
	CButton m_ctlPOTIONCHECK;
	CButton m_ctlMACROCHECK;
	CButton m_ctlBLACKHOLECHECK;
	CButton m_ctlSTORMARMORCHECK;
	CButton m_ctlMAGICWEAPONCHECK;
	CButton m_ctlVENGEANCECHECK;
	CButton m_ctlRAINOFVENGEANCECHECK;
	CButton m_ctlPREPARATIONCHECK;
	CButton m_ctlSKELEMAGECHECK;
	CButton m_ctlDEVOURCHECK;
	CButton m_ctlSIMCHECK;
	CButton m_ctlSECONDSIM;
	CButton m_ctlHEXING;
	CButton m_ctlARCHONCHECK;
	CButton m_ctlARCANEBLASTCHECK;
	CButton m_ctlEXPLOSIVEBLASTCHECK;
	CButton m_ctlBLOODNOVACHECK;
	CButton m_ctlBLINDINGFLASHCHECK;
	CButton m_ctlCOMMANDSKELETONSCHECK;
	CButton m_ctlAKARATCHECK;
	CButton m_ctlIRONSKINCHECK;
	CButton m_ctlLAWCHECK;
	CButton m_ctlBATTLERAGECHECK;
	CButton m_ctlCOTACHECK;
	CButton m_ctlFISTOHCHECK;
	CButton m_ctlHEAVENSFURYCHECK;
	CButton m_ctlJUDGMENTCHECK;
	CButton m_ctlFOREGROUND;

	CEdit m_ctlIPHOTKEY;
	CEdit m_ctlWCHOTKEY;
	CEdit m_ctlFALTERHOTKEY;
	CEdit m_ctlBERSERKERHOTKEY;
	CEdit m_ctlSPRINTHOTKEY;
	CEdit m_ctlEPIPHANYHOTKEY;
	CEdit m_ctlMANTRAHEALINGHOTKEY;
	CEdit m_ctlSWEEPINGWINDHOTKEY;
	CEdit m_ctlBOHHOTKEY;
	CEdit m_ctlMANTRACONVICTIONHOTKEY;
	CEdit m_ctlLANDOFTHEDEADHOTKEY;
	CEdit m_ctlBONEARMORHOTKEY;
	CEdit m_ctlPOTIONHOTKEY;
	CEdit m_ctlWAVEOFFORCEHOTKEY;
	CEdit m_ctlELECTROCUTEHOTKEY;
	CEdit m_ctlMETEORHOTKEY;
	CEdit m_ctlDISINTEGRATEHOTKEY;
	CEdit m_ctlBLACKHOLEHOTKEY;
	CEdit m_ctlSTORMARMORHOTKEY;
	CEdit m_ctlMAGICWEAPONHOTKEY;
	CEdit m_ctlMACROHOTKEY;
	CEdit m_ctlTIMINGKEY;
	CEdit m_ctlTOGGLEKEY;
	CEdit m_ctlVENGEANCEHOTKEY;
	CEdit m_ctlRAINOFVENGEANCEHOTKEY;
	CEdit m_ctlPREPARATIONHOTKEY;
	CEdit m_ctlSKELEMAGEHOTKEY;
	CEdit m_ctlDEVOURHOTKEY;
	CEdit m_ctlSIMHOTKEY;
	CEdit m_ctlARCHONHOTKEY;
	CEdit m_ctlARCANEBLASTHOTKEY;
	CEdit m_ctlEXPLOSIVEBLASTHOTKEY;
	CEdit m_ctlBLOODNOVAHOTKEY;
	CEdit m_ctlFORCESTANDSTILLHOTKEY;
	CEdit m_ctlPOSITIONHOTKEY;
	CEdit m_ctlBLINDINGFLASHHOTKEY;
	CEdit m_ctlCHANNELHOTKEY;
	CEdit m_ctlFORCEMOVEHOTKEY;
	CEdit m_ctlCOMMANDSKELETONSHOTKEY;
	CEdit m_ctlAKARATHOTKEY;
	CEdit m_ctlIRONSKINHOTKEY;
	CEdit m_ctlLAWHOTKEY;
	CEdit m_ctlBATTLERAGEHOTKEY;
	CEdit m_ctlCOTAHOTKEY;
	CEdit m_ctlFISTOHHOTKEY;
	CEdit m_ctlHEAVENSFURYHOTKEY;
	CEdit m_ctlJUDGMENTHOTKEY;
	CEdit m_ctlMACRODELAY;

	CEdit m_ctlUPPERBOUND;
	CEdit m_ctlLOWERBOUND;
	CEdit m_ctlTIME;
	CEdit m_ctlCOE;


	CDiabloCalcFancyDlg();
	static DWORD WINAPI StaticStartBytestreamReader(void* Param)
	{
		CDiabloCalcFancyDlg* This = (CDiabloCalcFancyDlg*)Param;
		return This->StartBytestreamReaderThread();
	}
	static DWORD WINAPI StaticPrint(void* Param)
	{
		CDiabloCalcFancyDlg* This = (CDiabloCalcFancyDlg*)Param;
		return This->PrintThread();
	}
	static DWORD WINAPI StaticDoLogic(void* Param)
	{
		CDiabloCalcFancyDlg* This = (CDiabloCalcFancyDlg*)Param;
		return This->DoLogicThread();
	}
	static DWORD WINAPI StaticCoeReader(void* Param)
	{
		CDiabloCalcFancyDlg* This = (CDiabloCalcFancyDlg*)Param;
		return This->CoeReaderThread();
	}
	static DWORD WINAPI StaticWizMacro(void* Param)
	{
		CDiabloCalcFancyDlg* This = (CDiabloCalcFancyDlg*)Param;
		return This->WizMacroThread();
	}
	static DWORD WINAPI StaticHexingMacro(void* Param)
	{
		CDiabloCalcFancyDlg* This = (CDiabloCalcFancyDlg*)Param;
		return This->HexingMacroThread();
	}
	DWORD StartBytestreamReaderThread();
	DWORD PrintThread();
	DWORD DoLogicThread();
	DWORD CoeReaderThread();
	DWORD WizMacroThread();
	DWORD HexingMacroThread();
	~CDiabloCalcFancyDlg();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	clipboard_reader clipboard_reader;
	InputSimulator input_simulator;
	WizMacro wiz_macro;
	sader_macro sader_macro;

	HANDLE hThread[6];
	DWORD dwThreadID[6];

	const std::wstring InitChecks = _T("1110111111111101011111100110111111111111");
	const std::wstring InitHotkeys = _T("24311R44211Rq1243LLRn98R4414LR11201h1b2u41233123");

	enum class SpecialHotkey { Key = L'0', Shift = L'1', Alt = L'2', Space = L'3'};

	unsigned int ChecksLength = InitChecks.size();
	unsigned int HotkeysLength = InitHotkeys.size();
	bool Active;

	bool IpCheck;
	bool WcCheck;
	bool FalterCheck;
	bool BerserkerCheck;
	bool SprintCheck;
	bool EpiphanyCheck;
	bool MantraHealingCheck;
	bool SweepingWindCheck;
	bool BohCheck;
	bool MantraConvictionCheck;
	bool LotdCheck;
	bool BoneArmorCheck;
	bool PotionCheck;
	bool MacroCheck;
	bool BlackholeCheck;
	bool StormArmorCheck;
	bool MagicWeaponCheck;
	bool VengeanceCheck;
	bool RainOfVengeanceCheck;
	bool PreparationCheck;
	bool SkeleMageCheck;
	bool DevourCheck;
	bool SimCheck;
	bool SecondSim;
	bool Hexing;
	bool ArchonCheck;
	bool ArcaneBlastCheck;
	bool ExplosiveBlastCheck;
	bool BloodNovaCheck;
	bool BlindingFlashCheck;
	bool CommandSkeletonsCheck;
	bool AkaratCheck;
	bool IronSkinCheck;
	bool LawCheck;
	bool BattleRageCheck;
	bool COTACheck;
	bool FistOHCheck;
	bool HeavensFuryCheck;
	bool JudgmentCheck;
	bool Foreground;

	wchar_t IpHotkey;
	wchar_t WcHotkey;
	wchar_t FalterHotkey;
	wchar_t BerserkerHotkey;
	wchar_t SprintHotkey;
	wchar_t EpiphanyHotkey;
	wchar_t MantraHealingHotkey;
	wchar_t SweepingWindHotkey;
	wchar_t BohHotkey;
	wchar_t MantraConvictionHotkey;
	wchar_t LotdHotkey;
	wchar_t BoneArmorHotkey;
	wchar_t PotionHotkey;
	wchar_t WaveOfForceHotkey;
	wchar_t ElectrocuteHotkey;
	wchar_t MeteorHotkey;
	wchar_t DisintegrateHotkey;
	wchar_t BlackholeHotkey;
	wchar_t StormArmorHotkey;
	wchar_t MagicWeaponHotkey;
	wchar_t MacroHotkey;
	wchar_t TimingKey;
	wchar_t ToggleKey;
	wchar_t VengeanceHotkey;
	wchar_t RainOfVengeanceHotkey;
	wchar_t PreparationHotkey;
	wchar_t SkeleMageHotkey;
	wchar_t DevourHotkey;
	wchar_t SimHotkey;
	wchar_t ArchonHotkey;
	wchar_t ArcaneBlastHotkey;
	wchar_t ExplosiveBlastHotkey;
	wchar_t BloodNovaHotkey;
	wchar_t ForceStandStillHotkey;
	wchar_t ForceStandStillSpecialHotkey;
	wchar_t PositionHotkey;
	wchar_t BlindingFlashHotkey;
	wchar_t ChannelHotkey;
	wchar_t CommandSkeletonsHotkey;
	wchar_t AkaratHotkey;
	wchar_t IronSkinHotkey;
	wchar_t LawHotkey;
	wchar_t BattleRageHotkey;
	wchar_t COTAHotkey;
	wchar_t FistOHHotkey;
	wchar_t HeavensFuryHotkey;
	wchar_t JudgmentHotkey;
	wchar_t ForcemoveHotkey;
	DWORD MacroDelay;

	void Update();
};


#endif  // MAIN_H_