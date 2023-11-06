﻿//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：DX12の機能を使うためのクラス
// 説明   ：DX12設定や描画処理を行う
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_DX12_SYSTEM_H
#define D_INCLUDE_GUARD_C_DX12_SYSTEM_H


// ☆ OS検知 ☆ //
#include "Platform_Detector_Macro.h"
#ifdef D_OS_IS_WINDOWS


// ☆ ファイルひらき ☆ //
#include <Windows.h>
#include <d3d12.h>
#include <d3d12shader.h>
#include <dxgi1_4.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>
#include <wrl/client.h>

#include "C_DX12_Vertex_Setting_Inform.h"
#include "C_DX12_Constant_Setting_Inform.h"
#include "C_DX12_Rendering_Texture_Setting_Inform.h"
#include "C_DX12_Rendering_Graphics_Setting_Inform.h"
#include "C_Rendering_Graphics_API_Base.h"
#include "S_Shader_Resource_Signature_Inform.h"


// ☆ ネームスペース ☆ //

// DX12システムを呼び出すための名前
namespace RENDERING::GRAPHICS::DX12
{
	// ☆ クラス ☆ //

	// DX12の機能用のクラス
	class C_DX12_System : private RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base
	{
		//==☆  プライベート  ☆==//
	private:

		// ☆ 定数 ☆ //

		// DX12用の定数の列挙
		enum class E_DX12_PARAMATOR
		{
			e_RENDER_TARGET_BUFFER_SUM = 2,	// レンダー用画面数

			e_RED = 0,		// 赤の配列番号
			e_GREEN = 1,	// 緑の配列番号
			e_BLUE = 2,		// 青の配列番号
			e_ALPHA = 3,	// αの配列番号
			e_COLOR_SUM,	// 色の配列数
		};


		// ☆ 変数宣言 ☆ //

		// 変数をしまうための構造体
		struct SPr_Variable
		{
			// フレームワーク用の構造体
			struct S_Frame_Work
			{
				Microsoft::WRL::ComPtr<ID3D12Device> device;	// デバイス（仮想アダプター）

				Microsoft::WRL::ComPtr<IDXGISwapChain3> swap_chain;	// 画面スワップ（画面バッファ切り替え用システム）

				Microsoft::WRL::ComPtr<IDXGIFactory3> factory;	// ファクトリ（全画面表示の切り替え用システム）

				float clear_color[(int)E_DX12_PARAMATOR::e_COLOR_SUM] = { 0.0f,0.0f,0.0f,0.0f };  // 画面塗りつぶし色

			} s_frame_work;	// フレームワーク用パラメータ(デバイスや画面切り替え、構成の設定など)


			// 描画コマンド用の構造体
			struct S_Command
			{
				Microsoft::WRL::ComPtr<ID3D12CommandQueue> queue;	// 描画実行システム

				Microsoft::WRL::ComPtr<ID3D12CommandAllocator> allocator;	// 描画命令制御用システム（GPU処理命令のストレージ割り当てシステム）

				Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> list;	// 描画命令のリスト

				int num_back_screen = 0;	// 後ろ側の画面の番号

			} s_command;	// 描画コマンド用パラメータ


			// レンダー用の構造体
			struct S_Render
			{
				HANDLE fence_event = nullptr;	// フェンスイベント（描画同期時のイベント）

				Microsoft::WRL::ComPtr<ID3D12Fence>  queue_fence;	// フェンス（描画同期用システム）


				// レンダーターゲットビュー用の構造体
				struct S_Render_Target_View
				{
					Microsoft::WRL::ComPtr<ID3D12Resource> render_buffer[(int)E_DX12_PARAMATOR::e_RENDER_TARGET_BUFFER_SUM];	// レンダー先の画面バッファ

					D3D12_CPU_DESCRIPTOR_HANDLE handle[(int)E_DX12_PARAMATOR::e_RENDER_TARGET_BUFFER_SUM] = {};	// テクスチャリソース識別用情報(GPUのためにリソースを分解して変換する)

					Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> heap;	// デスクリプタを整理するための木構造データシステム

				} rtv;	// レンダーターゲットビュー用パラメータ


				// 深度ステンシルビュー用の構造体
				struct S_Depth_Stencil_View
				{
					Microsoft::WRL::ComPtr<ID3D12Resource> buffer;	// 深度ステンシル用のバッファ

					Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> heap;	// デスクリプタを整理するための木構造データシステム

					D3D12_CPU_DESCRIPTOR_HANDLE handle = D3D12_CPU_DESCRIPTOR_HANDLE();	// テクスチャリソース識別用情報(GPUのためにリソースを分解して変換する)

				} dsv;	// 深度ステンシルビュー用パラメータ

			} s_render;	// レンダー用パラメータ

			std::unique_ptr<const ASSET::SHADER::S_All_Shader_Resource_Signatures> shader_resource_list = nullptr;	// 現在適用されているシェーダーのリソース識別名のリスト
		};

		std::unique_ptr<SPr_Variable> mpr_variable;	// このクラスの変数を呼び出すための名前


		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// コンストラクタ、シングルトン化するためにここで定義、静的変数でこのクラスにアクセスできる
		C_DX12_System(void);

		// デバイスや描画コマンド、レンダリング先の設定　戻り値：成功時のみtrue
		bool M_DirectX12_Init(void);


		//-☆- 生成 -☆-//

		// ファクトリを生成する(全画面表示遷移用システム)　戻り値：成功時のみtrue
		bool M_Create_Factory(void);

		// デバイスを生成する(仮想アダプター)　戻り値：成功時のみtrue
		bool M_Create_Device(void);

		// コマンドアロケーターを生成する（GPUコマンドのストレージ割り当てシステム）　戻り値：成功時のみtrue
		bool M_Create_Command_Allocator(void);

		// コマンドリストを生成する（描画命令のリストのカプセル）　戻り値：成功時のみtrue
		bool M_Create_Command_List(void);

		// コマンドキューを生成する（描画実行システム）　戻り値：成功時のみtrue
		bool M_Create_Command_Queue(void);

		// フェンスを生成する（描画同期用システム）　戻り値：成功時のみtrue
		bool M_Create_Fence(void);

		// スワップチェインを生成する（画面バッファ切り替え用システム）　戻り値：成功時のみtrue
		bool M_Create_Swap_Chain(void);

		// レンダーターゲットビューを生成する（レンダリング先の画面バッファ切り替え用システム）　戻り値：成功時のみtrue
		bool M_Create_Render_Target_View_Descriptor_Heap(void);

		// 深度ステンシルビューを生成する（深度ステンシル適用先の画面バッファの切り替え用システム）　戻り値：成功時のみtrue
		bool M_Create_Depth_Stencil_View_Descriptor_Heap(void);

		// 頂点バッファを生成する　引数：設定先の頂点情報, 生成用の情報(const)
		void M_Create_Vertex_Buffer(DX12INSTANCE::C_DX12_Vertex_Setting_Inform * &, const CREATE::C_Create_Vertex_Buffer_Inform & );

		// インデックスバッファを生成する　引数：設定先の頂点情報, 生成用の情報(const)
		void M_Create_Index_Buffer(DX12INSTANCE::C_DX12_Vertex_Setting_Inform * &, const CREATE::C_Create_Vertex_Buffer_Inform & );

		// 定数データ用のヒープを生成する　引数：設定先の定数の情報, 生成用の情報(const)
		void M_Create_Constant_Heap(DX12INSTANCE::C_DX12_Constant_Setting_Inform * &, const CREATE::C_Create_Constant_Buffer_Inform & );

		// 定数データ用の情報を生成する　引数：設定先の定数の情報, 生成用の情報(const)
		void M_Create_Constant_Resource(DX12INSTANCE::C_DX12_Constant_Setting_Inform * &, const CREATE::C_Create_Constant_Buffer_Inform&);

		// テクスチャ用のビューとヒープを生成する　引数：設定先のテクスチャの情報,  生成用の情報(const)
		void M_Create_Texture_Resource_View_And_Heap(DX12INSTANCE::C_DX12_Rendering_Texture_Setting_Inform * &, const CREATE::C_Create_Texture_Setting_Inform & );

		// テクスチャ用のデータを生成する　引数：設定先のテクスチャの情報,  生成用の情報(const)　戻り値：成功時のみtrue
		bool M_Create_Texture_Resource(DX12INSTANCE::C_DX12_Rendering_Texture_Setting_Inform * &, const CREATE::C_Create_Texture_Setting_Inform & );

		// ルートシグネチャデスクからルートシグネチャをシリアライズし生成する,　引数：ルートシグネチャを設定するための情報の参照(const), ルートシグネチャの設定先　戻り値：成功時のみtrue
		bool M_Serialize_And_Creat_RootSignature_By_Desc(const D3D12_ROOT_SIGNATURE_DESC &, Microsoft::WRL::ComPtr<ID3D12RootSignature> &);

		// ルートシグネチャを生成する　引数：設定先の描画パイプライン用情報, 生成用の情報(const)　戻り値：成功時のみtrue
		bool M_Create_Root_Signature(DX12INSTANCE::C_DX12_Rendering_Graphics_Setting_Inform * &, const CREATE::C_Create_Rendering_Graphics_Setting_Inform & );

		// パイプラインステートを生成する　引数：設定先の描画パイプライン用情報, 生成用の情報(const)　戻り値：成功時のみtrue
		bool M_Create_Pipeline_State(DX12INSTANCE::C_DX12_Rendering_Graphics_Setting_Inform * &, const CREATE::C_Create_Rendering_Graphics_Setting_Inform&);

		// シェーダー毎にリソースを定義する（ディスクリプタとレンジ、サンプラーを生成する）　引数：シェーダーのリソース識別情報の参照, ディスクリプタ設定用情報の参照, レンジの設定用情報の参照, サンプラー設定用情報の参照
		void M_Create_Descriptor_And_Sampler_By_Shaders_Inform(const ASSET::SHADER::S_All_Shader_Resource_Signatures &, std::vector<D3D12_ROOT_PARAMETER> &, std::vector<D3D12_DESCRIPTOR_RANGE> &, std::vector<D3D12_STATIC_SAMPLER_DESC> &);


		//-☆- 描画 -☆-//

		// リソース同期用バリアのセット
		void M_Set_Resource_Barrier(D3D12_RESOURCE_STATES, D3D12_RESOURCE_STATES);

		// 画面をクリアする
		void M_Clear_Screen(void);

		// コマンド実行待ち
		void M_Wait_For_Command_Queue(void);

		// ビューポートとシザーの設定を行う
		void M_Set_Scissor_And_View_Port(void);

		// 描画コマンド情報をリセットする
		void M_Reset_Command(void);


		//-☆- 識別用情報 -☆-//

		// 指定されたパイプライン情報を元にシェーダーのリソース識別名をセットする　引数：設定する識別用情報の参照(const)
		void M_Set_Shader_Resource_Signature_By_Rendering_Setting(const DX12INSTANCE::C_DX12_Rendering_Graphics_Setting_Inform * &);


		//-☆- 種別 -☆-//

		// 指定された機能レベルを文字列に変換する　引数：機能レベル指定用列挙　戻り値：変換後の文字列
		std::string M_Convert_D3D_FEATURE_LEVEL_Enum_To_String(D3D_FEATURE_LEVEL);


		//-☆- デバッグ -☆-//
#if _DEBUG
		// デバッグ時の更新
		void M_Debug_Update(void);
#endif // _DEBUG


		//==☆  パブリック  ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆-  初期化と終了時  -☆-//

		// DX12システムの初期化
		bool M_Set_Up(void) override;

		// DX12を生成する処理
		static void M_Create_DirectX12(void);

		// メモリ解放
		void M_Release(void) override;

		// デストラクタ
		~C_DX12_System(void) override;


		//-☆- レンダリング -☆-//

		// 描画開始時の処理
		void M_Rendering_Start(void) override;

		// レンダリング用情報をセット　引数：レンダリングパイプライン用情報(const)
		void M_Rendering_Set_Rendering_Setting(const std::unique_ptr<INSTANCE::C_Rendering_Graphics_Setting_Inform_Base> & ) override;

		// 定数データをセットする　引数：定数データ設定用情報
		void M_Rendering_Set_Constant_Buffer(INSTANCE::S_Constant_Buffer_Drawing_Setting &) override;

		// 指定されたインデックス番号のスロットに定数データをセットする　引数：定数バッファデータ, セット先のインデックス番号
		void M_Rendering_Set_Constant_Buffer_By_Index(std::unique_ptr<INSTANCE::C_Constant_Buffer_Setting_Inform_Base> & , int) override;

		// テクスチャのデータをセットする　引数：セットするテクスチャデータ情報
		void M_Rendering_Set_Texture(INSTANCE::S_Texture_Buffer_Drawing_Setting & ) override;

		// 指定されたインデックス番号のスロットにテクスチャのデータをセットする　引数：テクスチャデータ, セット先のインデックス番号
		void M_Rendering_Set_Texture_By_Index(std::unique_ptr<INSTANCE::C_Rendering_Texture_Setting_Inform_Base> & , int) override;

		// 今の描画を実行する　引数：頂点データ設定用情報(const)
		void M_Draw_All_Vertex_By_Index(const std::unique_ptr<INSTANCE::C_Vertex_Buffer_Setting_Inform_Base> & ) override;

		// 描画するインデックス番号を指定したうえで今の描画を実行する　引数：頂点データ設定用情報(const), 描画するインデックスの描画の開始番号, 描画するインデックスの終了番号
		void M_Draw_Select_Vertex_By_Index(const std::unique_ptr<INSTANCE::C_Vertex_Buffer_Setting_Inform_Base> &, int, int) override;

		// 画面をフリップして描画する処理
		void M_Rendering_End_And_Swap_Screen(void) override;


		//-☆- 生成 -☆-//

		// 指定された情報を元に頂点データを生成する　引数：設定先の頂点情報, 生成用の情報(const)
		void M_Create_Vertex_Inform(std::unique_ptr<INSTANCE::C_Vertex_Buffer_Setting_Inform_Base> &, const CREATE::C_Create_Vertex_Buffer_Inform &) override;

		// 定数データ用の情報を生成する　引数：設定先の定数情報, 生成用の情報(const)
		void M_Create_Constant_Inform(std::unique_ptr<INSTANCE::C_Constant_Buffer_Setting_Inform_Base> &, const CREATE::C_Create_Constant_Buffer_Inform &) override;

		// テクスチャ用の情報を生成する　引数：設定先のテクスチャ情報, 生成用の情報(const)
		bool M_Create_Texture_Inform(std::unique_ptr<INSTANCE::C_Rendering_Texture_Setting_Inform_Base> &, const CREATE::C_Create_Texture_Setting_Inform &) override;

		// 描画パイプライン用の情報を生成する　引数：設定先のパイプライン情報, 生成用の情報(const)　戻り値：成功時のみtrue
		bool M_Create_Rendering_Graphics_Inform(std::unique_ptr<INSTANCE::C_Rendering_Graphics_Setting_Inform_Base> &, const CREATE::C_Create_Rendering_Graphics_Setting_Inform &) override;

		// フォントを指定されたフォント名を元にロードする　引数：設定先のフォント情報パラメータ, 生成用の情報(const)　戻り値：成功時のみtrue
		bool M_Create_Font_Data(std::unique_ptr<INSTANCE::C_Rendering_Font_Inform_Base> &, const CREATE::C_Create_Font_Data_Inform &) override;

		// 渡された情報を元に文字列をマップにセットする　引数：フォントから画像を作るためのパッケージ情報　戻り値：成功時のみtrue
		bool M_Set_Font_To_Texture_Map(PAKAGE::FONT::S_Make_Font_To_Graph_Package & ) override;


		//-☆- ゲッタ -☆-//

		// このレンダリングシステムのシェーダーのフォルダまでのパス　戻り値：シェーダーのフォルダまでのパス
		std::string M_Get_Shader_Folder_Path(void) override;


		//-☆- セッタ -☆-//

		// 画面をクリアする色を設定する　引数：設定する色(const)
		void M_Set_Clear_Color(const DATA::COLOR::C_Color & ) override;


		//-☆- ロード -☆-//

		// テクスチャをロードする　引数：テクスチャファイルのパス, テクスチャマップの参照
		bool M_Load_Texture(std::string, ASSET::TEXTURE::C_Texture_Map &) override;
	};
}


#endif // OS_IS_WINDOWS
#endif // !DX12_SYSTEM


//☆======================================================================☆
// Copyright 2023 髙坂龍誠
// 
// もしもこのコードを自分のプロジェクトに利用したいのであれば、
// メールアドレス：takasaka.ryusei1116@gmail.com
// または、髙坂龍誠までご連絡ください。
// コードの不明部分の解説や、最新の状態の提供などに対応いたします。
//☆======================================================================☆

