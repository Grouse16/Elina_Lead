////
// Ú×   FGWpÌ_OÝèðÇ·é}l[W[
// à¾   FGWÉgp·é_OpCvCÝèÌú»Ægpð§ä·é
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_Engine_Rendering_Setting_Manager.h"


//  l[Xy[XÌÈª  //
using namespace GAME::DRAW;


//  Ïé¾  //
C_Engine_Rendering_Setting_Manager::SPr_Variable C_Engine_Rendering_Setting_Manager::mpr_variable;	// vCx[gÏðÄÑo·½ßÌ¼O

C_Engine_Rendering_Setting_Manager C_Engine_Rendering_Setting_Manager::m_this;	// ±ÌNXðCX^X»·é½ßÌÏ


//  Ö  //

//== vCx[g ==//

//-- ú» --//

//===============//
// Ú×   FRXgN^AVOg»Ì½ßÉBÁ
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Engine_Rendering_Setting_Manager::C_Engine_Rendering_Setting_Manager(void)
{
	return;
}


//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   Fú»ðs¤
// ø   Fvoid
// ßèl Fbool ¬÷ÌÝtrue
//===============//
bool C_Engine_Rendering_Setting_Manager::M_Init(void)
{
	// SÄÌ`æpÝèðú»·é@// ¸sµ½çG[ðoµÄ²¯é
	for (int loop_x = 0; loop_x < (int)E_RENDERING_SETTING_NUM::e_OBJECT; loop_x++)
	{
		if (mpr_variable.rendering_setting_system_list[loop_x].M_Creat_Pipeline_Setting(loop_x) == false)
		{
			return false;
		}
	}

	// ¬÷
	return true;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Engine_Rendering_Setting_Manager::~C_Engine_Rendering_Setting_Manager(void)
{
	M_Release();

	return;
}


//===============//
// Ú×   FÌðúðs¤
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Engine_Rendering_Setting_Manager::M_Release(void)
{
	for (int loop_x = 0; loop_x < (int)E_RENDERING_SETTING_NUM::e_SUM; loop_x++)
	{
		mpr_variable.rendering_setting_system_list[loop_x].M_Delete();
	}

	return;
}


//-- `æ --//

//===============//
// Ú×   Fwè³ê½_OÝèð`æÉKp·é
// ø   FE_RENDERING_SETTING_NUM _OÝèÌÔ
// ßèl Fvoid
//===============//
void C_Engine_Rendering_Setting_Manager::M_Attach_This_Rendering_Setting(E_RENDERING_SETTING_NUM in_rendering_setting_num)
{
	mpr_variable.rendering_setting_system_list[(int)in_rendering_setting_num].M_Set_Rendering_Setting_For_API();

	return;
}
