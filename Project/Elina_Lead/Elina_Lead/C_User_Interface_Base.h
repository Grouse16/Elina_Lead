////
// Ú×   FUIÌîêÆÈéNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_USER_INTERFACE_BASE_H_FILE
#define D_INCLUDE_GUARD_C_USER_INTERFACE_BASE_H_FILE


//  t@CÐç«  //
#include "C_Game_Instance_Base.h"


//  l[Xy[X  //

// Q[ÌUIÌîêNXðÄÑo·½ßÌ¼O
namespace GAME::INSTANCE::UI::BASE
{
	//  NX  //

	// UIÌîêÆÈéNX
	class C_User_Interface_Base : public GAME::INSTANCE::BASE::C_Game_Instance_Base
	{
		//== vCx[g ==//
	private:


		//== pubN ==//
	public:

		//  Ö  //

		//-- ú»ÆI¹ --//

		// RXgN^
		C_User_Interface_Base(void);

		// fXgN^
		virtual ~C_User_Interface_Base(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_USER_INTERFACE_BASE_H_FILE
