/*!--------------------------------------------------------
	CTaskManager.h
	製作者:Hideki Yoshinari
	作成日付:2011/03/26
	説明:
		タスクシステムのマネージャー
		ITaskクラスを継承しているクラスの登録が可能。
	メモ:
		【注意！！】
		子タスク周りの扱いは注意してください。
		親タスクがKillされて削除された場合、子タスクが自動登録されます。
		子タスクもKillされている場合は、親タスクが削除された次のフレームに削除。
--------------------------------------------------------*/

#pragma once

#include <list>
#include <vector>
#include <memory>

//	依存
#include "ITask.h"


//	リスト
typedef std::list<std::shared_ptr<ITask>> TaskList;

class CTaskManager
{
protected:
	TaskList m_TaskList;

	//!	タスクをリストから削除
	virtual void Detach(std::shared_ptr<ITask> pTask);

	//! タスク削除管理
	virtual void _TaskDelete();

	//! タスク実行管理
	virtual void _TaskProc();

	//! タスク描画管理
	virtual void _TaskDraw();

public:

	//! コンストラクタ
	CTaskManager();

	//! デストラクタ
	virtual ~CTaskManager();

	//!	タスクを登録する。
	virtual void Attach(std::shared_ptr<ITask> pTask);

	//!	タスクを全削除
	virtual void AllDetach();

	//!	ITask::Proc()呼び出し
	//! 削除要求が入っているタスクもここでリストから取り除く。
	virtual void UpdateTask();

	//! ITask::Draw()呼び出し
	virtual void Draw();

	//!	該当タスクに削除要求が出されていないか
	virtual bool IsTaskAlive(int type);

	//!	タスクが格納されているかどうか
	virtual bool HasTask();

	//!	タスクを取得する。
	virtual std::shared_ptr<ITask> GetTask(int type);

};

