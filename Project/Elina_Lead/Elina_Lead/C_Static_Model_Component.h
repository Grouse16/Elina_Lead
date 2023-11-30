////
// Ú×   FÏ`µÈ¢fÌR|[lgÌVXe
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_STATIC_MODEL_COMPONENT
#define D_INCLUDE_GUARD_C_STATIC_MODEL_COMPONENT


//  t@CÐç«  //
#include <string>

#include "C_Component_Base.h"
#include "C_3D_Model_User.h"
#include "C_Transform.h"
#include "C_Material_User.h"


//  l[Xy[X  //

// fpR|[lgðÄÑo·½ßÌ¼O
namespace GAME::COMPONENT::MODEL_COMPONENT
{
	//  NX  //

	// Ï`µÈ¢fÌR|[lgNX
	class C_Static_Model_Component : public GAME::COMPONENT::BASE::C_Component_Base
	{
		//== vCx[g ==//
	private:

		//  Ïé¾  //

		// vCx[gÏðÜÆß½\¢Ì
		struct SPr_Variable
		{
			ASSET::MODEL::C_3D_Model_User model_system;	// 3DfVXe
			
			MATH::C_Transform transform;	// fÌÝuÊui[JÀWj

		} mpr_variable;	// vCx[gÏðÄÑo·½ßÌ¼O


		//== pubN ==//
	public:

		//  Ö  //

		//-- ú»ÆI¹ --//

		// RXgN^
		C_Static_Model_Component(void);

		// fXgN^
		~C_Static_Model_Component(void);


		//-- [h --//

		// wè³ê½¼OÌfð[h·é@øF[h·éf¼@ßèlF¬÷ÌÝtrue
		bool M_Load_Model_By_Name(std::string);


		//-- Qb^ --//

		// [JÀWÌQÆðÔ·@ßèlF[JÀWÌQÆ
		MATH::C_Transform & M_Get_Transform(void);

		// fVXeÌAhXðÔ·@ßèlFfVXeÌAhX
		ASSET::MODEL::C_3D_Model_User * M_Get_Model_Address(void);


		//-- `æ --//

		// `æðs¤
		void M_Draw();
	};
}


#endif // !D_INCLUDE_GUARD_C_STATIC_MODEL_COMPONENT
