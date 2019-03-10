/*!--------------------------------------------------------
	ITask.h
	製作者:Hideki Yoshinari
	作成日付:2011/04/03
	説明:
		タスクマネージャーに登録することができる
		インターフェイスクラス。
--------------------------------------------------------*/

#pragma once

//	基本
#include "CNonCopyable.h"
#include <memory>

class	ITask: private CNonCopyable {

	friend class CTaskManager;

protected:
	int		m_Type;					//	このタイプはなにか。
	bool	m_bKill;				//	このプロセスは消去するか。
	bool	m_bActive;				//	動いているか
	bool	m_bPaused;				//	止まっているか
	bool	m_bInit;				//	初期化してなかったらtrue
	std::shared_ptr<ITask>	m_pNext;	//	依存プロセス
	
private:
	//	フラグ管理票
	enum TASKFLG{
		TASKFLG_ATTACHED = 1<<0,
	};

	unsigned int		m_TaskFlg;		//	プロセスフラグ

public:
	//!	コンストラクタ
	ITask(int type,	int order = 0);

	//!	デストラクタ
	virtual ~ITask();
public:

	//! タイプを取得する。
	int		GetType()	const { return m_Type; }

	//!	プロセスを消去するか
	bool	IsDead()	const {	return m_bKill; }

	//!	止まっているか
	bool	IsPaused()	const {	return m_bPaused; }

	//! ポーズ設定ポーズさせたかったらtrue
	void	SetPause(bool wantPause) { m_bPaused = wantPause; }

	//! ポーズしてたらtrue
	bool	IsPause()	const { return m_bPaused; }

	//!	初期化してたらtrue
	bool	IsInit()	const {	return m_bInit; }
	
	//!	依存プロセス取得
	std::shared_ptr<ITask>	GetNext()	{ return m_pNext; }
	//!	依存プロセス設定
	void	SetNext(std::shared_ptr<ITask> pNext);

	//!	動いているか
	bool	IsActive()	const {	return m_bActive; }
	//! 動いているか設定
	void	SetActive(bool wantActive) { m_bActive = wantActive; }

	//!	マネージャーに登録されているか
	bool			IsAttached()const;
	//! マネージャー登録設定
	void			SetAttached(const bool wantAttached);


	//!	メイン関数
	virtual	void Proc();

	//!	初期化
	virtual	void Init();

	//!	描画
	virtual	void Draw();

	//!	プロセス削除
	virtual void Kill();

};

