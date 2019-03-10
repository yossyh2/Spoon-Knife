/*--------------------------------------------------------
	CTaskManager.h
	�����:Hideki Yoshinari
	�쐬���t:2011/03/26
	����:
		�^�X�N�V�X�e���̃}�l�[�W���[
		ITask�N���X���p�����Ă���N���X�̓o�^���\�B
	����:
--------------------------------------------------------*/
#include "CTaskManager.h"

/*--------------------------------------------------------
�@�R���X�g���N�^
	input:	�Ȃ�
	return:	�Ȃ�
--------------------------------------------------------*/
CTaskManager::CTaskManager()
{
}

/*--------------------------------------------------------
�@�f�X�g���N�^
	input:	�Ȃ�
	return:	�Ȃ�
--------------------------------------------------------*/
CTaskManager::~CTaskManager()
{
	AllDetach();
}

/*--------------------------------------------------------
�@�^�X�N��o�^����B
	input:	std::shared_ptr<ITask>	�o�^����^�X�N
	return:	�Ȃ�
--------------------------------------------------------*/
void CTaskManager::Attach(std::shared_ptr<ITask> pTask)
{
	//	�T�C�Y���傫������ꍇ�Aassert
	//assert(m_TaskList.size() == m_TaskList.max_size());

	m_TaskList.push_back(pTask);
	pTask->SetAttached(true);

	//	�����̃A�N�e�B�u�X�C�b�`ON�͂ǂ������������B
	//	�g�����������ԐT�d�ɂȂ�B
	pTask->SetActive(true);
}

/*--------------------------------------------------------
�@�^�X�N��S�폜
	input:	�Ȃ�
	return:	�Ȃ�
--------------------------------------------------------*/
void CTaskManager::AllDetach()
{
	TaskList::iterator i = m_TaskList.begin();
	TaskList::iterator end = m_TaskList.end();
	//	�Ō�܂Ń��[�v
	while(i != end){
		//	�S���폜
		Detach(* (i++) );
	}
}

/*--------------------------------------------------------
�@ITask::Proc()��ITask::Draw()�ƌĂяo���B
�@�폜�v���������Ă���^�X�N�������Ń��X�g�����菜���B
	input:	�Ȃ�
	return:	�Ȃ�
--------------------------------------------------------*/
void CTaskManager::UpdateTask()
{

	//	�폜�v�����o�Ă���ꍇ�A�폜���s���B
	_TaskDelete();

	//	Update
	_TaskProc();

}

/*--------------------------------------------------------
�@ITask::Proc()��ITask::Draw()�Ăяo���B
	input:	�Ȃ�
	return:	�Ȃ�
--------------------------------------------------------*/
void CTaskManager::Draw()
{
	//	Draw
	_TaskDraw();
}

/*--------------------------------------------------------
�@�Y���^�X�N�ɍ폜�v�����o����Ă��Ȃ���
	input:	int	�^�X�N�̃^�C�v�B�o�^���Ɍ���B
	return:	bool �폜�v�����o����Ă��Ȃ�������TRUE�B
--------------------------------------------------------*/
bool CTaskManager::IsTaskAlive(int type)
{
	TaskList::iterator i = m_TaskList.begin();
	TaskList::iterator end = m_TaskList.end();
	//	�Ō�܂Ń��[�v
	while(i != end){
		//	�r���ɊY�����Ă���^�X�N�����݂��A
		//	�����Ă�����̂���������true��Ԃ��B
		if((*i)->GetType() == type &&
			(!((*i)->IsDead()) || (*i)->GetNext())){
				return true;
		}
		
		++i;

	}
	return false;
}

/*--------------------------------------------------------
�@�^�X�N���i�[����Ă��邩�ǂ���
	input:	�Ȃ�
	return:	bool �^�X�N���}�l�[�W���[�Ɋi�[����Ă�����TRUE
--------------------------------------------------------*/
bool CTaskManager::HasTask()
{
	return !m_TaskList.empty();
}

/*--------------------------------------------------------
�@�^�X�N�����X�g����폜�B
	input:	std::shared_ptr<ITask>	�o�^����^�X�N
	return:	�Ȃ�
--------------------------------------------------------*/
void CTaskManager::Detach(std::shared_ptr<ITask> pTask)
{
	m_TaskList.remove(pTask);
	pTask->SetAttached(false);
}

/*--------------------------------------------------------
�@�^�X�N�폜�Ǘ��B
	input:	�Ȃ�
	return:	�Ȃ�
--------------------------------------------------------*/
void CTaskManager::_TaskDelete()
{
	TaskList::iterator i = m_TaskList.begin();
	TaskList::iterator end = m_TaskList.end();
	std::shared_ptr<ITask> pNext;
	//	�Ō�܂Ń��[�v
	while(i != end){
		std::shared_ptr<ITask> p( *i );
		++i;
		//	�q�v���Z�X���������ꍇ�A�A�^�b�`����B
		if(p->IsDead()){

			pNext = p->GetNext();
			if(pNext){
				p->SetNext(std::shared_ptr<ITask>((ITask* ) NULL));
				Attach(pNext);
			}
			//	���X�g����폜�B
			Detach(p);
		}

	}
}

/*--------------------------------------------------------
�@�^�X�N���擾����B
	input:	int	�^�X�NID
	return:	std::shared_ptr<ITask> �o�^����Ă���N���X
--------------------------------------------------------*/
std::shared_ptr<ITask> CTaskManager::GetTask(int type)
{
	TaskList::iterator i = m_TaskList.begin();
	TaskList::iterator end = m_TaskList.end();
	//	�Ō�܂Ń��[�v
	while(i != end){
		//	�r���ɊY�����Ă���^�X�N�����݂��A
		//	�����Ă�����̂���������true��Ԃ��B
		if((*i)->GetType() == type)	{
			std::shared_ptr<ITask> p( *i );
			return	p;
		}
		++i;
	}

	//	������Ȃ�������NULL��Ԃ��B
	return std::shared_ptr<ITask>();
}
/*--------------------------------------------------------
�@�^�X�N���s�Ǘ��B
	input:	�Ȃ�
	return:	�Ȃ�
--------------------------------------------------------*/
void CTaskManager::_TaskProc()
{
	TaskList::iterator i = m_TaskList.begin();
	TaskList::iterator end = m_TaskList.end();
	std::shared_ptr<ITask> pNext;

	//	�Ō�܂Ń��[�v
	while(i != end){
		std::shared_ptr<ITask> p( *i );
		++i;
		//	���s�B
		if(p->IsActive() && !p->IsPaused()){

			p->Proc();

			pNext = p->GetNext();
			if(pNext){
				pNext->Proc();
			}
		}

	}
}

/*--------------------------------------------------------
�@�^�X�N���s�Ǘ��B
	input:	�Ȃ�
	return:	�Ȃ�
--------------------------------------------------------*/
void CTaskManager::_TaskDraw()
{
	TaskList::iterator i = m_TaskList.begin();
	TaskList::iterator end = m_TaskList.end();
	std::shared_ptr<ITask> pNext;

	//	�Ō�܂Ń��[�v
	while(i != end){
		std::shared_ptr<ITask> p( *i );
		++i;
		//	���s�B
		if(p->IsActive() && !p->IsPaused()){

			p->Draw();

			pNext = p->GetNext();
			if(pNext){
				pNext->Draw();
			}

		}

	}
}