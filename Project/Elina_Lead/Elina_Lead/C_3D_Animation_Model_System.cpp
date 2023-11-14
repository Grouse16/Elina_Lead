////
// Ú×   FAj[VfÌNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_3D_Animation_Model_System.h"

#ifdef _DEBUG
#include "C_Log_System.h"
#endif // _DEBUG


//  l[Xy[XÌÈª  //
using namespace ASSET::ANIMATION_MODEL;


//  Ö  //

//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_3D_Animation_Model_System::C_3D_Animation_Model_System(void)
{
	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_3D_Animation_Model_System::~C_3D_Animation_Model_System(void)
{
	M_Release();

	return;
}


//===============//
// Ú×   FÌðúðs¤
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_3D_Animation_Model_System::M_Release(void)
{
	for (S_Animative_Mesh_Data_Inform & mesh_data : mpr_variable.mesh_inform_list)
	{
		mesh_data.mesh_data.reset();
	}
	mpr_variable.mesh_inform_list.clear();
	mpr_variable.mesh_inform_list.shrink_to_fit();

	return;
}


//-- [h --//

//===============//
// Ú×   Fwè³ê½pXÌ3DAj[Vfð[h·é
// ø   Fstring 3DAj[VfÜÅÌpX
// ßèl Fbool ¬÷ÌÝture
//===============//
bool C_3D_Animation_Model_System::M_Load_3D_Animation_Model_By_Path(std::string in_3d_animation_model_path)
{
	//  Ïé¾  //
	SYSTEM::TEXT::C_Text_And_File_Manager file_data;	// t@CÌf[^ðÇÝæéVXe


	// wè³ê½t@Cð[h@[hÉ¸sÍG[ðoµÄ²¯é
	if (file_data.M_Load_Select_File(in_3d_animation_model_path) == false)
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_OBJECT, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR, "t@CÌæ¾É¸sµÜµ½F" + in_3d_animation_model_path);
#endif // _DEBUG

		return false;
	}

	// FØ¼ðTõ·é
	if (file_data.M_Goto_Right_By_Text_In_Front_Row("This-Is-ELANMMDL") == false)
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_OBJECT, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR, "±Ìt@CÍ.elanmmdl`®ÅÍ èÜ¹ñF" + in_3d_animation_model_path);
#endif // _DEBUG

		return false;
	}


	// »ÝÁÄ¢éAj[Vff[^Íí·é
	M_Release();


	// bVf[^ðæ¾
	file_data.M_Goto_Right_By_Text_In_Front_Row("MESHSUM:");
	mpr_variable.mesh_inform_list.resize(file_data.M_Get_Number());


	// {[ðæ¾µ»Ìª{[ð¶¬
	file_data.M_Goto_Right_By_Text_In_Front_Row("BONESUM:");
	mpr_variable.bone_list.resize(file_data.M_Get_Number());


	// {[f[^ªÇÝæé
	for (ASSET::ANIMATION::BONE::S_Bone_Inform & bone_inform : mpr_variable.bone_list)
	{
		// »ÝÌ{[Ìf[^ÜÅÚ®
		file_data.M_Move_Next_Raw();

		// {[¼ðæ¾
		bone_inform.bone_name = file_data.M_Get_Data_By_Text("/");

		// ItZbg}gNXAPð[h
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._11 = file_data.M_Get_Number();

		// ItZbg}gNXAQð[h
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._12 = file_data.M_Get_Number();

		// ItZbg}gNXARð[h
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._13 = file_data.M_Get_Number();
		
		// ItZbg}gNXASð[h
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._14 = file_data.M_Get_Number();

		// ItZbg}gNXBPð[h
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._21 = file_data.M_Get_Number();

		// ItZbg}gNXBQð[h
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._22 = file_data.M_Get_Number();

		// ItZbg}gNXBRð[h
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._23 = file_data.M_Get_Number();

		// ItZbg}gNXBSð[h
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._24 = file_data.M_Get_Number();

		// ItZbg}gNXCPð[h
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._31 = file_data.M_Get_Number();

		// ItZbg}gNXCQð[h
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._32 = file_data.M_Get_Number();

		// ItZbg}gNXCRð[h
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._33 = file_data.M_Get_Number();

		// ItZbg}gNXCSð[h
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._34 = file_data.M_Get_Number();

		// ItZbg}gNXDPð[h
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._41 = file_data.M_Get_Number();

		// ItZbg}gNXDQð[h
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._42 = file_data.M_Get_Number();

		// ItZbg}gNXDRð[h
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._43 = file_data.M_Get_Number();

		// ItZbg}gNXDSð[h
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._44 = file_data.M_Get_Number();
	}


	// bVf[^ªÇÝæé
	for (S_Animative_Mesh_Data_Inform & now_mesh_inform : mpr_variable.mesh_inform_list)
	{
		// bVÌÊuÖÚ®
		file_data.M_Goto_Right_By_Text_In_Front_Row("MESH:");

		// bV¼ðæ¾
		file_data.M_Move_Next_Raw();
		now_mesh_inform.name = file_data.M_Get_Data_Now_Row();

		// bVf[^ð¶¬
		now_mesh_inform.mesh_data.reset(new ASSET::ANIMATION::MESH::C_Animative_Mesh());

		// bVÌ}eAð[h@[h¸sÅG[ðoµÄ²¯é
		file_data.M_Move_Raw_By_Number(2);
		file_data.M_Goto_Column_By_Set_Number(0);
		if (now_mesh_inform.mesh_data->M_Load_Material_By_Name(file_data.M_Get_Data_Now_Row()) == false)
		{
#ifdef _DEBUG
			DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
			DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR, "}eAÌ[hÉ¸sµÜµ½BAj[VpfF" + in_3d_animation_model_path);
#endif // _DEBUG

			return false;
		}

		// ¸_ðæ¾µA¸_f[^ð¶¬
		file_data.M_Goto_Right_By_Text_In_Front_Row("VERT:");
		now_mesh_inform.mesh_data->M_Creat_Vertex_List(file_data.M_Get_Number());

		// ¸_f[^ð[h
		for (DATA::VERTEX::S_3D_Animation_Model_Vertex & now_vertex_data : now_mesh_inform.mesh_data->M_Get_Vertex_Data_List())
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

			// {[EFCgi{[e¿ljîñÌÊuÖÚ®
			file_data.M_Goto_Right_By_Text_In_Front_Column(":");

			// {[EFCgîñÌI¹ÌLª­é©ASñJèÔ·ÜÅA{[EFCgîñð[hµ±¯é
			for (int loop_cnt = 0; loop_cnt < DATA::VERTEX::con_BONE_WEIGHT_INDEX_SUM || file_data.M_Get_Text_Of_Now_Position() != ':'; loop_cnt++)
			{
				now_vertex_data.bone_weight[loop_cnt].bone_index = file_data.M_Get_Number();
				file_data.M_Goto_Right_By_Text_In_Front_Column("/");
				now_vertex_data.bone_weight[loop_cnt].weight = file_data.M_Get_Float_Double_Number();
				file_data.M_Goto_Right_By_Text_In_Front_Column(",");
			}
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

	// [hÉ¬÷AfobOÍ¬÷Oð\¦
#ifdef _DEBUG
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT, "Aj[VpfÌ[hÉ¬÷µÜµ½F" + in_3d_animation_model_path);
#endif // _DEBUG

	return true;
}


//===============//
// Ú×   Fwè³ê½¼OÌAj[Vf[^ð[h·é
// ø   Fstring [h·éAj[Vf[^¼
// ßèl Fbool ¬÷ÌÝtrue
//===============//
bool C_3D_Animation_Model_System::M_Load_Animation_Data_By_Path(std::string in_animation_data_name)
{
	// ·ÅÉ[h³êÄ¢éÈç½àµÈ¢
	for (S_Animation_Data_Inform & now_animation_data : mpr_variable.animation_data_list)
	{
		if (now_animation_data.name == in_animation_data_name)
		{
			return;
		}
	}


	//  Ïé¾  //
	std::string load_path = "project/asset/animation/" + in_animation_data_name + ".elanmdt";	// Aj[Vf[^ÜÅÌpX

	int new_animation_data = mpr_variable.animation_data_list.size();	// Vµ¢Aj[Vf[^ÌzñÔ


	// Aj[Vf[^ð[h·é@¸sÅfalseðÔµÄ²¯é
	mpr_variable.animation_data_list[new_animation_data].animation_data.reset(new ASSET::ANIMATION_SYSTEM::C_Animation_Data_System());
	if (mpr_variable.animation_data_list[new_animation_data].animation_data->M_Load_Anmation_Data_By_Path(load_path, mpr_variable.bone_list) == false)
	{
		return false;
	}

	// [hÉ¬÷
	return true;
}


//-- Qb^ --//

//===============//
// Ú×   Fwè³ê½¼OÌbVðÔ·
// ø   Fstring T·bVÌ¼O
// ßèl FC_3D_Animation_Model_System::S_Animative_Mesh_Data_Inform * ¼Oªêvµ½bVÌAhXAêvµÈ©Á½çnullptrðÔ·
//===============//
C_3D_Animation_Model_System::S_Animative_Mesh_Data_Inform * C_3D_Animation_Model_System::M_Get_Mesh_Data_By_Name(std::string in_mesh_name)
{
	// êv·ébV¼ðTµA êÎ»ÌAhXðÔ·
	for (S_Animative_Mesh_Data_Inform & now_mesh_data : mpr_variable.mesh_inform_list)
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
// ßèl Fvector<C_3D_Animation_Model_System::S_Animative_Mesh_Data_Inform> & bVîñÌXgÌQÆ
//===============//
std::vector<C_3D_Animation_Model_System::S_Animative_Mesh_Data_Inform> &  C_3D_Animation_Model_System::M_Get_Mesh_Inform_List(void)
{
	return mpr_variable.mesh_inform_list;
}


//-- `æ --//

//===============//
// Ú×   F3Dfð`æ·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_3D_Animation_Model_System::M_Draw_3D_Model(void)
{
	// SÄÌbVð`æ
	for (S_Animative_Mesh_Data_Inform & now_mesh_inform : mpr_variable.mesh_inform_list)
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
void C_3D_Animation_Model_System::M_Draw_Meshes_By_Name(std::string in_draw_mesh_name)
{
	// SÄÌbV©ç`æ·ébV¼Æ¯¶bVÌÝ`æ
	for (S_Animative_Mesh_Data_Inform & now_mesh_inform : mpr_variable.mesh_inform_list)
	{
		if (now_mesh_inform.name == in_draw_mesh_name)
		{
			now_mesh_inform.mesh_data->M_Draw_Mesh();
		}
	}

	return;
}

