////
// Ú×   FGWpÌEBhEvV[WÌNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_WND_PROC_FOR_ENGINE_APK
#define D_INCLUDE_GUARD_C_WND_PROC_FOR_ENGINE_APK


//  OSm  //
#include "Platform_Detector_Macro.h"
#ifdef D_OS_IS_WINDOWS


//  t@CÐç«  //
#include <Windows.h>


//  l[Xy[X  //

// EBhEYpÌVXeðÄÑo·½ßÌ¼O
namespace OS::WINDOWS::PROC
{
	//  NX  //

	// EBhEvV[Wð§ä·é½ßÌVXe
	class C_Wnd_Proc_For_Engine_APK
	{
	//== vCx[g ==//
	private:

		//  Ïé¾  //
		static C_Wnd_Proc_For_Engine_APK m_this;	// ©gÌCX^X(VOg»Égp)


		//  Ö  //

		//-- ú» --//

		// RXgN^
		C_Wnd_Proc_For_Engine_APK(void);

	//== pubN ==//
	public:

		//  Ö  //

		//-- EBhEY --//

		// EBhEvV[W
		static LRESULT CALLBACK Wnd_Proc(HWND, UINT, WPARAM, LPARAM);
	};
}


#endif // OS_IS_WINDOWS
#endif // !D_INCLUDE_GUARD_C_WND_PROC_FOR_ENGINE_APK



//======================================================================
// Copyright 2023 ûüâ´½
// 
// àµà±ÌR[hð©ªÌvWFNgÉpµ½¢ÌÅ êÎA
// [AhXFtakasaka.ryusei1116@gmail.com
// Ü½ÍAûüâ´½ÜÅ²A­¾³¢B
// R[hÌs¾ªÌðàâAÅVÌóÔÌñÈÇÉÎ¢½µÜ·B
//======================================================================

