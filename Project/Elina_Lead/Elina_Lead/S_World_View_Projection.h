////
// Ú×   F[hAr[AvWFNVÏ·sñÌè`
// à¾   FRDfð2DXN[àÅ`æ·é½ßÌf[^
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_WORLD_VIEW_PROJECTION_H_FILE
#define D_INCLUDE_GUARD_C_WORLD_VIEW_PROJECTION_H_FILE


//  t@CÐç«  //
#include <DirectXMath.h>


//  l[Xy[X  //

// [hAr[AvWFNVÏ·sñðÄÑo·½ßÌ¼O
namespace MATH::WVP
{
	//  \¢Ì  //

	// world view projectionsñð®ñµÄè`·é½ßÌ\¢Ì
	struct S_World_View_Projection_Data
	{
		DirectX::XMMATRIX world = DirectX::XMMATRIX();		// [hÏ·sñ
		DirectX::XMMATRIX view = DirectX::XMMATRIX();		// r[Ï·sñ
		DirectX::XMMATRIX projection = DirectX::XMMATRIX();	// vWFNVÏ·sñ
	};
}


#endif // !D_INCLUDE_GUARD_C_WORLD_VIEW_PROJECTION_H_FILE
