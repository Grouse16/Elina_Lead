////
// Ú×   FAj[VfÌ[hð·éVXe
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_ANIMATION_MODEL_LOADER_H_FILE
#define D_INCLUDE_GUARD_C_ANIMATION_MODEL_LOADER_H_FILE


//  t@CÐç«  //
#include "S_Animation_Model_Load_Information.h"


//  l[Xy[X  //

// Aj[Vfð[h·é½ßÌVXeðÄÑo·½ßÌ¼O
namespace ASSET::ANIMATION_MODEL::LOADER
{
	//  NX  //

	// Aj[Vfð[h·éNX
	class C_Animation_Model_Loader
	{
	//== vCx[g ==//
	private:

		//  Ö  //

		//-- ú» --//

		// CX^X»Å«È¢æ¤ÉRXgN^ðBÁµ½ãÅí
		C_Animation_Model_Loader(void) = delete;


	//== pubN ==//
	public:

		//  Ö  //

		//-- [h --//

		// Aj[Vfð[h·é@øF[h·é½ßÌîñÌQÆ@ßèlF¬÷ÌÝtrue
		static bool M_Load_Animation_Model(S_Animation_Model_Load_System &);
	};
}


#endif // !D_INCLUDE_GUARD_C_ANIMATION_MODEL_LOADER_H_FILE

