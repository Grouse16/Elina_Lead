using SharpDX;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3D_Model_Converter_And_Drawer.Rendering_Systems.Camera
{
	// ☆ クラス ☆ //

	// カメラ制御システムのクラス
	public class CS_Camera_Manager
	{
		// ☆ 変数宣言 ☆ //
		static private CS_Camera_Manager m_instance = new CS_Camera_Manager(); // カメラ制御システムのクラスのインスタンス（シングルトン化）

		static private CS_Camera_System m_camera_system = new CS_Camera_System(); // カメラシステムのクラス

		static private SharpDX.Vector3 m_target_position = new SharpDX.Vector3(); // カメラの目標の位置座標

		static private float m_camera_distance = 10.0f;         // カメラの目標からの距離
		static private float m_camera_angle_by_target = 0.0f;   // カメラの目標からの角度
		static private float m_camera_height = 0.0f;            // カメラの高さ


		// ☆ プロパティ ☆ //

		// カメラシステムのクラス
		static public CS_Camera_System mp_camera_system
		{
			// ゲッタ
			get
			{
				return m_camera_system;
			}
		}


		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// コンストラクタ
		private CS_Camera_Manager()
		{
			M_Set_Target_To_Camera_Distance(10.0f);

			return;
		}


		//-☆- 更新 -☆-//

		// カメラの目標からの距離と角度からカメラの座標と角度を更新
		public static void M_Update_Camera_Position_And_Angle_By_Target()
		{
			// ☆ 変数宣言 ☆ //
			Vector3 target_to_set_camera_position_dire_vector = new Vector3();	// カメラの目標からカメラの座標への方向ベクトル
			
			
			// カメラのクラスを初期化
			m_camera_system = new CS_Camera_System();
			
			
            // 目的地からの角度からカメラの座標への方向ベクトルを設定
            target_to_set_camera_position_dire_vector = new Vector3
			(
				(float)Math.Sin(m_camera_angle_by_target),
				m_camera_height,
				(float)Math.Cos(m_camera_angle_by_target)
			);

            // カメラ目標への方向ベクトルを正規化
            target_to_set_camera_position_dire_vector = CS_My_Math_System.M_Normalize_Vector(target_to_set_camera_position_dire_vector);

			// カメラの目標からの距離からカメラの座標を設定
			m_camera_system.mp_position.mp_pos = m_target_position + -target_to_set_camera_position_dire_vector * m_camera_distance;

            // カメラの目標への方向ベクトルからカメラの角度を設定
            m_camera_system.mp_camera_rotation.mp_rotation = SharpDX.Quaternion.RotationAxis(-target_to_set_camera_position_dire_vector, 0.0f);

			return;
		}


		//-☆- セッタ -☆-//

		// カメラの目標からの角度をセット　引数：カメラの目標からの角度
		static public void M_Set_Target_To_Camera_Angle(float in_angle)
		{
			m_camera_angle_by_target = in_angle;
			M_Update_Camera_Position_And_Angle_By_Target();

			return;
		}


		// カメラの目標からの距離をセット　引数：カメラの目標からの距離
		static public void M_Set_Target_To_Camera_Distance(float in_distance)
		{
			m_camera_distance = in_distance;
			M_Update_Camera_Position_And_Angle_By_Target();

			return;
		}


		// カメラの目標の位置座標をセット　引数：カメラの目標の位置座標
		static public void M_Set_Camera_Target_Position(Vector3 in_position)
		{
			m_target_position = in_position;
			M_Update_Camera_Position_And_Angle_By_Target();

			return;
		}
	}
}
