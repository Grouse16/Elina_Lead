////
// Ú×   FDX12Ì_OÝèpf[^ÌZbgpÌf[^ÌNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_DX12_Rendering_Texture_Setting_Inform.h"


//  l[Xy[XÌÈª  //
using namespace RENDERING::GRAPHICS::DX12::DX12INSTANCE;


//  Ö  //

//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_DX12_Rendering_Texture_Setting_Inform::C_DX12_Rendering_Texture_Setting_Inform(void)
{
	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_DX12_Rendering_Texture_Setting_Inform::~C_DX12_Rendering_Texture_Setting_Inform(void)
{
	M_Delete();

	return;
}


//===============//
// Ú×   Fððú·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_DX12_Rendering_Texture_Setting_Inform::M_Delete(void)
{
	mpr_variable.texture_data.Reset();
	mpr_variable.texture_heap.Reset();
	mpr_variable.pix_size_x = 0;
	mpr_variable.pix_size_y = 0;

	return;
}


//-- XV --//

//===============//
// Ú×   FeNX`Ìf[^ðZbg·é
// ø   Fconst std::vector<DATA::TEXTURE::S_Tex_Color> & Ýè·éeNX`îñÖÌQÆ, int eNX`Ì¡, int eNX`Ìc
// ßèl Fvoid
//===============//
void C_DX12_Rendering_Texture_Setting_Inform::M_Set_Texture_Data(const std::vector<DATA::TEXTURE::S_Tex_Color> & in_texture_map, int in_width, int in_height)
{
	//  Ïé¾  //
	int pixel_width = in_width;	// ¡ÅÌsNZTCY
	int pixel_height = in_height;	// cÅÌsNZTCY


	// «ÝÍÍÌûªL¢Èç©gÌsNZTCYÉ²®
	if (pixel_width > mpr_variable.pix_size_x)
	{
		pixel_width = mpr_variable.pix_size_x;
	}

	if (pixel_height > mpr_variable.pix_size_y)
	{
		pixel_height = mpr_variable.pix_size_y;
	}


	//Tu\[XÉ«Ý
	mpr_variable.texture_data->WriteToSubresource(0, nullptr, &in_texture_map[0], (pixel_width * 4), (pixel_height * 4));

	return;
}
