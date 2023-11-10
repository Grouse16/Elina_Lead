////
// Ú×   FbVÌf[^ÇpÌVXeÌNX
// à¾   F¸_â¸_CfbNXîñÌÇðs¤
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_MESH_DATA_H_FILE
#define D_INCLUDE_GUARD_C_MESH_DATA_H_FILE


//  t@CÐç«  //
#include <string>

#include "C_Object_Vertex_System.h"
#include "S_3D_Model_Vertex.h"
#include "C_Material_User.h"


//  l[Xy[X  //

// bVÌVXeðÄÑo·½ßÌ¼O
namespace ASSET::MESH
{
	//  NX  //

	// bVÌf[^ÇpÌVXeÌNX
	class C_Mesh_Data
	{
		//== vCx[g ==//
	private:

		//  Ïé¾  //

		// vCx[gÏðÜÆß½\¢Ì
		struct SPr_Variable
		{
			RENDERING::CAPSULE::C_Object_Vertex_System<DATA::VERTEX::S_3D_Model_Vertex> vertex_setting;	// ¸_pVXe
			
			ASSET::MATERIAL::C_Material_User material;	// }eAf[^

		} mpr_variable;	// vCx[gÏðÄÑo·½ßÌ¼O


		//== pubN ==//
	public:

		//  Ö  //

		//-- ú»ÆI¹ --//

		// RXgN^
		C_Mesh_Data(void);

		// fXgN^
		~C_Mesh_Data(void);


		//-- Ýè --//

		// ¸_ðwè³ê½ª¶¬@øF¶¬·é¸_
		void M_Creat_Vertex_List(int);

		// ¸_CfbNXðwè³ê½ª¶¬@øF¶¬·é¸_CfbNX
		void M_Creat_Index_List(int);

		// ¸_obt@Æ¸_CfbNXobt@ð¶¬·é@¸_f[^Æ¸_CfbNXðKvÈ¾¯¶¬µÄ©çÀs·é±Æ
		void M_Creat_Vertex_Buffer_And_Index_Buffer(void);

		// ¸_CfbNXf[^ð¸_CfbNXobt@ÉÝè·é
		void M_Attach_Index_Data_To_Buffer(void);

		// ¸_f[^ð¸_obt@ÉÝè·é
		void M_Attach_Vertex_Data_To_Buffer(void);

		// ¸_f[^ÌÝðí·éi¸_obt@ÉÝèãAÒWµÈ¢ÈçÁÄ¨­KvªÈ¢j
		void M_Delete_Vertex_Data(void);

		// ¸_CfbNXf[^ÌÝðí·éi¸_CfbNXobt@ÉÝèãAÒWµÈ¢ÈçÁÄ¨­KvªÈ¢j
		void M_Delete_Index_Data(void);

		// wè³ê½¼OÌ}eAð[h·é@øF}eA¼@ßèlF¬÷ÌÝtrue
		bool M_Load_Material_By_Name(std::string);


		//-- Qb^ --//

		// ¸_f[^ÌXgÌQÆðÔ·@ßèlF¸_f[^ÌXgÌQÆ
		std::vector<DATA::VERTEX::S_3D_Model_Vertex> & M_Get_Vertex_Data_List(void);

		// ¸_CfbNXf[^ÌXgÌQÆðÔ·@ßèlF¸_CfbNXf[^ÌXgÌQÆ
		std::vector<unsigned __int32> & M_Get_Index_Data_List(void);

		// »ÝÌ}eA[U[ÌQÆðÔ·@ßèlF}eA[U[ÌQÆðÔ·
		ASSET::MATERIAL::C_Material_User & M_Get_Material_User(void);


		//-- `æ --//

		// bVÌ`æðÀs·é
		void M_Draw_Mesh(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_MESH_DATA_H_FILE

