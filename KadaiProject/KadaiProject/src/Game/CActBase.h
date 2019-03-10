/*--------------------------------------------------------
	CActBase.h
	�����:Hideki Yoshinari
	�쐬���t:2011/03/17
	����:
		�A�N�V�����̊��N���X�ł��B
	����:
--------------------------------------------------------*/

#pragma once


#include "ITask.h"
#include <DirectXMath.h>


class CActBase :public ITask{

public:

	struct Vertex
	{
		DirectX::XMFLOAT3 position;
		DirectX::XMFLOAT4 color;
	};

	// �J�v�Z������
	struct CapsuleCol {
		DirectX::XMFLOAT3 start;	// �J�n
		DirectX::XMFLOAT3 end;		// �I��
		float			  radius;	// ���a
	};

	// �{�[������
	struct SphereCol {
		DirectX::XMFLOAT3 center;	// �J�n
		float			  radius;	// ���a
	};

	// �R���W�����̌`��
	enum class ColShapeType : int {
		None,
		Sphere,
		Capsule,
	};

public:

	//! �I�u�W�F�N�gID
	int			m_ObjId;

	//! �ʒu
	DirectX::XMFLOAT3	m_Pos = { 0.f,0.f,0.f };

	//! �o�^�ʒu
	DirectX::XMFLOAT3	m_PrePos = { 0.f,0.f,0.f };

	//! �X�^�[�g�ʒu
	DirectX::XMFLOAT3	m_FirstPos = { 0.f,0.f,0.f };

	//! ������
	SphereCol			m_SphereCol = { {0.f,0.f,0.f }, 0.f };

	//! �J�v�Z������
	CapsuleCol			m_CapsuleCol = { {0.f,0.f,0.f }, { 0.f,0.f,0.f },0.f };

	//! ����
	ColShapeType		m_ShapeType = ColShapeType::None;

	//! �����x�N�g��
	DirectX::XMFLOAT3	m_AddSpd = { 0.f,0.f,0.f };

	//! ���݂̑��x�x�N�g��
	DirectX::XMFLOAT3	m_Spd = { 0.f,0.f,0.f };

public:

	//!	�R���X�g���N�^
	CActBase(int type, int order = 0);

	//!	�f�X�g���N�^
	virtual ~CActBase();

	//	��Ԃ̃��Z�b�g
	virtual void	Reset();

	//!	�N���X�Ƃ��̔j��
	virtual void	Destroy();

	//!	�����[�v�s������
	virtual void	PreProc();
	virtual void	Proc();
	virtual void	PostProc();
	
	//!	�����[�v�s������
	virtual void	Draw();

	//! ���������s������
	virtual void	Init();

};

