////
// Ú×   FbVÌf[^ÇpÌVXeÌNX
// à¾   F¸_â¸_CfbNXîñÌÇðs¤
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_Mesh_Data.h"


//  l[Xy[XÌÈª  //
using namespace ASSET::MESH;


//  Ö  //

//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Mesh_Data::C_Mesh_Data(void)
{
	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Mesh_Data::~C_Mesh_Data(void)
{
	return;
}


//-- Ýè --//

//===============//
// Ú×   F¸_ðwè³ê½ª¶¬
// ø   Fint ¶¬·é¸_
// ßèl Fvoid
//===============//
void C_Mesh_Data::M_Creat_Vertex_List(int in_creat_vertex_sum)
{
	mpr_variable.vertex_setting.M_Creat_Vertex_Data_By_Number(in_creat_vertex_sum);

	return;
}


//===============//
// Ú×   F¸_CfbNXðwè³ê½ª¶¬
// ø   Fint ¶¬·é¸_CfbNX
// ßèl Fvoid
//===============//
void C_Mesh_Data::M_Creat_Index_List(int in_creat_index_sum)
{
	mpr_variable.vertex_setting.M_Creat_Index_Data_By_Number(in_creat_index_sum);

	return;
}


//===============//
// Ú×   F¸_obt@Æ¸_CfbNXobt@ð¶¬µ@¸_f[^Æ¸_CfbNXðKvÈ¾¯¶¬µÄ©çÀs·é±Æ
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Mesh_Data::M_Creat_Vertex_Buffer_And_Index_Buffer(void)
{
	mpr_variable.vertex_setting.M_Create_Vertex_And_Index_Buffer_By_Now_Parameter();

	return;
}


//===============//
// Ú×   F¸_CfbNXÌf[^ðCfbNXobt@ÉÝè·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Mesh_Data::M_Attach_Index_Data_To_Buffer(void)
{
	mpr_variable.vertex_setting.M_Index_Data_To_Buffer();

	return;
}


//===============//
// Ú×   F¸_f[^ð¸_obt@ÉÝè·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Mesh_Data::M_Attach_Vertex_Data_To_Buffer(void)
{
	mpr_variable.vertex_setting.M_Vertex_Data_To_Buffer();

	return;
}


//===============//
// Ú×   F¸_CfbNXf[^ÌÝðí·éiobt@ÉÝèãAÒWµÈ¢ÈçKvªÈ¢j
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Mesh_Data::M_Delete_Index_Data(void)
{
	mpr_variable.vertex_setting.M_Delete_Index_Data();

	return;
}


//===============//
// Ú×   Fwè³ê½¼OÌ}eAð[h·é
// ø   F}eA¼
// ßèl F¬÷ÌÝtrue
//===============//
bool C_Mesh_Data::M_Load_Material_By_Name(std::string in_load_material_name)
{
	mpr_variable.material.M_Release();
	mpr_variable.material.M_Load_Material(in_load_material_name);

	// }eAªæ¾Å«Ä¢½çtrue
	return mpr_variable.material.M_Get_Material_Address() != nullptr;
}


//-- Qb^ --//

//===============//
// Ú×   F¸_f[^ÌXgÌQÆðÔ·
// ø   Fvoid
// ßèl Fvector<S_3D_Model_Vertex> & ¸_f[^ÌXgðÔ·
//===============//
std::vector<DATA::VERTEX::S_3D_Model_Vertex> & C_Mesh_Data::M_Get_Vertex_Data_List(void)
{
	return mpr_variable.vertex_setting.M_Get_Vertex_Data();
}


//===============//
// Ú×   F¸_CfbNXf[^ÌXgÌQÆðÔ·
// ø   Fvoid
// ßèl Fvector<unsigned __int32> & ¸_CfbNXf[^ÌXgÌQÆ
//===============//
std::vector<unsigned __int32> & C_Mesh_Data::M_Get_Index_Data_List(void)
{
	return mpr_variable.vertex_setting.M_Get_Index_Data();
}


//===============//
// Ú×   F»ÝÌ}eA[U[ÌQÆðÔ·
// ø   Fvoid
// ßèl FC_Material_User & }eA[U[ÌQÆðÔ·
//===============//
ASSET::MATERIAL::C_Material_User & C_Mesh_Data::M_Get_Material_User(void)
{
	return mpr_variable.material;
}


//-- `æ --//

//===============//
// Ú×   FbVÌ`æðÀs·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Mesh_Data::M_Draw_Mesh(void)
{
	// }eAðZbg·éi_OÝèðo^µAèobt@AeNX`ðGPUÌf[^XbgÉZbgj
	mpr_variable.material.M_Material_Attach_To_Draw();

	// ¸_ð`æ·éi¸_CfbNXobt@ÌXgSÄð`æ·éj
	mpr_variable.vertex_setting.M_Draw_All_Vertex();

	return;
}


