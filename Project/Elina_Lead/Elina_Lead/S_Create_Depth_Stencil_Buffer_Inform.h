////
// Ú×   F[xXeVobt@ð¶¬·é½ßÌîñ
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_S_CREATE_DEPTH_STENCIL_BUFFER_INFORM_H_FILE
#define D_INCLUDE_GUARD_S_CREATE_DEPTH_STENCIL_BUFFER_INFORM_H_FILE


//  t@CÐç«  //
#include "E_DEPTH_STENCIL_BUFFER_PIXEL_BYTE_FORMAT.h"


//  l[Xy[X  //

// _OAPIÉgp·éVXeð¶¬·é½ßÌîñ
namespace RENDERING::API::CREATE
{
	//  \¢Ì  //

	// [xXeVobt@ð¶¬·é½ßÌîñ
	struct S_Create_Depth_Stencil_Buffer_Inform
	{
		RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_STENCIL_BUFFER_PIXEL_BYTE_FORMAT m_byte_format = RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_STENCIL_BUFFER_PIXEL_BYTE_FORMAT::e_4_BYTE;	// sNZÌoCg^
	};
}


#endif // !D_INCLUDE_GUARD_S_CREATE_DEPTH_STENCIL_BUFFER_INFORM_H_FILE

