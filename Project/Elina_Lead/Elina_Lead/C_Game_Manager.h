////
// Ú×   FQ[ÌVXe§äpÌNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  CN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_ENGINE_MANAGER_H_FILE
#define D_INCLUDE_GUARD_C_ENGINE_MANAGER_H_FILE


//  t@CÐç«  //
#include "C_Game_State_Manager.h"

#include <vector>


//  l[Xy[X  //

// GWÌ§äpÌVXe
namespace GAME
{
	//  NX  //

	// GW§äpVXe
	class C_Game_Manager
	{
		//== vCx[g ==//
	private:

		//  Ïé¾  //

		// ÏðÜÆß½\¢Ì
		struct SPr_Variable
		{
			bool flg_engine_exsist = true;		// GWª¶ÝµÄ¢é©Ç¤©ÌtO
			bool flg_engine_activate = false;	// GWªÒ­©Ç¤©ÌtO
			bool flg_OS_active_now = false;		// OSVXeªÒ­©Ç¤©ÌtO

		} static mpr_variable;	// ÏðÄÑo·½ßÌ¼O

		static C_Game_Manager m_this;	// GW§äpÌVXeÌÀÌ(VOg)


		//  Ö  //

		//-- ú» --//

		// RXgN^
		C_Game_Manager(void);

		// GWpÌ`æpÝèðú»·é
		static bool M_Draw_Setting_Init(void);

		
		//-- XV --//

		// f[^ÌXVðs¤
		static void M_Data_Update(void);

		// EBhE^CgÌXV
		static void M_Window_Title_Update(void);


		//== pubN ==//
	public:

		//  Ö  //

		//-- ú»ÆI¹ --//

		// GWÌú»
		static void M_Init(void);

		// fXgN^
		~C_Game_Manager(void);

		// ðú
		static void M_Release(void);


		//-- Zb^ --//

		// GWð¶ÝµÄ¢éóÔ©Ç¤©ðÝè·é@øFtrueÍ³íÉ¶ÝµÄ¢é
		static void M_Set_Engine_Exist_Flg(bool);

		// GWªÒ­©Ç¤©ðÝè·é@øFtrueÍÒ­
		static void M_Set_Engine_Activate_Flg(bool);


		//-- Qb^ --//

		// GWð¶ÝµÄ¢éóÔ©Ç¤©ðæ¾·é@øFtrueÍ³íÉ¶ÝµÄ¢é
		static bool M_Get_Engine_Exist_Flg(void);

		// GWªANeBuóÔ©Ç¤©ðÔ·@ßèlFANeBuÌÝture
		static bool M_Get_Engine_Active_Flg(void);


		//-- Às --//

		// GWÌðÀs·é
		static void M_Executes_Process(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_ENGINE_MANAGER_H_FILE


//======================================================================
// Copyright 2023 ûüâ´½
// 
// àµà±ÌR[hð©ªÌvWFNgÉpµ½¢ÌÅ êÎA
// [AhXFtakasaka.ryusei1116@gmail.com
// Ü½ÍAûüâ´½ÜÅ²A­¾³¢B
// R[hÌs¾ªÌðàâAÅVÌóÔÌñÈÇÉÎ¢½µÜ·B
//======================================================================
