//---------------------------------------------------------------------------

#ifndef hahaha_xmlH
#define hahaha_xmlH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

class hahaha_xml
{
public:
	hahaha_xml();
	~hahaha_xml();

	hahaha_xml(const hahaha_xml& hx);
    hahaha_xml(hahaha_xml&& hx) noexcept;
	hahaha_xml& operator=(const hahaha_xml& hx);
    hahaha_xml& operator=(hahaha_xml&& hx) noexcept;
	void Copy(const hahaha_xml& hx);
    void Move(hahaha_xml&& hx) noexcept;
public:
	int Reset();

public:

};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
