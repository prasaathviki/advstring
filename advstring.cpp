/*
*   author : prasaathviki@gmail.com
*   advstring is a string class with advance options.
*
*/
#include "advstring.h"

std::string advstring::inttostring(int nValue)
{
	std::stringstream ss;
	ss << nValue;
	return ss.str();
}
std::string advstring::floattostring(float nValue)
{
	std::stringstream ss;
	ss << nValue;
	return ss.str();
}

std::string advstring::doubletostring(double nValue)
{
	std::ostringstream out;
	out << std::fixed << nValue;
	return out.str();
}
int advstring::stringtoint(std::string sValue)
{
	int nValue(0);
	std::stringstream ss(sValue);
	ss >> nValue;
	return nValue;
}
float advstring::stringtofloat(std::string sValue)
{
	float nValue(0.0);
	std::stringstream ss(sValue);
	ss >> nValue;
	return nValue;
}
double advstring::stringtodouble(std::string sValue)
{
	double nValue(0.0);
	std::stringstream ss(sValue);
	ss >> nValue;
	return nValue;
}
advstring::advstring()
{
	this->m_sValue = "";
}
advstring::advstring(std::string sValue)
{
	this->m_sValue = sValue;
}
advstring::advstring(int nValue)
{
	this->m_sValue = inttostring(nValue);
}
advstring::advstring(float nValue)
{
	this->m_sValue = floattostring(nValue);
}
advstring::advstring(double nValue)
{
	this->m_sValue = doubletostring(nValue);
}
advstring::advstring(const char *pcchValue)
{
	this->m_sValue = pcchValue;
}
std::string advstring::getClass()
{
	return "advstring";
}
void  advstring::DispString()
{
	cout<<this->m_sValue.c_str();
}
void  advstring::DispStringEndl()
{
	cout<<this->m_sValue.c_str()<<endl;
}
void advstring::operator = (std::string sValue)
{
	this->m_sValue = sValue;
}
void advstring::operator = (advstring asValue)
{
	this->m_sValue = asValue.m_sValue;
}
void advstring::operator = (const char *pcchValue)
{
	this->m_sValue = pcchValue;
}
advstring advstring::operator + (advstring asValue)
{
	return (advstring(this->m_sValue + asValue.m_sValue));
}
advstring advstring::operator + (const char *pcchValue)
{
	return (advstring(this->m_sValue + pcchValue));
}
advstring advstring::operator + (int nValue)
{
	return (advstring(this->m_sValue + inttostring(nValue)));
}
advstring advstring::operator + (float nValue)
{
	return (advstring(this->m_sValue + floattostring(nValue)));
}
advstring advstring::operator + (double nValue)
{
	return (advstring(this->m_sValue + doubletostring(nValue)));
}
void advstring::operator += (advstring asValue)
{
	this->m_sValue = this->m_sValue + asValue.m_sValue;
}
void advstring::operator += (int nValue)
{
	this->m_sValue = this->m_sValue + inttostring(nValue);
}
void advstring::operator += (float nValue)
{
	this->m_sValue = this->m_sValue + floattostring(nValue);
}
void advstring::operator += (double nValue)
{
	this->m_sValue = this->m_sValue + doubletostring(nValue);
}
bool advstring::operator == (advstring asValue)
{
	if(this->m_sValue == asValue.m_sValue)
		return true;
	else
		return false;
}
bool advstring::operator == (int nValue)
{
	if(this->m_sValue == inttostring(nValue))
		return true;
	else
		return false;
}
bool advstring::operator == (float nValue)
{
	if(this->m_sValue == floattostring(nValue))
		return true;
	else
		return false;
}
bool advstring::operator == (double nValue)
{
	if(this->m_sValue == doubletostring(nValue))
		return true;
	else
		return false;
}
bool advstring::operator == (const char* pcchValue)
{
	if(this->m_sValue == pcchValue)
		return true;
	else
		return false;
}
bool advstring::operator != (advstring asValue)
{
	if(this->m_sValue != asValue.m_sValue)
		return true;
	else
		return false;
}
bool advstring::operator != (int nValue)
{
	if(this->m_sValue != inttostring(nValue))
		return true;
	else
		return false;
}
bool advstring::operator != (float nValue)
{
	if(this->m_sValue != floattostring(nValue))
		return true;
	else
		return false;
}
bool advstring::operator != (double nValue)
{
	if(this->m_sValue != doubletostring(nValue))
		return true;
	else
		return false;
}
bool advstring::operator != (const char* pcchValue)
{
	if(this->m_sValue != pcchValue)
		return true;
	else
		return false;
}
advstring::operator int()	
{
	return stringtoint(this->m_sValue);
}
advstring::operator float()	
{
	return stringtofloat(this->m_sValue);
}
advstring::operator double()	
{
	return stringtodouble(this->m_sValue);
}
advstring::operator const char*()	
{
	return this->m_sValue.c_str();
}
advstring::operator char*()
{
	// Please delete the chNewValue after usage. if not deleted it may cause memory leak.
	char * chNewValue = new char[this->m_sValue.size() + 1];
	std::copy(this->m_sValue.begin(), this->m_sValue.end(), chNewValue);
	chNewValue[this->m_sValue.size()] = '\0'; 
	return chNewValue;
}
std::string advstring::toStdString()
{
	return this->m_sValue;
}
void advstring::Empty()
{
	this->m_sValue.clear();
}
const char* advstring::GetBuffer()
{
	return this->m_sValue.c_str();
}
int advstring::GetLength()
{
	return this->m_sValue.size();
}
int advstring::MaxSize()
{
	return this->m_sValue.capacity();
}
bool advstring::IsEmpty()
{
	return this->m_sValue.empty();
}
char advstring::GetAt(int nIndex)
{
	assert(0 <= nIndex && nIndex <= (int)this->m_sValue.size());
	return this->m_sValue[nIndex];
}
void advstring::SetAt(int nIndex,char chValue)
{
	assert(0 <= nIndex && nIndex < (int)this->m_sValue.size());
	this->m_sValue[nIndex] = chValue;
}
int advstring::Insert(int nIndex,char chValue)
{
	int nLength = this->m_sValue.size();

	if (nIndex < 0)
		nIndex = 0;
	if( nIndex > nLength)
		nIndex = nLength;

	this->m_sValue.insert(nIndex,1,chValue);

	return this->m_sValue.size();
}
int advstring::Insert(int nIndex,advstring asValue)
{
	int nLength = this->m_sValue.size();

	if (nIndex < 0)
		nIndex = 0;
	if( nIndex > nLength)
		nIndex = nLength;

	this->m_sValue.insert(nIndex,asValue.m_sValue.c_str(),(int)asValue.m_sValue.size());
	return this->m_sValue.size();
}
int advstring::Replace(char chOldValue,char chNewValue)
{
	int nReplaceCount(0);
	if(chOldValue == chNewValue)
		return nReplaceCount;
	int sSize = this->m_sValue.size();
	for(int x = 0;x< sSize;x++)
	{
		char chCurChar = this->m_sValue[x];
		if(chCurChar == chOldValue)
		{
			this->m_sValue[x]  = chNewValue;
			nReplaceCount++;
		}
	}
	return nReplaceCount;
}
int advstring::Replace(advstring asOldValue,advstring asNewValue)
{
	int nReplaceCount(0);

	if(asOldValue.m_sValue.empty())
		return 0;
	size_t start_pos = 0;
	while((start_pos = this->m_sValue.find(asOldValue.m_sValue, start_pos)) != std::string::npos) 
	{
		this->m_sValue.replace(start_pos, asOldValue.m_sValue.length(), asNewValue.m_sValue);
		start_pos += asNewValue.m_sValue.length(); 
		nReplaceCount++;
	}
	return nReplaceCount;
}
void advstring::Remove(char chRemValue)
{
	int sSize = this->m_sValue.size();
	for(int x = 0;x< sSize;x++)
	{
		char chCurChar = this->m_sValue[x];
		if(chCurChar == chRemValue)
		{
			this->m_sValue.erase(x,1);
			x--;
			sSize--;
		}
	}
}
int advstring::Find(char chFindValue,int nIndex)
{
	int nFindedPlace(-1);
	int sSize = this->m_sValue.size();
	assert (0 <= nIndex);
	for(int x = nIndex;x< sSize;x++)
	{
		char chCurChar = this->m_sValue[x];
		if(chCurChar == chFindValue)
		{
			nFindedPlace  = x;
			break;
		}
	}
	return nFindedPlace;
}
int advstring::Find(advstring asFindValue,int nIndex)
{
	assert (0 <= nIndex);
	return  this->m_sValue.find(asFindValue.m_sValue.c_str(),nIndex,asFindValue.m_sValue.size());;
}
int advstring::ReverseFind(char chFindValue)
{
	int nFindedPlace(-1);
	int sSize = this->m_sValue.size();
	for(int x = sSize-1;x >= 0;x--)
	{
		char chCurChar = this->m_sValue[x];
		if(chCurChar == chFindValue)
		{
			nFindedPlace  = x;
			break;
		}
	}
	return nFindedPlace;
}
int advstring::ReverseFind(advstring asFindValue)
{
	return this->m_sValue.rfind(asFindValue.m_sValue);
}
advstring advstring::Mid(int nIndex, int nCount)
{
	advstring tmp = "";

	if (nIndex < 0)
		nIndex = 0;
	if (nCount < 0)
		nCount = 0;

	int nLength = this->m_sValue.size();

	if((nIndex+ nCount) > nLength)
	{
		nCount = nLength - nIndex;
	}
	if( nIndex > nLength)
	{
		nCount = 0;
	}
	if(nCount != 0)
	{
		tmp = this->m_sValue.substr(nIndex, nCount);
	}
	
	return tmp;
}
int advstring::Compare(advstring asCompValue)
{
	return this->m_sValue.compare(asCompValue.m_sValue);
}
void advstring::Format(const char* pcchValue, ...) 
{
	va_list args;
	va_start (args, pcchValue);
	int size = vsnprintf(NULL, 0, pcchValue, args); 
	this->m_sValue.resize(size);
	vsnprintf ((char*)this->m_sValue.c_str(),size+1,pcchValue, args);
	va_end (args);
}
void advstring::ReleaseBuffer()
{
	this->m_sValue.resize(0);
}
advstring advstring::Left(int nIndex)
{
	// nCount is in XCHARs
	if (nIndex < 0)
		nIndex = 0;

	int nLength = this->m_sValue.size();
	if( nIndex >= nLength )
	{
		return( *this );
	}
	else
	{
		return advstring(this->m_sValue.substr(0,nIndex));
	}
}
advstring advstring::Right(int nIndex ) 
{
	if (nIndex < 0)
		nIndex = 0;

	int nLength = this->m_sValue.size();
	if( nIndex >= nLength )
	{
		return( *this );
	}
	else
	{
		return advstring(this->m_sValue.substr(nLength-nIndex,nIndex));
	}
}
