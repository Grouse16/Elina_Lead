////
// Ú×   F3DfÌNX
// à¾   F3DfÌæ¾©ç`æAAj[VÌÀsÜÅðs¤
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_3D_Model_System.h"
#include "C_Text_And_File_Manager.h"

#ifdef _DEBUG
#include "C_Log_System.h"
#endif // _DEBUG


//  l[Xy[XÌÈª  //
using namespace ASSET::MODEL;


//  Ö  //

//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_3D_Model_System::C_3D_Model_System(void)
{
	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_3D_Model_System::~C_3D_Model_System(void)
{
	M_Release();

	return;
}


//===============//
// Ú×   FÌðúðs¤
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_3D_Model_System::M_Release(void)
{
	for (S_Mesh_Data_Inform & mesh_data : mpr_variable.mesh_inform_list)
	{
		mesh_data.mesh_data.reset();
	}
	mpr_variable.mesh_inform_list.clear();
	mpr_variable.mesh_inform_list.shrink_to_fit();

	return;
}


//-- [h --//

//===============//
// Ú×   Fwè³ê½pXÌ3Dfð[h·é
// ø   Fstring 3DfÜÅÌpX
// ßèl Fbool ¬÷ÌÝture
//===============//
bool C_3D_Model_System::M_Load_3D_Model_By_Path(std::string in_3d_model_path)
{
	//  Ïé¾  //
	SYSTEM::TEXT::C_Text_And_File_Manager file_data;	// t@CÌf[^ðÇÝæéVXe


	// wè³ê½t@Cð[h@[hÉ¸sÍG[ðoµÄ²¯é
	if (file_data.M_Load_Select_File(in_3d_model_path) == false)
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_OBJECT, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR, "t@CÌæ¾É¸sµÜµ½F" + in_3d_model_path);
#endif // _DEBUG

		return false;
	}

	// FØ¼ðTõ·é
	if (file_data.M_Goto_Right_By_Text_In_Front_Row("This-Is-ELSTTMDL") == false)
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_OBJECT, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR, "±Ìt@CÍ.elsttmdl`®ÅÍ èÜ¹ñF" + in_3d_model_path);
#endif // _DEBUG

		return false;
	}


	// »ÝÁÄ¢éff[^Íí·é
	M_Release();

	
	// bVf[^ðæ¾
	file_data.M_Goto_Right_By_Text_In_Front_Row("MESHSUM:");
	mpr_variable.mesh_inform_list.resize(file_data.M_Get_Number());

	// bVf[^ªÇÝæé
	for(S_Mesh_Data_Inform & now_mesh_inform : mpr_variable.mesh_inform_list)
	{
		// bVÌÊuÖÚ®
		file_data.M_Goto_Right_By_Text_In_Front_Row("MESH:");

		// bV¼ðæ¾
		file_data.M_Move_Next_Raw();
		now_mesh_inform.name = file_data.M_Get_Data_Now_Row();

		// bVf[^ð¶¬
		now_mesh_inform.mesh_data.reset(new ASSET::MESH::C_Mesh_Data());

		// bVÌ}eAð[h@[h¸sÅG[ðoµÄ²¯é
		file_data.M_Move_Raw_By_Number(2);
		file_data.M_Goto_Column_By_Set_Number(0);
		if (now_mesh_inform.mesh_data->M_Load_Material_By_Name(file_data.M_Get_Data_Now_Row()) == false)
		{
#ifdef _DEBUG
			DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
			DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR, "}eAÌ[hÉ¸sµÜµ½BfF" + in_3d_model_path + "-" + file_data.M_Get_Data_Now_Row());
#endif // _DEBUG

			return false;
		}

		// ¸_ðæ¾µA¸_f[^ð¶¬
		file_data.M_Goto_Right_By_Text_In_Front_Row("VERT:");
		now_mesh_inform.mesh_data->M_Creat_Vertex_List(file_data.M_Get_Number());

		// ¸_f[^ð[h
		for (DATA::VERTEX::S_3D_Model_Vertex & now_vertex_data : now_mesh_inform.mesh_data->M_Get_Vertex_Data_List())
		{
			// »ÝÌ¸_f[^ÜÅÚ®
			file_data.M_Move_Next_Raw();

			// ¸_ÀWÌ[h
			now_vertex_data.vertex.x = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Column(",");
			now_vertex_data.vertex.y = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Column(",");
			now_vertex_data.vertex.z = file_data.M_Get_Float_Double_Number();

			// UVÀWÌ[h
			file_data.M_Goto_Right_By_Text_In_Front_Column(":");
			now_vertex_data.uv.u = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Column(",");
			now_vertex_data.uv.v = file_data.M_Get_Float_Double_Number();

			// FÌ[h
			file_data.M_Goto_Right_By_Text_In_Front_Column(":");
			now_vertex_data.color.r = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Column(",");
			now_vertex_data.color.g = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Column(",");
			now_vertex_data.color.b = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Column(",");
			now_vertex_data.color.a = file_data.M_Get_Float_Double_Number();

			// @üxNgÌ[h
			file_data.M_Goto_Right_By_Text_In_Front_Column(":");
			now_vertex_data.normal.x = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Column(",");
			now_vertex_data.normal.y = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Column(",");
			now_vertex_data.normal.z = file_data.M_Get_Float_Double_Number();

			// ^WFgxNgÌ[h
			file_data.M_Goto_Right_By_Text_In_Front_Column(":");
			now_vertex_data.tangent.x = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Column(",");
			now_vertex_data.tangent.y = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Column(",");
			now_vertex_data.tangent.z = file_data.M_Get_Float_Double_Number();

			// oCm[}^WFgxNgi]@üxNgjÌ[h
			file_data.M_Goto_Right_By_Text_In_Front_Column(":");
			now_vertex_data.binormal_tangent.x = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Column(",");
			now_vertex_data.binormal_tangent.y = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Column(",");
			now_vertex_data.binormal_tangent.z = file_data.M_Get_Float_Double_Number();
		}

		// ¸_CfbNXðæ¾µÄA¸_CfbNXf[^ð¶¬
		file_data.M_Goto_Right_By_Text_In_Front_Row("INDEX:");
		now_mesh_inform.mesh_data->M_Creat_Index_List(file_data.M_Get_Number());

		// ¸_CfbNXf[^ð[h
		for (unsigned __int32 & now_index_data : now_mesh_inform.mesh_data->M_Get_Index_Data_List())
		{
			file_data.M_Move_Next_Raw();
			now_index_data = file_data.M_Get_Number();
		}

		// ¸_Æ¸_CfbNXîñªÌobt@ð¶¬µAf[^ðobt@ÉZbgA»Ìãf[^ÍgpµÈ¢ÌÅíiobt@Ícéj
		now_mesh_inform.mesh_data->M_Creat_Vertex_Buffer_And_Index_Buffer();
		now_mesh_inform.mesh_data->M_Attach_Vertex_Data_To_Buffer();
		now_mesh_inform.mesh_data->M_Attach_Index_Data_To_Buffer();
		now_mesh_inform.mesh_data->M_Delete_Vertex_Data();
		now_mesh_inform.mesh_data->M_Delete_Index_Data();
	}

	// }eAÌèobt@ðTõµAÁêÈ¼OÌXbgðæ¾·é
	for (S_Mesh_Data_Inform & now_mesh : mpr_variable.mesh_inform_list)
	{
		//  Ïé¾  //
		ASSET::MATERIAL::C_Material* now_material = now_mesh.mesh_data->M_Get_Material_User().M_Get_Material_Address();	// }eAÌAhX


		// gXtH[@ êÎèobt@ðmÛ·é
		now_mesh.unique_buffer_number.transform = now_material->M_Get_Constant_Buffer_Number_By_Name("CB_TRANSFORM");

		// ArGgCg
		now_mesh.unique_buffer_number.ambient_light = now_material->M_Get_Constant_Buffer_Number_By_Name("CB_AMBIENT_LIGHT");

		// fBNViCg
		now_mesh.unique_buffer_number.directional_light = now_material->M_Get_Constant_Buffer_Number_By_Name("CB_DIRECTIONAL_LIGHT");

		// |CgCg
		now_mesh.unique_buffer_number.point_light = now_material->M_Get_Constant_Buffer_Number_By_Name("CB_POINT_LIGHT");

		// X|bgCg
		now_mesh.unique_buffer_number.spot_light = now_material->M_Get_Constant_Buffer_Number_By_Name("CB_POINT_LIGHT");

		// GACg
		now_mesh.unique_buffer_number.area_light = now_material->M_Get_Constant_Buffer_Number_By_Name("CB_POINT_LIGHT");

		// CÆÈéeNX`
		now_mesh.unique_buffer_number.main_texture = now_material->M_Get_Texture_Number_By_Name("CT_MAIN_TEXTURE");
	}

	// [hÉ¬÷AfobOÍ¬÷Oð\¦
#ifdef _DEBUG
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT, "fÌ[hÉ¬÷µÜµ½F" + in_3d_model_path);
#endif // _DEBUG

	return true;
}


//-- Qb^ --//

//===============//
// Ú×   Fwè³ê½¼OÌbVðÔ·
// ø   Fstring T·bVÌ¼O
// ßèl FC_3D_Model_System::S_Mesh_Data_Inform * ¼Oªêvµ½bVÌAhXAêvµÈ©Á½çnullptrðÔ·
//===============//
C_3D_Model_System::S_Mesh_Data_Inform * C_3D_Model_System::M_Get_Mesh_Data_By_Name(std::string in_mesh_name)
{
	// êv·ébV¼ðTµA êÎ»ÌAhXðÔ·
	for (S_Mesh_Data_Inform & now_mesh_data : mpr_variable.mesh_inform_list)
	{
		if (now_mesh_data.name == in_mesh_name)
		{
			return &now_mesh_data;
		}
	}

	// ©Â©çÈ©Á½
	return nullptr;
}


//===============//
// Ú×   FbVîñÌXgÌQÆðÔ·
// ø   Fvoid
// ßèl Fvector<C_3D_Model_System::S_Mesh_Data_Inform> & bVîñÌXgÌQÆ
//===============//
std::vector<C_3D_Model_System::S_Mesh_Data_Inform> & C_3D_Model_System::M_Get_Mesh_Inform_List(void)
{
	return mpr_variable.mesh_inform_list;
}


//-- `æ --//

//===============//
// Ú×   F3Dfð`æ·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_3D_Model_System::M_Draw_3D_Model(void)
{
	// SÄÌbVð`æ
	for (S_Mesh_Data_Inform & now_mesh_inform : mpr_variable.mesh_inform_list)
	{
		now_mesh_inform.mesh_data->M_Draw_Mesh();
	}

	return;
}


//===============//
// Ú×   F3Df©çwè³ê½bV¼ÌÝ`æ·é
// ø   Fstring `æ·ébV¼i¡»è·éj
// ßèl Fvoid
//===============//
void C_3D_Model_System::M_Draw_Meshes_By_Name(std::string in_draw_mesh_name)
{
	// SÄÌbV©ç`æ·ébV¼Æ¯¶bVÌÝ`æ
	for (S_Mesh_Data_Inform & now_mesh_inform : mpr_variable.mesh_inform_list)
	{
		if (now_mesh_inform.name == in_draw_mesh_name)
		{
			now_mesh_inform.mesh_data->M_Draw_Mesh();
		}
	}

	return;
}
