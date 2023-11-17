////
// Ú×   FEBhEYÌ@\ðg¤½ßÌNX
// à¾   FEBhEÝèâbZ[Wðs¤
// ì¬Ò Fûüâ´½
////


//  OSm  //
#include "Platform_Detector_Macro.h"
#ifdef D_OS_IS_WINDOWS


//  t@CÐç«  //
#include <time.h>

#include "C_Windows_System.h"
#include "C_Wnd_Proc_Manager.h"

#ifdef _DEBUG
#include "C_Log_System.h"
#endif // _DEBUG


//  l[Xy[XÌÈª  //
using namespace OS::WINDOWS;


//  }N  //
#define D_ICON_ADDRESS L"data/asset/image/window/star.ico"	// ACRnh

#define D_WND_WIDTH 1000	// EBhEÌ¡ÌTCY
#define D_WND_HEIGHT 500	// EBhEÌcÌTCY


//  Ö  //

//==  vCx[g  ==//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl Fvoid
//===============//
C_Windows_System::C_Windows_System(void)
{
	return;
}

//===============//
// Ú×   FEBhEð¶¬·é
// ø   Fvoid
// ßèl F¬÷µ½©Ç¤© ¬÷µÄ½çtrue
//===============//
bool C_Windows_System::M_Creat_Window(void)
{
	//  Ïé¾  //
	WNDCLASSEX w_wc;	// WNDCLASSEX\¢ÌÌgÌõ

	std::wstring device_name_in_wstr;	// Ch¶ñÅÌEBhE¼


	// EBhEðCh¶ñÉÏ·
	{
		//  Ïé¾  //
		int text_size = (int)con_DEVICE_NAME.size();	// ¶


		device_name_in_wstr.resize(text_size + 1);
		device_name_in_wstr[text_size] = '\0';

		for (int l_now_text = 0; l_now_text < text_size; l_now_text++)
		{
			device_name_in_wstr[l_now_text] = con_DEVICE_NAME[l_now_text];
		}
	}


	// ±Ì\¢ÌÌTCY
	w_wc.cbSize = sizeof(WNDCLASSEX);

	// EBhEÌX^C
	w_wc.style = CS_CLASSDC | CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;

	// EBhEvV[WÌAhX
	w_wc.lpfnWndProc = OS::WINDOWS::PROC::C_Wnd_Proc_Manager::M_Get_Game_APK_Wnd_Proc();

	// \¢ÌÌ\õÌ
	w_wc.cbClsExtra = 0;

	// EBhE¤Ì\õÌ
	w_wc.cbWndExtra = 0;

	// CX^Xnh
	w_wc.hInstance = GetModuleHandle(0);

	// AvÌV[gJbgÌACRÌ©½ß
	w_wc.hIcon = LoadIcon(w_wc.hInstance, D_ICON_ADDRESS);

	// EBhEãÌ}EXJ[\Ì©½ß
	w_wc.hCursor = LoadCursor(NULL, IDC_ARROW);

	// EBhEàÌwiFiNCAgÌæÌwiFj
	w_wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

	// EBhEÌj[Ì¼O
	w_wc.lpszMenuName = NULL;

	// EBhEÌNXÌ¼O
	w_wc.lpszClassName = device_name_in_wstr.data();

	// ^Cgo[ÌACRÌ©½ß
	w_wc.hIconSm = LoadIcon(w_wc.hInstance, D_ICON_ADDRESS);

	// WX^ÉZbgµÄEBhEîñðo^
	RegisterClassEx(&w_wc);


	// EBhEÌå«³ðÝè
	M_Set_Window_Size_Variable(D_WND_WIDTH, D_WND_HEIGHT);
	

	// EBhEÌ\¦ÝèÌú»
	mpr_variable.s_wnd.h_my_wind = CreateWindowEx(

		// g£EBhEX^C
		0,

		// EBhENXÌ¼O
		w_wc.lpszClassName,

		// EBhEÌ¼O
		device_name_in_wstr.data(),

		// EBhEX^C
		WS_OVERLAPPED | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SIZEBOX | WS_CAPTION,

		// \¦Êu
		CW_USEDEFAULT,	// ¶ãwÀW
		CW_USEDEFAULT,	// ¶ãxÀW 

		//EBhEÌTCY
		(int)D_WND_WIDTH,	// EBhEÌ
		(int)D_WND_HEIGHT,	// EBhEÌ³

		// eEBhEÌnh
		NULL,

		// j[nhÜ½ÍqEBhEID
		NULL,

		// CX^Xnh
		GetModuleHandle(0),

		// EBhEì¬f[^
		NULL);


	// EBhEð\¦
	ShowWindow(mpr_variable.s_wnd.h_my_wind, mpr_variable.m_cmd_show);

	// EBhEÌóÔð¼¿É½f(EBhEÌNCAgÌæðXV)
	UpdateWindow(mpr_variable.s_wnd.h_my_wind);

	// ¬÷
	return true;
}


//==  pubN  ==//

//--  ú»ÆI¹  --//

//===============//
// Ú×   FEBhEYÌVXeðú»·é
// ø   Fvoid
// ßèl FÈµ
//===============//
void C_Windows_System::M_Creat_Windows_System(void)
{
	m_this_instance.reset(new C_Windows_System());

	// fobOVXeú»
#ifdef _DEBUG
	DEBUGGER::LOG::C_Log_System::M_Init_Debug();
#endif // _DEBUG

	return;
}


//===============//
// Ú×   FEBhEY@\Ìú»p
// ø   FHINSTANCE& CX^Xnh, int& R}hÔ
// ßèl F¬÷ÌÝtrue
//===============//
bool C_Windows_System::M_Set_Up(void)
{
	//  fobOÌÝZbgAbvJnðÊm  //
#if _DEBUG
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_BLACK, DEBUGGER::LOG::E_LOG_COLOR::e_GREEN);
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::WINDOWS::con_SET_UP_SUCCEEDED, "--------EBhEYÌZbgAbvJn--------");
#endif // _DEBUG


	// EBhEð¶¬·é
	M_Creat_Window();


	//  fobOÌÝZbgAbv®¹ðÊm  //
#if _DEBUG
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_BLACK, DEBUGGER::LOG::E_LOG_COLOR::e_GREEN);
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::WINDOWS::con_SET_UP_SUCCEEDED, "--------EBhEYÌZbgAbvÉ¬÷AGUIðN®®¹--------");
	DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
	DEBUGGER::LOG::C_Log_System::M_Console_LOG_Flush();
#endif // _DEBUG


	// EBhETCYÌXV
	M_Window_Size_Update();

	// ¬÷
	return true;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Windows_System::~C_Windows_System()
{
	M_Release();

	return;
}


//===============//
// Ú×   FÌðúÈÇI¹Ìðs¤
// ø   Fvoid
// ßèl FÈµ
//===============//
void C_Windows_System::M_Release(void)
{
	mpr_variable.m_cmd_show = 0;
	mpr_variable.s_wnd.h_my_wind = NULL;
	mpr_variable.s_wnd.msg_of_wnd = MSG();

	return;
}


//-- XV --//

//===============//
// Ú×   FEBhEÌXVð¨±È¤
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Windows_System::M_Update(void)
{
	//  EBhEÌ  //

	// [U[ÉæéüÍÌXV
	while (PeekMessage(&mpr_variable.s_wnd.msg_of_wnd, NULL, 0, 0, PM_REMOVE) > 0)
	{
		// ¶bZ[Wð¶¬
		TranslateMessage(&mpr_variable.s_wnd.msg_of_wnd);

		// EBhEvV[WðÄÑoµÄbZ[WXV
		DispatchMessage(&mpr_variable.s_wnd.msg_of_wnd);

		// EBhEªÂ¶½çtOð§Ä»êðÊm·é
		if (mpr_variable.s_wnd.msg_of_wnd.message == WM_QUIT)
		{
			m_flg_os_active = false;

			break;
		}
	}

	// EBhETCYÌXV
	M_Window_Size_Update();

	return;
}


//===============//
// Ú×   FEBhEÌTCYÌXVðs¤
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Windows_System::M_Window_Size_Update(void)
{
	//  Ïé¾  //
	RECT client_rect;	// NCAgÌæÌsNZÀW

	S_Window_Position set_window_pos;	// Ýè·éEBhEÀW


	// EBhEÌTCYðæ¾
	GetClientRect(mpr_variable.s_wnd.h_my_wind, &client_rect);
	M_Set_Window_Size_Variable(client_rect.right - client_rect.left, client_rect.bottom - client_rect.top);


	// EBhEÌÊuðæ¾
	set_window_pos.position_left_x = client_rect.left;
	set_window_pos.position_right_x = client_rect.right;
	set_window_pos.position_top_y = GetSystemMetrics(SM_CYSCREEN) - client_rect.top;
	set_window_pos.position_bottom_y = GetSystemMetrics(SM_CYSCREEN) - client_rect.bottom;
	M_Set_Window_Position_Variable(set_window_pos);

	return;
}


//===============//
// Ú×   FEBhEÌúR}hÔðZbg
// ø   Fint R}hÔ
// ßèl Fvoid
//===============//
void C_Windows_System::M_Set_Cmd_Show(int in_cmdshow)
{
	//  Ïé¾  //
	C_Windows_System * wind_os_system = static_cast<C_Windows_System*>(m_this_instance.get());	// EBhEYOSpÌVXe


	wind_os_system->mpr_variable.m_cmd_show = in_cmdshow;

	return;
}


//-- Qb^ --//

//===============//
// Ú×   F©EBhEÌnhðÔ·
// ø   Fvoid
// ßèl FHWND ©EBhEÌnh
//===============//
HWND C_Windows_System::M_Get_Window_Handle(void)
{
	return static_cast<C_Windows_System*>(m_this_instance.get())->mpr_variable.s_wnd.h_my_wind;
}


//===============//
// Ú×   F»ÝÌÔðøÌQÆæÉn·
// ø   FS_Time_Inform & ÔÌÝèæ
// ßèl Fvoid
//===============//
void C_Windows_System::M_Get_Now_Time(OS::S_Time_Inform & in_set_time_inform)
{
	//  Ïé¾  //
	time_t get_time = time(nullptr);	// Ôîñ

	tm time_data;	// ÔîñððÍµ½f[^


	// Ôîñðf[^ÉÏ·
	localtime_s(&time_data, &get_time);


	// útðÝè
	in_set_time_inform.year = time_data.tm_year + 1900;	// NAüèµ½îñÍ1900NªÈª³êÄ¢é½ßù³
	in_set_time_inform.month = time_data.tm_mon + 1;	// Aüèµ½îñªOnÜèÅðvZµÄ¢éÌÅù³(0`11 + 1 = 1`12)
	in_set_time_inform.day = time_data.tm_mday;			// ú

	// ðÝè
	in_set_time_inform.hour = time_data.tm_hour;
	in_set_time_inform.minute = time_data.tm_min;
	in_set_time_inform.second = time_data.tm_sec;

	return;
}


//===============//
// Ú×   FoßÔð~bPÊÅæ¾·é
// ø   Funsigned __int64 & æ¾æÌÔÏÌQÆ
// ßèl Fvoid
//===============//
void C_Windows_System::M_Get_Now_Milli_Second(unsigned __int64 & in_plz_set_this_timer)
{// * GetTickCount64ª1.26imbÅÅ¬ÈÌÅgpµÄ¢é
	in_plz_set_this_timer = GetTickCount64();

	return;
}


//-- EBhE@\ --//

//===============//
// Ú×   FEBhEÌ^CgðÒW·é
// ø   Fconst wstring & Zbg·é^Cg¼
// ßèl Fvoid
//===============//
void C_Windows_System::M_Set_Window_Title(const std::wstring & in_set_title_name)
{
	// EBhE^CgðZbg
	SetWindowText(mpr_variable.s_wnd.h_my_wind, in_set_title_name.c_str());

	return;
}

//===============//
// Ú×   FbZ[W{bNXð\¦·é(EBhEnhðKvÆ·é½ß)
// ø   Fconst wstring & ^Cg, const wstring & \¦àe, const unsigned int bZ[W{bNXÌíÞ
// ßèl Fint EBhEüÍÌÊ
//===============//
int C_Windows_System::M_Creat_Massage_Box(const std::wstring & in_title, const std::wstring & in_text, const unsigned int in_type)
{
	return MessageBox(mpr_variable.s_wnd.h_my_wind, in_text.c_str(), in_title.c_str(), in_type);
}


#endif // OS_IS_WINDOWS

