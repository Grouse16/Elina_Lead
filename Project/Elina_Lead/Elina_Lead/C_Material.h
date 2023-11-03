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

#include "C_Rendering_Setting_System.h"
#include "C_Texture_Data_User.h"
#include "C_Constant_Data_System.h"
#include "C_Text_And_File_Manager.h"
#include "C_Shader_Setting.h"


//  l[Xy[X  //

// }eAðÄÑo·½ßÌ¼O
namespace ASSET::MATERIAL
{
	//  \¢Ì  //

	// èobt@ðgp·éÛÌîñðÜÆß½\¢Ì
	struct S_Constant_Buffer_Data
	{
		RENDERING::CAPSULE::C_Constant_Buffer_Data_System data;	// èobt@ðÇ·éVXe

		std::string signature_name = "default";	// èobt@¯Êp¼

		int index = 0;	// èobt@ÌCfbNXÔ
	};


	// eNX`obt@ðgp·éÛÌîñðÜÆß½\¢Ì
	struct S_Texture_Buffer_Data
	{
		ASSET::TEXTURE::C_Texture_Data_User data;	// eNX`ðgp·é½ßÌVXe

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

		} mpr_variable;	// vCx[gÏðÄÑo·½ßÌ¼O

		
		//  Ö  //

		//-- ¶¬ --//

		// XbgÌîñðZbg·é@øFÝè·éXbg¯ÊpÌîñ
		void M_Create_Resource_By_Signature_Inform(const ASSET::SHADER::S_All_Shader_Resource_Signatures & );

		// _Oîñð¶¬·é@øF»ÝÌt@C¶ñ, VF[_[ÌÝèpÌîñ@ßèlF¬÷ÌÝtrue
		bool M_Create_Rendering_Setting(SYSTEM::TEXT::C_Text_And_File_Manager &, ASSET::SHADER::C_Shader_Setting & );


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
			mpr_variable.constant_data_list[in_index].data.M_Set_Constant_Data(constant_data_size, in_buffer_index, reinterpret_cast<void * >(&in_set_data));

			return;
		}

		// wè³ê½XbgÉeNX`ð[h·é@øFeNX`XbgÔ, [h·éeNX`¼
		void M_Load_Texture_For_Slot_By_Index(int, std::string);


		//-- Qb^ --//

		// wè³ê½èobt@Çpf[^ðÔ·@øFæ¾·éèobt@Çpf[^ÌÔ
		const S_Constant_Buffer_Data & M_Get_Constant_Buffer_Data_By_Index(int);

		// wè³ê½eNX`Çpf[^ðÔ·@øFæ¾·éeNX`Çpf[^ÌÔ
		const S_Texture_Buffer_Data & M_Get_Texture_Data_By_Index(int);
	};
}


#endif // !D_INCLUDE_GUARD_C_MATERIAL_H_FILE

