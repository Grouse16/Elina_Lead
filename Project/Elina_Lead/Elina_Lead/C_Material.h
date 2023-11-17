////
// Ú×   F}eAÌNXA`æÌ`æû@ÌÝèðs¤
// à¾   Fobt@ÌÇâ_OÝèÌÇðs¤
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_MATERIAL_H_FILE
#define D_INCLUDE_GUARD_C_MATERIAL_H_FILE


//  t@CÐç«  //
#include <string>
#include <vector>
#include <memory>

#include "C_Rendering_Setting_System.h"
#include "C_Texture_Data_User.h"
#include "C_Constant_Data_System.h"
#include "C_Text_And_File_Manager.h"
#include "C_Shader_Setting_User.h"


//  l[Xy[X  //

// }eAðÄÑo·½ßÌ¼O
namespace ASSET::MATERIAL
{
	//  \¢Ì  //

	// èobt@ðgp·éÛÌîñðÜÆß½\¢Ì
	struct S_Constant_Buffer_Data
	{
		std::unique_ptr<RENDERING::CAPSULE::C_Constant_Buffer_Data_System> data;	// èobt@ðÇ·éVXe

		std::string signature_name = "default";	// èobt@¯Êp¼

		int index = 0;	// èobt@ÌCfbNXÔ
	};


	// eNX`obt@ðgp·éÛÌîñðÜÆß½\¢Ì
	struct S_Texture_Buffer_Data
	{
		std::unique_ptr<ASSET::TEXTURE::C_Texture_Data_User> data;	// eNX`ðgp·é½ßÌVXe

		std::string signature_name = "default";	// eNX`Xbg¯Êp¼

		int index = 0;	// eNX`ÌCfbNXÔ
	};


	//  NX  //
	
	// }eAÌNXA`æÌ`æû@ÌÝèðs¤
	class C_Material
	{
		//== vCx[g ==//
	private:

		//  Ïé¾  //

		// vCx[gÏðÜÆß½\¢Ì
		struct SPr_Variable
		{
			RENDERING::CAPSULE::C_Rendering_Setting_System rendering_setting;	// `æpÝè

			std::vector<S_Constant_Buffer_Data> constant_data_list;	// gp·éèobt@ÌXg
		
			std::vector<S_Texture_Buffer_Data> texture_data_list;	// gp·éeNX`ÌXg

			ASSET::SHADER::C_Shader_Setting_User shader_setting_data;	// VF[_[Ýèpîñ

		} mpr_variable;	// vCx[gÏðÄÑo·½ßÌ¼O

		
		//  Ö  //

		//-- uhÝè --//

		// ÇÌuh[hðÝè·é©ðwè³ê½¶ñ©çÁèµÄÔ·@øFuh[hð¦·¶ñ@ßèlFÁèµ½uh[h
		RENDERING::INFORM::BLEND::E_BLEND_MODE M_Get_Blend_Mode_By_Text(std::string);

		// ÇÌFÌìðÝè·é©ðwè³ê½¶ñ©çÁèµÄÔ·@øFFÌìð¦·¶ñ@ßèlFÁèµ½FÌì
		RENDERING::INFORM::BLEND::E_BLEND_OPTION M_Get_Blend_Option_By_Text(std::string);

		// ÇÌ«Þ`®ðÝè·é©ðwè³ê½¶ñ©çÁèµÄÔ·@øF«Þf[^`®ðð¦·¶ñ@ßèlF«Þf[^Ì`®
		RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT M_Get_Blend_Write_Format_By_Text(std::string);

		// ÇÌ«ÞFÌíÞðÝè·é©ðwè³ê½¶ñ©çÁèµÄÔ·@øF«ÞFÌíÞð¦·¶ñ@ßèlF«ÞFÌíÞ
		RENDERING::INFORM::BLEND::E_RENDERING_DRAW_COLOR M_Get_Blend_Write_Color_By_Text(std::string);


		//-- [xXeV --//

		// ÇÌ[x[hðÝè·é©ðwè³ê½¶ñ©çÁèµÄÔ·@øF[x[hÌíÞð¦·¶ñ@ßèlF[x[hÌíÞ
		RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_MODE M_Get_Depth_Mode_By_Text(std::string);

		// ÇÌ[xIvVðÝè·é©ðwè³ê½¶ñ©çÁèµÄÔ·@øF[xIvVÌíÞð¦·¶ñ@ßèlF[xIvVÌíÞ
		RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE M_Get_Depth_Option_By_Text(std::string);

		// ÇÌXeVðLøÉ·é©ðwè³ê½¶ñ©çÁèµÄÔ·@øFXeVÌLø³øð¦·¶ñ@ßèlFXeVÌLø³ø
		RENDERING::INFORM::DEPTH_STENCIL::E_STENCIL_IS M_Get_Stencil_Is_Active_By_Text(std::string);


		//-- X^CU --//

		// ÇÌ`æ[hðÝè·é©ðwè³ê½¶ñ©çÁèµÄÔ·@øF`æ[hÌíÞð¦·¶ñ@ßèlF`æ[hÌíÞ
		RENDERING::INFORM::RASTERIZER::E_DRAW_MODE M_Get_Draw_Mode_By_Text(std::string);

		// ÇÌÊð\¦·é©ðwè³ê½¶ñ©çÁèµÄÔ·@øFÊ\¦ÌíÞð¦·¶ñ@ßèlFÊÌ\¦[hðÔ·
		RENDERING::INFORM::RASTERIZER::E_MESH_CULLING M_Get_Mesh_Culling_By_Text(std::string);

		// ÇÌÊÌ\ÊÌÝèðgp·é©ðwè³ê½¶ñ©çÁèµÄÔ·@øF\ÊÝèÌíÞð¦·¶ñ@ßèlF\ÊÝèðÔ·
		RENDERING::INFORM::RASTERIZER::E_MESH_FRONT M_Get_Mesh_Front_By_Text(std::string);

		// ÇÌA`GCAVOÌíÞðwè³ê½¶ñ©çÁèµÄÔ·@øFA`GCAVOÌíÞð¦·¶ñ@ßèlFA`GCAVOÌíÞðÔ·
		RENDERING::INFORM::RASTERIZER::E_ANTIALIASING M_Get_Antialiasing_By_Text(std::string);


		//-- [h --//

		// uhÌÝèð}eAîñ©ç[h·é@øFuhÌÝèæ, ÇÝñ¾t@CÌîñ
		void M_Load_Blend_Setting(std::vector<RENDERING::GRAPHICS::CREATE::C_Create_Rendering_Graphics_Setting_Inform::S_Blend_Setting_Create_Data> &, SYSTEM::TEXT::C_Text_And_File_Manager &);

		// [xXeVð}eAîñ©ç[h·é@øF[xXeVÌÝèæ, ÇÝñ¾t@CÌîñ
		void M_Load_Depth_Stencil_Setting(RENDERING::GRAPHICS::CREATE::C_Create_Rendering_Graphics_Setting_Inform::S_Depth_Stencil_Create_Data &, SYSTEM::TEXT::C_Text_And_File_Manager &);

		// X^CUð}eAîñ©ç[h·é@øFX^CUÌÝèæ, ÇÝñ¾t@CÌîñ
		void M_Load_Rasterizer_Setting(RENDERING::GRAPHICS::CREATE::C_Create_Rendering_Graphics_Setting_Inform::S_Rasterizer_Create_Data &, SYSTEM::TEXT::C_Text_And_File_Manager &);

		// »Ì¼Ýèð[h·é@øFÝèæÌ_OÝè¶¬pîñ, ÇÝñ¾t@CÌîñ
		void M_Load_Another_Setting(RENDERING::GRAPHICS::CREATE::C_Create_Rendering_Graphics_Setting_Inform &, SYSTEM::TEXT::C_Text_And_File_Manager &);


		//-- ¶¬ --//

		// XbgÌîñðZbg·é@øFÝè·éXbg¯ÊpÌîñ
		void M_Create_Resource_By_Signature_Inform(const ASSET::SHADER::S_All_Shader_Resource_Signatures & );

		// _Oîñð¶¬·é@øF»ÝÌt@C¶ñ@ßèlF¬÷ÌÝtrue
		bool M_Create_Rendering_Setting(SYSTEM::TEXT::C_Text_And_File_Manager &);

		//== pubN ==//
	public:

		//  Ö  //

		//-- ú»ÆI¹ --//

		// RXgN^
		C_Material(void);

		// fXgN^
		~C_Material(void);

		// ððúµÄú»·é
		void M_Release(void);


		//-- [h --//

		// }eAf[^ÖÌpX©ç}eAîñð[h@øF}eAf[^ÖÌpX@ßèlF¬÷ÌÝtrue
		bool M_Load_Material_By_Path(std::string);


		//-- `æ --//

		// _OpÌîñðGPUÉÝè·é
		void M_Attach_To_GPU(void);


		//-- Zb^ --//

		//===============//
		// Ú×   Fwè³ê½èobt@Éf[^ðZbg·é
		// ø   Fint ÝèæÌèobt@ÌÔ, int èobt@ÌzñÔ, const C_Constant_Data_Class & èobt@ÉZbg·éf[^
		// ßèl Fvoid
		//===============//
		template<class C_Constant_Data_Class>
		void M_Set_Constant_Data_To_Buffer_By_Index(int in_index, int in_buffer_index, const C_Constant_Data_Class & in_set_data)
		{
			// zñOðwè³ê½ç²¯é
			if (mpr_variable.constant_data_list.size() <= in_index)
			{
				return;
			}


			//  Ïé¾  //
			int constant_data_size = sizeof(C_Constant_Data_Class);	// èf[^ÌoCg


			// f[^ðZbg·é
			mpr_variable.constant_data_list[in_index].data->M_Set_Constant_Data(constant_data_size, in_buffer_index, reinterpret_cast<void * >(&in_set_data));

			return;
		}

		// wè³ê½XbgÉeNX`ð[h·é@øFeNX`XbgÔ, [h·éeNX`¼
		void M_Load_Texture_For_Slot_By_Index(int, std::string);


		//-- Qb^ --//

		// wè³ê½èobt@Çpf[^ÌAhXðÔ·@øFæ¾·éèobt@Çpf[^ÌÔ@ßèlFwè³ê½èobt@îñÌAhXAÈ¯êÎnullptr
		S_Constant_Buffer_Data * M_Get_Constant_Buffer_Data_By_Index(int);

		// wè³ê½eNX`Çpf[^ÌAhXðÔ·@øFæ¾·éeNX`Çpf[^ÌÔ@ßèlFwè³ê½eNX`obt@îñÌAhXAÈ¯êÎnullptr
		S_Texture_Buffer_Data* M_Get_Texture_Data_By_Index(int);

		// wè³ê½¼OÌèobt@Çpf[^ÌAhXðÔ·@øFæ¾·éèobt@Çpf[^Ì¼O@ßèlFwè³ê½èobt@îñÌAhXAÈ¯êÎnullptr
		S_Constant_Buffer_Data * M_Get_Constant_Buffer_Data_By_Name(std::string);

		// wè³ê½¼OÌeNX`Çpf[^ÌAhXðÔ·@øFæ¾·éeNX`Çpf[^Ì¼O@ßèlFwè³ê½eNX`obt@îñÌAhXAÈ¯êÎnullptr
		S_Texture_Buffer_Data * M_Get_Texture_Data_By_Name(std::string);

		// wè³ê½¼OÌèobt@Çpf[^ÌXbgÔðÔ·@øFæ¾·éèobt@Çpf[^Ì¼O@ßèlFint wè³ê½èobt@ÌÔAÈ¯êÎ-1
		int M_Get_Constant_Buffer_Number_By_Name(std::string);

		// wè³ê½¼OÌeNX`Çpf[^ÌXbgÔðÔ·@øFæ¾·éeNX`Çpf[^Ì¼O@ßèlFwè³ê½eNX`ÌÔAÈ¯êÎ-1
		int M_Get_Texture_Number_By_Name(std::string);
	};
}


#endif // !D_INCLUDE_GUARD_C_MATERIAL_H_FILE

