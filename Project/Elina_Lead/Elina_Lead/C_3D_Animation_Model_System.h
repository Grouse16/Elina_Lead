////
// Ú×   FAj[VfÌNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_3D_ANIMATION_MODEL_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_3D_ANIMATION_MODEL_SYSTEM_H_FILE


//  t@CÐç«  //
#include "C_Animative_Mesh.h"
#include "S_Bone_Inform.h"
#include "C_Animation_Data_System.h"


//  l[Xy[X  //

// Aj[VÅ«é3DfðÄÑo·½ßÌ¼O
namespace ASSET::ANIMATION_MODEL
{
	//  NX  //

	// Aj[VfÌVXe
	class C_3D_Animation_Model_System
	{
		//== pubN ==//
	public:

		//  \¢Ì  //

		// Aj[VfÌÁêobt@ÌXbgÌÔðÜÆß½\¢Ì
		struct S_Unique_Buffer_Slot
		{
			int transform = 0;			// gXtH[
			
			int ambient_light = 0;		// ArGgCg
			int directional_light = 0;	// fBNViCg
			int point_light = 0;		// |CgCg
			int spot_light = 0;			// X|bgCg
			int area_light = 0;			// GACg

			int bone = 0;				// {[
		};

		// bVðÇ·é½ßÌf[^Ì\¢Ì
		struct S_Animative_Mesh_Data_Inform
		{
			std::unique_ptr<ASSET::ANIMATION::MESH::C_Animative_Mesh> mesh_data = nullptr;	// bVf[^

			std::string name = "default";	// bV¼

			S_Unique_Buffer_Slot unique_buffer_number;	// ÁêÈobt@Ô
		};

		// Aj[VðÇ·é½ßÌf[^Ì\¢Ì
		struct S_Animation_Data_Inform
		{
			std::unique_ptr<ASSET::ANIMATION_SYSTEM::C_Animation_Data_System> animation_data = nullptr;	// Aj[Vf[^

			std::string name = "default";	// Aj[Vf[^¼
		};


		//== vCx[g ==//
	private:

		//  Ïé¾  //

		// vCx[gÏðÜÆß½\¢Ì
		struct SPr_Variable
		{
			std::vector<S_Animative_Mesh_Data_Inform> mesh_inform_list;	// bVÌÇpîñXg

			std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> bone_list;	// {[îñÌXg

			std::vector<S_Animation_Data_Inform> animation_data_list;	// Aj[Vf[^ÌXg

		} mpr_variable;	// vCx[gÏðÄÑo·½ßÌ¼O


		//== pubN ==//
	public:

		//  Ö  //

		//-- ú»ÆI¹ --//

		// RXgN^
		C_3D_Animation_Model_System(void);

		//fXgN^
		~C_3D_Animation_Model_System(void);

		// Ìðúðs¤
		void M_Release(void);


		//-- [h --//

		// wè³ê½pXÌ3DAj[Vfð[h·é@øF3DAj[VfÜÅÌpX@ßèlF¬÷ÌÝtrue
		bool M_Load_3D_Animation_Model_By_Path(std::string);

		// wè³ê½¼OÌAj[Vf[^ð[h·é@øF[h·éAj[Vf[^¼@ßèlF¬÷ÌÝtrue
		bool M_Load_Animation_Data_By_Name(std::string);


		//-- Qb^ --//

		// wè³ê½¼OÌbVf[^îñÌAhXðÔ·@øFT·bVÌ¼O@ßèlF¼Oªêvµ½bVÌAhXAêvµÈ©Á½çnullptrðÔ·
		ASSET::ANIMATION::MESH::C_Animative_Mesh * M_Get_Mesh_Data_By_Name(std::string);

		// bVîñÌXgÌQÆðÔ·@ßèlFbVîñÌXgÌQÆ
		std::vector<S_Animative_Mesh_Data_Inform> & M_Get_Mesh_Inform_List(void);

		// wè³ê½¼OÌAj[Vf[^îñÌAhXðÔ·@øFT·Aj[Vf[^Ì¼O@ßèlF¼Oªêvµ½Aj[VÌAhXAêvµÈ©Á½çnullptrðÔ·
		const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * M_Get_Animation_Data_By_Name(std::string);

		// Aj[VîñÌXgÌQÆðÔ·@ßèlFAj[VîñÌXgÌQÆ
		const std::vector<S_Animation_Data_Inform> & M_Get_Animation_Inform_List(void);

		// {[îñÌXgðÔ·@ßèlF{[îñÌXgÌQÆ(const)
		const std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> & M_Get_Bone_Inform_List(void);


		//-- `æ --//

		// {[Ì}gNXð}eAÉZbg·é@øFZbg·é{[}gNXzñÌQÆ(const)
		void M_Set_Bone_Matrix(const std::vector<DirectX::XMFLOAT4X4> &);

		// 3Dfð`æ·é
		void M_Draw_3D_Model(void);

		// 3Df©çwè³ê½Aj[V¼ÌÝ`æ·é@øF`æ·éAj[V¼i¡»è·éj
		void M_Draw_Meshes_By_Name(std::string);

		// }eAðÝè¹¸ÉA3Dfð`æ·éi`æOÉ}eAðZbg·éÆ«pj
		void M_Draw_3D_Model_Do_Not_Use_Material(void);

		// }eAðÝè¹¸ÉA3Df©çwè³ê½bV¼ÌÝ`æ·éi`æOÉ}eAðZbg·éÆ«pj@øF`æ·ébV¼i¡»è·éj
		void M_Draw_Meshes_By_Name_Do_Not_Use_Material(std::string);
	};
}


#endif // !D_INCLUDE_GUARD_C_3D_ANIMATION_MODEL_SYSTEM_H_FILE

