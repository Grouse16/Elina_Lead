////
// Ú×   FOðoÍ·éNX
// à¾   FfobOpÉOðL^·é
// ì¬Ò Fûüâ´½
////


//  fobOÌÝLø  //
#if _DEBUG


//  t@CÐç«  //
#include <string>
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <atlstr.h>

#include "C_Log_System.h"
#include "C_Text_And_File_Manager.h"
#include "C_OS_User_System.h"


// fobOÍ[No
#define _CRTDBG_MAP_ALLOC


//  l[Xy[XÌÈª  //
using namespace DEBUGGER::LOG;


//  Ïé¾  //
C_Log_System C_Log_System::m_this;	// ©NXÖÌANZXpÌÏ
C_Log_System::Pr_Variable C_Log_System::mpr_variable;	// vCx[gÏÖÌANZXpÌÏ


//  è  //
const char* con_DEBUG_FOLDER_PATH = "DEBUG_DATA/DEBUG_LOG";	// fobOf[^Û¶æÌpX


//  Ö  //

//== vCx[g ==//

//-- ú» --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl Fvoid
//===============//
C_Log_System::C_Log_System(void)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	return;
}


//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   FfobOVXeÌú»
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Log_System::M_Init_Debug(void)
{
	// ú»³êÄ¢êÎ²¯é
	if (mpr_variable.initialized == true)
	{
		return;
	}

	// ú»³ê½±ÆðL^
	mpr_variable.initialized = true;

	// R\[æÊðú»·é
	FreeConsole();


	// R\[æÊð¢«·é
	AllocConsole();
	AttachConsole(ATTACH_PARENT_PROCESS);


	// R\[Ìf[^t@Cðüè
	_wfreopen_s(&mpr_variable.console_file, L"CONOUT$", L"w+", stdout);

	// oÍÌ¶R[hwèAhttps://learn.microsoft.com/en-us/cpp/c-runtime-library/translation-mode-constants?view=msvc-170
	{int stab = _setmode(_fileno(stdout), _O_TEXT);}


	// ÈñÆÈ­JbR¢¢FðÝè·é
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);


	// O¢«µ½ðOÆµÄc·
	M_Print_Log(E_LOG_TAGS::e_SET_UP, ALL_LOG_NAME::MAIN_SYSTEM::con_CONSOLE_CREATED, "fobOpR\[yÑVXeÌ¶¬É¬÷(Create C_Log_System & ConsoleFSucceeded)");

	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Log_System::~C_Log_System(void)
{
	// R\[æÊðí·é
	FreeConsole();


	// t@CðÂ¶é
	if (mpr_variable.console_file != nullptr)
	{
		fclose(mpr_variable.console_file);
	}

	return;
}


//-- OoÍ --//

//===============//
// Ú×   FOðoÍ·é
// ø   FC_Log_System::E_LOG_TAGS OÌíÞ, string L^·ét@C¼, string L^àe
// ßèl Fvoid
//===============//
void C_Log_System::M_Print_Log(E_LOG_TAGS in_tag, std::string in_file_name, std::string in_print_log)
{
	// ú»³êÄ¢È¯êÎú»
	M_Init_Debug();


	//  Ïé¾  //
	SYSTEM::TEXT::C_Text_And_File_Manager file_user_system;	// t@CìpVXe

	OS::S_Day_And_Time_Inform now_time_and_day;	// ÔÆút

	std::string log_title;	// oÍ·éO^Cg
	std::string print_log;	// oÍ·éO

	
	// »ÝÌÔîñðæ¾
	now_time_and_day = OS::C_OS_User_System::M_Get_Now_Day_And_Time();


	// oÍ·éOÌútðÝè
	log_title += std::to_string(now_time_and_day.year)		// NÌ\¦
		+ "-" + std::to_string(now_time_and_day.month)		// Ì\¦
		+ "-" + std::to_string(now_time_and_day.day) + "/";	// úÌ\¦


	//  OÌ¯ÊÔÉæÁÄÊXÌîñðtÁ  //
	switch (in_tag)
	{
		//-- VXe --//

		//  ZbgAbv  //
	case E_LOG_TAGS::e_SET_UP:
		log_title += "SYSTEM_00-SET_UP-";
		break;

		//  Vbg_E  //
	case E_LOG_TAGS::e_SHUT_DOWN:
		log_title += "SYSTEM_01-SHUT_DOWN-";
		break;


		//-- AvP[V --//

		//  IuWFNg  //
	case E_LOG_TAGS::e_OBJECT:
		log_title += "APPLICATION_00-OBJECT-";
		break;

		//  Q[Ì`æpVXe  //
	case E_LOG_TAGS::e_GAME_RENDERING:
		log_title += "APPLICATION_01-GAME_RENDERING-";
		break;

		//  UI  //
	case E_LOG_TAGS::e_UI:
		log_title += "APPLICATION_02-UI-";
		break;


		//-- G[ --//

		// áO
	default:
		break;
	}


	// oÍ·éOðÝè
	print_log =
		std::to_string(now_time_and_day.hour) + "-hour."	// Ô
		+ std::to_string(now_time_and_day.minute) + "-min."	// ª
		+ std::to_string(now_time_and_day.second) + "-sec\n"	// b
		+ (std::string)(in_print_log)+"\n";				// Oàe


	// R\[Éîñð\¦·é
	std::wcout << std::endl << log_title.c_str() << std::endl << print_log.c_str();


	// f[^ðLü·é
	file_user_system.M_Set_File_Path(((std::string)con_DEBUG_FOLDER_PATH + "/" + log_title + "/" + (std::string)(in_file_name)+".txt").c_str());
	file_user_system.M_Input_This_Data((print_log + "\n\0").c_str());
	file_user_system.M_Add_Data_To_Now_File();
	
	return;
}


//===============//
// Ú×   FR\[ðÝé½ßÉð~ßÄüÍobt@ðSÄNAµ
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Log_System::M_Stop_Update_And_Log_Present(void)
{
	// obt@ÌàeðæÊÉoÍ
	std::wcout << std::flush;

	// enterðÒÂ
	std::cout << "Press Enter to continue...";
	std::system("pause");
	
	return;
}


//===============//
// Ú×   FR\[ÌOðú»·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Log_System::M_Console_LOG_Flush(void)
{
	// Fð³Éß·
	C_Log_System::M_Set_Console_Text_Color(E_LOG_COLOR::e_WHITE);
	C_Log_System::M_Set_Console_Back_Ground_Color(E_LOG_COLOR::e_BLACK);
	std::system("cls");

	return;
}


//===============//
// Ú×   FR\[Ì¶J[ðÏX·é
// ø   FE_LOG_COLOR Ýè·éFÔ
// ßèl Fvoid
//===============//
void C_Log_System::M_Set_Console_Text_Color(E_LOG_COLOR in_set_color)
{
	// {Æz[y[W https://learn.microsoft.com/ja-JP/windows/console/console-screen-buffers#character-attributes

	//  ¶J[ÏXðÝè  //
	switch (in_set_color)
	{
		//    //
	case E_LOG_COLOR::e_WHITE:
		m_this.mpr_variable.color_text = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED;
		break;

		//    //
	case E_LOG_COLOR::e_BLACK:
		m_this.mpr_variable.color_text = 0;
		break;

		//  Â  //
	case E_LOG_COLOR::e_BLUE:
		m_this.mpr_variable.color_text = FOREGROUND_BLUE;
		break;

		//  Î  //
	case E_LOG_COLOR::e_GREEN:
		m_this.mpr_variable.color_text = FOREGROUND_GREEN;
		break;

		//  Ô  //
	case E_LOG_COLOR::e_RED:
		m_this.mpr_variable.color_text = FOREGROUND_RED;
		break;

		//    //
	case E_LOG_COLOR::e_PURPLE:
		m_this.mpr_variable.color_text = FOREGROUND_RED | FOREGROUND_BLUE;
		break;
	}


	// FÌXV
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), m_this.mpr_variable.color_text | m_this.mpr_variable.color_back);

	return;
}


//===============//
// Ú×   FR\[ÌwiJ[ðÏX·é
// ø   FE_LOG_COLOR Ýè·éFÔ
// ßèl Fvoid
//===============//
void C_Log_System::M_Set_Console_Back_Ground_Color(E_LOG_COLOR in_set_color)
{
	//  wiJ[ÏXðÝè  //
	switch (in_set_color)
	{
		//    //
	case E_LOG_COLOR::e_WHITE:
		m_this.mpr_variable.color_back = BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED;
		break;

		//    //
	case E_LOG_COLOR::e_BLACK:
		m_this.mpr_variable.color_back = 0;
		break;

		//  Â  //
	case E_LOG_COLOR::e_BLUE:
		m_this.mpr_variable.color_back = BACKGROUND_BLUE;
		break;

		//  Î  //
	case E_LOG_COLOR::e_GREEN:
		m_this.mpr_variable.color_back = BACKGROUND_GREEN;
		break;

		//  Ô  //
	case E_LOG_COLOR::e_RED:
		m_this.mpr_variable.color_back = BACKGROUND_RED;
		break;

		//    //
	case E_LOG_COLOR::e_PURPLE:
		m_this.mpr_variable.color_back = BACKGROUND_RED | BACKGROUND_BLUE;
		break;
	}


	// FÌXV
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), m_this.mpr_variable.color_text | m_this.mpr_variable.color_back);

	return;
}


//===============//
// Ú×   FR\[ÌwiJ[ðÏX·é
// ø   FE_LOG_COLOR eLXgÌFÔ, E_LOG_COLOR wiÌFÔ
// ßèl Fvoid
//===============//
void C_Log_System::M_Set_Console_Color_Text_And_Back(E_LOG_COLOR in_txt_color, E_LOG_COLOR in_back_color)
{
	M_Set_Console_Text_Color(in_txt_color);
	M_Set_Console_Back_Ground_Color(in_back_color);

	return;
}


#endif // _DEBUG

