/*--------------------------------------------------------
	CActBall.cpp
	製作者:Hideki Yoshinari
	作成日付:2019/03/09
	説明:
		ボールのクラス
	メモ:
--------------------------------------------------------*/


#include "CActBall.h"


/*--------------------------------------------------------
　コンストラクタ
　機能：クラス初期化
	input:	ACTHDL	アクションハンドル
	return:	なし
--------------------------------------------------------*/
CActBall::CActBall(int type, int order)
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
CActBall::~CActBall()
{
}

/*--------------------------------------------------------
　状態のリセット
	input:	なし
	return:	なし
--------------------------------------------------------*/
void	CActBall::Reset()
{
}

/*--------------------------------------------------------
　破棄
	input:	なし
	return:	なし
--------------------------------------------------------*/
void	CActBall::Destroy()
{
}


/*--------------------------------------------------------
　メイン前処理
　機能：毎ループ行う処理
	input:	なし
	return:	なし
--------------------------------------------------------*/
void	CActBall::PreProc()
{
}


/*--------------------------------------------------------
　メイン処理
　機能：毎ループ行う処理
	input:	なし
	return:	なし
--------------------------------------------------------*/
void	CActBall::Proc()
{
}

/*--------------------------------------------------------
　初期化
	input:	なし
	return:	なし
--------------------------------------------------------*/
void	CActBall::Init()
{
}


/*--------------------------------------------------------
　メイン後処理
　機能：毎ループ行う処理
	input:	なし
	return:	なし
--------------------------------------------------------*/
void	CActBall::PostProc()
{
}


/*--------------------------------------------------------
　メイン描画処理
　機能：毎ループ行う処理
	input:	なし
	return:	なし
--------------------------------------------------------*/
void	CActBall::Draw()
{
}
