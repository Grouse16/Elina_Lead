////
// Ú×   F_OÝèÌè`ðs¤t@C
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_RENDERING_ANOTHER_SETTING_INFORM_H_FILE
#define D_INCLUDE_GUARD_RENDERING_ANOTHER_SETTING_INFORM_H_FILE


//  l[Xy[X  //

// _OÝèè`pÌîñðÄÑo·½ßÌ¼O
namespace RENDERING::INFORM::SETTING
{
	//  \¢Ì  //

	// TvOÌÝèðs¤½ßÌîñÌ\¢Ì
	struct S_Sampling_Setting_Inform
	{
		int sampling_count = 1;		// TvOÌñ
		int sampling_quality = 1;	// TvOÌi¿

		bool flg_conservative = true;	// ÛçIÈTvOÌtOAtrueÅLøAfalseÅ³ø
	};
}


#endif // !D_INCLUDE_GUARD_RENDERING_ANOTHER_SETTING_INFORM_H_FILE



