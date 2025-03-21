/*--------------------------------------------------------
	CActHole.cpp
	製作者:Hideki Yoshinari
	作成日付:2019/03/09
	説明:
		ボールのクラス
	メモ:
--------------------------------------------------------*/


#include "CActHole.h"


/*--------------------------------------------------------
　コンストラクタ
　機能：クラス初期化
	input:	ACTHDL	アクションハンドル
	return:	なし
--------------------------------------------------------*/
CActHole::CActHole(int type, int order)
	:CActBase(type, order)
{
	Reset();
}

/*--------------------------------------------------------
　デストラクタ
　機能：クラス破棄
	input:	なし
	return:	なし
--------------------------------------------------------*/
CActHole::~CActHole()
{
}

/*--------------------------------------------------------
　状態のリセット
	input:	なし
	return:	なし
--------------------------------------------------------*/
void	CActHole::Reset()
{
}

/*--------------------------------------------------------
　破棄
	input:	なし
	return:	なし
--------------------------------------------------------*/
void	CActHole::Destroy()
{
}


/*--------------------------------------------------------
　メイン前処理
　機能：毎ループ行う処理
	input:	なし
	return:	なし
--------------------------------------------------------*/
void	CActHole::PreProc()
{
}


/*--------------------------------------------------------
　メイン処理
　機能：毎ループ行う処理
	input:	なし
	return:	なし
--------------------------------------------------------*/
void	CActHole::Proc()
{
}

/*--------------------------------------------------------
　初期化
	input:	なし
	return:	なし
--------------------------------------------------------*/
void	CActHole::Init()
{
}


/*--------------------------------------------------------
　メイン後処理
　機能：毎ループ行う処理
	input:	なし
	return:	なし
--------------------------------------------------------*/
void	CActHole::PostProc()
{
}


/*--------------------------------------------------------
　メイン描画処理
　機能：毎ループ行う処理
	input:	なし
	return:	なし
--------------------------------------------------------*/
void	CActHole::Draw()
{
}
