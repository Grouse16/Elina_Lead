////
// Ú×   FDX12Ì_OXN[i_OææjÌVXe
// à¾   F_[^[Qbgr[Æ[xXeVr[ðÇ·é
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include <DirectXMath.h>

#include "C_DX12_Rendering_Screen_System.h"
#include "C_Half_Color.h"

#ifdef _DEBUG
#include "C_Log_System.h"
#endif // _DEBUG


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
C_DX12_Rendering_Screen_System::C_DX12_Rendering_Screen_System(void)
{
	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_DX12_Rendering_Screen_System::~C_DX12_Rendering_Screen_System(void)
{
	return;
}


//===============//
// Ú×   FðJú·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_DX12_Rendering_Screen_System::M_Release(void)
{
	m_render_target_view.buffer_list.clear();
	m_render_target_view.buffer_list.shrink_to_fit();
	
	return;
}


//-- æ --//

//===============//
// Ú×   Fwè³ê½ÔÌ_OæÊðeNX`æÆµÄÛ¶·é
// ø   Fint _OæÊÔ, C_Texture_Map & Û¶æÌeNX`æÊÌQÆ
// ßèl F¬÷ÌÝtrue
//===============//
bool C_DX12_Rendering_Screen_System::M_Save_Screen_For_Texture(int in_screen_number, ASSET::TEXTURE::C_Texture_Map & in_to_texture)
{
	// ÍÍOðwè³ê½çG[ðoµÄ²¯é
	if (0 < in_screen_number || in_screen_number <= m_rendering_screen_sum)
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_GAME_RENDERING, DEBUGGER::LOG::ALL_LOG_NAME::GAME_RENDERING::con_RENDERING_ERROR, "XN[æÔÉÍÍOðwè³êÜµ½");
		DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
#endif // _DEBUG

		return;
	}


	//  Ïé¾  //
	int texture_width = m_render_target_view.buffer_list[in_screen_number].screen_width;	// æÌ¡
	int texture_height = m_render_target_view.buffer_list[in_screen_number].screen_height;	// æÌc

	void * map_data = nullptr;	// }bvÉæÁÄæ¾µ½f[^


	// _[^[Qbgr[Ìf[^ðæ¾
	m_render_target_view.buffer_list[in_screen_number].render_buffer.Get()->Map(0, nullptr, &map_data);

	// æ¾É¸sµ½çG[Å²¯é
	if (map_data == nullptr)
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_GAME_RENDERING, DEBUGGER::LOG::ALL_LOG_NAME::GAME_RENDERING::con_RENDERING_ERROR, "XN[æÌæ¾É¸sµÜµ½");
		DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
#endif // _DEBUG

		return;
	}

	// æfÌ^ÉæÁÄªò
	switch (m_screen_format)
	{
		// æfÌFîñÍRGB»ê¼êPoCgÅ éiO`QTTj
	case RENDERING::INFORM::RENDERING_SCREEN::E_RENDERING_SCREEN_FORMAT::e_1_BYTE:
		{
			//  Ïé¾  //
			DATA::TEXTURE::C_Tex_Color* texture_color = nullptr;	// RGBAðSÄO`QTTÅó¯æêé^


			// ^ÌðßðÏX
			texture_color = static_cast<DATA::TEXTURE::C_Tex_Color*>(map_data);

			// eNX`pÌ}bvð¶¬·é
			in_to_texture.M_Create_Texture_Map(m_render_target_view.buffer_list[in_screen_number].screen_width, m_render_target_view.buffer_list[in_screen_number].screen_height);


			//  Ïé¾  //
			std::vector<DATA::COLOR::C_Color>& texture_map = in_to_texture.M_Get_Texture_Map();	// eNX`Ì}bvðæ¾·é


			// eNX`pÌ}bvÉlðÚ·
			for (int l_now_height = 0; l_now_height < texture_height; l_now_height++)
			{
				for (int l_now_width = 0; l_now_width < texture_width; l_now_width++)
				{
					//  Ïé¾  //
					int now_pixel_number = l_now_width + l_now_height * texture_width;	// »ÝÌsNZÔ


					// sNZÉFðhÁÄ¢­
					texture_map[now_pixel_number].m_r = texture_color[now_pixel_number].r / 255.0f;
					texture_map[now_pixel_number].m_g = texture_color[now_pixel_number].g / 255.0f;
					texture_map[now_pixel_number].m_b = texture_color[now_pixel_number].b / 255.0f;
					texture_map[now_pixel_number].m_a = texture_color[now_pixel_number].a / 255.0f;
				}
			}

			// _[^[Qbgr[Ìf[^ðÂ¶ÄI¹
			m_render_target_view.buffer_list[in_screen_number].render_buffer.Get()->Unmap(0, nullptr);
		}
		return;

		// æfÌFîñÍRGBA»ê¼êQoCgÅ éi-1.0~1.0j
	case RENDERING::INFORM::RENDERING_SCREEN::E_RENDERING_SCREEN_FORMAT::e_2_BYTE:
		{
			//  Ïé¾  //
			DATA::TEXTURE::C_Tex_Color* texture_color = nullptr;	// RGBAðSÄO`QTTÅó¯æêé^


			// ^ÌðßðÏX
			texture_color = static_cast<DATA::TEXTURE::C_Tex_Color*>(map_data);

			// eNX`pÌ}bvð¶¬·é
			in_to_texture.M_Create_Texture_Map(m_render_target_view.buffer_list[in_screen_number].screen_width, m_render_target_view.buffer_list[in_screen_number].screen_height);


			//  Ïé¾  //
			std::vector<DATA::COLOR::C_Color>& texture_map = in_to_texture.M_Get_Texture_Map();	// eNX`Ì}bvðæ¾·é


			// eNX`pÌ}bvÉlðÚ·
			for (int l_now_height = 0; l_now_height < texture_height; l_now_height++)
			{
				for (int l_now_width = 0; l_now_width < texture_width; l_now_width++)
				{
					//  Ïé¾  //
					int now_pixel_number = l_now_width + l_now_height * texture_width;	// »ÝÌsNZÔ


					// sNZÉFðhÁÄ¢­
					texture_map[now_pixel_number].m_r = texture_color[now_pixel_number].r / 255.0f;
					texture_map[now_pixel_number].m_g = texture_color[now_pixel_number].g / 255.0f;
					texture_map[now_pixel_number].m_b = texture_color[now_pixel_number].b / 255.0f;
					texture_map[now_pixel_number].m_a = texture_color[now_pixel_number].a / 255.0f;
				}
			}

			// _[^[Qbgr[Ìf[^ðÂ¶ÄI¹
			m_render_target_view.buffer_list[in_screen_number].render_buffer.Get()->Unmap(0, nullptr);
		}
		return;

		// æfÌFîñÍRGBA»ê¼êSoCgÅ éi-1.0~1.0j
	case RENDERING::INFORM::RENDERING_SCREEN::E_RENDERING_SCREEN_FORMAT::e_4_BYTE:
		{
		}
		return;
	}

	return;
}

