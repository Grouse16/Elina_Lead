////
// Ú×   F©ìQ[AGiE[hÌCÖ
// à¾   F±±ÅC[vâZbgAbvðs¤
// ì¬Ò Fûüâ´½
////


//  }N  //

// fobOðs¤½ßÌOVXeÌ}N
#if _DEBUG
#define _CRTDBG_MAP_ALLOC
#include "C_Log_System.h"
#endif // _DEBUG


//  OSm  //
#include "Platform_Detector_Macro.h"


//  t@CÐç«  //
#include "C_Game_Manager.h"
#include "C_API_Initialize_And_Release_Manager.h"


//  Ö  //

//-- ú»ÆI¹ --//

// OSVXeÌ¶¬ðs¤
void M_OS_Creat_System(void);

// _OAPIÌú»ðs¤
void M_Rendering_API_Init(void);

// Q[VXeÌú»ðs¤
void M_Game_Set_Up(void);

// Q[ÌI¹
void M_Game_End(void);


//-- fobO --//
#if _DEBUG

// ú»Ì¬÷ð\¦·é
void M_Print_Log_Of_Succeeded_Init(void);

#endif // _DEBUG


//  CÖ  //

// EBhEYÍWinmainÖðg¤ª±Ì}NÌLøÍÍOÅÍlðgpµÈ¢±Æ(¼vbgtH[Ì½ßÉ)	// EBhEYÌTuVXeðwè·é±Æ
#ifdef D_OS_IS_WINDOWS
#include "C_Windows_System.h"
int APIENTRY WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE /* à¤gp³êéÍÈ¢AíÉO */, _In_ LPSTR, _In_ int in_cmd_show)
{
// »Ì¼Ì OpenGLnÍint main(void)Ö©çnßé
#else
int main(void)
{
#endif

	//=== Jn ===//
	
	// OSpVXeÌ¶¬
	M_OS_Creat_System();


// EBhEYÍR}hÔðZbgiDirectX¢gpÍX[³êéj
#ifdef D_OS_IS_WINDOWS
	PLATFORM::C_API_Initialize_And_Release_Manager::M_Set_CMD_Number(in_cmd_show);
#endif


	// _OAPIÌ¶¬
	M_Rendering_API_Init();

	// Q[pVXeÌú»
	M_Game_Set_Up();


	// fobOÈçú»Ì¬÷ð\¦i¸sÍX[³êéj
#if _DEBUG
	M_Print_Log_Of_Succeeded_Init();
#endif // _DEBUG
	

	//  C[v  //
	while (GAME::C_Game_Manager::M_Get_Game_Exist_Flg())
	{
		// Q[ÌvZXðÀs
		GAME::C_Game_Manager::M_Executes_Process();
	}


	//  I¹  //
	M_Game_End();


	//  Av¨íè  //
	return 0;
}


//  Ö  //

//-- ú»ÆI¹ --//

//===============//
// Ú×   FOSVXeÌ¶¬ðs¤
// ø   Fvoid
// ßèl Fvoid
//===============//
void M_OS_Creat_System(void)
{
	// OSð¶¬·é@¸sÅI¹
	if (!PLATFORM::C_API_Initialize_And_Release_Manager::M_Creat_OS(PLATFORM::E_RENDERING_API_KIND::e_DX12))
	{
		GAME::C_Game_Manager::M_Set_Game_Exist_Flg(false);
	}

	return;
}


//===============//
// Ú×   F_OAPIVXeÌ¶¬ðs¤
// ø   Fvoid
// ßèl Fvoid
//===============//
void M_Rendering_API_Init(void)
{
	// OSÌú»ðs¤@¸sÅI¹
	if (!PLATFORM::C_API_Initialize_And_Release_Manager::M_Init_OS())
	{
		GAME::C_Game_Manager::M_Set_Game_Exist_Flg(false);
	}


	// _OAPIð¶¬·é@¸sÅI¹
	if (!PLATFORM::C_API_Initialize_And_Release_Manager::M_Init_API())
	{
		GAME::C_Game_Manager::M_Set_Game_Exist_Flg(false);
	}

	return;
}


//===============//
// Ú×   FQ[VXeÌú»ðs¤
// ø   Fvoid
// ßèl Fvoid
//===============//
void M_Game_Set_Up(void)
{
	// ±êÜÅÌú»ª¬÷µÄ¢éÌÝú»ðs¤
	if (GAME::C_Game_Manager::M_Get_Game_Exist_Flg())
	{
		GAME::C_Game_Manager::M_Init();
	}

	return;
}



//===============//
// Ú×   FQ[ÌI¹
// ø   Fvoid
// ßèl Fvoid
//===============//
void M_Game_End(void)
{
	//  fobOÈçI¹ð\¦  //
#if _DEBUG
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_BLACK, DEBUGGER::LOG::E_LOG_COLOR::e_GREEN);
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SHUT_DOWN, DEBUGGER::LOG::ALL_LOG_NAME::MAIN_SYSTEM::con_END, "--------I¹ªÀs³ê½ÌÅAvP[Vðâ~--------");
	DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
	DEBUGGER::LOG::C_Log_System::M_Console_LOG_Flush();
#endif // _DEBUG


	// Q[Ìðú
	GAME::C_Game_Manager::M_Release();

	// _OpÌAvP[VðI¹·é
	PLATFORM::C_API_Initialize_And_Release_Manager::M_Relese_Graphics_API();

	return;
}


//-- fobO --//
#if _DEBUG

//===============//
// Ú×   Fú»Ì¬÷ð\¦·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void M_Print_Log_Of_Succeeded_Init(void)
{
	// ú»É¬÷µÄ¢È©Á½ç²¯é
	if (!GAME::C_Game_Manager::M_Get_Game_Exist_Flg())
	{
		return;
	}

	//  fobOÈçú»Ì¬÷ð\¦  //
#if _DEBUG
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_BLACK, DEBUGGER::LOG::E_LOG_COLOR::e_GREEN);
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::MAIN_SYSTEM::con_ALL_SET_UP_SUCCEEDED, "--------ú»I¹--------");
	DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
	DEBUGGER::LOG::C_Log_System::M_Console_LOG_Flush();

	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_BLACK, DEBUGGER::LOG::E_LOG_COLOR::e_GREEN);
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::MAIN_SYSTEM::con_ALL_SET_UP_SUCCEEDED, "--------AvP[VJn--------");
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::MAIN_SYSTEM::con_ALL_SET_UP_SUCCEEDED, "GUIÌæÊ`æðJnµÜ·");
#endif

	return;
}

#endif // _DEBUG


//======================================================================
// Copyright 2023 ûüâ´½
// 
// àµà±ÌR[hð©ªÌvWFNgÉpµ½¢ÌÅ êÎA
// [AhXFtakasaka.ryusei1116@gmail.com
// Ü½ÍAûüâ´½ÜÅ²A­¾³¢B
// R[hÌs¾ªÌðàâAÅVÌóÔÌñÈÇÉÎ¢½µÜ·B
//======================================================================

