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
#include "C_Texture_Data_System.h"
#include "C_Constant_Data_System.h"


//  l[Xy[X  //

// }eAðÄÑo·½ßÌ¼O
namespace ASSET::MATERIAL
{
	//  NX  //
	
	// }eAÌNXA`æÌ`æû@ÌÝèðs¤
	class C_Material
	{
		//== vCx[g ==//
	private:

		//  \¢Ì  //

		// èobt@ðgp·éÛÌîñðÜÆß½\¢Ì
		struct S_Constant_Buffer_Data
		{
			RENDERING::CAPSULE::C_Constant_Buffer_Data_System data;	// èobt@ðÇ·éVXe

			int index = 0;	// èobt@ÌCfbNXÔ
		};


		// eNX`obt@ðgp·éÛÌîñðÜÆß½\¢Ì
		struct S_Texture_Buffer_Data
		{
			RENDERING::CAPSULE::C_Texture_Data_System * data = nullptr;	// eNX`obt@ðÇ·éVXe

			int index = 0;	// èobt@ÌCfbNXÔ
		};


		//  Ïé¾  //

		// vCx[gÏðÜÆß½\¢Ì
		struct SPr_Variable
		{
			RENDERING::CAPSULE::C_Rendering_Setting_System rendering_setting;	// `æpÝè

			SHADER::C_Shader_Setting shader_setting_data;	// VF[_[Ýèpîñ

			std::vector<S_Constant_Buffer_Data> constant_data_list;	// gp·éèobt@ÌXg
		
			std::vector<S_Texture_Buffer_Data> texture_data_list;	// gp·éeNX`ÌXg

		} mpr_variable;	// vCx[gÏðÄÑo·½ßÌ¼O


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
	};
}


#endif // !D_INCLUDE_GUARD_C_MATERIAL_H_FILE

