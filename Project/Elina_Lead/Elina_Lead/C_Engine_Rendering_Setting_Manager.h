////
// Ú×   FGWpÌ_OÝèðÇ·é}l[W[
// à¾   FGWÉgp·é_OpCvCÝèÌú»Ægpð§ä·é
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_ENGINE_RENDERING_SETTING_MANAGER
#define D_INCLUDE_GUARD_C_ENGINE_RENDERING_SETTING_MANAGER


//  t@CÐç«  //
#include "C_Rendering_Setting_System_For_Engine.h"


//  l[Xy[X  //

// GWpÌ`æpVXeðÄÑo·½ßÌ¼O
namespace GAME::DRAW
{
	//  ñ  //

	// gp·é_OÝèÌÔðwè·é
	enum class E_RENDERING_SETTING_NUM
	{
		e_UI,		// UIpÌ_OÝè
		e_OBJECT,	// IuWFNgpÌ_OÝè

		e_SUM,	// _OÝè
	};


	//  NX  //

	// GWpÌ_OÝèðÇ·é}l[W[ÌNX
	class C_Engine_Rendering_Setting_Manager
	{
	//== vCx[g ==//
	private:

		//  Ïé¾  //
		
		// vCx[gÏðÜÆß½\¢Ì
		struct SPr_Variable
		{
			RENDERING::CAPSULE::C_Rendering_Setting_System_For_Engine rendering_setting_system_list[(int)E_RENDERING_SETTING_NUM::e_SUM];	// _OÝèVXeÌXg
		};

		static SPr_Variable mpr_variable;	// vCx[gÏðÄÑo·½ßÌ¼O

		static C_Engine_Rendering_Setting_Manager m_this;	// ±ÌNXðCX^X»·é½ßÌÏ


		//  Ö  //

		//-- ú» --//

		// RXgN^AVOg»Ì½ßÉBÁ
		C_Engine_Rendering_Setting_Manager(void);


	//== pubN ==//
	public:

		//  Ö  //

		//-- ú»ÆI¹ --//

		// ú»ðs¤@ßèlF¬÷ÌêÍAtrue
		static bool M_Init(void);

		// fXgN^
		~C_Engine_Rendering_Setting_Manager(void);

		// Ìðú
		static void M_Release(void);


		//-- `æ --//

		// wè³ê½_OÝèð`æÉKp·é@øF_OÝèÌÔ
		static void M_Attach_This_Rendering_Setting(E_RENDERING_SETTING_NUM);
	};
}


#endif // !D_INCLUDE_GUARD_C_ENGINE_RENDERING_SETTING_MANAGER

