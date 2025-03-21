/*--------------------------------------------------------
	class CNonCopyable.h
	製作者:Hideki Yoshinari
	作成日付:2019/03/09
	説明:
		boostのnoncopyableの代替
	メモ:
--------------------------------------------------------*/

#pragma once

class CNonCopyable
{
public:
	CNonCopyable() = default;
	CNonCopyable(const CNonCopyable&) = delete;
	CNonCopyable & operator=(const CNonCopyable) = delete;
};
