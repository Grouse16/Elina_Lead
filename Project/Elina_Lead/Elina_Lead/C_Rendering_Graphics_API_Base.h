////
// Ú×   FT[hp[eBÌàÌOtBbNð§ä·éVXeÌîêNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_THIRD_PARTY_SDK_GRAPHICS_BASE_H_FILE
#define D_INCLUDE_GUARD_C_THIRD_PARTY_SDK_GRAPHICS_BASE_H_FILE


//  t@CÐç«  //
#include<iostream>
#include<memory>
#include<vector>
#include<string>

#include "C_Rendering_Vertex_Buffer_Setting_Inform_Base.h"
#include "C_Rendering_Texture_Setting_Inform_Base.h"
#include "C_Rendering_Constant_Buffer_Setting_Inform_Base.h"
#include "C_Rendering_Graphics_Setting_Inform_Base.h"
#include "C_Rendering_Font_Inform_Base.h"
#include "C_Rendering_Screen_System_Base.h"
#include "C_Rendering_Depth_Stencil_Buffer_Base.h"

#include "S_Create_Vertex_Buffer_Inform.h"
#include "S_Create_Constant_Buffer_Inform.h"
#include "S_Create_Rendering_Graphics_Setting_Inform.h"
#include "S_Create_Texture_Setting_Inform.h"
#include "S_Create_Font_Data_Inform.h"
#include "S_Create_Render_Screen_Inform.h"
#include "S_Create_Depth_Stencil_Buffer_Inform.h"

#include "C_Color.h"
#include "S_Rect.h"
#include "S_Make_Font_To_Graph_Pakage.h"


//  l[Xy[X  //

// OtBbNð§ä·éVXeÌîêðÄÑo·½ßÌ¼O
namespace RENDERING::GRAPHICS
{
	//  NX  //
	
	// T[hp[eBÌàÌOtBbNð§ä·éVXeÌîêNX
	class C_Rendering_Graphics_API_Base
	{
	//== veNg ==//
	protected:

		//  Ïé¾  //
		static std::unique_ptr<C_Rendering_Graphics_API_Base> m_this;	// NXÌCX^XpAhXAåÉ|[tBY»Égp


	//== pubN ==//
	public:

		//  Ö  //

		//-- ú»ÆI¹ --//

		// ú»µÄgpÂ\É·é
		virtual bool M_Set_Up(void) = 0;

		// ðú
		virtual void M_Release(void) = 0;

		// _OpÌAPIðI¹·é
		static void M_Delete_API(void);

		// fXgN^
		virtual ~C_Rendering_Graphics_API_Base(void);


		//-- _O --//

		// _OðJn·é
		virtual void M_Rendering_Start(void) = 0;

		// `æpCvCpÌîñð¶¬·é@øFÝèæÌpCvCîñ, ¶¬pÌîñ(const)
		virtual bool M_Create_Rendering_Graphics_Inform(std::unique_ptr<INSTANCE::C_Rendering_Graphics_Setting_Inform_Base>&, const CREATE::S_Create_Rendering_Graphics_Setting_Inform&) = 0;

		// Ì`æÀsðJn·é@øF_OpCvCpîñ(const)
		virtual void M_Rendering_Set_Rendering_Setting(const std::unique_ptr<INSTANCE::C_Rendering_Graphics_Setting_Inform_Base>&) = 0;

		// _OðI¹µÄAæÊð\¦
		virtual void M_Rendering_End_And_Swap_Screen(void) = 0;


		//-- _OæÊ --//

		// _OæÊð¶¬·é@øFÝèæÌ_OæÊÌQÆ, _OæÊð¶¬·é½ßÌîñÌQÆiconstj@ßèlF¬÷ÌÝtrue
		virtual bool M_Create_Rendering_Screen(std::unique_ptr<RENDERING::GRAPHICS::INSTANCE::C_Rendering_Screen_System_Base> &, const RENDERING::GRAPHICS::CREATE::S_Create_Render_Screen_Inform & ) = 0;

		// _OæÊðNA·é@øFNA·é_OæÊÔ, NA·é_OæÊVXeÌQÆ
		virtual void M_Clear_Rendering_Screen(int, std::unique_ptr<RENDERING::GRAPHICS::INSTANCE::C_Rendering_Screen_System_Base>&) = 0;

		// wè³ê½_OæÊðZbg·é@øFÝè·é_OæÊÔ, ÝèæÌ_OæÊÌQÆ
		virtual void M_Set_Rendering_Screen_To_Render_Target(int, std::unique_ptr<RENDERING::GRAPHICS::INSTANCE::C_Rendering_Screen_System_Base> & ) = 0;

		// _OæÊðwè³ê½eNX`ÌXbgÉZbg·é@øF_OæÊÔ, ÝèæÌeNX`ÌXbgÔ, _OæÊVXeÌQÆ
		virtual void M_Set_Rendering_Screen_To_Texture_Slot(int, int, std::unique_ptr<RENDERING::GRAPHICS::INSTANCE::C_Rendering_Screen_System_Base> & ) = 0;

		// _OæÊÌf[^iæfzñjðæ¾Â\ÈóÔÉ·é@øFÝè·é_OæÊÔ, _OæÊVXeÌQÆ
		virtual void M_Set_Rendering_Screen_Can_Readable(int, std::unique_ptr<RENDERING::GRAPHICS::INSTANCE::C_Rendering_Screen_System_Base> & ) = 0;

		// CÌ_OæÊÉß·
		virtual void M_Set_Main_Rendering_Screen_To_Rendering(void) = 0;

		// CÌ_OæÊðeNX`XbgÉZbg·é@øFÝèæÌeNX`ÌXbgÔ
		virtual void M_Set_Main_Rendering_Screen_To_Texture_Slot(int) = 0;

		// CÌ_OæÊÌf[^ðeNX`ÉÚ·@øFÝèæÌeNX`ÌQÆ
		virtual void M_Save_Main_Rendering_Screen_To_Texture(ASSET::TEXTURE::C_Texture_Map & ) = 0;

		// wè³ê½_OæÊÌf[^ðeNX`ÉÚ·@øFÝè·é_OæÊÔ, _OæÊVXeÌQÆ, ÝèæÌeNX`ÌQÆ
		virtual void M_Save_Rendering_Screen_To_Texture(int, std::unique_ptr<RENDERING::GRAPHICS::INSTANCE::C_Rendering_Screen_System_Base> & , ASSET::TEXTURE::C_Texture_Map & ) = 0;

		// _OæÊÌíðÊm·é@øFí³ê½_OæÊÌAhXiconstj
		virtual void M_Notice_Rendering_Screen_Deleted(const RENDERING::GRAPHICS::INSTANCE::C_Rendering_Screen_System_Base * ) = 0;


		//-- [xXeVobt@ --//

		// [xXeVobt@ð¶¬·é@øF¶¬æÌ[xXeVobt@ÌQÆ, [xXeVobt@ð¶¬·é½ßÌîñÌQÆiconstj@ßèlF¬÷ÌÝtrue
		virtual bool M_Create_Depth_Stencil_Buffer(std::unique_ptr<RENDERING::GRAPHICS::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base> & , const RENDERING::GRAPHICS::CREATE::S_Create_Depth_Stencil_Buffer_Inform & ) = 0;

		// [xXeVobt@ð`æpÉZbg·é@øFÝè·é[xXeVobt@ÌQÆ
		virtual void M_Set_Depth_Stencil_Buffer_To_Rendering(std::unique_ptr<RENDERING::GRAPHICS::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base> & ) = 0;

		// [xXeVobt@ðNA·é@øFNA·é[xXeVobt@ÌQÆ
		virtual void M_Clear_Depth_Stencil_Buffer(std::unique_ptr<RENDERING::GRAPHICS::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base> & ) = 0;

		// [xXeVobt@ðGPUp\[XÌeNX`XbgÉZbg@øFÝèæÌXbgÔ, Ýè·é[xXeVobt@ÌQÆ
		virtual void M_Set_Depth_Stencil_Buffer_To_Texture_Slot(int, std::unique_ptr<RENDERING::GRAPHICS::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base> & ) = 0;

		// CÌ[xXeVobt@ðZbg·é
		virtual void M_Set_Main_Depth_Stencil_Buffer_To_Rendering(void) = 0;

		// CÌ[xXeVobt@ðeNX`XbgÉZbg·é@øFÝèæÌeNX`ÌXbgÔ
		virtual void M_Set_Main_Depth_Stencil_Buffer_To_Texture_Slot(int) = 0;

		// [xXeVobt@ÌíðÊm·é@øFí³ê½[xXeVobt@ÌAhXiconstj
		virtual void M_Notice_Depth_Stencil_Buffer_Deleted(const RENDERING::GRAPHICS::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base * ) = 0;


		//-- ¸_obt@ --//

		// ¸_f[^pÌîñð¶¬·é@øFÝèæÌ¸_îñ, ¶¬pÌîñ(const)
		virtual void M_Create_Vertex_Inform(std::unique_ptr<INSTANCE::C_Rendering_Vertex_Buffer_Setting_Inform_Base> & , const CREATE::S_Create_Vertex_Buffer_Inform&) = 0;

		// ¡Ì`æðÀs·é@øF¸_f[^Ýèpîñ(const)
		virtual void M_Draw_All_Vertex_By_Index(const std::unique_ptr<INSTANCE::C_Rendering_Vertex_Buffer_Setting_Inform_Base> & ) = 0;

		// `æ·éCfbNXÔðwèµ½¤¦Å¡Ì`æðÀs·é@øF¸_f[^Ýèpîñ(const), `æ·éCfbNXÌ`æÌJnÔ,`æ·éCfbNXÌI¹Ô
		virtual void M_Draw_Select_Vertex_By_Index(const std::unique_ptr<INSTANCE::C_Rendering_Vertex_Buffer_Setting_Inform_Base> & , int, int) = 0;


		//-- èobt@ --//

		// èf[^pÌîñð¶¬·é@øFÝèæÌèîñ, ¶¬pÌîñ(const)
		virtual void M_Create_Constant_Inform(std::unique_ptr<INSTANCE::C_Rendering_Constant_Buffer_Setting_Inform_Base>&, const CREATE::S_Create_Constant_Buffer_Inform&) = 0;

		// èf[^ðZbg·é@øFèf[^Ýèpîñ(const)
		virtual void M_Rendering_Set_Constant_Buffer(INSTANCE::S_Constant_Buffer_Drawing_Setting & ) = 0;

		// wè³ê½CfbNXÔÌXbgÉèf[^ðZbg·é@øFèf[^Ýèpîñ, ZbgæÌCfbNXÔ
		virtual void M_Rendering_Set_Constant_Buffer_By_Index(std::unique_ptr<INSTANCE::C_Rendering_Constant_Buffer_Setting_Inform_Base> & , int) = 0;


		//-- eNX` --//

		// eNX`pÌîñð¶¬·é@øFeNX`pîñ, ¶¬pÌîñ(const)@ßèlF¬÷ÌÝtrue
		virtual bool M_Create_Texture_Inform(std::unique_ptr<INSTANCE::C_Rendering_Texture_Setting_Inform_Base>&, const CREATE::S_Create_Texture_Setting_Inform&) = 0;

		// eNX`Ìf[^ðZbg·é@øFZbg·éeNX`f[^îñ(const)
		virtual void M_Rendering_Set_Texture(INSTANCE::S_Texture_Buffer_Drawing_Setting & ) = 0;

		// wè³ê½CfbNXÔÌXbgÉeNX`Ìf[^ðZbg·é@øFZbg·éeNX`f[^îñ(const), ZbgæÌCfbNXÔ
		virtual void M_Rendering_Set_Texture_By_Index(std::unique_ptr<INSTANCE::C_Rendering_Texture_Setting_Inform_Base> & , int) = 0;


		//-- tHg --//

		// tHgðwè³ê½tHg¼ð³É[h·é@øFÝèæÌtHgîñp[^, ¶¬pÌîñ(const)@ßèlF¬÷ÌÝtrue
		virtual bool M_Create_Font_Data(std::unique_ptr<INSTANCE::C_Rendering_Font_Inform_Base> &, const CREATE::S_Create_Font_Data_Inform &) = 0;

		// n³ê½îñð³É¶ñð}bvÉZbg·é@øFtHg©çæðìé½ßÌpbP[Wîñ@ßèlF¬÷ÌÝtrue
		virtual bool M_Set_Font_To_Texture_Map(PAKAGE::FONT::S_Make_Font_To_Graph_Package & ) = 0;


		//-- Qb^ --//

		// ±ÌNXÌÀÌÌAhXðÔ·@ßèlF©NXÌCX^XÖÌAhX
		static C_Rendering_Graphics_API_Base * M_Get_Instance(void);

		// ±Ì_OVXeÌVF[_[ÌtH_ÜÅÌpXðÔ·@ßèlFVF[_[ÌtH_ÜÅÌpX
		virtual std::string M_Get_Shader_Folder_Path(void) = 0;

		// ±Ì_OVXeÌVF[_[Ìg£qðÔ·@ßèlFVF[_[Ìg£q
		virtual std::string M_Get_Shader_Extension(void) = 0;

		// _OVXeªI¹µÄ¢é©Ç¤©ÌtOðÔ·@ßèlF_OVXeªI¹µÄ¢é©Ç¤©ÌtO
		virtual bool M_Get_End_Rendering_System(void) = 0;


		//-- Zb^ --//

		// æÊðNA·éFðÝè·é@øFÝè·éF(const)
		virtual void M_Set_Clear_Color(const DATA::COLOR::C_Color & ) = 0;


		//-- [h --//

		// eNX`ð[h·é@øFeNX`t@CÌpX, eNX`}bvÌQÆ
		virtual bool M_Load_Texture(std::string, ASSET::TEXTURE::C_Texture_Map &) = 0;
	};
}


#endif // !D_INCLUDE_GUARD_C_THIRD_PARTY_SDK_GRAPHICS_BASE


//======================================================================
// Copyright 2023 ûüâ´½
// 
// àµà±ÌR[hð©ªÌvWFNgÉpµ½¢ÌÅ êÎA
// [AhXFtakasaka.ryusei1116@gmail.com
// Ü½ÍAûüâ´½ÜÅ²A­¾³¢B
// R[hÌs¾ªÌðàâAÅVÌóÔÌñÈÇÉÎ¢½µÜ·B
//======================================================================

