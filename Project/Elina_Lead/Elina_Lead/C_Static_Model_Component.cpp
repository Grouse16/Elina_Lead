////
// Ú×   FÏ`µÈ¢fÌR|[lgÌVXe
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_Static_Model_Component.h"


//  l[Xy[XÌÈª  //
using namespace GAME::COMPONENT::MODEL_COMPONENT;


//  Ö  //

//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Static_Model_Component::C_Static_Model_Component(void)
{
	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Static_Model_Component::~C_Static_Model_Component(void)
{
	return;
}


//-- [h --//

//===============//
// Ú×   Fwè³ê½¼OÌfð[h·é
// ø   Fstring [h·éf¼
// ßèl Fbool ¬÷ÌÝtrue
//===============//
bool C_Static_Model_Component::M_Load_Model_By_Name(std::string in_load_model_name)
{
	return mpr_variable.model_system.M_Load_3D_Model(in_load_model_name);
}


//-- Qb^ --//

//===============//
// Ú×   F[JÀWÌQÆðÔ·
// ø   Fvoid
// ßèl FC_Transform & [JÀWÌQÆ
//===============//
MATH::C_Transform & C_Static_Model_Component::M_Get_Transform(void)
{
	return mpr_variable.transform;
}


//===============//
// Ú×   FfVXeÌAhXðÔ·
// ø   Fvoid
// ßèl FC_3D_Model_User * fVXeÌAhX
//===============//
ASSET::MODEL::C_3D_Model_User * C_Static_Model_Component::M_Get_Model_Address(void)
{
	return mpr_variable.model_system.get();
}
