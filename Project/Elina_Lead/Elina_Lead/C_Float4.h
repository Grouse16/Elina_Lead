////
// Ú×   Ft[glÂªðÇ·éNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_MY_FLOAT_4_H_FILE
#define D_INCLUDE_GUARD_C_MY_FLOAT_4_H_FILE


//  l[Xy[X  //

// wnðÄÑo·½ßÌ¼O
namespace MATH
{
	//  NX  //

	// t[glÂªðÇ·éNX
	class C_Float4
	{
		//== pubN ==//
	public:

		//  Ïé¾  //
		float x = 0.0f;	// vfP
		float y = 0.0f;	// vfQ
		float z = 0.0f;	// vfR
		float w = 0.0f;	// vfS


		//  Ö  //

		//-- ú» --//

		// RXgN^
		C_Float4(void);

		// xyzwðÉZbg·éRXgN^@øFxÉZbg·él, yÉZbg·él, zÉZbg·él, wÉZbg·él
		C_Float4(float, float, float, float);

		// xyzðÉZbg·éRXgN^@øFxÉZbg·él, yÉZbg·él, zÉZbg·él
		C_Float4(float, float, float);

		// xyðÉZbg·éRXgN^@øFxÉZbg·él, yÉZbg·él
		C_Float4(float, float);

		// xðÉZbg·éRXgN^@øFxÉZbg·él
		C_Float4(float);

		// fXgN^
		~C_Float4(void);


		//-- Iy[^ --//

		// Float4ÆÌCR[Z(QÆ^)@øGãü·ét[g4l
		void operator= (C_Float4 & );

		// Float4ÆÌCR[Z@øFãü·ét[g4l
		void operator= (C_Float4);

		// Float4ÆÌ{Z(QÆ^)@øFÁZ·ét[g4l
		C_Float4 operator+ (C_Float4 & );

		// Float4ÆÌ{Z@øFÁZ·ét[g4l
		C_Float4 operator+ (C_Float4);

		// floatÆÌ{ZiSÄÌÏðÁZj@øFÁZ·ét[gl
		C_Float4 operator+ (float &);
	};
}


#endif // !D_INCLUDE_GUARD_C_MY_FLOAT_4_H_FILE
