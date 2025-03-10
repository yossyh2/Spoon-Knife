/*--------------------------------------------------------
	CActFloor.cpp
	製作者:Hideki Yoshinari
	作成日付:2019/03/09
	説明:
		ボールのクラス
	メモ:
--------------------------------------------------------*/


#include "CActFloor.h"


/*--------------------------------------------------------
　コンストラクタ
　機能：クラス初期化
	input:	ACTHDL	アクションハンドル
	return:	なし
--------------------------------------------------------*/
CActFloor::CActFloor(int type, int order)
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
CActFloor::~CActFloor()
{
}

/*--------------------------------------------------------
　状態のリセット
	input:	なし
	return:	なし
--------------------------------------------------------*/
void	CActFloor::Reset()
{
}

/*--------------------------------------------------------
　破棄
	input:	なし
	return:	なし
--------------------------------------------------------*/
void	CActFloor::Destroy()
{
}


/*--------------------------------------------------------
　メイン前処理
　機能：毎ループ行う処理
	input:	なし
	return:	なし
--------------------------------------------------------*/
void	CActFloor::PreProc()
{
}


/*--------------------------------------------------------
　メイン処理
　機能：毎ループ行う処理
	input:	なし
	return:	なし
--------------------------------------------------------*/
void	CActFloor::Proc()
{
}

/*--------------------------------------------------------
　初期化
	input:	なし
	return:	なし
--------------------------------------------------------*/
void	CActFloor::Init()
{
}


/*--------------------------------------------------------
　メイン後処理
　機能：毎ループ行う処理
	input:	なし
	return:	なし
--------------------------------------------------------*/
void	CActFloor::PostProc()
{
}


/*--------------------------------------------------------
　メイン描画処理
　機能：毎ループ行う処理
	input:	なし
	return:	なし
--------------------------------------------------------*/
void	CActFloor::Draw()
{
}
