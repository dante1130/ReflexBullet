// SoundTime.cpp: implementation of the CSoundTime class.
//
//////////////////////////////////////////////////////////////////////

#include "SoundTime.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CSoundTime::CSoundTime(Uint32 time)
{
	m_time = time;
	// convert to mins, sec and ms from time
	ConvertToMinSecMs();
}

CSoundTime::CSoundTime(int min, int sec, int ms)
	: m_minutes(min), m_seconds(sec), m_milliseconds(ms)
{
	// convert to time from mins, sec and ms
	Uint32 m_time = ConvertToSDLTime();
}

CSoundTime::~CSoundTime()
{
}

Uint32	CSoundTime::GetSDLTime()
{
	return (Uint32)m_time;
}


CSoundTime & CSoundTime::operator+= (CSoundTime *)
{
	return *this;
}

CSoundTime & CSoundTime::operator-= (CSoundTime *)
{
	return *this;
}

CSoundTime & CSoundTime::operator+= (int)
{
	return *this;
}

CSoundTime & CSoundTime::operator-= (int)
{
	return *this;
}

CSoundTime & CSoundTime::operator++ ()
{
	return *this;
}

CSoundTime & CSoundTime::operator-- ()
{
	return *this;
}

//int CSoundTime::operator== (const CSoundTime& cst1, const CSoundTime& cst2)
//{
//	return 0;
//}
				
int CSoundTime::operator== (const CSoundTime& cst)
{
	return 0;
}
	
void CSoundTime::addMin(int mins)
{
}

void CSoundTime::addSec(int seconds)
{
}

void CSoundTime::addMS(int milliseconds)
{
}

void CSoundTime::ConvertToMinSecMs()
{
	Uint32 tempTime = m_time;

	m_minutes = tempTime / 60000.0;
	tempTime -= m_minutes * 60000.0;

	m_seconds = tempTime / 1000.0;
	tempTime -= m_minutes * 1000.0;

	m_milliseconds = tempTime;
}

Uint32 CSoundTime::ConvertToSDLTime()
{
	double tempTime = (double)m_minutes * 600000.0 + (double)m_seconds * 1000.0 + (double)m_milliseconds;
	return (Uint32)tempTime;
}
