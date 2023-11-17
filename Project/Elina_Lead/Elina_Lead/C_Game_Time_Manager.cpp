////
// Ú×   FQ[ÌüÍð§ä·éVXe
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_Game_Time_Manager.h"

#include "C_OS_System_Base.h"

#include "C_Log_System.h"


//  l[Xy[XÌÈª  //
using namespace GAME::TIME;


//  X^eBbNÏ  //
std::unique_ptr<C_Game_Time_Manager> C_Game_Time_Manager::m_this;	// CX^X»·é½ßÌÀÌiVOgpj


//  Ö  //

//== vCx[g ==//

//-- ú» --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Game_Time_Manager::C_Game_Time_Manager(void)
{
	// fobOÍ¶¬µ½±ÆðOÉc·
#ifdef _DEBUG
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT, "Q[pÌÔVXeð¶¬");
#endif // _DEBUG

	// úÔðL^
	OS::C_OS_System_Base::M_Get_Instance()->M_Get_Now_Milli_Second(mpr_variable.now_timer);
	mpr_variable.time_of_seconds_start = mpr_variable.now_timer;
	mpr_variable.then_timer = mpr_variable.now_timer;

	return;
}


//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   FÔpVXeð¶¬·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Time_Manager::M_Init(void)
{
	m_this.reset(new C_Game_Time_Manager);
	M_Set_Frame_Rate(m_this->mpr_variable.frame_rate);

	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Game_Time_Manager::~C_Game_Time_Manager(void)
{
	// fobOÍíµ½±ÆðOÉc·
#ifdef _DEBUG
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT, "Q[pÌÔVXeðí");
#endif // _DEBUG

	M_Release();

	return;
}


//===============//
// Ú×   Fððú·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Time_Manager::M_Release(void)
{
	m_this.reset();

	return;
}


//-- XV --//

//===============//
// Ú×   FÔÌXV
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Time_Manager::M_Time_Update(void)
{
	// ÅVÌÔðæ¾·é
	OS::C_OS_System_Base::M_Get_Instance()->M_Get_Now_Milli_Second(m_this->mpr_variable.now_timer);


	//oßÔÆ»ÝÌÔðXV
	m_this->mpr_variable.delta_second = ((float)(m_this->mpr_variable.now_timer - m_this->mpr_variable.then_timer)) / 1000.0f;

	// t[îñðXV
	m_this->mpr_variable.now_frame += 1;

	return;
}


//===============//
// Ú×   Ft[ÌI¹És¤XV
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Time_Manager::M_Frame_End_Update(void)
{
	// Pt[oßÌîñXV
	m_this->mpr_variable.need_spend_time = ((float)m_this->mpr_variable.time_of_seconds_start / 1000.0f) + m_this->mpr_variable.one_frame_time * m_this->mpr_variable.now_frame;
	m_this->mpr_variable.then_timer = m_this->mpr_variable.now_timer;


	// t[[gðÛÂ½ßÌÔªoß·éÜÅÒ@·é
	if (m_this->mpr_variable.flg_constant_frame)
	{
		while (M_Get_FPS_Request_Time_Passed() == false)
		{
			OS::C_OS_System_Base::M_Get_Instance()->M_Get_Now_Milli_Second(m_this->mpr_variable.now_timer);
		}
	}

	// êbÔÈãoßµ½çt[[gîñðXV
	if (m_this->mpr_variable.now_timer - m_this->mpr_variable.time_of_seconds_start >= 1000)
	{
		m_this->mpr_variable.time_of_seconds_start = m_this->mpr_variable.now_timer;
		m_this->mpr_variable.fps = m_this->mpr_variable.now_frame;
		m_this->mpr_variable.now_frame = 0;
	}

	return;
}


//-- Qb^ --//

//===============//
// Ú×   FFPSðÛ·é½ßÌÔªoßµÄ¢é©Ç¤©ðÔ·
// ø   Fvoid
// ßèl Fbool trueÈçoßµÄ¢é
//===============//
bool C_Game_Time_Manager::M_Get_FPS_Request_Time_Passed(void)
{
	return ((float)m_this->mpr_variable.now_timer / 1000.0f) >= m_this->mpr_variable.need_spend_time;
}


//===============//
// Ú×   F»ÝÌKèt[[gðÔ·
// ø   Fvoid
// ßèl Fint Kèt[[g
//===============//
int C_Game_Time_Manager::M_Get_Frame_Rate(void)
{
	return m_this->mpr_variable.frame_rate;
}


//===============//
// Ú×   F»ÝÌfpsðÔ·
// ø   Fvoid
// ßèl Fint »ÝÌfpsiêbÔÌt[j
//===============//
int C_Game_Time_Manager::M_Get_FPS(void)
{
	return m_this->mpr_variable.fps;
}


//===============//
// Ú×   F»ÝÌoßÔðÔ·
// ø   Fvoid
// ßèl Ffloat »ÝÌoßÔ
//===============//
float C_Game_Time_Manager::M_Get_Delta_Second(void)
{
	return m_this->mpr_variable.delta_second;
}


//===============//
// Ú×   FQ[àÅÌoßÔðÔ·
// ø   Fvoid
// ßèl Ffloat Q[ÅÌoßÔ
//===============//
float C_Game_Time_Manager::M_Get_Game_Second(void)
{
	return m_this->mpr_variable.delta_second * m_this->mpr_variable.game_speed;
}


//===============//
// Ú×   FQ[àÔÌXs[hðÔ·
// ø   Fvoid
// ßèl Ffloat Q[àÔÌXs[h
//===============//
float C_Game_Time_Manager::M_Get_Game_Speed(void)
{
	return m_this->mpr_variable.game_speed;
}


//-- Zb^ --//

//===============//
// Ú×   Ft[[gðZbg·é
// ø   Fint Ýè·ét[[g
// ßèl Fvoid
//===============//
void C_Game_Time_Manager::M_Set_Frame_Rate(int in_set_frame_rate)
{
	m_this->mpr_variable.frame_rate = in_set_frame_rate;
	m_this->mpr_variable.one_frame_time = (1.0f / (float)m_this->mpr_variable.frame_rate);

	return;
}


//===============//
// Ú×   FQ[àÔÌXs[hðZbg·é
// ø   Ffloat Zbg·éQ[àÔÌXs[h
// ßèl Fvoid
//===============//
void C_Game_Time_Manager::M_Set_Game_Speed(float in_set_game_speed)
{
	m_this->mpr_variable.game_speed = in_set_game_speed;

	return;
}



