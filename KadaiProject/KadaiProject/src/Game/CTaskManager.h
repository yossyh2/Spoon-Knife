/*!--------------------------------------------------------
	CTaskManager.h
	�����:Hideki Yoshinari
	�쐬���t:2011/03/26
	����:
		�^�X�N�V�X�e���̃}�l�[�W���[
		ITask�N���X���p�����Ă���N���X�̓o�^���\�B
	����:
		�y���ӁI�I�z
		�q�^�X�N����̈����͒��ӂ��Ă��������B
		�e�^�X�N��Kill����č폜���ꂽ�ꍇ�A�q�^�X�N�������o�^����܂��B
		�q�^�X�N��Kill����Ă���ꍇ�́A�e�^�X�N���폜���ꂽ���̃t���[���ɍ폜�B
--------------------------------------------------------*/

#pragma once

#include <list>
#include <vector>
#include <memory>

//	�ˑ�
#include "ITask.h"


//	���X�g
typedef std::list<std::shared_ptr<ITask>> TaskList;

class CTaskManager
{
protected:
	TaskList m_TaskList;

	//!	�^�X�N�����X�g����폜
	virtual void Detach(std::shared_ptr<ITask> pTask);

	//! �^�X�N�폜�Ǘ�
	virtual void _TaskDelete();

	//! �^�X�N���s�Ǘ�
	virtual void _TaskProc();

	//! �^�X�N�`��Ǘ�
	virtual void _TaskDraw();

public:

	//! �R���X�g���N�^
	CTaskManager();

	//! �f�X�g���N�^
	virtual ~CTaskManager();

	//!	�^�X�N��o�^����B
	virtual void Attach(std::shared_ptr<ITask> pTask);

	//!	�^�X�N��S�폜
	virtual void AllDetach();

	//!	ITask::Proc()�Ăяo��
	//! �폜�v���������Ă���^�X�N�������Ń��X�g�����菜���B
	virtual void UpdateTask();

	//! ITask::Draw()�Ăяo��
	virtual void Draw();

	//!	�Y���^�X�N�ɍ폜�v�����o����Ă��Ȃ���
	virtual bool IsTaskAlive(int type);

	//!	�^�X�N���i�[����Ă��邩�ǂ���
	virtual bool HasTask();

	//!	�^�X�N���擾����B
	virtual std::shared_ptr<ITask> GetTask(int type);

};

