////
// Ú×   FAvP[V§äpÌNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_APK_Manager.h"
#include "C_Scene_Manager.h"


//  l[Xy[XÌÈª  //
using namespace GAME::APPLICATION;


//  Ïé¾  //
std::unique_ptr<C_APK_Manager> C_APK_Manager::m_this;	// ©NXÖÌANZXpÌÏ


//  Ö  //

//== vCx[g ==//

//-- ú» --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_APK_Manager::C_APK_Manager(void)
{
	return;
}


//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   F ú»µÄgpÂ\É·é
// ø   Fvoid
// ßèl Fbool ¬÷ÌÝtrue
//===============//
bool C_APK_Manager::M_Init(void)
{
	m_this.reset(new C_APK_Manager);

	// úV[ð[h@¸sÅfalseªÔé
	return GAME::SCENE::MANAGER::C_Scene_Manager::M_Scene_Load(con_INITIALIZED_SCENE_NAME);
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_APK_Manager::~C_APK_Manager(void)
{
	M_Release();

	return;
}


//===============//
// Ú×   Fðú
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_APK_Manager::M_Release(void)
{
	m_this.reset();
	GAME::SCENE::MANAGER::C_Scene_Manager::M_Release();

	return;
}


//-- üÍ --//

//===============//
// Ú×   FAvP[VÌüÍðs¤
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_APK_Manager::M_APK_Input(void)
{
	// AvP[VªANeBuÅÈ¯êÎX[
	if (m_this == nullptr)
	{
		return;
	}


	//  üÍ  //



	return;
}


//-- XV --//

//===============//
// Ú×   FAvP[VÌXVðs¤
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_APK_Manager::M_APK_Update(void)
{
	// AvP[VªANeBuÅÈ¯êÎX[
	if (m_this == nullptr)
	{
		return;
	}


	//  XV  //

	// V[ÉæéQ[XVOÌXVðs¤
	GAME::SCENE::MANAGER::C_Scene_Manager::M_Get_Scene()->M_Scene_Before_Update();

	// Q[ÌXVðs¤


	// V[ÉæéQ[XVãÌXVðs¤
	GAME::SCENE::MANAGER::C_Scene_Manager::M_Get_Scene()->M_Scene_After_Update();

	return;
}


//-- `æ --//

//===============//
// Ú×   FAvP[VÌ`æðs¤
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_APK_Manager::M_APK_Draw(void)
{
	// AvP[VªANeBuÅÈ¯êÎX[
	if (m_this == nullptr)
	{
		return;
	}


	//  `æ  //

	// Q[Ì`æðs¤


	// V[Éæé`æãÌXVðs¤
	GAME::SCENE::MANAGER::C_Scene_Manager::M_Get_Scene()->M_Scene_Update_After_Draw();

	return;
}
