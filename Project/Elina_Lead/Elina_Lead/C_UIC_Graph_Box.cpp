////
// Ú×   Fæð\¦·éUIÌNXiUIÌR|[lgj
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_UIC_Graph_Box.h"
#include "E_BOX_VERTEX_SETTING.h"


//  l[Xy[XÌÈª  //
using namespace GAME::UI_COMPONENT;


//  Ö  //

//-- ú»ÆI¹ --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_UIC_Text_Box::C_UIC_Text_Box(void)
{
	// }eAÌ[h
	mpr_variable.material.M_Load_Material("UI_Material");

	// ¸_f[^Ì¶¬
	mpr_variable.vertex_system.M_Create_Vertex_And_Index_Data_And_Buffer((int)DATA::VERTEX::SETTING::E_BOX_VERTEX_SETTING::e_SUM, (int)DATA::VERTEX::SETTING::E_BOX_INDEX_SETTING::e_SUM);
	
	
	//  Ïé¾@ //
	std::vector<unsigned int> & index_list = mpr_variable.vertex_system.M_Get_Index_Data();	// CfbNXf[^ÌXg


	// CfbNXf[^ðZbg·é
	index_list[0] = (unsigned int)DATA::VERTEX::SETTING::E_BOX_INDEX_SETTING::e_INDEX_1;
	index_list[0] = (unsigned int)DATA::VERTEX::SETTING::E_BOX_INDEX_SETTING::e_INDEX_2;
	index_list[0] = (unsigned int)DATA::VERTEX::SETTING::E_BOX_INDEX_SETTING::e_INDEX_3;
	index_list[0] = (unsigned int)DATA::VERTEX::SETTING::E_BOX_INDEX_SETTING::e_INDEX_4;
	index_list[0] = (unsigned int)DATA::VERTEX::SETTING::E_BOX_INDEX_SETTING::e_INDEX_5;
	index_list[0] = (unsigned int)DATA::VERTEX::SETTING::E_BOX_INDEX_SETTING::e_INDEX_6;

	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_UIC_Text_Box::~C_UIC_Text_Box(void)
{
	mpr_variable.vertex_system.M_Release();
	mpr_variable.material.M_Release();

	return;
}


//-- [h --//

//===============//
// Ú×   Fwè³ê½¼OÌeNX`ð[h·é
// ø   Fstring [h·éeNX`¼
// ßèl FÈµ
//===============//
void C_UIC_Text_Box::M_Load_Texture(std::string in_load_texture_name)
{
	mpr_variable.material.M_Get_Material_Address()->M_Load_Texture_For_Slot_By_Index(0, in_load_texture_name);

	return;
}


//-- XV --//

//===============//
// Ú×   FXVðs¤
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_UIC_Text_Box::M_Update(void)
{
	return;
}


//-- `æ --//

//===============//
// Ú×   F`æðs¤
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_UIC_Text_Box::M_Draw(void)
{
	// }eAð`æÉKp
	mpr_variable.material.M_Material_Attach_To_Draw();

	// ¸_ð`æ·é
	mpr_variable.vertex_system.M_Draw_All_Vertex();

	return;
}


//-- ÀW --//

//===============//
// Ú×   FUIÌÀWðZbg·é
// ø   FS_Rect lp`i¶ºªOCEãªPj
// ßèl Fvoid
//===============//
void C_UIC_Text_Box::M_Set_UI_Position(DATA::RECTSETTING::S_Rect in_set_rect)
{
	//  Ïé¾  //
	std::vector<DATA::VERTEX::S_UI_Vertex> & vertex_list = mpr_variable.vertex_system.M_Get_Vertex_Data();	// ¸_f[^ÌXg


	// ¶ã¸_ÌÀWðZbg
	vertex_list[(int)DATA::VERTEX::SETTING::E_BOX_VERTEX_SETTING::e_LEFT_TOP].position.x = in_set_rect.left_x;
	vertex_list[(int)DATA::VERTEX::SETTING::E_BOX_VERTEX_SETTING::e_LEFT_TOP].position.y = in_set_rect.top_y;

	// Eã¸_ÌÀWðZbg
	vertex_list[(int)DATA::VERTEX::SETTING::E_BOX_VERTEX_SETTING::e_RIGHT_TOP].position.x = in_set_rect.right_x;
	vertex_list[(int)DATA::VERTEX::SETTING::E_BOX_VERTEX_SETTING::e_RIGHT_TOP].position.y = in_set_rect.top_y;

	// ¶º¸_ÌÀWðZbg
	vertex_list[(int)DATA::VERTEX::SETTING::E_BOX_VERTEX_SETTING::e_LEFT_BOTTOM].position.x = in_set_rect.left_x;
	vertex_list[(int)DATA::VERTEX::SETTING::E_BOX_VERTEX_SETTING::e_LEFT_BOTTOM].position.y = in_set_rect.bottom_y;

	// Eº¸_ÌÀWðZbg
	vertex_list[(int)DATA::VERTEX::SETTING::E_BOX_VERTEX_SETTING::e_RIGHT_BOTTOM].position.x = in_set_rect.right_x;
	vertex_list[(int)DATA::VERTEX::SETTING::E_BOX_VERTEX_SETTING::e_RIGHT_BOTTOM].position.y = in_set_rect.bottom_y;

	// ¸_obt@ÉZbg
	mpr_variable.vertex_system.M_Vertex_Data_To_Buffer();

	return;
}


//-- J[ --//

//===============//
// Ú×   FFðÝè·é
// ø   FC_Color F
// ßèl Fvoid
//===============//
void C_UIC_Text_Box::M_Set_Color(DATA::COLOR::C_Color in_set_color)
{
	//  Ïé¾  //
	std::vector<DATA::VERTEX::S_UI_Vertex> & vertex_list = mpr_variable.vertex_system.M_Get_Vertex_Data();	// ¸_f[^ÌXg


	// ¸_ÌFðÝèµÄ¸_obt@ÉZbg
	for (DATA::VERTEX::S_UI_Vertex & now_vertex : vertex_list)
	{
		now_vertex.color = in_set_color;
	}
	mpr_variable.vertex_system.M_Vertex_Data_To_Buffer();

	return;
}
