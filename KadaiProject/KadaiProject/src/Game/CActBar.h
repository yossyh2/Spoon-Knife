/*--------------------------------------------------------
	CActBar.h
	製作者:Hideki Yoshinari
	作成日付:2019/03/09
	説明:
		ボールのクラス
	メモ:
--------------------------------------------------------*/

#pragma once


#include "CActBase.h"

class CActBar :public CActBase {


public:

	//!	コンストラクタ
	CActBar(int type, int order = 0);

	//!	デストラクタ
	virtual ~CActBar();

	//	状態のリセット
	virtual void	Reset();

	//!	クラスとかの破棄
	virtual void	Destroy();

	//!	毎ループ行う処理
	virtual void	PreProc();
	virtual void	Proc();
	virtual void	PostProc();

	//!	毎ループ行う処理
	virtual void	Draw();

	//! 初期化を行う処理
	virtual void	Init();


};
