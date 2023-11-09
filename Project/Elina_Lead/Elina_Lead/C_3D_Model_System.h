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
		//== vCx[g ==//
	private:

		//  \¢Ì  //

		// bVðÇ·é½ßÌf[^Ì\¢Ì
		struct S_Mesh_Data_Inform
		{
			std::unique_ptr<ASSET::MESH::C_Mesh_Data> mesh_data = nullptr;	// bVf[^

			std::string mesh_name = "default";	// bV¼
		};


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
	};
}


#endif // !D_INCLUDE_GUARD_C_3D_MODEL_SYSTEM_H_FILE
