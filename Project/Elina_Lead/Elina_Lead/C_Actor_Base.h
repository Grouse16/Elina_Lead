////
// Ú×   FAN^[ÌîêÆÈéNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_ACTOR_BASE_H_FILE
#define D_INCLUDE_GUARD_C_ACTOR_BASE_H_FILE


//  t@CÐç«  //
#include "C_Game_Instance_Base.h"


//  l[Xy[X  //

// Q[ÌAN^[ÌîêNXðÄÑo·½ßÌ¼O
namespace GAME::INSTANCE::ACTOR::BASE
{
	//  NX  //

	// AN^[ÌîêÆÈéNX
	class C_Actor_Base : public GAME::INSTANCE::BASE::C_Game_Instance_Base
	{
		//== vCx[g ==// 
	private:

		//  Ïé¾  //
		bool m_draw_flg = true;			// `æ·é©Ç¤©ÌtO
		bool m_after_draw_flg = false;	// Êí`æãÉ`æ·é©Ç¤©ÌtO


		//== pubN ==//
	public:

		//  Ö  //

		//-- ú»ÆI¹ --//

		// RXgN^
		C_Actor_Base(void);

		// fXgN^
		virtual ~C_Actor_Base(void);


		//-- Dæx --//

		// AN^[ÌDæxðÔ·@ßèlFAN^[ÌDæx
		virtual int M_Get_Priority(void) = 0;


		//-- XV --//

		// AN^[ÌXVðs¤
		virtual void M_Actor_Update(void) = 0;


		//-- `æ --//

		// AN^[`æ·é
		virtual void M_Actor_Draw(void) = 0;

		// Êí`æãÉAN^[ð`æ·é
		virtual void M_Actor_After_Draw(void) = 0;


		//-- Zb^ --//

		// AN^[ðÊí`æÅ`æ·é©Ç¤©ÌtOðZbg·é@øFtrueÌÍ`æ·éAfalseÌÍ`æµÈ¢
		void M_Set_Draw_Flg(bool);

		// Êí`æãÉAN^[ð`æ·é©Ç¤©ÌtOðZbg·é@øFtrueÌÍ`æ·éAfalseÌÍ`æµÈ¢
		void M_Set_After_Draw_Flg(bool);

		
		//-- Qb^ --//

		// AN^[ð`æ·é©Ç¤©ÌtOðÔ·@ßèlFtrueÍ`æ·éAfalseÍ`æµÈ¢
		bool M_Get_Draw_Flg(void);

		// Êí`æãÉAN^[ð`æ·é©Ç¤©ÌtOðÔ·@ßèlFtrueÍ`æ·éAfalseÍ`æµÈ¢
		bool M_Get_After_Draw_Flg(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_ACTOR_BASE_H_FILE


