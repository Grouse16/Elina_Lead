////
// Ú×   FIuWFNgÌÀWAñ]Aå«³ÌÝè
// à¾   F¼OðgXtH[Æ·é
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_Transform.h"


//  l[Xy[XÌÈª  //
using namespace MATH;


//  Ö  //

//-- ú»ÆI¹ --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Transform::C_Transform(void)
{
	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Transform::~C_Transform(void)
{
	return;
}


//-- Ú® --//

//===============//
// Ú×   F¡ü¢Ä¢éûüðOûÆµÄÚ®ðs¤
// ø   FÚ®Ê
// ßèl Fvoid
//===============//
void C_Transform::M_Move(DirectX::XMFLOAT3 in_move_value)
{
	position.M_Move_By_Direction(quaternion.M_Get_Rotation_Matrix(), in_move_value);

	return;
}


//-- sñÏ· --//

//===============//
// Ú×   F[hÏ·sñÉÏ·µÄÔ·
// ø   FXMMATRIX & Ï·f[^ÌÝèæÌQÆ
// ßèl Fvoid
//===============//
void C_Transform::M_Generate_World_Matrix(DirectX::XMMATRIX & put_set_matrix) const
{
	// Ï·sñð¶¬µÄZbg·é
	put_set_matrix =

		// XP[
		scale.M_Get_Scale_Matrix()
		*

		// ñ]
		quaternion.M_Get_Rotation_Matrix() 
		*

		// ÊuÀW
		position.M_Get_Position_Matrix();
	
	return;
}


