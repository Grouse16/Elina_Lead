////
// Ú×   F}eAÌNXA`æÌ`æû@ÌÝèðs¤
// à¾   Fobt@ÌÇâ_OÝèÌÇðs¤
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_Material.h"
#include "C_Rendering_Graphics_API_Base.h"


// fobOÌÝOVXeðgp
#ifdef _DEBUG
#include "C_Log_System.h"
#endif // _DEBUG


//  l[Xy[XÌÈª  //
using namespace ASSET::MATERIAL;


//  Ö  //

//== vCx[g ==//

//-- uhÝè --//

//===============//
// Ú×   FÇÌuh[hðÝè·é©ðwè³ê½¶ñ©çÁèµÄÔ·
// ø   Fstring uh[hð¦·¶ñ
// ßèl FE_BLEND_MODE Áèµ½uh[h
//===============//
RENDERING::INFORM::BLEND::E_BLEND_MODE C_Material::M_Get_Blend_Mode_By_Text(std::string in_blend_mode_signature)
{
	// ÊíÍAFð»ÌÜÜg¤
	if (in_blend_mode_signature == "NORMAL")
	{
		return RENDERING::INFORM::BLEND::E_BLEND_MODE::e_NORMAL;
	}

	// Êí`æÅ¿lÌÝPÅÅè
	if (in_blend_mode_signature == "NORMAL_NOT_ALPHA")
	{
		return RENDERING::INFORM::BLEND::E_BLEND_MODE::e_NORMAL_NOT_ALPHA;
	}

	// oÍ³ê½Fð¸Zû®Ågp·é
	if (in_blend_mode_signature == "INVERT")
	{
		return RENDERING::INFORM::BLEND::E_BLEND_MODE::e_INVERT;
	}

	// oÍ³ê½Fð¸Zû®Ågp·éªA¿lÍPÅÅè
	if (in_blend_mode_signature == "INVERT_NOT_ALPHA")
	{
		return RENDERING::INFORM::BLEND::E_BLEND_MODE::e_INVERT_NOT_ALPHA;
	}

	// ÇêÉàÄÍÜçÈ©Á½çúlðÔ·
	return RENDERING::INFORM::BLEND::E_BLEND_MODE::e_NORMAL;
}


//===============//
// Ú×   FÇÌFÌìðÝè·é©ðwè³ê½¶ñ©çÁèµÄÔ·
// ø   Fstring FÌìð¦·¶ñ
// ßèl FE_BLEND_OPTION Áèµ½FÌì
//===============//
RENDERING::INFORM::BLEND::E_BLEND_OPTION C_Material::M_Get_Blend_Option_By_Text(std::string in_blend_option_signature)
{
	// ÁZ·é
	if (in_blend_option_signature == "ADD")
	{
		return RENDERING::INFORM::BLEND::E_BLEND_OPTION::e_ADD;
	}

	// ¸Z·é
	if (in_blend_option_signature == "SUB")
	{
		RENDERING::INFORM::BLEND::E_BLEND_OPTION::e_SUB;
	}

	// sNZVF[_[ÌoÍFð¸Z·é
	if (in_blend_option_signature == "SUB_PIX")
	{
		RENDERING::INFORM::BLEND::E_BLEND_OPTION::e_SUB_PIX;
	}

	// sNZVF[_[Æ_OæðärµAÅålðoÍ·é
	if (in_blend_option_signature == "MAX")
	{
		RENDERING::INFORM::BLEND::E_BLEND_OPTION::e_MAX;
	}

	// sNZVF[_[Æ_OæðärµAÅ¬lðoÍ·é
	if (in_blend_option_signature == "MIN")
	{
		RENDERING::INFORM::BLEND::E_BLEND_OPTION::e_MIN;
	}

	// ÇêÉàÄÍÜçÈ©Á½çúlðÔ·
	return RENDERING::INFORM::BLEND::E_BLEND_OPTION::e_ADD;
}


//===============//
// Ú×   FÇÌ«Þ`®ðÝè·é©ðwè³ê½¶ñ©çÁèµÄÔ·
// ø   Fstring «Þf[^`®ðð¦·¶ñ
// ßèl FE_RENDERING_DRAW_FORMAT «Þf[^Ì`®
//===============//
RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT C_Material::M_Get_Blend_Write_Format_By_Text(std::string in_format_signature)
{
	// SoCgÌFLOAT
	if (in_format_signature == "BYTE_4_FLOAT")
	{
		return RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT::e_BYTE_4_FLOAT;
	}

	// 2oCgÌFLOAT
	if (in_format_signature == "BYTE_2_FLOAT")
	{
		return RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT::e_BYTE_2_FLOAT;
	}

	// SoCgÌUINT
	if (in_format_signature == "BYTE_4_UINT")
	{
		return RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT::e_BYTE_4_UINT;
	}

	// QoCgÌUINT
	if (in_format_signature == "BYTE_2_UINT")
	{
		return RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT::e_BYTE_2_UINT;
	}

	// PoCgÌUINT
	if (in_format_signature == "BYTE_1_UINT")
	{
		return RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT::e_BYTE_1_UINT;
	}

	return RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT::e_BYTE_2_FLOAT;
}


//===============//
// Ú×   FÇÌ«ÞFÌíÞðÝè·é©ðwè³ê½¶ñ©çÁèµÄÔ·
// ø   Fstring «ÞFÌíÞð¦·¶ñ
// ßèl FE_RENDERING_DRAW_COLOR «ÞFÌíÞ
//===============//
RENDERING::INFORM::BLEND::E_RENDERING_DRAW_COLOR C_Material::M_Get_Blend_Write_Color_By_Text(std::string in_color_signature)
{
	// SFÆà é
	if (in_color_signature == "RGBA")
	{
		return RENDERING::INFORM::BLEND::E_RENDERING_DRAW_COLOR::e_RGBA;
	}

	// ÔÆÎFªÌÝ
	if (in_color_signature == "RG")
	{
		return RENDERING::INFORM::BLEND::E_RENDERING_DRAW_COLOR::e_RG;
	}

	// ÔFªÌÝ
	if (in_color_signature == "R")
	{
		return RENDERING::INFORM::BLEND::E_RENDERING_DRAW_COLOR::e_R;
	}

	return RENDERING::INFORM::BLEND::E_RENDERING_DRAW_COLOR::e_RGBA;
}


//-- [xXeV --//

//===============//
// Ú×   FÇÌ[x[hðÝè·é©ðwè³ê½¶ñ©çÁèµÄÔ·
// ø   Fstring [x[hÌíÞð¦·¶ñ
// ßèl FE_DEPTH_MODE [x[hÌíÞ
//===============//
RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_MODE C_Material::M_Get_Depth_Mode_By_Text(std::string in_depth_mode_signature)
{
	// [xf[^ªOÌªÉÌÝ«Þ
	if (in_depth_mode_signature == "ZERO")
	{
		return RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_MODE::e_ZERO;
	}

	// í[xf[^ð«Þ
	if (in_depth_mode_signature == "ONE")
	{
		return RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_MODE::e_ONE;
	}

	// [xÈµAÜ½ÍîñªÈ¢Æ«Í³ø
	return RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_MODE::e_NO;
}


//===============//
// Ú×   FÇÌ[xIvVðÝè·é©ðwè³ê½¶ñ©çÁèµÄÔ·
// ø   Fstring [xIvVÌíÞð¦·¶ñ
// ßèl FE_DEPTH_WRITE_RULE [xIvVÌíÞ
//===============//
RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE C_Material::M_Get_Depth_Option_By_Text(std::string in_depth_option_signature)
{
	// í«Þ
	if (in_depth_option_signature == "ALWAYS")
	{
		return RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE::e_ALWAYS;
	}

	// ³Ìlð´¦éÌÝ«Þ
	if (in_depth_option_signature == "GREATER")
	{
		return RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE::e_GREATER;
	}

	// ³Ìl¢ÌÌÝ«Þ
	if (in_depth_option_signature == "LESS")
	{
		return RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE::e_LESS;
	}

	// ³ÌlÈãÌÌÝ«Þ
	if (in_depth_option_signature == "GREATER_EQUAL")
	{
		return RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE::e_GREATERE_EQUAL;
	}

	// ³ÌlÈºÌÌÝ«Þ
	if (in_depth_option_signature == "LESS_EQUAL")
	{
		return RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE::e_LESS_EQUAL;
	}

	// ¯¶lÌÌÝ«Þ
	if (in_depth_option_signature == "EQUAL")
	{
		return RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE::e_EQUAL;
	}

	// ³ÌlÆµ­È¢ÌÝ«Þ
	if (in_depth_option_signature == "NOT_EQUAL")
	{
		return RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE::e_NOT_EQUAL;
	}

	// îñªÈ¢©½àµÈ¢Æ«
	return RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE::e_DONT;
}


//===============//
// Ú×   FÇÌXeVðLøÉ·é©ðwè³ê½¶ñ©çÁèµÄÔ·
// ø   Fstring XeVÌLø³øð¦·¶ñ
// ßèl FE_STENCIL_IS XeVÌLø³ø
//===============//
RENDERING::INFORM::DEPTH_STENCIL::E_STENCIL_IS C_Material::M_Get_Stencil_Is_Active_By_Text(std::string in_stencil_signature)
{
	// XeVLø
	if (in_stencil_signature == "ACTIVE")
	{
		return RENDERING::INFORM::DEPTH_STENCIL::E_STENCIL_IS::e_ACTIVE;
	}

	// XeV³øAÜ½ÍîñªÈ¢Æ«
	return RENDERING::INFORM::DEPTH_STENCIL::E_STENCIL_IS::e_NO_ACTIVE;
}


//-- X^CU --//

//===============//
// Ú×   FÇÌ`æ[hðÝè·é©ðwè³ê½¶ñ©çÁèµÄÔ·
// ø   Fstring `æ[hÌíÞð¦·¶ñ
// ßèl FE_DRAW_MODE `æ[hÌíÞ
//===============//
RENDERING::INFORM::RASTERIZER::E_DRAW_MODE C_Material::M_Get_Draw_Mode_By_Text(std::string in_draw_mode_signature)
{
	// C[t[\¦
	if (in_draw_mode_signature == "WIRE_FRAME")
	{
		return RENDERING::INFORM::RASTERIZER::E_DRAW_MODE::e_WIRE_FRAME;
	}

	// Êí\¦ðs¤AÜ½ÍîñªÈ¢Æ«
	return RENDERING::INFORM::RASTERIZER::E_DRAW_MODE::e_NORMAL;
}


//===============//
// Ú×   FÇÌÊð\¦·é©ðwè³ê½¶ñ©çÁèµÄÔ·
// ø   Fstring Ê\¦ÌíÞð¦·¶ñ
// ßèl FE_MESH_CULLING ÊÌ\¦[hðÔ·
//===============//
RENDERING::INFORM::RASTERIZER::E_MESH_CULLING C_Material::M_Get_Mesh_Culling_By_Text(std::string in_culling_signature)
{
	// \ÊÌÝ`æ
	if (in_culling_signature == "FRONT")
	{
		RENDERING::INFORM::RASTERIZER::E_MESH_CULLING::e_FRONT;
	}

	//  ÊÌÝ`æ
	if (in_culling_signature == "BACK")
	{
		RENDERING::INFORM::RASTERIZER::E_MESH_CULLING::e_BACK;
	}

	// ÁÉwèªÈ¢ÈçSÄÌÊð`æ
	return RENDERING::INFORM::RASTERIZER::E_MESH_CULLING::e_ALWAYS;
}


//===============//
// Ú×   FÇÌÊÌ\ÊÌÝèðgp·é©ðwè³ê½¶ñ©çÁèµÄÔ·
// ø   Fstring \ÊÝèÌíÞð¦·¶ñ
// ßèl FE_MESH_FRONT \ÊÝèðÔ·
//===============//
RENDERING::INFORM::RASTERIZER::E_MESH_FRONT ASSET::MATERIAL::C_Material::M_Get_Mesh_Front_By_Text(std::string in_mesh_front_signature)
{
	// ½vñè
	if (in_mesh_front_signature == "ANTI_CLOCK_WISE")
	{
		return RENDERING::INFORM::RASTERIZER::E_MESH_FRONT::e_ANTI_CLOCK_WISE;
	}

	// vñèAÜ½ÍîñªÈ¢Æ«
	return RENDERING::INFORM::RASTERIZER::E_MESH_FRONT::e_CLOCK_WISE;
}


//===============//
// Ú×   FÇÌA`GCAVOÌíÞðwè³ê½¶ñ©çÁèµÄÔ·
// ø   Fstring A`GCAVOÌíÞð¦·¶ñ
// ßèl FE_ANTIALIASING A`GCAVOÌíÞðÔ·
//===============//
RENDERING::INFORM::RASTERIZER::E_ANTIALIASING C_Material::M_Get_Antialiasing_By_Text(std::string in_antialiasing_signature)
{
	// ¿lÅA`GCAVOð©¯é
	if (in_antialiasing_signature == "ALPHA")
	{
		return RENDERING::INFORM::RASTERIZER::E_ANTIALIASING::e_ALPHA;
	}

	// sNZîÅA`GCAVOð©¯é
	if (in_antialiasing_signature == "PIXEL")
	{
		return RENDERING::INFORM::RASTERIZER::E_ANTIALIASING::e_PIXEL;
	}

	// ÓÌâÔÅA`GCAVOð©¯é
	if (in_antialiasing_signature == "LINE")
	{
		return RENDERING::INFORM::RASTERIZER::E_ANTIALIASING::e_LINE;
	}

	// A`GCAVOðµÈ¢AÜ½ÍîñªÈ¢Æ«
	return RENDERING::INFORM::RASTERIZER::E_ANTIALIASING::e_DONT;
}


//-- [h --//

//===============//
// Ú×   FuhÌÝèð}eAîñ©ç[h·é
// ø   Fvector<C_Create_Rendering_Graphics_Setting_Inform::S_Blend_Setting_Create_Data> & uhÌÝèæ, C_Text_And_File_Manager & ÇÝñ¾t@CÌîñ
// ßèl Fvoid
//===============//
void C_Material::M_Load_Blend_Setting(std::vector<RENDERING::GRAPHICS::CREATE::C_Create_Rendering_Graphics_Setting_Inform::S_Blend_Setting_Create_Data> & in_blend_setting_list, SYSTEM::TEXT::C_Text_And_File_Manager & in_file_data)
{
	//  è  //
	const int con_blend_setting_max = 8;	// uhÝèð¶¬Å«éãÀl


	// îñÌÅÖÚ®
	in_file_data.M_Goto_Sentence_Start();


	// uhÌîñªcÁÄ¢éÔA8ÂÉÈéÜÅÍÝèµ±¯é
	for (int l_slot_num = 0; l_slot_num < con_blend_setting_max; l_slot_num++)
	{
		// uhÝèÌ»ÝÌÔÜÅÚ®AÈ¯êÎI¹
		if (in_file_data.M_Goto_Left_By_Text_In_Front_Row("BLEND" + std::to_string(l_slot_num + 1) + ":") == false)
		{
			return;
		}


		// uhÝèo^pÌzñðg£
		in_blend_setting_list.resize(l_slot_num + 1);


		// uh[hðæ¾
		in_file_data.M_Move_Next_Raw();
		in_blend_setting_list[l_slot_num].blend_mode = M_Get_Blend_Mode_By_Text(in_file_data.M_Get_Data_Now_Row());

		// uhÌìðæ¾
		in_file_data.M_Move_Next_Raw();
		in_blend_setting_list[l_slot_num].blend_option = M_Get_Blend_Option_By_Text(in_file_data.M_Get_Data_Now_Row());

		// _[^[QbgÖÌ«Ý`®ðæ¾
		in_file_data.M_Move_Next_Raw();
		in_blend_setting_list[l_slot_num].draw_format = M_Get_Blend_Write_Format_By_Text(in_file_data.M_Get_Data_Now_Row());

		// _[^[QbgÖÌ«ÞFÌíÞðæ¾
		in_file_data.M_Move_Next_Raw();
		in_blend_setting_list[l_slot_num].draw_color = M_Get_Blend_Write_Color_By_Text(in_file_data.M_Get_Data_Now_Row());
	}

	return;
}


//===============//
// Ú×   F[xXeVð}eAîñ©ç[h·é
// ø   FC_Create_Rendering_Graphics_Setting_Inform::S_Depth_Stencil_Create_Data & [xXeVÌÝèæ, C_Text_And_File_Manager & ÇÝñ¾t@CÌîñ
// ßèl Fvoid
//===============//
void C_Material::M_Load_Depth_Stencil_Setting(RENDERING::GRAPHICS::CREATE::C_Create_Rendering_Graphics_Setting_Inform::S_Depth_Stencil_Create_Data & in_depth_stencil_inform, SYSTEM::TEXT::C_Text_And_File_Manager & in_file_data)
{
	// [xXeVÌÊuÖÚ®AÈ¯êÎúlÌÜÜ
	in_file_data.M_Goto_Sentence_Start();
	if (in_file_data.M_Goto_Right_By_Text_In_Front_Row("DEPTH") == false)
	{
		return;
	}


	// [xÌ«Ý[hðÝè
	in_file_data.M_Move_Next_Raw();
	in_depth_stencil_inform.mode = M_Get_Depth_Mode_By_Text(in_file_data.M_Get_Data_Now_Row());

	// [xIvVðÝè
	in_file_data.M_Move_Next_Raw();
	in_depth_stencil_inform.write_rule = M_Get_Depth_Option_By_Text(in_file_data.M_Get_Data_Now_Row());

	// XeVÌLø³øðÝè
	in_file_data.M_Move_Next_Raw();
	in_depth_stencil_inform.stencil_activate = M_Get_Stencil_Is_Active_By_Text(in_file_data.M_Get_Data_Now_Row());

	return;
}


//===============//
// Ú×   FX^CUð}eAîñ©ç[h·é
// ø   FC_Create_Rendering_Graphics_Setting_Inform::S_Rasterizer_Create_Data & X^CUÌÝèæ, C_Text_And_File_Manager & ÇÝñ¾t@CÌîñ
// ßèl Fvoid
//===============//
void C_Material::M_Load_Rasterizer_Setting(RENDERING::GRAPHICS::CREATE::C_Create_Rendering_Graphics_Setting_Inform::S_Rasterizer_Create_Data & in_rasterizer_setting, SYSTEM::TEXT::C_Text_And_File_Manager & in_file_data)
{
	// X^CUîñÌÊuÉs­AÈ¯êÎúlÌÜÜ
	in_file_data.M_Goto_Start_Row();
	if (in_file_data.M_Goto_Right_By_Text_In_Front_Row("RASTERIZER") == false)
	{
		return;
	}


	// `æ[hÌÝè
	in_file_data.M_Move_Next_Raw();
	in_rasterizer_setting.draw_mode = M_Get_Draw_Mode_By_Text(in_file_data.M_Get_Data_Now_Row());

	// c·bVÌü«ðßé
	in_file_data.M_Move_Next_Raw();
	in_rasterizer_setting.mesh_culling = M_Get_Mesh_Culling_By_Text(in_file_data.M_Get_Data_Now_Row());

	// bVÌ\ÊÝèðßé
	in_file_data.M_Move_Next_Raw();
	in_rasterizer_setting.mesh_front = M_Get_Mesh_Front_By_Text(in_file_data.M_Get_Data_Now_Row());

	// [xoCAXðßé
	in_file_data.M_Move_Next_Raw();
	in_rasterizer_setting.depth_value.depth_bias = in_file_data.M_Get_Number();

	// bVÌ\ÊÝèðßé
	in_file_data.M_Move_Next_Raw();
	in_rasterizer_setting.depth_value.depth_max = in_file_data.M_Get_Float_Double_Number();

	// bVÌ\ÊÝèðßé
	in_file_data.M_Move_Next_Raw();
	in_rasterizer_setting.depth_value.depth_slope = in_file_data.M_Get_Float_Double_Number();

	// A`GCAVOÝèðßé
	in_file_data.M_Move_Next_Raw();
	in_rasterizer_setting.antialiasing = M_Get_Antialiasing_By_Text(in_file_data.M_Get_Data_Now_Row());

	// ÛçIÈX^CYðßé
	in_file_data.M_Move_Next_Raw();
	in_rasterizer_setting.flg_conservative = in_file_data.M_Get_Data_Now_Row() == "true";

	return;
}


//===============//
// Ú×   F»Ì¼Ýèð[h·é
// ø   FC_Create_Rendering_Graphics_Setting_Inform & ÝèæÌ_OÝè¶¬pîñ, C_Text_And_File_Manager & ÇÝñ¾t@CÌîñ
// ßèl Fvoid
//===============//
void C_Material::M_Load_Another_Setting(RENDERING::GRAPHICS::CREATE::C_Create_Rendering_Graphics_Setting_Inform & in_creat_rendering_graphics_setting, SYSTEM::TEXT::C_Text_And_File_Manager & in_file_data)
{
	// TvOÝèÜÅÚ®·éAÈ¯êÎúlÌÜÜ
	in_file_data.M_Goto_Start_Row();
	if (in_file_data.M_Goto_Right_By_Text_In_Front_Row("SAMPLING") == false)
	{
		return;
	}


	// TvOñðæ¾
	in_file_data.M_Move_Next_Raw();
	in_creat_rendering_graphics_setting.sampling_setting.sampling_count = in_file_data.M_Get_Number();

	// TvOi¿ðæ¾
	in_file_data.M_Move_Next_Raw();
	in_creat_rendering_graphics_setting.sampling_setting.sampling_quality = in_file_data.M_Get_Number();

	return;
}


//-- ¶¬ --//

//===============//
// Ú×   FXbgÌîñðZbg·é
// ø   Fconst S_All_Shader_Resource_Signatures & Ýè·éXbg¯ÊpÌîñ
// ßèl Fbool ¬÷ÌÝtrue
//===============//
void C_Material::M_Create_Resource_By_Signature_Inform(const ASSET::SHADER::S_All_Shader_Resource_Signatures& in_resource_signature)
{
	//  Ïé¾  //
	int now_index_number = 0;			// »ÝìÌCfbNXXbgÔ
	int now_constant_index_number = 0;	// »ÝìÌèobt@
	int now_texture_index_number = 0;	// »ÝìÌeNX`Xbg


	//-- \[XÌ¶¬ --//

	//-- SVF[_[É¤Ê·éXbgðÝè --//

	// è`ªÌèobt@pÌîñðìèAîñðÝè·é
	mpr_variable.constant_data_list.resize(in_resource_signature.all_shader_signature.constant_data.size());
	for (const ASSET::SHADER::S_Constant_Resource_Signature & now_constant_inform : in_resource_signature.all_shader_signature.constant_data)
	{
		// èobt@ð¶¬
		mpr_variable.constant_data_list[now_constant_index_number].data.reset(new RENDERING::CAPSULE::C_Constant_Buffer_Data_System());

		// èobt@Æf[^ð¶¬
		if (now_constant_inform.data_create_flg)
		{
			mpr_variable.constant_data_list[now_constant_index_number].data->M_Create_Constant_Buffer_And_Data(now_constant_inform.array_sum);
		}

		// èobt@ÌÝ¶¬
		else
		{
			mpr_variable.constant_data_list[now_constant_index_number].data->M_Create_Only_Constant_Buffer(now_constant_inform.array_sum);
		}

		// èobt@ÌA^b`æÌVF[_[ðÝè
		mpr_variable.constant_data_list[now_constant_index_number].data->M_Set_Attach_Shader_Kind(ASSET::SHADER::E_SHADER_KIND::e_ALL);

		// ÝèæÌGPUÅÌèobt@XbgÔ
		mpr_variable.constant_data_list[now_constant_index_number].index = now_index_number;

		// èobt@¯Ê¼
		mpr_variable.constant_data_list[now_constant_index_number].signature_name = now_constant_inform.signature_name;
		mpr_variable.constant_data_list[now_constant_index_number].data->M_Set_Data_Signature_Name(now_constant_inform.signature_name);

		// Ìèobt@XbgÆÝèæÌXbgÔðÝè
		now_constant_index_number += 1;
		now_index_number += 1;
	}

	// eNX`ªÌXbgðìé
	mpr_variable.texture_data_list.resize(in_resource_signature.all_shader_signature.texture_data.size());
	for (const ASSET::SHADER::S_Texture_Resource_Signature & now_texture_inform : in_resource_signature.all_shader_signature.texture_data)
	{
		// eNX`Ìf[^ð¶¬·é
		mpr_variable.texture_data_list[now_constant_index_number].data.reset(new ASSET::TEXTURE::C_Texture_Data_User());


		// ú©çeNX`È¢±Æð¦³êÄ¢éÈç½àµÈ¢
		if (now_texture_inform.initialized_texture_name == "NOTHING")
		{

		}

		// IWiwèª³êÄ¢½çÅIWiÌeNX`ð¶¬·é
		else if (now_texture_inform.initialized_texture_name == "ORIGINAL")
		{
			mpr_variable.texture_data_list[now_constant_index_number].data->M_Create_Original_Texture_Data();
		}

		// ú©çeNX`ª éÈç»êð[h·é
		else
		{
			mpr_variable.texture_data_list[now_constant_index_number].data->M_Load_Texture(now_texture_inform.initialized_texture_name);
		}


		// eNX`obt@ÌA^b`æÌVF[_[ðÝè
		mpr_variable.texture_data_list[now_constant_index_number].data->M_Set_Texture_Shader_Kind(ASSET::SHADER::E_SHADER_KIND::e_ALL);

		// ÝèæÌGPUÅÌeNX`obt@XbgÔ
		mpr_variable.texture_data_list[now_constant_index_number].index = now_index_number;

		// eNX`obt@¯Ê¼
		mpr_variable.texture_data_list[now_constant_index_number].signature_name = now_texture_inform.signature_name;
		mpr_variable.texture_data_list[now_constant_index_number].data->M_Set_Texture_Signature(now_texture_inform.signature_name);

		// ÌeNX`XbgÆÝèæÌXbgÔðÝè
		now_texture_index_number += 1;
		now_index_number += 1;
	}

	//-- eVF[_[²ÆÌXbgðÝè --//
	for (int l_now_shader_number = 0; l_now_shader_number < (int)ASSET::SHADER::E_SHADER_KIND::e_ALL; l_now_shader_number++)
	{
		// è`ªÌèobt@pÌîñðìèAîñðÝè·é
		mpr_variable.constant_data_list.resize(in_resource_signature.signature_list[l_now_shader_number].constant_data.size());
		for (const ASSET::SHADER::S_Constant_Resource_Signature & now_constant_inform : in_resource_signature.signature_list[l_now_shader_number].constant_data)
		{
			// èobt@ð¶¬
			mpr_variable.constant_data_list[now_constant_index_number].data.reset(new RENDERING::CAPSULE::C_Constant_Buffer_Data_System());

			// èobt@Æf[^ð¶¬
			if (now_constant_inform.data_create_flg)
			{
				mpr_variable.constant_data_list[now_constant_index_number].data->M_Create_Constant_Buffer_And_Data(now_constant_inform.array_sum);
			}

			// èobt@ÌÝ¶¬
			else
			{
				mpr_variable.constant_data_list[now_constant_index_number].data->M_Create_Only_Constant_Buffer(now_constant_inform.array_sum);
			}

			// èobt@ÌA^b`æÌVF[_[ðÝè
			mpr_variable.constant_data_list[now_constant_index_number].data->M_Set_Attach_Shader_Kind((ASSET::SHADER::E_SHADER_KIND)l_now_shader_number);

			// ÝèæÌGPUÅÌèobt@XbgÔ
			mpr_variable.constant_data_list[now_constant_index_number].index = now_index_number;

			// èobt@¯Ê¼
			mpr_variable.constant_data_list[now_constant_index_number].signature_name = now_constant_inform.signature_name;

			// Ìèobt@XbgÆÝèæÌXbgÔðÝè
			now_constant_index_number += 1;
			now_index_number += 1;
		}

		// eNX`ªÌXbgðìé
		mpr_variable.texture_data_list.resize(in_resource_signature.signature_list[l_now_shader_number].texture_data.size());
		for (const ASSET::SHADER::S_Texture_Resource_Signature & now_texture_inform : in_resource_signature.signature_list[l_now_shader_number].texture_data)
		{
			// eNX`Ìf[^ð¶¬·é
			mpr_variable.texture_data_list[now_constant_index_number].data.reset(new ASSET::TEXTURE::C_Texture_Data_User());


			// ú©çeNX`È¢±Æð¦³êÄ¢éÈç½àµÈ¢
			if (now_texture_inform.initialized_texture_name == "NOTHING")
			{

			}

			// IWiwèª³êÄ¢½çÅIWiÌeNX`ð¶¬·é
			else if (now_texture_inform.initialized_texture_name == "ORIGINAL")
			{
				mpr_variable.texture_data_list[now_constant_index_number].data->M_Create_Original_Texture_Data();
			}

			// ú©çeNX`ª éÈç»êð[h·é
			else
			{
				mpr_variable.texture_data_list[now_constant_index_number].data->M_Load_Texture(now_texture_inform.initialized_texture_name);
			}


			// eNX`obt@ÌA^b`æÌVF[_[ðÝè
			mpr_variable.texture_data_list[now_constant_index_number].data->M_Set_Texture_Shader_Kind((ASSET::SHADER::E_SHADER_KIND)l_now_shader_number);

			// ÝèæÌGPUÅÌeNX`obt@XbgÔ
			mpr_variable.texture_data_list[now_constant_index_number].index = now_index_number;

			// eNX`obt@¯Ê¼
			mpr_variable.texture_data_list[now_constant_index_number].signature_name = now_texture_inform.signature_name;
			mpr_variable.texture_data_list[now_constant_index_number].data->M_Set_Texture_Signature(now_texture_inform.signature_name);

			// ÌeNX`XbgÆÝèæÌXbgÔðÝè
			now_texture_index_number += 1;
			now_index_number += 1;
		}
	}

	return;
}


//===============//
// Ú×   F_Oîñð¶¬·é
// ø   FC_Text_And_File_Manager & »ÝÌt@C¶ñ
// ßèl Fbool ¬÷ÌÝtrue
//===============//
bool C_Material::M_Create_Rendering_Setting(SYSTEM::TEXT::C_Text_And_File_Manager & in_file_text)
{
	//  Ïé¾  //
	RENDERING::GRAPHICS::CREATE::C_Create_Rendering_Graphics_Setting_Inform create_rendering_setting_inform;	// _OÝèÌ¶¬pÌîñ


	// VF[_[ÝèðZbg
	create_rendering_setting_inform.shader_setting = mpr_variable.shader_setting_data.M_Get_Shader_Setting();

	// uhÌÝèðÇÝÞ
	M_Load_Blend_Setting(create_rendering_setting_inform.blend_setting, in_file_text);

	// XeVÌÝèðÇÝÞ
	M_Load_Depth_Stencil_Setting(create_rendering_setting_inform.depth_stencil_data, in_file_text);

	// X^CUÌÝèðÇÝÞ
	M_Load_Rasterizer_Setting(create_rendering_setting_inform.rasterizer_data, in_file_text);

	// »Ì¼ÌÝèðÇÝÞ
	M_Load_Another_Setting(create_rendering_setting_inform, in_file_text);


	// _OÝèð¶¬·é
	return mpr_variable.rendering_setting.M_Create_Pipeline_Setting(create_rendering_setting_inform);
}


//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Material::C_Material(void)
{
	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Material::~C_Material(void)
{
	M_Release();

	return;
}


//===============//
// Ú×   Fðú
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Material::M_Release(void)
{
	// `æpÝè
	mpr_variable.rendering_setting.M_Delete();

	// èobt@
	for (S_Constant_Buffer_Data & now_constant_buffer : mpr_variable.constant_data_list)
	{
		if(now_constant_buffer.data)
		{
			now_constant_buffer.data->M_Release();
			now_constant_buffer.data.reset();
		}
	}
	mpr_variable.constant_data_list.clear();
	mpr_variable.constant_data_list.shrink_to_fit();

	// eNX`
	for (S_Texture_Buffer_Data & now_texture_buffer : mpr_variable.texture_data_list)
	{
		if (now_texture_buffer.data)
		{
			now_texture_buffer.data->M_Release();
			now_texture_buffer.data.reset();
		}
	}
	mpr_variable.texture_data_list.clear();
	mpr_variable.texture_data_list.shrink_to_fit();

	// VF[_[Ýè
	mpr_variable.shader_setting_data.M_Release();
	
	return;
}


//-- [h --//

//===============//
// Ú×   F}eAf[^ÖÌpX©ç}eAîñð[h
// ø   Fstring }eAf[^ÖÌpX
// ßèl Fbool ¬÷ÌÝtrue
//===============//
bool C_Material::M_Load_Material_By_Path(std::string in_material_path)
{
	//  Ïé¾  //
	SYSTEM::TEXT::C_Text_And_File_Manager material_inform_file_data;	// }eAîñÌt@CÌf[^


	// wè³ê½t@CÌ[hðs¤@G[ÅI¹·é
	if (material_inform_file_data.M_Load_Select_File(in_material_path) == false)
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_GAME_RENDERING, DEBUGGER::LOG::ALL_LOG_NAME::GAME_RENDERING::con_ERROR, "wè³ê½}eAÌt@CÍ èÜ¹ñ");
#endif // _DEBUG

		return false;
	}

	
	// »ÝÌf[^ðú»·é
	M_Release();


	// }eAÉgp·éVF[_[Ýè¼ðª éÊuÖÚ®@¸sÅG[ðoµÄ²¯é
	if (material_inform_file_data.M_Goto_Right_By_Text_In_Front_Row("ShaderF") == false)
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_GAME_RENDERING, DEBUGGER::LOG::ALL_LOG_NAME::GAME_RENDERING::con_ERROR, "}eAÌîñÉVF[_[Ìf[^ªÝè³êÄ¢Ü¹ñ");
#endif // _DEBUG

		return false;
	}
	

	// VF[_[Ýè¼©çVF[_[ðÝèð[h·é@¸sÅG[ðoµÄ²¯é
	mpr_variable.shader_setting_data.M_Load_Shader_Setting(material_inform_file_data.M_Get_Data_Right_In_Row());
	if (mpr_variable.shader_setting_data.M_Get_Shader_Setting() == nullptr)
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_GAME_RENDERING, DEBUGGER::LOG::ALL_LOG_NAME::GAME_RENDERING::con_ERROR, "±ÌVF[_[ÝèÍ³øÅ·B¶ÝµÈ¢t@C©Ýèª³µ­È¢Â\«ª èÜ·");
#endif // _DEBUG

		return false;
	}


	// VF[_[ÝèÌ\[XÌîñðàÆÉ\[Xð¶¬·é
	M_Create_Resource_By_Signature_Inform(mpr_variable.shader_setting_data.M_Get_Shader_Setting()->M_Get_Resource_Signature());


	// _OÝèð¶¬·éA¸sÅG[ðoµÄ²¯é
	if (M_Create_Rendering_Setting(material_inform_file_data) == false)
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_GAME_RENDERING, DEBUGGER::LOG::ALL_LOG_NAME::GAME_RENDERING::con_ERROR, "_OÝèÌ¶¬É¸sµÜµ½");
#endif // _DEBUG

		return false;
	}


	// fobOÍ¶¬É¬÷µ½±ÆðL^·é
#ifdef _DEBUG
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_GAME_RENDERING, DEBUGGER::LOG::ALL_LOG_NAME::GAME_RENDERING::con_INIT, "}eAÌ¶¬É¬÷µÜµ½");
#endif // _DEBUG
	return true;
}


//-- `æ --//

//===============//
// Ú×   F_OpÌîñðGPUÉÝè·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Material::M_Attach_To_GPU(void)
{
	// _OÝèðKp
	mpr_variable.rendering_setting.M_Set_Rendering_Setting_For_API();

	// èobt@ðêÂÃÂKp·é
	for (S_Constant_Buffer_Data & now_constant_buffer : mpr_variable.constant_data_list)
	{
		now_constant_buffer.data->M_Set_Constant_Buffer_To_GPU_By_Index(now_constant_buffer.index);
	}

	// eNX`obt@ðêÂÃÂKp·é
	for (S_Texture_Buffer_Data & now_texture_buffer : mpr_variable.texture_data_list)
	{
		now_texture_buffer.data->M_Texture_Attach_To_Draw_By_Index(now_texture_buffer.index);
	}

	return;
}


//-- Zb^ --//

//===============//
// Ú×   Fwè³ê½XbgÉeNX`ð[h·é
// ø   Fint eNX`XbgÔ, string [h·éeNX`¼
// ßèl Fvoid
//===============//
void C_Material::M_Load_Texture_For_Slot_By_Index(int in_index, std::string in_load_texture_name)
{
	// zñOðwè³ê½ç²¯é
	if (mpr_variable.texture_data_list.size() <= in_index)
	{
		return;
	}

	mpr_variable.texture_data_list[in_index].data->M_Load_Texture(in_load_texture_name);

	return;
}


//-- Qb^ --//

//===============//
// Ú×   Fwè³ê½èobt@Çpf[^ÌAhXðÔ·
// ø   Fint æ¾·éèobt@Çpf[^ÌÔ
// ßèl FS_Constant_Buffer_Data * wè³ê½èobt@îñÌAhXAÈ¯êÎnullptr
//===============//
S_Constant_Buffer_Data * C_Material::M_Get_Constant_Buffer_Data_By_Index(int in_index)
{
	// ÍÍOðwè³ê½çnullptrÅ©Â©çÈ©Á½±Æð¦·
	if (0 <= in_index || in_index < mpr_variable.constant_data_list.size())
	{
		return nullptr;
	}

	return &mpr_variable.constant_data_list[in_index];
}


//===============//
// Ú×   Fwè³ê½eNX`Çpf[^ÌAhXðÔ·
// ø   Fint æ¾·éeNX`Çpf[^ÌÔ
// ßèl FS_Texture_Buffer_Data * wè³ê½eNX`obt@îñÌAhXAÈ¯êÎnullptr
//===============//
S_Texture_Buffer_Data * C_Material::M_Get_Texture_Data_By_Index(int in_index)
{
	// ÍÍOðwè³ê½çnullptrÅ©Â©çÈ©Á½±Æð¦·
	if (0 <= in_index || in_index < mpr_variable.texture_data_list.size())
	{
		return nullptr;
	}

	return &mpr_variable.texture_data_list[in_index];
}


//===============//
// Ú×   Fwè³ê½¼OÌèobt@Çpf[^ÌAhXðÔ·
// ø   Fstring æ¾·éèobt@Çpf[^Ì¼O
// ßèl FS_Constant_Buffer_Data * wè³ê½èobt@îñÌAhXAÈ¯êÎnullptr
//===============//
S_Constant_Buffer_Data * C_Material::M_Get_Constant_Buffer_Data_By_Name(std::string in_constant_buffer_name)
{
	// êv·é¼OðTõµA êÎ»ÌAhXðÔ·
	for (S_Constant_Buffer_Data & constant_data_inform : mpr_variable.constant_data_list)
	{
		if (constant_data_inform.signature_name == in_constant_buffer_name)
		{
			return &constant_data_inform;
		}
	}

	// ©Â©çÈ©Á½
	return nullptr;
}


//===============//
// Ú×   Fwè³ê½¼OÌeNX`obt@Çpf[^ÌAhXðÔ·
// ø   Fstring æ¾·éeNX`obt@Çpf[^Ì¼O
// ßèl FS_Texture_Buffer_Data * wè³ê½eNX`obt@îñÌAhXAÈ¯êÎnullptr
//===============//
S_Texture_Buffer_Data * C_Material::M_Get_Texture_Data_By_Name(std::string in_texture_buffer_name)
{
	// êv·é¼OðTõµA êÎ»ÌAhXðÔ·
	for (S_Texture_Buffer_Data & texture_data_inform : mpr_variable.texture_data_list)
	{
		if (texture_data_inform.signature_name == in_texture_buffer_name)
		{
			return &texture_data_inform;
		}
	}

	// ©Â©çÈ©Á½
	return nullptr;
}


//===============//
// Ú×   Fwè³ê½¼OÌèÇpf[^ÌXbgÔðÔ·
// ø   Fstring æ¾·éèobt@Çpf[^Ì¼O
// ßèl Fint wè³ê½èobt@ÌÔAÈ¯êÎ-1
//===============//
int C_Material::M_Get_Constant_Buffer_Number_By_Name(std::string in_constant_buffer_name)
{
	//  Ïé¾  //
	int constant_sum = mpr_variable.constant_data_list.size();	// èobt@


	// êv·é¼OðTõµA êÎ»ÌAhXðÔ·
	for (int l_constant_num = 0; l_constant_num < constant_sum; l_constant_num++)
	{
		if (mpr_variable.constant_data_list[l_constant_num].signature_name == in_constant_buffer_name)
		{
			return l_constant_num;
		}
	}

	// ©Â©çÈ©Á½
	return -1;
}


//===============//
// Ú×   Fwè³ê½¼OÌeNX`obt@Çpf[^ÌXbgÔðÔ·
// ø   Fstring æ¾·éeNX`obt@Çpf[^Ì¼O
// ßèl Fint wè³ê½eNX`ÌÔAÈ¯êÎ-1
//===============//
int C_Material::M_Get_Texture_Number_By_Name(std::string in_texture_buffer_name)
{
	//  Ïé¾  //
	int texture_sum = mpr_variable.texture_data_list.size();	// eNX`


	// êv·é¼OðTõµA êÎ»ÌAhXðÔ·
	for (int l_texture_num = 0; l_texture_num < texture_sum; l_texture_num++)
	{
		if (mpr_variable.texture_data_list[l_texture_num].signature_name == in_texture_buffer_name)
		{
			return l_texture_num;
		}
	}

	// ©Â©çÈ©Á½
	return -1;
}



