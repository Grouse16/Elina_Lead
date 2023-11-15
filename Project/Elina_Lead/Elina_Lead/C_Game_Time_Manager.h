////
// Ú×   FGWÌüÍð§ä·éVXe
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_ENGINE_TIME_MANAGER_H_FILE
#define D_INCLUDE_GUARD_C_ENGINE_TIME_MANAGER_H_FILE


//  t@CÐç«  //
#include <memory>


//  l[Xy[X  //

// GWÌÔðÄÑo·½ßÌ¼O
namespace GAME::TIME
{
	//  NX  //

	// GWÌÔð§ä·éVXe
	class C_Game_Time_Manager
	{
		//== vCx[g ==//
	private:

		//  Ïé¾  //

		// vCx[gÏðÜÆß½\¢Ì
		struct SPr_Variable
		{
			unsigned __int64 time_of_seconds_start = 0;	// êbÌnÜèÌÔ
			unsigned __int64 now_timer = 0;				// ¡ÌÔðvª·é
			unsigned __int64 then_timer = 0;			// OñÌÔðvª·é

			float need_spend_time = 0;		// t[[gðÛ·é½ßÉÍ±ÌÔÜÅÒ@·é×«Æ¢¤Ô
			float delta_second = 0.0f;		// OÌXV©çÌoßÔibPÊj
			float one_frame_time = 0.0f;	// Pt[ÔÅoßµÄ¢é×«Ô
			float game_speed = 1.0f;		// Q[ÌXs[h

			int frame_rate = 60;	// t[[g
			int fps = 1;		// êbÔÌt[
			int now_frame = 0;	// »ÝÌt[

			bool flg_constant_frame = false;	// Åèt[É·é©Ç¤©ÌtO

		} mpr_variable;	// vCx[gÏðÄÑo·½ßÌ¼O

		static std::unique_ptr<C_Game_Time_Manager> m_this;	// CX^X»·é½ßÌÀÌiVOgpj


		//  Ö  //

		//-- ú» --//

		// RXgN^
		C_Game_Time_Manager(void);


		//== pubN ==//
	public:

		//  Ö  //

		//-- ú»ÆI¹ --//

		// ÔpVXeð¶¬·é
		static void M_Init(void);

		// fXgN^
		~C_Game_Time_Manager(void);

		// ððú·é
		static void M_Release(void);


		//-- XV --//

		// ÔÌXV
		static void M_Time_Update(void);

		// t[ÌI¹És¤XV
		static void M_Frame_End_Update(void);


		//-- Qb^ --//

		// FPSðÛ·é½ßÌÔªoßµÄ¢é©Ç¤©ðÔ·@ßèlFtrueÈçoßµÄ¢é
		static bool M_Get_FPS_Request_Time_Passed(void);

		// »ÝÌKèt[[gðÔ·@ßèlFKèt[[g
		static int M_Get_Frame_Rate(void);

		// »ÝÌfpsðÔ·@ßèlF»ÝÌfps
		static int M_Get_FPS(void);

		// »ÝÌoßÔðÔ·@ßèlF»ÝÌoßÔ
		static float M_Get_Delta_Second(void);

		// Q[àÅÌoßÔðÔ·@ßèlFQ[ÅÌoßÔ
		static float M_Get_Game_Second(void);

		// Q[àÔÌXs[hðÔ·@ßèlFQ[àÔÌXs[h
		static float M_Get_Game_Speed(void);


		//-- Zb^ --//

		// t[[gðZbg·é@øFÝè·ét[[g
		static void M_Set_Frame_Rate(int);

		// Q[àÔÌXs[hðZbg·é@øFZbg·éQ[àÔÌXs[h
		static void M_Set_Game_Speed(float);
	};
}


#endif // !D_INCLUDE_GUARD_C_ENGINE_TIME_H_FILE
