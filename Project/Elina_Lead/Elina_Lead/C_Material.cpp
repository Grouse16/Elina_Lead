////
// Ú×   F}eAÌNXA`æÌ`æû@ÌÝèðs¤
// à¾   Fobt@ÌÇâ_OÝèÌÇðs¤
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_Material.h"
#include "C_Rendering_Graphics_API_Base.h"
#include "C_Text_And_File_Manager.h"


// fobOÌÝOVXeðgp
#ifdef _DEBUG
#include "C_Log_System.h"
#endif // _DEBUG


//  l[Xy[XÌÈª  //
using namespace ASSET::MATERIAL;


//  Ö  //

//== vCx[g ==//

//-- Zb^ --//

//===============//
// Ú×   FXbgÌîñðZbg·é
// ø   Fconst S_All_Shader_Resource_Signatures & Ýè·éXbg¯ÊpÌîñ
// ßèl Fbool ¬÷ÌÝtrue
//===============//
void C_Material::M_Creat_Resource_By_Signature_Inform(const ASSET::SHADER::S_All_Shader_Resource_Signatures& in_resource_signature)
{
	//  Ïé¾  //
	int now_index_number = 0;			// »ÝìÌCfbNXXbgÔ
	int now_constant_index_number = 0;	// »ÝìÌèobt@
	int now_texture_index_number = 0;	// »ÝìÌeNX`Xbg


	//-- \[XÌ¶¬ --//

	//-- SVF[_[É¤Ê·éXbgðÝè --//

	// è`ªÌèobt@ðìèAîñðÝè·é
	mpr_variable.constant_data_list.resize(in_resource_signature.all_shader_signature.constant_data.size());
	for (const ASSET::SHADER::S_Resource_Signature& now_constant_inform : in_resource_signature.all_shader_signature.constant_data)
	{
		mpr_variable.constant_data_list[now_constant_index_number].index = now_index_number;
		mpr_variable.constant_data_list[now_constant_index_number].signature_name = now_constant_inform.signature_name;

		now_constant_index_number += 1;
		now_index_number += 1;
	}

	// eNX`ªÌXbgðìé
	mpr_variable.texture_data_list.resize(in_resource_signature.all_shader_signature.texture_data.size());
	for (const ASSET::SHADER::S_Resource_Signature& now_texture_inform : in_resource_signature.all_shader_signature.texture_data)
	{
		mpr_variable.texture_data_list[now_texture_index_number].index = now_index_number;
		mpr_variable.texture_data_list[now_texture_index_number].signature_name = now_texture_inform.signature_name;

		now_texture_index_number += 1;
		now_index_number += 1;
	}

	//-- eVF[_[²ÆÌXbgðÝè --//
	for (int l_now_shader_number = 0; l_now_shader_number < (int)ASSET::SHADER::E_SHADER_KIND::e_ALL; l_now_shader_number++)
	{
		// è`ªÌèobt@ðìèAîñðÝè·é
		mpr_variable.constant_data_list.resize(in_resource_signature.signature_list[l_now_shader_number].constant_data.size());
		for (const ASSET::SHADER::S_Resource_Signature& now_constant_inform : in_resource_signature.signature_list[l_now_shader_number].constant_data)
		{
			mpr_variable.constant_data_list[now_constant_index_number].index = now_index_number;
			mpr_variable.constant_data_list[now_constant_index_number].signature_name = now_constant_inform.signature_name;

			now_constant_index_number += 1;
			now_index_number += 1;
		}

		// eNX`ªÌXbgðìé
		mpr_variable.texture_data_list.resize(in_resource_signature.signature_list[l_now_shader_number].texture_data.size());
		for (const ASSET::SHADER::S_Resource_Signature& now_texture_inform : in_resource_signature.signature_list[l_now_shader_number].texture_data)
		{
			mpr_variable.texture_data_list[now_texture_index_number].index = now_index_number;
			mpr_variable.texture_data_list[now_texture_index_number].signature_name = now_texture_inform.signature_name;

			now_texture_index_number += 1;
			now_index_number += 1;
		}
	}

	return;
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
		now_constant_buffer.data.M_Release();
	}
	mpr_variable.constant_data_list.clear();
	mpr_variable.constant_data_list.shrink_to_fit();

	// eNX`
	for (S_Texture_Buffer_Data & now_texture_buffer : mpr_variable.texture_data_list)
	{
		now_texture_buffer.data.M_Release();
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


	// wè³ê½t@CÌ[hðs¤@G[ÅI¹·é
	if (material_inform_file_data.M_Load_Select_File(in_material_path) == false)
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_GAME_RENDERING, DEBUGGER::LOG::ALL_LOG_NAME::GAME_RENDERING::con_ERROR, "wè³ê½}eAÌt@CÍ èÜ¹ñ");
#endif // _DEBUG

		return false;
	}

	// }eAÉgp·éVF[_[Ýè¼ðª éÊuÖÚ®@¸sÅG[ðoµÄ²¯é
	if (material_inform_file_data.M_Goto_Right_By_Text_In_Front_Sentence("ShaderF") == false)
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_GAME_RENDERING, DEBUGGER::LOG::ALL_LOG_NAME::GAME_RENDERING::con_ERROR, "}eAÌîñÉVF[_[Ìf[^ªÝè³êÄ¢Ü¹ñ");
#endif // _DEBUG

		return false;
	}


	//  Ïé¾  //
	ASSET::SHADER::C_Shader_Setting shader_setting_data;	// VF[_[Ýèpîñ
	

	// VF[_[Ýè¼©çVF[_[ðÝèð[h·é@¸sÅG[ðoµÄ²¯é
	if (shader_setting_data.M_Load_Shaders_Inform_By_Shader_Setting_Name(material_inform_file_data.M_Get_Data_Right_In_Row()) == false)
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_GAME_RENDERING, DEBUGGER::LOG::ALL_LOG_NAME::GAME_RENDERING::con_ERROR, "±ÌVF[_[ÝèÍ³øÅ·B¶ÝµÈ¢t@C©Ýèª³µ­È¢Â\«ª èÜ·");
#endif // _DEBUG

		return false;
	}


	// VF[_[ÝèÌ\[XÌîñðàÆÉ\[Xð¶¬·é
	M_Creat_Resource_By_Signature_Inform(shader_setting_data.M_Get_Resource_Signature());


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
		now_constant_buffer.data.M_Set_Constant_Buffer_To_GPU_By_Index(now_constant_buffer.index);
	}

	// eNX`obt@ðêÂÃÂKp·é
	for (S_Texture_Buffer_Data & now_texture_buffer : mpr_variable.texture_data_list)
	{
		now_texture_buffer.data.M_Texture_Attach_To_Draw(now_texture_buffer.index);
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

	mpr_variable.texture_data_list[in_index].data.M_Load_Texture(in_load_texture_name);

	return;
}


//-- Qb^ --//

//===============//
// Ú×   Fwè³ê½èobt@Çpf[^ðÔ·
// ø   Fint æ¾·éèobt@Çpf[^ÌÔ
// ßèl Fvoid
//===============//
const S_Constant_Buffer_Data & C_Material::M_Get_Constant_Buffer_Data_By_Index(int in_index)
{
	return mpr_variable.constant_data_list[in_index];
}


//===============//
// Ú×   Fwè³ê½eNX`Çpf[^ðÔ·
// ø   Fint æ¾·éeNX`Çpf[^ÌÔ
// ßèl Fvoid
//===============//
const S_Texture_Buffer_Data & C_Material::M_Get_Texture_Data_By_Index(int in_index)
{
	return mpr_variable.texture_data_list[in_index];
}



