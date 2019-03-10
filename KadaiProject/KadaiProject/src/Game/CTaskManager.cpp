/*--------------------------------------------------------
	CTaskManager.h
	製作者:Hideki Yoshinari
	作成日付:2011/03/26
	説明:
		タスクシステムのマネージャー
		ITaskクラスを継承しているクラスの登録が可能。
	メモ:
--------------------------------------------------------*/
#include "CTaskManager.h"

/*--------------------------------------------------------
　コンストラクタ
	input:	なし
	return:	なし
--------------------------------------------------------*/
CTaskManager::CTaskManager()
{
}

/*--------------------------------------------------------
　デストラクタ
	input:	なし
	return:	なし
--------------------------------------------------------*/
CTaskManager::~CTaskManager()
{
	AllDetach();
}

/*--------------------------------------------------------
　タスクを登録する。
	input:	std::shared_ptr<ITask>	登録するタスク
	return:	なし
--------------------------------------------------------*/
void CTaskManager::Attach(std::shared_ptr<ITask> pTask)
{
	//	サイズが大きすぎる場合、assert
	//assert(m_TaskList.size() == m_TaskList.max_size());

	m_TaskList.push_back(pTask);
	pTask->SetAttached(true);

	//	ここのアクティブスイッチONはどうすっか検討。
	//	使い方がだいぶ慎重になる。
	pTask->SetActive(true);
}

/*--------------------------------------------------------
　タスクを全削除
	input:	なし
	return:	なし
--------------------------------------------------------*/
void CTaskManager::AllDetach()
{
	TaskList::iterator i = m_TaskList.begin();
	TaskList::iterator end = m_TaskList.end();
	//	最後までループ
	while(i != end){
		//	全部削除
		Detach(* (i++) );
	}
}

/*--------------------------------------------------------
　ITask::Proc()とITask::Draw()と呼び出し。
　削除要求が入っているタスクもここでリストから取り除く。
	input:	なし
	return:	なし
--------------------------------------------------------*/
void CTaskManager::UpdateTask()
{

	//	削除要請が出ている場合、削除を行う。
	_TaskDelete();

	//	Update
	_TaskProc();

}

/*--------------------------------------------------------
　ITask::Proc()とITask::Draw()呼び出し。
	input:	なし
	return:	なし
--------------------------------------------------------*/
void CTaskManager::Draw()
{
	//	Draw
	_TaskDraw();
}

/*--------------------------------------------------------
　該当タスクに削除要求が出されていないか
	input:	int	タスクのタイプ。登録時に決定。
	return:	bool 削除要求が出されていなかったらTRUE。
--------------------------------------------------------*/
bool CTaskManager::IsTaskAlive(int type)
{
	TaskList::iterator i = m_TaskList.begin();
	TaskList::iterator end = m_TaskList.end();
	//	最後までループ
	while(i != end){
		//	途中に該当しているタスクが存在かつ、
		//	生きているものがあったらtrueを返す。
		if((*i)->GetType() == type &&
			(!((*i)->IsDead()) || (*i)->GetNext())){
				return true;
		}
		
		++i;

	}
	return false;
}

/*--------------------------------------------------------
　タスクが格納されているかどうか
	input:	なし
	return:	bool タスクがマネージャーに格納されていたらTRUE
--------------------------------------------------------*/
bool CTaskManager::HasTask()
{
	return !m_TaskList.empty();
}

/*--------------------------------------------------------
　タスクをリストから削除。
	input:	std::shared_ptr<ITask>	登録するタスク
	return:	なし
--------------------------------------------------------*/
void CTaskManager::Detach(std::shared_ptr<ITask> pTask)
{
	m_TaskList.remove(pTask);
	pTask->SetAttached(false);
}

/*--------------------------------------------------------
　タスク削除管理。
	input:	なし
	return:	なし
--------------------------------------------------------*/
void CTaskManager::_TaskDelete()
{
	TaskList::iterator i = m_TaskList.begin();
	TaskList::iterator end = m_TaskList.end();
	std::shared_ptr<ITask> pNext;
	//	最後までループ
	while(i != end){
		std::shared_ptr<ITask> p( *i );
		++i;
		//	子プロセスがあった場合、アタッチする。
		if(p->IsDead()){

			pNext = p->GetNext();
			if(pNext){
				p->SetNext(std::shared_ptr<ITask>((ITask* ) NULL));
				Attach(pNext);
			}
			//	リストから削除。
			Detach(p);
		}

	}
}

/*--------------------------------------------------------
　タスクを取得する。
	input:	int	タスクID
	return:	std::shared_ptr<ITask> 登録されているクラス
--------------------------------------------------------*/
std::shared_ptr<ITask> CTaskManager::GetTask(int type)
{
	TaskList::iterator i = m_TaskList.begin();
	TaskList::iterator end = m_TaskList.end();
	//	最後までループ
	while(i != end){
		//	途中に該当しているタスクが存在かつ、
		//	生きているものがあったらtrueを返す。
		if((*i)->GetType() == type)	{
			std::shared_ptr<ITask> p( *i );
			return	p;
		}
		++i;
	}

	//	見つからなかったらNULLを返す。
	return std::shared_ptr<ITask>();
}
/*--------------------------------------------------------
　タスク実行管理。
	input:	なし
	return:	なし
--------------------------------------------------------*/
void CTaskManager::_TaskProc()
{
	TaskList::iterator i = m_TaskList.begin();
	TaskList::iterator end = m_TaskList.end();
	std::shared_ptr<ITask> pNext;

	//	最後までループ
	while(i != end){
		std::shared_ptr<ITask> p( *i );
		++i;
		//	実行。
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
　タスク実行管理。
	input:	なし
	return:	なし
--------------------------------------------------------*/
void CTaskManager::_TaskDraw()
{
	TaskList::iterator i = m_TaskList.begin();
	TaskList::iterator end = m_TaskList.end();
	std::shared_ptr<ITask> pNext;

	//	最後までループ
	while(i != end){
		std::shared_ptr<ITask> p( *i );
		++i;
		//	実行。
		if(p->IsActive() && !p->IsPaused()){

			p->Draw();

			pNext = p->GetNext();
			if(pNext){
				pNext->Draw();
			}

		}

	}
}