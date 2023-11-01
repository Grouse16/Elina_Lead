////
// Ú×   F}eAÌNXA`æÌ`æû@ÌÝèðs¤
// à¾   Fobt@ÌÇâ_OÝèÌÇðs¤
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_Log_System.h"
#include "C_Material.h"
#include "C_Rendering_Graphics_API_Base.h"
#include "C_Text_And_File_Manager.h"


//  l[Xy[XÌÈª  //
using namespace ASSET::MATERIAL;


//  Ö  //

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
		now_constant_buffer.data.M_Release();
	}
	mpr_variable.constant_data_list.clear();
	mpr_variable.constant_data_list.shrink_to_fit();

	// eNX`
	for (S_Texture_Buffer_Data & now_texture_buffer : mpr_variable.texture_data_list)
	{
		now_texture_buffer.data->M_Delete();
	}
	mpr_variable.texture_data_list.clear();
	mpr_variable.texture_data_list.shrink_to_fit();

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

	mpr_variable.constant_data_list.size();	// 


	// wè³ê½t@CÌ[hðs¤@G[ÅI¹·é
	if (material_inform_file_data.M_Load_Select_File(in_material_path) == false)
	{
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT, "wè³ê½}eAÌt@CÍ èÜ¹ñ");

		return false;
	}

	// }eAÉgp·éVF[_[Ýè¼ðæ¾·é
	material_inform_file_data.M_Goto_Right_By_Text_In_Front_Sentence("ShaderF");
	mpr_variable.shader_setting_data.M_Load_Shaders_Inform_By_Shader_Setting_Name(material_inform_file_data.M_Get_Data_Right_In_Row());


	// èobt@ðÝè·é


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
		now_constant_buffer.data.M_Set_Constant_Buffer_To_GPU_By_Index(now_constant_buffer.index);
	}

	// eNX`obt@ðêÂÃÂKp·é
	for (S_Texture_Buffer_Data & now_texture_buffer : mpr_variable.texture_data_list)
	{
		now_texture_buffer.data->M_Attach_To_Shader_By_Index(now_texture_buffer.index);
	}

	return;
}



