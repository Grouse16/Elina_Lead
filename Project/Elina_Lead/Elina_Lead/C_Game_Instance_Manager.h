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
		void M_All_Instance_Destroy_Update(void);

		// SÄÌCX^Xðí·é
		void M_Delete_All_Instance(void);


		//-- Qb^ --//
		
		// wè³ê½íÞÌAN^[ÌXgðæ¾·é
		template<class C_Actor>
		void M_Get_Actor_List(void);

		// wè³ê½íÞÌUIðXgÌæ¾·é
		template<class C_UI>
		void M_Get_User_Interface_List(void);

		// wè³ê½íÞÌTEhÌXgðæ¾·é
		template<class C_Sound>
		void M_Get_Sound_List(void);

		// wè³ê½íÞÌ|XgGtFNgÌXgðæ¾·é
		template<class C_Post_Effect>
		void M_Get_Post_Effect_List(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_GAME_INSTANCE_MANAGER_H_FILE
