////
// Ú×   FAj[VÌvZð§ä·éNX
// à¾   F{[}gNXÉÎ·éAj[VÌìðs¤
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_Animation_Calculation_System.h"
#include "C_Bone_Data.h"
#include "C_Animation_Algorithm_No_Animation.h"


//  l[Xy[XÌÈª  //
using namespace ASSET::ANIMATION::CALCULATOR;


//  Ö  //

//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   FRXgN^
// ø   Fconst vector<S_Bone_Inform> & {[îñÌXgÌQÆ
// ßèl FÈµ
//===============//
C_Animation_Calculation_System::C_Animation_Calculation_System(const std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> & in_bone_list)
{
	// {[ðæ¾
	mpr_variable.bone_sum = in_bone_list.size();

	// úóÔÌ{[ðÝè·éASYð¶¬
	mpr_variable.animation_algorithm.reset(new ASSET::ANIMATION::ALGORITHM::C_Animation_Algorithm_No_Animation(in_bone_list));

	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Animation_Calculation_System::~C_Animation_Calculation_System(void)
{
	M_Release();

	return;
}


//===============//
// Ú×   FÌðúðs¤
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Animation_Calculation_System::M_Release(void)
{
	mpr_variable.animation_algorithm.reset();
	mpr_variable.bone_sum = 0;

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
	// {[f[^pÌzñðmÛ·é
	out_bone_matrix_list.clear();
	out_bone_matrix_list.shrink_to_fit();
	out_bone_matrix_list.resize(mpr_variable.bone_sum);

	mpr_variable.animation_algorithm->M_Animation_Time_Update();
	mpr_variable.animation_algorithm->M_Animation_Update(out_bone_matrix_list);

	return;
}
