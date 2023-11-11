////
// Ú×   F3DfÌNX
// à¾   F3DfÌæ¾©ç`æAAj[VÌÀsÜÅðs¤
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_3D_MODEL_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_3D_MODEL_SYSTEM_H_FILE


//  t@CÐç«  //
#include <vector>
#include <memory>
#include <string>

#include "C_Mesh_Data.h"


//  l[Xy[X  //

// 3DfðÄÑo·½ßÌ¼O
namespace ASSET::MODEL
{
	//  NX  //

	// 3DfÌNX
	class C_3D_Model_System
	{
		//== pubN ==//
	public:

		//  \¢Ì  //

		// bVðÇ·é½ßÌf[^Ì\¢Ì
		struct S_Mesh_Data_Inform
		{
			std::unique_ptr<ASSET::MESH::C_Mesh_Data> mesh_data = nullptr;	// bVf[^

			std::string name = "default";	// bV¼
		};


		//== vCx[g ==//
	private:

		//  Ïé¾  //
		
		// vCx[gÏðÜÆß½\¢Ì
		struct SPr_Variable
		{
			std::vector<S_Mesh_Data_Inform> mesh_inform_list;	// bVÌÇpîñXg

		} mpr_variable;	// vCx[gÏðÄÑo·½ßÌ¼O


		//== pubN ==//
	public:

		//  Ö  //

		//-- ú»ÆI¹ --//

		// RXgN^
		C_3D_Model_System(void);

		//fXgN^
		~C_3D_Model_System(void);

		// Ìðúðs¤
		void M_Release(void);


		//-- [h --//

		// wè³ê½pXÌ3Dfð[h·é@øF3DfÜÅÌpX@ßèlF¬÷ÌÝtrue
		bool M_Load_3D_Model_By_Path(std::string);


		//-- Qb^ --//

		// wè³ê½¼OÌbVîñÌAhXðÔ·@øFT·bVÌ¼O@ßèlF¼Oªêvµ½bVÌAhXAêvµÈ©Á½çnullptrðÔ·
		S_Mesh_Data_Inform * M_Get_Mesh_Data_By_Name(std::string);

		// bVîñÌXgÌQÆðÔ·@ßèlFbVîñÌXgÌQÆ
		std::vector<S_Mesh_Data_Inform> & M_Get_Mesh_Inform_List(void);


		//-- `æ --//

		// 3Dfð`æ·é
		void M_Draw_3D_Model(void);

		// 3Df©çwè³ê½bV¼ÌÝ`æ·é@øF`æ·ébV¼i¡»è·éj
		void M_Draw_Meshes_By_Name(std::string);
	};
}


#endif // !D_INCLUDE_GUARD_C_3D_MODEL_SYSTEM_H_FILE
