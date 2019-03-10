/*--------------------------------------------------------
	CActBase.h
	製作者:Hideki Yoshinari
	作成日付:2011/03/17
	説明:
		アクションの基底クラスです。
	メモ:
--------------------------------------------------------*/

#pragma once


#include "ITask.h"
#include <DirectXMath.h>


class CActBase :public ITask{

public:

	struct Vertex
	{
		DirectX::XMFLOAT3 position;
		DirectX::XMFLOAT4 color;
	};

	// カプセル判定
	struct CapsuleCol {
		DirectX::XMFLOAT3 start;	// 開始
		DirectX::XMFLOAT3 end;		// 終了
		float			  radius;	// 半径
	};

	// ボール判定
	struct SphereCol {
		DirectX::XMFLOAT3 center;	// 開始
		float			  radius;	// 半径
	};

	// コリジョンの形状
	enum class ColShapeType : int {
		None,
		Sphere,
		Capsule,
	};

public:

	//! オブジェクトID
	int			m_ObjId;

	//! 位置
	DirectX::XMFLOAT3	m_Pos = { 0.f,0.f,0.f };

	//! 登録位置
	DirectX::XMFLOAT3	m_PrePos = { 0.f,0.f,0.f };

	//! スタート位置
	DirectX::XMFLOAT3	m_FirstPos = { 0.f,0.f,0.f };

	//! 球判定
	SphereCol			m_SphereCol = { {0.f,0.f,0.f }, 0.f };

	//! カプセル判定
	CapsuleCol			m_CapsuleCol = { {0.f,0.f,0.f }, { 0.f,0.f,0.f },0.f };

	//! 判定
	ColShapeType		m_ShapeType = ColShapeType::None;

	//! 加速ベクトル
	DirectX::XMFLOAT3	m_AddSpd = { 0.f,0.f,0.f };

	//! 現在の速度ベクトル
	DirectX::XMFLOAT3	m_Spd = { 0.f,0.f,0.f };

public:

	//!	コンストラクタ
	CActBase(int type, int order = 0);

	//!	デストラクタ
	virtual ~CActBase();

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

