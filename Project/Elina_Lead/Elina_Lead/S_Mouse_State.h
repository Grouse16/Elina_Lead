////
// Ú×   F}EXîñpÌ^Ìè`
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_S_MOUSE_STATE_H_FILE
#define D_INCLUDE_GUARD_S_MOUSE_STATE_H_FILE


//  t@CÐç«  //
#include "E_Mouse_Click_State.h"


//  l[Xy[X  //

// OS§äpVXeðÄÑo·½ßÌ¼O
namespace OS
{
	//  \¢Ì //

	// }EXÀWpÌ\¢Ì
	struct S_Mouse_State
	{
		E_MOUSE_CLICK_STATE left_click = E_MOUSE_CLICK_STATE::e_NON;	// ¶NbNÌóÔ
		E_MOUSE_CLICK_STATE center_click = E_MOUSE_CLICK_STATE::e_NON;	// NbNÌóÔ
		E_MOUSE_CLICK_STATE right_click = E_MOUSE_CLICK_STATE::e_NON;	// ENbNÌóÔ

		int x = 0;	// }EXÀW
		int y = 0;	// }EXÀW
	};
}


#endif // !D_INCLUDE_GUARD_S_MOUSE_STATE_H_FILE
