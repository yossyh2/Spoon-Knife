/*--------------------------------------------------------
	class CNonCopyable.h
	»ìÒ:Hideki Yoshinari
	ì¬“ú•t:2019/03/09
	à–¾:
		boost‚Ìnoncopyable‚Ì‘ã‘Ö
	ƒƒ‚:
--------------------------------------------------------*/

#pragma once

class CNonCopyable
{
public:
	CNonCopyable() = default;
	CNonCopyable(const CNonCopyable&) = delete;
	CNonCopyable & operator=(const CNonCopyable) = delete;
};
