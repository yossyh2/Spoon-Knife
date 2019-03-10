/*--------------------------------------------------------
	CActHole.h
	�����:Hideki Yoshinari
	�쐬���t:2019/03/09
	����:
		�{�[���̃N���X
	����:
--------------------------------------------------------*/

#pragma once


#include "CActBase.h"

class CActHole :public CActBase {


public:

	//!	�R���X�g���N�^
	CActHole(int type, int order = 0);

	//!	�f�X�g���N�^
	virtual ~CActHole();

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
