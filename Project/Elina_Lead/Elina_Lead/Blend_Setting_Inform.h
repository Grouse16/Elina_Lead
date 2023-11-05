////
// Ú×   FuhÝèÌè`ðs¤t@C
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_E_BLEND_MODE_H_FILE
#define D_INCLUDE_GUARD_E_BLEND_MODE_H_FILE


//  l[Xy[X  //

// uhè`pÌîñðÄÑo·½ßÌ¼O
namespace RENDERING::INFORM::BLEND
{
	// uh[hðè`·éñ
	enum class E_BLEND_MODE
	{
		e_NORMAL,			// Êí`æ
		e_NORMAL_NOT_ALPHA,	// ¿lðgp¹¸É`æ

		e_INVERT,			// ¸Zû®Å`æ
		e_INVERT_NOT_ALPHA,	// ¿lðgp¹¸É¸Zû®Å`æ
	};

	// sNZVF[_[Æ_OæÌFÌ¬ºûðwè·éñ
	enum class E_BLEND_OPTION
	{
		e_ADD,		// sNZVF[_[ÌFðÁZ
		e_SUB,		// sNZVF[_[ÌFð¸Z
		e_SUB_PIX,	// sNZVF[_[ÌFð»ÝÌFÅ¸Z
		e_MAX,		// »ÝÌFÆsNZVF[_[ÌFðärµ½Æ«ÌÅål
		e_MIN,		// »ÝÌFÆsNZVF[_[ÌFðärµ½Æ«ÌÅ¬l
	};

	// _OæÉ«ÞsNZÌf[^`®Ìñ
	enum class E_RENDERING_DRAW_FORMAT
	{
		e_BYTE_1_UINT,	// PoCgÌUINT
		e_BYTE_2_UINT,	// QoCgÌUINT
		e_BYTE_4_UINT,	// SoCgÌUINT

		e_BYTE_2_FLOAT,	// QoCgÌFLOAT
		e_BYTE_4_FLOAT,	// SoCgÌFLOAT
	};

	// _OæÉ«ÞFÌíÞÌñ
	enum class E_RENDERING_DRAW_COLOR
	{
		e_R,	// ÔÌÝ
		e_RG,	// ÔÆÎ
		e_RGBA,	// ÔÆÎÆÂÆ¿l
	};

}


#endif // !D_INCLUDE_GUARD_E_BLEND_MODE_H_FILE

