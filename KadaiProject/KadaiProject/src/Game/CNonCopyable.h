/*--------------------------------------------------------
	class CNonCopyable.h
	�����:Hideki Yoshinari
	�쐬���t:2019/03/09
	����:
		boost��noncopyable�̑��
	����:
--------------------------------------------------------*/

#pragma once

class CNonCopyable
{
public:
	CNonCopyable() = default;
	CNonCopyable(const CNonCopyable&) = delete;
	CNonCopyable & operator=(const CNonCopyable) = delete;
};
