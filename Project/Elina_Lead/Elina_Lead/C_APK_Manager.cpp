////
// Ú×   FAvP[V§äpÌNX
// à¾   F
// ì¬Ò Fûüâ´½
////

//  t@CÐç«  //
#include "C_APK_Manager.h"
#include "C_DX12_System.h"


//  l[Xy[XÌÈª  //
using namespace APPLICATION;


//  Ïé¾  //
std::unique_ptr<C_APK_Manager> C_APK_Manager::m_this;	// ©NXÖÌANZXpÌÏ


//  Ö  //

//== vCx[g ==//

//-- ú» --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl Fvoid
//===============//
C_APK_Manager::C_APK_Manager(void)
{

	return;
}


//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl Fbool ¬÷ÌÝtrue
//===============//
bool C_APK_Manager::M_Init(void)
{
	m_this.reset(new C_APK_Manager);

	return true;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl Fvoid
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

	return;
}


//-- V[Jn --//

//===============//
// Ú×   FV[ÌðJn·é
// ø   Fint V[ÌÔ
// ßèl Fvoid
//===============//
void C_APK_Manager::M_Start_Scene(int in_scene_number)
{
	


	return;
}


//-- V[I¹ --//

//===============//
// Ú×   FV[ÌðI¹·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_APK_Manager::M_End_Scene(void)
{

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

	return;
}
