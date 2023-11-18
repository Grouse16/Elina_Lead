////
// Ú×   F|XgGtFNgÌ`æ§äVXe
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_Post_Effect_Draw_Manager.h"


//  l[Xy[XÌÈª  //
using namespace GAME::INSTANCE::POST_EFFECT::DRAW_MANAGER;


//  X^eBbNÏ  //
C_Post_Effect_Draw_Manager C_Post_Effect_Draw_Manager::m_this;


//  Ö  //

//== vCx[g ==//

//-- ú» --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Post_Effect_Draw_Manager::C_Post_Effect_Draw_Manager(void)
{
	return;
}


//== pubN ==//

//-- I¹ --//

//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Post_Effect_Draw_Manager::~C_Post_Effect_Draw_Manager(void)
{
	return;
}


//-- Zb^ --//

//===============//
// Ú×   FUIÌOÉ`æ·é|XgGtFNgð`æXgÉÇÁ·é
// ø   FC_Post_Effect_Base * ÇÁ·é|XgGtFNg
// ßèl Fvoid
//===============//
void C_Post_Effect_Draw_Manager::M_Set_Post_Effect_Before_UI(GAME::INSTANCE::POST_EFFECT::BASE::C_Post_Effect_Base * in_add_post_effect)
{
	// UI`æOÉ`æµÈ¢|XgGtFNgÍ`æXgÉÇÁµÈ¢
	if (in_add_post_effect->M_Get_Flg_Post_Effect_Before_UI_Draw() == false)
	{
		return;
	}


	//  Ïé¾  //
	int set_post_effect_slot = m_this.mpr_variable.post_effect_before_ui_list.size();	// |XgGtFNgÌÇÁæXbg


	// |XgGtFNgð`æXgÉÇÁ
	m_this.mpr_variable.post_effect_before_ui_list.resize(set_post_effect_slot + 1);
	m_this.mpr_variable.post_effect_before_ui_list[set_post_effect_slot] = in_add_post_effect;

	return;
}


//===============//
// Ú×   FUIÌOÉ`æ·é|XgGtFNgð`æXgÉÇÁ·é
// ø   FC_Post_Effect_Base * ÇÁ·é|XgGtFNg
// ßèl Fvoid
//===============//
void C_Post_Effect_Draw_Manager::M_Set_Post_Effect_After_UI(GAME::INSTANCE::POST_EFFECT::BASE::C_Post_Effect_Base* in_add_post_effect)
{
	// UI`æãÉ`æµÈ¢|XgGtFNgÍ`æXgÉÇÁµÈ¢
	if (in_add_post_effect->M_Get_Flg_Post_Effect_After_UI_Draw() == false)
	{
		return;
	}


	//  Ïé¾  //
	int set_post_effect_slot = m_this.mpr_variable.post_effect_after_ui_list.size();	// |XgGtFNgÌÇÁæXbg


	// |XgGtFNgð`æXgÉÇÁ
	m_this.mpr_variable.post_effect_after_ui_list.resize(set_post_effect_slot + 1);
	m_this.mpr_variable.post_effect_after_ui_list[set_post_effect_slot] = in_add_post_effect;

	return;
}


//-- `æ --//

//===============//
// Ú×   FUIÌOÌ|XgGtFNgð`æ·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Post_Effect_Draw_Manager::M_Draw_Post_Effect_Before_UI(void)
{
	for (GAME::INSTANCE::POST_EFFECT::BASE::C_Post_Effect_Base * draw_post_effect : m_this.mpr_variable.post_effect_before_ui_list)
	{
		draw_post_effect->M_Post_Effect_Draw_Before_UI();
	}

	
	// UI`æOÉ`æ·é|XgGtFNgÌXg
	m_this.mpr_variable.post_effect_before_ui_list.clear();
	m_this.mpr_variable.post_effect_before_ui_list.shrink_to_fit();

	return;
}


//===============//
// Ú×   FUIÌãÌ|XgGtFNgð`æ·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Post_Effect_Draw_Manager::M_Draw_Post_Effect_After_UI(void)
{
	for (GAME::INSTANCE::POST_EFFECT::BASE::C_Post_Effect_Base * draw_post_effect : m_this.mpr_variable.post_effect_after_ui_list)
	{
		draw_post_effect->M_Post_Effect_Draw_Before_UI();
	}


	// UI`æãÉ`æ·é|XgGtFNgÌXg
	m_this.mpr_variable.post_effect_after_ui_list.clear();
	m_this.mpr_variable.post_effect_after_ui_list.shrink_to_fit();

	return;
}


