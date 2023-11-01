////
// Ú×   FGWpÌEBhEvV[WÌNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  OSm  //
#include "Platform_Detector_Macro.h"
#ifdef D_OS_IS_WINDOWS


//  t@CÐç«  //
#include "C_Wnd_Proc_For_Engine_APK.h"
#include "C_Wnd_Proc_Manager.h"
#include "C_OS_System_Base.h"
#include "C_Game_Manager.h"

#include <windowsx.h>


//  l[Xy[XÌÈª  //
using namespace OS::WINDOWS::PROC;


//  Ïé¾  //
C_Wnd_Proc_For_Engine_APK C_Wnd_Proc_For_Engine_APK::m_this;	// ©gðCX^X»·é½ßÌÏ


//  Ö  //

//== vCx[g ==//

//-- ú» --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Wnd_Proc_For_Engine_APK::C_Wnd_Proc_For_Engine_APK(void)
{
	// EBhEvV[WðZbg
	OS::WINDOWS::PROC::C_Wnd_Proc_Manager::M_Set_Engine_APK_Wnd_Proc(Wnd_Proc);

	return;
}


//== pubN ==//

//-- VXep --//

//===============//
// Ú×   FEBhEÌðs¤vV[W
// ø   FHWND ©AvÌEBhEîñ, UINT [U[ÌüÍîñ, WPARAM zC[ÌüÍîñ, LPARAM }EXÈÇÌüÍîñ
// ßèl FLRESULT ÊðÔ·
//===============//
LRESULT CALLBACK C_Wnd_Proc_For_Engine_APK::Wnd_Proc(HWND in_h_wnd, UINT in_msg, WPARAM in_w_param, LPARAM in_l_param)
{
	// I¹³êÄ©ç±ÌðsíÈ¢æ¤É~ßé
	if (in_h_wnd == NULL || in_msg == WM_QUIT)
	{
		return 0;
	}


	// uMsgi±ÌÖÌæ2øjªA[U[ìÌIDîñ
	switch (in_msg)
	{
		//  I¹n  //

		// ¢¸ê©ÌL[ª³ê½Æ«
	case WM_KEYDOWN:

		//  I¹Ì{^  //
		if (LOWORD(in_w_param) == VK_ESCAPE)
		{
			DestroyWindow(in_h_wnd);  // gWM_DESTROYhbZ[Wðé
		}

		break;

		// EBhEjüÌbZ[W
	case WM_DESTROY:
		PostQuitMessage(0);	// gWM_QUIThbZ[Wðé@¨@AvI¹

		break;

		// x{^
	case WM_CLOSE:
		DestroyWindow(in_h_wnd);  // gWM_DESTROYhbZ[Wðé

		break;

		// ¶NbN
	case WM_LBUTTONDOWN:
		OS::C_OS_System_Base::M_Get_Instance()->M_Set_Left_Click_State(OS::E_MOUSE_CLICK_STATE::e_CLICK);

		break;

		// ¶NbNI¹
	case WM_LBUTTONUP:
		OS::C_OS_System_Base::M_Get_Instance()->M_Set_Left_Click_State(OS::E_MOUSE_CLICK_STATE::e_NON);

		break;

		// ¶_uNbN
	case WM_LBUTTONDBLCLK:
		OS::C_OS_System_Base::M_Get_Instance()->M_Set_Left_Click_State(OS::E_MOUSE_CLICK_STATE::e_DOUBLE_CLICK);

		break;

		// ENbN
	case WM_RBUTTONDOWN:
		OS::C_OS_System_Base::M_Get_Instance()->M_Set_Right_Click_State(OS::E_MOUSE_CLICK_STATE::e_CLICK);

		break;

		// ENbNI¹
	case WM_RBUTTONUP:
		OS::C_OS_System_Base::M_Get_Instance()->M_Set_Right_Click_State(OS::E_MOUSE_CLICK_STATE::e_NON);

		break;

		// E_uNbN
	case WM_RBUTTONDBLCLK:
		OS::C_OS_System_Base::M_Get_Instance()->M_Set_Right_Click_State(OS::E_MOUSE_CLICK_STATE::e_DOUBLE_CLICK);

		break;

		// NbN
	case WM_MBUTTONDOWN:
		OS::C_OS_System_Base::M_Get_Instance()->M_Set_Center_Click_State(OS::E_MOUSE_CLICK_STATE::e_CLICK);

		break;

		// NbNI¹
	case WM_MBUTTONUP:
		OS::C_OS_System_Base::M_Get_Instance()->M_Set_Center_Click_State(OS::E_MOUSE_CLICK_STATE::e_NON);

		break;

		// _uNbN
	case WM_MBUTTONDBLCLK:
		OS::C_OS_System_Base::M_Get_Instance()->M_Set_Center_Click_State(OS::E_MOUSE_CLICK_STATE::e_DOUBLE_CLICK);

		break;

		// }EXÌÚ®
	case WM_MOUSEMOVE:

		// }EXÌÀWðüè
		OS::C_OS_System_Base::M_Get_Instance()->M_Set_Mouse_Position_Variable(GET_X_LPARAM(in_l_param) + 1, OS::C_OS_System_Base::M_Get_Instance()->M_Get_Window_Size().height - GET_Y_LPARAM(in_l_param) + 1);
		
		break;


		// EBhEÌTCYÏX
	case WM_SIZING:

		// EBhETCYðXVµÄà¤êxðÀs
		OS::C_OS_System_Base::M_Get_Instance()->M_Window_Size_Update();
		GAME::C_Game_Manager::M_Executes_Process();

		break;


		// EBhEÌÚ®
	case WM_MOVE:

		// EBhETCYðXVµÄà¤êxðÀs
		OS::C_OS_System_Base::M_Get_Instance()->M_Window_Size_Update();
		GAME::C_Game_Manager::M_Executes_Process();

		break;


		// EBhEÌTCYÏX®¹
	case WM_SIZE:

		//  TCYÌÏXàeÉæÁÄªò  //
		switch (in_w_param)
		{
			//  TCYÏX  //
		case SIZE_RESTORED:

			// EBhETCYðXVµÄà¤êxðÀs
			OS::C_OS_System_Base::M_Get_Instance()->M_Window_Size_Update();
			GAME::C_Game_Manager::M_Executes_Process();

			break;


			//  Åå»³ê½  //
		case SIZE_MAXIMIZED:

			// EBhETCYðXVµÄà¤êxðÀs
			OS::C_OS_System_Base::M_Get_Instance()->M_Window_Size_Update();
			GAME::C_Game_Manager::M_Executes_Process();

			break;

			//  »Ì¼ÌbZ[WÍ½µÈ¢  //
		default:
			break;
		}

		break;


		//  gðGÁÄ¢é¾¯Ì  //
	case WM_WINDOWPOSCHANGED:

		// EBhETCYðXVµÄà¤êxðÀs
		OS::C_OS_System_Base::M_Get_Instance()->M_Window_Size_Update();
		GAME::C_Game_Manager::M_Executes_Process();

		break;


		// ãÌcaseÈOÌêÌðÀs
	default:

		// returnÉÓAEBhEÌîñðXVµÄð²¯é
		return DefWindowProc(in_h_wnd, in_msg, in_w_param, in_l_param);

		break;
	}

	return 0;
}


#endif // OS_IS_WINDOWS

