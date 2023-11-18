////
// Ú×   FQ[CX^XÌîêÆÈéNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_GAME_INSTANCE_BASE_H_FILE
#define D_INCLUDE_GUARD_C_GAME_INSTANCE_BASE_H_FILE


//  t@CÐç«  //
#include <string>


//  l[Xy[X  //

// Q[ÌIuWFNgÌîêÆÈéVXeðÄÑo·½ßÌ¼O
namespace GAME::INSTANCE::BASE
{
	//  NX  //

	// Q[ãÌCX^XÌîêÆÈéNX
	class C_Game_Instance_Base
	{
		//== vCx[g ==//
	private:

		//  Ïé¾  //
		std::string m_name = "default";	// CX^X¼

		bool m_flg_destroy_instance = false;	// Q[CX^Xðí·é©Ç¤©ÌtO


		//== pubN ==//
	public:

		//-- ú»ÆI¹ --//

		// RXgN^
		C_Game_Instance_Base(void);

		// fXgN^
		virtual ~C_Game_Instance_Base(void);


		//-- Zb^ --//

		// CX^X¼ðÝè·é@øFÝè·éCX^XÌ¼O
		void M_Set_Instance_Name(std::string);


		//-- Qb^ --//

		// CX^Xðí·é©Ç¤©ÌtOÌlðÔ·@ßèlFCX^Xðí·é©Ç¤©ÌtO
		bool M_Get_Destroy_Instance_Flg(void);

		// CX^X¼ðÔ·@ßèlFCX^XÌ¼Oiconst^j
		const std::string & M_Get_Instance_Name(void);


		//-- í --//

		// íÌÀsð\·é
		void M_Destroy(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_GAME_INSTANCE_BASE_H_FILE



