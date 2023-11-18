////
// Ú×   FQ[ãÌCX^Xð§ä·éNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_GAME_INSTANCE_MANAGER_H_FILE
#define D_INCLUDE_GUARD_C_GAME_INSTANCE_MANAGER_H_FILE


//  t@CÐç«  //
#include <vector>
#include <string>
#include <memory>

#include "C_Actor_List.h"
#include "C_User_Interface_List.h"
#include "C_Sound_List.h"
#include "C_Post_Effect_List.h"


//  l[Xy[X  //

// Q[ÌIuWFNgnÌXgðÄÑo·½ßÌ¼O
namespace GAME::INSTANCE
{
	//  NX  //

	// Q[ãÌCX^Xð§ä·éNX
	class C_Game_Instance_Manager
	{
		//== vCx[g ==//
	private:

		//  Ö  //

		//-- ú»ÆI¹ --//

		// RXgN^
		C_Game_Instance_Manager(void);


		//== pubN ==//
	public:

		//  Ö  //

		//-- í --//

		// Q[ãÌSÄÌCX^XÌÈ©©çAíÌtOª§ÁÄ¢éàÌðÁ·
		static void M_All_Instance_Destroy_Update(void);

		// SÄÌCX^Xðí·é
		static void M_Delete_All_Instance(void);


		//-- XV --//

		// SÄÌAN^[ÌXVð·é
		static void M_Update_Actor(void);

		// SÄÌUIÌXVð·é
		static void M_Update_UI(void);

		// SÄÌ|XgGtFNgÌXVð·é
		static void M_Update_Post_Effect(void);

		// SÄÌTEhÌXVð·é
		static void M_Update_Sound(void);


		//-- `æ --//

		// SÄÌAN^[Ì`æð·é
		static void M_Draw_Actor(void);

		// |XgGtFNgð`æpXgÉÇÁ·é
		static void M_Set_Post_Effect_To_Draw_List(void);

		// UIÌOÉ|XgGtFNgð©¯é`æð·é
		static void M_Draw_Post_Effect_Before_UI(void);

		// SÄÌUIð`æ·é
		static void M_Draw_UI(void);

		// UIÌãÉ|XgGtFNgð©¯é`æð·é
		static void M_Draw_Post_Effect_After_UI(void);


		//-- Qb^ --//

		//===============//
		// Ú×   Fwè³ê½íÞÌAN^[ÌXgðæ¾·é
		// ø   Fvoid
		// ßèl Fvector<unique_ptr<C_Actor>> & wè³ê½AN^[ÌXgÌQÆ
		//===============//
		template<ACTOR::LIST::CONCEPT::C_Checked_Actor_Class C_Actor>
		static std::vector<std::unique_ptr<C_Actor>> & M_Get_Actor_List(void)
		{
			return ACTOR::LIST::C_Actor_List<C_Actor>::M_Get_Actor_List();
		}


		//===============//
		// Ú×   Fwè³ê½íÞÌUIÌXgðæ¾·é
		// ø   Fvoid
		// ßèl Fvector<unique_ptr<C_UI>> & wè³ê½UIÌXgÌQÆ
		//===============//
		template<UI::LIST::CONCEPT::C_Checked_UI_Class C_UI>
		static std::vector<std::unique_ptr<C_UI>> & M_Get_UI_List(void)
		{
			return UI::LIST::C_User_Interface_List<C_UI>::M_Get_UI_List();
		}


		//===============//
		// Ú×   Fwè³ê½íÞÌTEhÌXgðæ¾·é
		// ø   Fvoid
		// ßèl Fvector<unique_ptr<C_Sound>> & wè³ê½TEhÌXgÌQÆ
		//===============//
		template<SOUND::LIST::CONCEPT::C_Checked_Sound_Class C_Sound>
		static std::vector<std::unique_ptr<C_Sound>> & M_Get_Sound_List(void)
		{
			return SOUND::LIST::C_Sound_List<C_Sound>::M_Get_Sound_List();
		}


		//===============//
		// Ú×   Fwè³ê½íÞÌ|XgGtFNgÌXgðæ¾·é
		// ø   Fvoid
		// ßèl Fvector<unique_ptr<UI>> & wè³ê½|XgGtFNgÌXgÌQÆ
		//===============//
		template<SOUND::LIST::CONCEPT::C_Checked_Sound_Class C_Sound>
		static std::vector<std::unique_ptr<C_Sound>> & M_Get_Post_Effect_List(void)
		{
			return POST_EFFECT::LIST::C_Post_Effect_List<C_Sound>::M_Get_Post_Effect_List();
		}
	};
}


#endif // !D_INCLUDE_GUARD_C_GAME_INSTANCE_MANAGER_H_FILE
