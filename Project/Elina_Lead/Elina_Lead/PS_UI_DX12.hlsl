////
// Ú×   FJ[ÆeNX`ðKvÆ·éUIÌeNX`psNZVF[_[
// à¾   FuvÀWª-10ÈçJ[ðèÄé
// ì¬Ò Fûüâ´½
////


//  \¢Ì  //

// sNZVF[_[ÉüÁÄ­éîñ
struct S_PS_IN
{
	float4 position : SV_POSITION;  // ÊuÀW
	float4 color : COLOR0;          // F
	float2 uv : TEXCOORD0;          // UVÀW
};


//  eNX`  //

// eNX`nh
Texture2D<float4> tex_color : register(t0);


//  ÃITv[  //

// Tv[nh
SamplerState samp0 : register(s0);


//  CÖ  //
float4 ps_main(S_PS_IN in_ps) : SV_TARGET
{
	//  Ïé¾  //
	float4 out_color = in_ps.color;   // F
	
	
	// eNX`J[ð¬ºé
	out_color *= tex_color.Sample(samp0, in_ps.uv);
	
	
	// J[ðoÍ
	return out_color;
}

