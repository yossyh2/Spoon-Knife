/*--------------------------------------------------------
	ITask.h
	製作者:Hideki Yoshinari
	作成日付:2011/04/03
	説明:
		タスクマネージャーに登録することができる
		インターフェイスクラス。
	メモ:
		インターフェイスクラスなので、あまり書かない
--------------------------------------------------------*/


#include "ITask.h"

/*--------------------------------------------------------
　コンストラクタ
	input:	int		タイプ（各タスクにつくタイプ。検索とかに使う。）
			int		オーダー。まだ何に使うか決めてない。
	return:	なし
--------------------------------------------------------*/
ITask::ITask(int type,	int order)
: m_Type(type)
, m_bKill(false)
, m_bActive(false)
, m_bPaused(false)
, m_bInit(false)
, m_TaskFlg(0)
{
}

/*--------------------------------------------------------
　デストラクタ
	input:	なし
	return:	なし
--------------------------------------------------------*/
ITask::~ITask()
{
}
/*--------------------------------------------------------
　登録チェック関数
	input:	なし
	return:	bool	(true:登録/false:非登録)
--------------------------------------------------------*/
bool ITask::IsAttached() const
{
	return (m_TaskFlg & TASKFLG_ATTACHED) ? true : false;
}

/*--------------------------------------------------------
　タスク登録設定
	input:	bool	(true:登録/false:非登録)
	return:	なし
--------------------------------------------------------*/
void ITask::SetAttached(const bool wantAttached)
{
	if(wantAttached){
		m_TaskFlg |= TASKFLG_ATTACHED;
	}
	else{
		m_TaskFlg &= ~TASKFLG_ATTACHED;
	}
}

/*--------------------------------------------------------
　依存プロセス設定
	input:	std::shared_ptr<ITask>	依存プロセス
	return:	なし
--------------------------------------------------------*/
void	ITask::SetNext(std::shared_ptr<ITask> pNext)
{
	m_pNext = pNext;

	//	アクティブにしておく。
	if(m_pNext){
		m_pNext->SetActive(true);
	}
}


/*--------------------------------------------------------
　メイン関数
	input:	なし
	return:	なし
--------------------------------------------------------*/
void ITask::Proc(){
	if(!IsInit()){
		Init();
		m_bInit = true;
	}
}

/*--------------------------------------------------------
　初期化
	input:	なし
	return:	なし
--------------------------------------------------------*/
void ITask::Init(){
}

/*--------------------------------------------------------
　描画
	input:	なし
	return:	なし
--------------------------------------------------------*/
void ITask::Draw(){
}

/*--------------------------------------------------------
　プロセス削除
	input:	なし
	return:	なし
--------------------------------------------------------*/
void ITask::Kill(){
	//	削除要請。
	m_bKill = true;
}
