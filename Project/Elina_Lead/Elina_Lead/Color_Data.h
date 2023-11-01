////
// Ú×   FFè`pÌt@C
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_COLOR_DATA_H_FILE
#define D_INCLUDE_GUARD_COLOR_DATA_H_FILE


//  l[Xy[X  //

// FÌè`ðÄÑo·½ßÌ¼O
namespace DATA::COLOR
{
	//  NX  //

	// FÌNX
	class C_Color
	{
		//== pubN ==//
	public:

		//  Ïé¾  //
		float r = 0.0f;	// Ô
		float g = 0.0f;	// Î
		float b = 0.0f;	// Â
		float a = 0.0f;	// §¾x


		//  Ö  //

		//-- ú»ÆI¹ --//

		// RXgN^
		C_Color(void) { return; }

		// O`PFðÝè·éÌRXgN^
		C_Color(float in_r, float in_g, float in_b, float in_a)
		{
			r = in_r;
			g = in_g;
			b = in_b;
			a = in_a;

			return;
		}

		// O`QTTÅFðÝè·éÌRXgN^
		C_Color(int in_r, int in_g, int in_b, int in_a)
		{
			r = in_r / static_cast<float>(255);
			g = in_g / static_cast<float>(255);
			b = in_b / static_cast<float>(255);
			a = in_a / static_cast<float>(255);

			return;
		}


		// fXgN^
		~C_Color(void) { return; }


		//-- Ýè --//

		//===============//
		// Ú×   FO`PÅFÌÝèðs¤
		// ø   Ffloat Ô, float Î, float Â, float §¾x
		// ßèl Fvoid
		//===============//
		void M_Set_Color_By_0_1(float in_r, float in_g, float in_b, float in_a)
		{
			r = in_r;
			g = in_g;
			b = in_b;
			a = in_a;

			return;
		}


		//===============//
		// Ú×   F// O`QTTÅFÌÝèðs¤
		// ø   Fint Ô, int Î, int Â, int §¾x
		// ßèl Fvoid
		//===============//
		void M_Set_Color_By_0_255(int in_r, int in_g, int in_b, int in_a)
		{
			r = in_r / static_cast<float>(255);
			g = in_g / static_cast<float>(255);
			b = in_b / static_cast<float>(255);
			a = in_a / static_cast<float>(255);

			return;
		}


		//-- Iy[^[ --//

		// F¯mÌ|¯Z
		C_Color operator*(C_Color& in_color)
		{
			//  Ïé¾  //
			C_Color result;	// vZÊ


			// Fð¬·é
			result.r = in_color.r * r;
			result.g = in_color.g * g;
			result.b = in_color.b * b;
			result.a = in_color.a * a;

			return result;
		}

		// FðÝè·é
		void operator=(C_Color& in_color)
		{
			// Fð¬·é
			r = in_color.r;
			g = in_color.g;
			b = in_color.b;
			a = in_color.a;

			return;
		}
	};
}


#endif // !D_INCLUDE_GUARD_COLOR_DATA_H_FILE

