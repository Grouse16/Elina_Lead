////
// Ú×   FXg[~OoÍpobt@ÌîêNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_DX12_Streaming_Output_Buffer_Base.h"


//  l[Xy[XÌÈª  //
using namespace RENDERING::API::DX12::DX12_TOOL;


//  Ö  //

//== pubN ==//

//-- ú» --//

//===============//
// Ú×   FXg[~OoÍpobt@ðgpµÈ¢Ìú»ðs¤
// ø   FD3D12_GRAPHICS_PIPELINE_STATE_DESC & pCvC¶¬pîñ
// ßèl Fvoid
//===============//
void C_DX12_Streaming_Output_Buffer_Base::M_Do_Not_Use_Setting(D3D12_GRAPHICS_PIPELINE_STATE_DESC & in_pipeline_desc)
{
    // Xg[~OoÍXbgÌ¸_obt@Ì¸_vfpÌ\¢ÌÌzñÌAhX
    in_pipeline_desc.StreamOutput.pSODeclaration = nullptr;

    // ãLA¸_obt@Ì¸_vfpÌ\¢ÌÌzñÌzñ
    in_pipeline_desc.StreamOutput.NumEntries = 0;

    // ¸_ÌXgCh(sb`)ÌzñÌAhXiobt@ÌvfÌTCYj
    in_pipeline_desc.StreamOutput.pBufferStrides = nullptr;

    // ãLA¸_ÌXgCh(sb`)ÌzñÌzñ
    in_pipeline_desc.StreamOutput.NumStrides = 0;

    // X^CU[ÉéXg[oÍobt@ÌæÊÔ(CfbNXÔ)
    in_pipeline_desc.StreamOutput.RasterizedStream = 0;

	return;
}
