////
// Ú×   FeNX`UVpÌf[^è`pÌt@C
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_TEXTURE_UV_DATA_H_FILE
#define D_INCLUDE_GUARD_TEXTURE_UV_DATA_H_FILE


//  l[Xy[X  //

// eNX`UVpÌf[^Ìè`ðÄÑo·½ßÌ¼O
namespace DATA::TEXTURE_UV
{
	//  NX  //

	// ¸_ÀWÌNX
	class C_Texture_UV
	{
		//== pubN ==//
	public:

		//  Ïé¾  //
		float u = 0.0f;	// UÀW
		float v = 0.0f;	// VÀW


		//  Ö  //

		//-- ú»ÆI¹ --//

		// RXgN^
		C_Texture_UV(void) { return; }
		
		// tuÀWðZbg·éRXgN^
		C_Texture_UV(float in_u, float in_v) 
		{
			u = in_u;
			v = in_v;

			return;
		}

		// fXgN^
		~C_Texture_UV(void) { return; }


		//-- Ýè --//

		//===============//
		// Ú×   FUVÀWðZbg·é
		// ø   Ffloat Zbg·éU, float Zbg·éV
		// ßèl Fvoid
		//===============//
		void M_Set_UV(float in_u, float in_v)
		{
			u = in_u;
			v = in_v;

			return;
		}
	};
}


#endif // !D_INCLUDE_GUARD_TEXTURE_UV_DATA_H_FILE

