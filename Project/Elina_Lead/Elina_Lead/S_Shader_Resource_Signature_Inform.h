////
// Ú×   FVF[_[Ì¯Ê¼ðÇ·é½ßÌ\¢ÌÌé¾
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_S_SHADER_SIGNATURE_INFORM
#define D_INCLUDE_GUARD_S_SHADER_SIGNATURE_INFORM


//  t@CÐç«  //
#include <vector>
#include <string>

#include "E_Shader_Kind.h"


//  l[Xy[X  //

// VF[_[pÌè`ðÄÑo·½ßÌ¼O
namespace ASSET::SHADER
{
	//  \¢Ì  //

	// èobt@Ì¯ÊpÌîñÌ\¢Ì
	struct S_Constant_Resource_Signature
	{
		std::string signature_name = "";	// ¯ÊpÌ¼O

		int array_sum = 0;	// zñ

		bool data_create_flg = false;	// f[^ð¶¬·é©Ç¤©ÌtO
	};

	// eNX`obt@Ì¯ÊpÌîñÌ\¢Ì
	struct S_Texture_Resource_Signature
	{
		std::string signature_name = "";	// ¯ÊpÌ¼O
		std::string initialized_texture_name = "";	// gp·éeNX`¼
	};

	// Tv[ÝèÌîñÌ\¢Ì
	struct S_Sampler_Resource_Signature
	{
		std::string uv_setting = "";	// UVÌgpû@
	};


	// VF[_[Ì\[XÌ¯Ê¼ðÇ·é½ßÌ\¢Ì
	struct S_Shader_Resource_Signature_Inform
	{
		std::vector<S_Constant_Resource_Signature> constant_data;	// èobt@f[^¯ÊpÌîñ

		std::vector<S_Texture_Resource_Signature> texture_data;	// eNX`f[^Ì¯ÊpÌîñ

		std::vector<S_Sampler_Resource_Signature> sampler_data;	// Tv[
	};


	// ·×ÄÌVF[_[Ì\[XÌ¯Ê¼ðÜÆßé½ßÌ\¢Ì
	struct S_All_Shader_Resource_Signatures
	{
		S_Shader_Resource_Signature_Inform all_shader_signature;	// SÄÌVF[_[É¤Ê·é\[X¯Ê¼

		S_Shader_Resource_Signature_Inform signature_list[(int)E_SHADER_KIND::e_ALL];	// VF[_[Ì\[X
	};
}


#endif // !D_INCLUDE_GUARD_S_SHADER_SIGNATURE_INFORM

