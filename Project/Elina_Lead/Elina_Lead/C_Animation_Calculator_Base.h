//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：アニメーションの計算を制御するクラスの基底クラス
// 説明   ：どんなアニメーションをするかを分岐ではなく、生成するクラスによって分岐できるようにするための抽象化レイヤー　アニメーションの計算がおこなわれないときはこれを実体化する
// 作成者 ：��坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_ANIMATION_CALCULATOR_BASE
#define D_INCLUDE_GUARD_C_ANIMATION_CALCULATOR_BASE


// ☆ ネームスペース ☆ //

// アニメーション用計算システムを呼び出すための名前
namespace ASSET::ANIMATION::CALCULATOR
{
	// ☆ クラス ☆ //

	// アニメーションの計算を制御するクラスの基底クラス
	class C_Animation_Calculator_Base
	{
		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Animation_Calculator_Base(void);

		// デストラクタ
		virtual ~C_Animation_Calculator_Base(void);

		
		//-☆- 更新 -☆-//

		// アニメーション時間の更新
		virtual void M_Animation_Time_Update(void);

		// アニメーションの更新
		virtual void M_Animation_Update(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_ANIMATION_CALCULATOR_BASE
