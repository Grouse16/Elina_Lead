//����������������������������������������������//
// �ڍ�   �F���_���𐶐����邽�߂̏��̃N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_CREAT_VERTEX_BUFFER_INFORM_H_FILE
#define D_INCLUDE_GUARD_C_CREAT_VERTEX_BUFFER_INFORM_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <vector>


// �� �l�[���X�y�[�X �� //

// �O���t�B�b�N�𐧌䂷��V�X�e���̏��𐶐����邽�߂̏����Ăяo�����߂̖��O
namespace RENDERING::GRAPHICS::CREAT
{
	// �� �N���X �� //
	
	// ���_���𐶐����邽�߂̏��̃N���X
	class C_Creat_Vertex_Buffer_Inform
	{
		//==�� �p�u���b�N ��==//
	public:

		// �� �ϐ��錾 �� //
		int size_of_vertex = 0;	// ���_����̃T�C�Y
		int vertex_sum = 0;		// ���_��
		int index_sum = 0;		// �C���f�b�N�X��
	};
}


#endif // !D_INCLUDE_GUARD_C_CREAT_VERTEX_BUFFER_INFORM_H_FILE
