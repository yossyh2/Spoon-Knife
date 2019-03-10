/*!--------------------------------------------------------
	ITask.h
	�����:Hideki Yoshinari
	�쐬���t:2011/04/03
	����:
		�^�X�N�}�l�[�W���[�ɓo�^���邱�Ƃ��ł���
		�C���^�[�t�F�C�X�N���X�B
--------------------------------------------------------*/

#pragma once

//	��{
#include "CNonCopyable.h"
#include <memory>

class	ITask: private CNonCopyable {

	friend class CTaskManager;

protected:
	int		m_Type;					//	���̃^�C�v�͂Ȃɂ��B
	bool	m_bKill;				//	���̃v���Z�X�͏������邩�B
	bool	m_bActive;				//	�����Ă��邩
	bool	m_bPaused;				//	�~�܂��Ă��邩
	bool	m_bInit;				//	���������ĂȂ�������true
	std::shared_ptr<ITask>	m_pNext;	//	�ˑ��v���Z�X
	
private:
	//	�t���O�Ǘ��[
	enum TASKFLG{
		TASKFLG_ATTACHED = 1<<0,
	};

	unsigned int		m_TaskFlg;		//	�v���Z�X�t���O

public:
	//!	�R���X�g���N�^
	ITask(int type,	int order = 0);

	//!	�f�X�g���N�^
	virtual ~ITask();
public:

	//! �^�C�v���擾����B
	int		GetType()	const { return m_Type; }

	//!	�v���Z�X���������邩
	bool	IsDead()	const {	return m_bKill; }

	//!	�~�܂��Ă��邩
	bool	IsPaused()	const {	return m_bPaused; }

	//! �|�[�Y�ݒ�|�[�Y��������������true
	void	SetPause(bool wantPause) { m_bPaused = wantPause; }

	//! �|�[�Y���Ă���true
	bool	IsPause()	const { return m_bPaused; }

	//!	���������Ă���true
	bool	IsInit()	const {	return m_bInit; }
	
	//!	�ˑ��v���Z�X�擾
	std::shared_ptr<ITask>	GetNext()	{ return m_pNext; }
	//!	�ˑ��v���Z�X�ݒ�
	void	SetNext(std::shared_ptr<ITask> pNext);

	//!	�����Ă��邩
	bool	IsActive()	const {	return m_bActive; }
	//! �����Ă��邩�ݒ�
	void	SetActive(bool wantActive) { m_bActive = wantActive; }

	//!	�}�l�[�W���[�ɓo�^����Ă��邩
	bool			IsAttached()const;
	//! �}�l�[�W���[�o�^�ݒ�
	void			SetAttached(const bool wantAttached);


	//!	���C���֐�
	virtual	void Proc();

	//!	������
	virtual	void Init();

	//!	�`��
	virtual	void Draw();

	//!	�v���Z�X�폜
	virtual void Kill();

};

