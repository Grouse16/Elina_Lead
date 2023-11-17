////
// Ú×   FEBhEYÌ@\ðg¤½ßÌNX
// à¾   FEBhEÝèâbZ[Wðs¤
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_WINDOWS_SYSTEM_H
#define D_INCLUDE_GUARD_C_WINDOWS_SYSTEM_H


//  OSm  //
#include "Platform_Detector_Macro.h"
#ifdef D_OS_IS_WINDOWS


//  t@CÐç«  //
#include <Windows.h>
#include <memory>
#include <string>

#include "C_OS_System_Base.h"


//  l[Xy[X  //

// EBhEYpÌVXeðÄÑo·½ßÌ¼O
namespace OS::WINDOWS
{
	//  NX  //

	// EBhEYÌ@\ðg¤½ßÌNX
	class C_Windows_System : public OS::C_OS_System_Base
	{
		//==  vCx[g  ==//
	private:

		//  \¢Ì  //

		// ÏðµÜ¤½ßÌ\¢Ì
		struct SPr_Variable
		{
			// EBhEpîñÌ\¢Ì
			struct S_WND
			{
				HWND h_my_wind = nullptr;	// ©EBhEÌnh

				MSG msg_of_wnd = MSG();	// EBhEÌpÌÏ

			} s_wnd;	// EBhE

			int m_cmd_show = 0;	// æÊÉEBhEð\¦·é½ßÌl
		};


		//  Ïé¾  //
		SPr_Variable mpr_variable;	// ±ÌNXÌÏðÄÑo·½ßÌ¼O


		//  Ö  //

		//-- ú» --//

		// RXgN^AÊíÌû@ÅCX^X»oÈ­·é
		C_Windows_System(void);

		// EBhEð¶¬·é
		bool M_Create_Window(void);


		//==  pubN  ==//
	public:

		//  Ö  //

		//--  ú»ÆI¹  --//

		// EBhEYpÌVXeð¶¬·é
		static void M_Create_Windows_System(void);

		// EBhEY@\Ìú»pAøFHINSTANCE& CX^Xnh, int& R}hÔ
		bool M_Set_Up(void) override;

		// fXgN^
		~C_Windows_System(void);

		// ðú
		void M_Release(void) override;


		//-- XV --//

		// EBhEÌXVð¨±È¤
		void M_Update(void) override;

		// EBhEÌTCYÌXVðs¤
		void M_Window_Size_Update(void) override;


		//-- Zb^ --//

		// EBhEÌúR}hÔðZbg@øFR}hÔ
		static void M_Set_Cmd_Show(int);


		//-- Qb^ --//

		// ©EBhEÌnhðÔ·
		static HWND M_Get_Window_Handle(void);

		// »ÝÌÔðøÌQÆæÉn·
		void M_Get_Now_Time(OS::S_Time_Inform & ) override;

		// oßÔð~bPÊÅæ¾·é@øFæ¾æÌÔÏÌQÆ
		void M_Get_Now_Milli_Second(unsigned __int64 & ) override;


		//-- EBhE@\ --//

		// EBhEÌ^CgðÒW·é@øFconst std::wstring & Zbg·é^Cg¼
		void M_Set_Window_Title(const std::wstring &) override;

		// bZ[W{bNXð\¦·é(EBhEnhðKvÆ·é½ß)@øFconst std::wstring & ^Cg, const std::wstring & \¦àe, const unsigned int bZ[W{bNXÌíÞ
		int M_Create_Massage_Box(const std::wstring &, const std::wstring &, const unsigned int) override;
	};
}


#endif // OS_IS_WINDOWS
#endif // !D_INCLUDE_GUARD_C_WINDOWS_SYSTEM_H


//======================================================================
// Copyright 2023 ûüâ´½
// 
// àµà±ÌR[hð©ªÌvWFNgÉpµ½¢ÌÅ êÎA
// [AhXFtakasaka.ryusei1116@gmail.com
// Ü½ÍAûüâ´½ÜÅ²A­¾³¢B
// R[hÌs¾ªÌðàâAÅVÌóÔÌñÈÇÉÎ¢½µÜ·B
//======================================================================

