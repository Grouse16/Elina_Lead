////
// Ú×   FAj[VÌvZð§ä·éNX
// à¾   F{[}gNXÉÎ·éAj[VÌìðs¤
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_Animation_Calculation_System.h"


//  l[Xy[XÌÈª  //
using namespace ASSET::ANIMATION::CALCULATOR;


//  Ö  //

//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Animation_Calculation_System::C_Animation_Calculation_System(void)
{
	mpr_variable.animation_algorithm.reset(new ASSET::ANIMATION::CALCULATOR::ALGORITHM::C_Animation_Calculate_Algorithm_Base);

	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Animation_Calculation_System::~C_Animation_Calculation_System(void)
{
	return;
}


//-- Aj[V --//

//===============//
// Ú×   Fwè³ê½zñÉ{[}gNXzñÌf[^ðZbg·é
// ø   Fvector<XMFLOAT4X4> & ÝèæÌ{[}gNXzñÌf[^
// ßèl Fvoid
//===============//
void C_Animation_Calculation_System::M_Get_Bone_Matrix(std::vector<DirectX::XMFLOAT4X4> & out_bone_matrix_list)
{


	return;
}
