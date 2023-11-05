////
// Ú×   FOtBbNXAPIðú»·é½ßÌNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_API_Initialize_And_Release_Manager.h"
#include "Platform_Detector_Macro.h"
#include "C_Platform_Detection_System.h"


//  EBhEYOSÌÌÝDirextXðLø»  //
#ifdef D_OS_IS_WINDOWS
#include "C_Windows_System.h"
#include "C_DX12_System.h"
#endif // D_OS_IS_WINDOWS


//  }N  //
#if _DEBUG
#include "C_Log_System.h"
#endif // _DEBUG


//  l[Xy[XÌÈª  //
using namespace PLATFORM;


//  Ö  //

//== vCx[g ==//

//-- ú» --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_API_Initialize_And_Release_Manager::C_API_Initialize_And_Release_Manager(void)
{
	return;
}


//== pubN ==//

//-- ú» --//

//===============//
// Ú×   FOSÌ¶¬ðs¤
// ø   FE_RENDERING_API_KIND gp·éAPIÌíÞÖÌQÆ
// ßèl Fbool ¬÷ÌÝtrue
//===============//
bool C_API_Initialize_And_Release_Manager::M_Creat_OS(E_RENDERING_API_KIND in_use_api_kind)
{
	//  EBhEYñÎÍOpenGLÉØèÖ¦é  //
	if ((in_use_api_kind == E_RENDERING_API_KIND::e_DX12 || in_use_api_kind == E_RENDERING_API_KIND::e_DX11) && PLATFORM::DETECTION::C_Platform_Detection_System::M_Get_Platform_Number() != PLATFORM::DETECTION::E_PLATFORM_NUMBER::e_WINDOWS)
	{
		in_use_api_kind = E_RENDERING_API_KIND::e_OPENGL;
	}


	//  ú»·éAPIÉæÁÄªò  //
	switch (in_use_api_kind)
	{
//  EBhEYOSÌÌÝDirextXðLø»  //
#ifdef D_OS_IS_WINDOWS

	//  DX11  //
	case E_RENDERING_API_KIND::e_DX11:

		// EBhEYÌ¶¬
		OS::WINDOWS::C_Windows_System::M_Creat_Windows_System();


		// _OAPIªDX11Å é±Æð¦·
		PLATFORM::DETECTION::C_Platform_Detection_System::M_Set_Rendering_API_Number(PLATFORM::DETECTION::E_RENDERING_API_NUMBER::e_DX11);

		break;

	//  DX12  //
	case E_RENDERING_API_KIND::e_DX12:

		// EBhEYÌ¶¬
		OS::WINDOWS::C_Windows_System::M_Creat_Windows_System();
		

		// _OAPIªDX12Å é±Æð¦·
		PLATFORM::DETECTION::C_Platform_Detection_System::M_Set_Rendering_API_Number(PLATFORM::DETECTION::E_RENDERING_API_NUMBER::e_DX12);

		break;

#endif // D_OS_IS_WINDOWS

	//  OpenGL  //
	case E_RENDERING_API_KIND::e_OPENGL:


		// _OAPIªOpenGLÅ é±Æð¦·
		PLATFORM::DETECTION::C_Platform_Detection_System::M_Set_Rendering_API_Number(PLATFORM::DETECTION::E_RENDERING_API_NUMBER::e_OPENGL);

		break;


	//  Vulkan  //
	case E_RENDERING_API_KIND::e_VULKAN:


		break;

	//  ÈÉà¶¬Å«È©Á½ÌÅG[ðoµÄI¹  //
	default:
		return false;
		break;
	}

	// ú»É¬÷
	return true;
}


//===============//
// Ú×   FOSÌú»ðs¤
// ø   Fvoid
// ßèl Fbool ¬÷ÌÝtrue
//===============//
bool C_API_Initialize_And_Release_Manager::M_Init_OS(void)
{
	return OS::C_OS_System_Base::M_Get_Instance()->M_Set_Up();
}


//===============//
// Ú×   FAPIÌú»ðs¤
// ø   Fvoid
// ßèl Fbool ¬÷ÌÝtrue
//===============//
bool C_API_Initialize_And_Release_Manager::M_Init_API(void)
{
	//  ú»·éAPIÉæÁÄªò  //
	switch (PLATFORM::DETECTION::C_Platform_Detection_System::M_Get_Rendering_API_Number())
	{
		//  EBhEYOSÌÌÝDirextXðLø»  //
#ifdef D_OS_IS_WINDOWS

	//  DX11  //
	case PLATFORM::DETECTION::E_RENDERING_API_NUMBER::e_DX11:

		break;

		//  DX12  //
	case PLATFORM::DETECTION::E_RENDERING_API_NUMBER::e_DX12:

		// DX12Ìú»
		RENDERING::GRAPHICS::DX12::C_DX12_System::M_Create_DirectX12();
		return RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Set_Up();

		break;

#endif // D_OS_IS_WINDOWS

		//  OpenGL  //
	case PLATFORM::DETECTION::E_RENDERING_API_NUMBER::e_OPENGL:


		// _OAPIªOpenGLÅ é±Æð¦·
		PLATFORM::DETECTION::C_Platform_Detection_System::M_Set_Rendering_API_Number(PLATFORM::DETECTION::E_RENDERING_API_NUMBER::e_OPENGL);

		break;


		//  Vulkan  //
	case PLATFORM::DETECTION::E_RENDERING_API_NUMBER::e_VULKAN:


		break;

		//  ÈÉà¶¬Å«È©Á½ÌÅG[ðoµÄI¹  //
	default:
		return false;
		break;
	}

	// ú»É¬÷
	return true;
}


//===============//
// Ú×   FEBhEYOSÌÆ«ÌÝKvÈR}hÔðwè·éA±êªÈ¢ÆEBhEð¶¬Å«È¢
// ø   Fint R}hÔ
// ßèl Fvoid
//===============//
void C_API_Initialize_And_Release_Manager::M_Set_CMD_Number(int in_set_cmd)
{
	// EBhEYÍR}hÔðZbg
#ifdef D_OS_IS_WINDOWS

	// DirectXgpÌÝÅæ¢
	if (PLATFORM::DETECTION::C_Platform_Detection_System::M_Get_Rendering_API_Number() == PLATFORM::DETECTION::E_RENDERING_API_NUMBER::e_DX11 ||
		PLATFORM::DETECTION::C_Platform_Detection_System::M_Get_Rendering_API_Number() == PLATFORM::DETECTION::E_RENDERING_API_NUMBER::e_DX12)
	{
		OS::WINDOWS::C_Windows_System::M_Set_Cmd_Show(in_set_cmd);
	}

#endif

	return;
}


//-- I¹ --//

//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_API_Initialize_And_Release_Manager::~C_API_Initialize_And_Release_Manager(void)
{
	M_Relese_Graphics_API();

	return;
}


//===============//
// Ú×   FAPIððú·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_API_Initialize_And_Release_Manager::M_Relese_Graphics_API(void)
{
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Release();
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Delete_API();
	OS::C_OS_System_Base::M_Get_Instance()->M_Release();
	OS::C_OS_System_Base::M_Delete_OS_System();

	return;
}
