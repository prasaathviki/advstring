/*
*   advstring
*   
*   Author: Prasaath Viki
*   Email: prasaathviki@gmail.com
*   Description: advstring is a string class with advance options.
*   Place: Chennai.
*   Version: 2.0.7
*   Date: Tuesday, May 20, 2014.
*/

#include "advstring.h"

std::string advstring::IntToString(int nValue)
{
	std::stringstream ss;
	ss << nValue;
	return ss.str();
}
std::string advstring::FloatToString(float nValue)
{
	std::stringstream ss;
	ss << nValue;
	return ss.str();
}

std::string advstring::DoubleToString(double nValue)
{
	std::ostringstream out;
	out << std::fixed << nValue;
	return out.str();
}
int advstring::StringToInt(std::string sValue)
{
	int nValue(0);
	std::stringstream ss(sValue);
	ss >> nValue;
	return nValue;
}
float advstring::StringToFloat(std::string sValue)
{
	float nValue(0.0);
	std::stringstream ss(sValue);
	ss >> nValue;
	return nValue;
}
double advstring::StringToDouble(std::string sValue)
{
	double nValue(0.0);
	std::stringstream ss(sValue);
	ss >> nValue;
	return nValue;
}
std::string advstring::GetDateTime(std::string sFormatValue)
{
	std::string sRetString;
	time_t rawtime;
	struct tm * timeinfo;
	int nBufferSize(80),inc(1);
	char *pchBuffer = NULL;
	time (&rawtime);
	timeinfo = localtime (&rawtime);
	size_t sizRem(0);
	do
	{
		if(inc != 1) delete [] pchBuffer;
		pchBuffer = new char[nBufferSize*inc];
		sizRem = strftime(pchBuffer,nBufferSize*inc,sFormatValue.c_str(),timeinfo);
		inc++;
	}while(sizRem < 1);
	sRetString = pchBuffer;
	delete [] pchBuffer;
	return sRetString;
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
	this->m_sValue = IntToString(nValue);
}
advstring::advstring(float nValue)
{
	this->m_sValue = FloatToString(nValue);
}
advstring::advstring(double nValue)
{
	this->m_sValue = DoubleToString(nValue);
}
advstring::advstring(const char *pcchValue)
{
	this->m_sValue = pcchValue;
}
std::string advstring::GetClass()
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
advstring operator+( advstring asValue, const advstring& asValue2)
{
	return advstring(asValue.m_sValue + asValue2.m_sValue);
}
advstring operator+( const char* pcchValue ,const advstring& asValue2)
{
	return advstring(pcchValue + asValue2.m_sValue);
}
advstring operator+( int nValue, const advstring& asValue2)
{
	return advstring(advstring::IntToString(nValue) + asValue2.m_sValue);
}
advstring operator+( float nValue ,const advstring& asValue2)
{
	return advstring(advstring::FloatToString(nValue) + asValue2.m_sValue);
}
advstring operator+( double nValue ,const advstring& asValue2)
{
	return advstring(advstring::DoubleToString(nValue) + asValue2.m_sValue);
}
advstring advstring::operator + (const char *pcchValue)
{
	return (advstring(this->m_sValue + pcchValue));
}
advstring advstring::operator + (int nValue)
{
	return (advstring(this->m_sValue + IntToString(nValue)));
}
advstring advstring::operator + (float nValue)
{
	return (advstring(this->m_sValue + FloatToString(nValue)));
}
advstring advstring::operator + (double nValue)
{
	return (advstring(this->m_sValue + DoubleToString(nValue)));
}
void advstring::operator += (const char *pcchValue)
{
	this->m_sValue += pcchValue;
}
void advstring::operator += (advstring asValue)
{
	this->m_sValue = this->m_sValue + asValue.m_sValue;
}
void advstring::operator += (int nValue)
{
	this->m_sValue = this->m_sValue + IntToString(nValue);
}
void advstring::operator += (float nValue)
{
	this->m_sValue = this->m_sValue + FloatToString(nValue);
}
void advstring::operator += (double nValue)
{
	this->m_sValue = this->m_sValue + DoubleToString(nValue);
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
	if(this->m_sValue == IntToString(nValue))
		return true;
	else
		return false;
}
bool advstring::operator == (float nValue)
{
	if(this->m_sValue == FloatToString(nValue))
		return true;
	else
		return false;
}
bool advstring::operator == (double nValue)
{
	if(this->m_sValue == DoubleToString(nValue))
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
	if(this->m_sValue != IntToString(nValue))
		return true;
	else
		return false;
}
bool advstring::operator != (float nValue)
{
	if(this->m_sValue != FloatToString(nValue))
		return true;
	else
		return false;
}
bool advstring::operator != (double nValue)
{
	if(this->m_sValue != DoubleToString(nValue))
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
	return StringToInt(this->m_sValue);
}
advstring::operator float()	
{
	return StringToFloat(this->m_sValue);
}
advstring::operator double()	
{
	return StringToDouble(this->m_sValue);
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
int advstring::ToInt()
{
	return StringToInt(this->m_sValue);
}
float advstring::ToFloat()
{
	return StringToFloat(this->m_sValue);
}
double advstring::ToDouble()
{
	return StringToDouble(this->m_sValue);
}
std::string advstring::ToStdString()
{
	return this->m_sValue;
}
const char* advstring::GetBuffer()
{
	return this->m_sValue.c_str();
}
char* advstring::GetNewBuffer()
{
	// Please delete the chNewValue after usage. if chNewValue not deleted it may cause memory leak.
	char * chNewValue = new char[this->m_sValue.size() + 1];
	std::copy(this->m_sValue.begin(), this->m_sValue.end(), chNewValue);
	chNewValue[this->m_sValue.size()] = '\0'; 
	return chNewValue;
}
void advstring::Empty()
{
	this->m_sValue.clear();
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

void advstring::Append(advstring asAppString)
{
	this->m_sValue = this->m_sValue + asAppString.m_sValue;
}
void advstring::AppendChar(char chApp)
{
	int nLength = this->m_sValue.size();
	this->m_sValue.insert(nLength,1,chApp);
}
int advstring::FileWrite(advstring asFpath)
{
	FILE *fKeyFile;
	fKeyFile = fopen(asFpath.GetBuffer(), "w");
	if(fKeyFile != NULL)
	{
		fprintf(fKeyFile, "%s", this->m_sValue.c_str());
		fclose(fKeyFile);
		return 1;
	}
	else
	{
		return -1;
	}
}
int advstring::FileAppend(advstring asFpath)
{
	FILE *fKeyFile;
	fKeyFile = fopen(asFpath.GetBuffer(), "a");
	if(fKeyFile != NULL)
	{
		fprintf(fKeyFile, "%s", this->m_sValue.c_str());
		fclose(fKeyFile);
		return 1;
	}
	else
	{
		return -1;
	}
}
int advstring::FileAppendWithDateTime(advstring asFpath)
{
	std::string sWriString = GetDateTime("[%Y/%m/%d %H:%M:%S] ") + this->m_sValue + "\n";
	FILE *fKeyFile;
	fKeyFile = fopen(asFpath.GetBuffer(), "a");
	if(fKeyFile != NULL)
	{
		fprintf(fKeyFile, "%s", sWriString.c_str());
		fclose(fKeyFile);
		return 1;
	}
	else
	{
		return -1;
	}
}
int advstring::FileRead(advstring asFpath)
{
	FILE *OldKeyFile;
	if((OldKeyFile = fopen(asFpath.GetBuffer(), "r")) != NULL) 
	{ 
		fseek(OldKeyFile, 0, SEEK_END);
		size_t size = ftell(OldKeyFile);
		this->m_sValue.resize(size);
		rewind(OldKeyFile);
		fread((char*)this->m_sValue.c_str(), sizeof(char), this->m_sValue.size(), OldKeyFile);
		fclose(OldKeyFile);
		return 1;
	}
	else
	{
		this->m_sValue = "";
		return -1;
	}
}
int advstring::SetCurDateTime()
{
	this->m_sValue =  GetDateTime("%Y/%m/%d %H:%M:%S");
	return 1;
}
int advstring::SetCurTime()
{
	this->m_sValue =  GetDateTime("%H:%M:%S");
	return 1;
}
int advstring::SetCurDateTimeStamp()
{
	this->m_sValue = GetDateTime("%Y%m%d%H%M%S");
	return 1;
}
int advstring::AppCurDateTime()
{
	this->m_sValue +=  GetDateTime("%Y/%m/%d %H:%M:%S");
	return 1;
}
int advstring::AppCurTime()
{
	this->m_sValue +=  GetDateTime("%H:%M:%S");
	return 1;
}
int advstring::AppCurDateTimeStamp()
{
	this->m_sValue += GetDateTime("%Y%m%d%H%M%S");
	return 1;
}
void advstring::AppendFormat(const char* pcchValue, ...)
{
	std::string sFormatedString;
	va_list args;
	va_start (args, pcchValue);
	int size = vsnprintf(NULL, 0, pcchValue, args); 
	sFormatedString.resize(size);
	vsnprintf ((char*)sFormatedString.c_str(),size+1,pcchValue, args);
	va_end (args);
	this->m_sValue += sFormatedString;
}
void advstring::FormatV(const char* pcchValue,va_list args)
{
	int size = vsnprintf(NULL, 0, pcchValue, args); 
	this->m_sValue.resize(size);
	vsnprintf ((char*)this->m_sValue.c_str(),size+1,pcchValue, args);
}
void advstring::AppendFormatV(const char* pcchValue,va_list args)
{
	std::string sFormatValue;
	int size = vsnprintf(NULL, 0, pcchValue, args); 
	sFormatValue.resize(size);
	vsnprintf ((char*)sFormatValue.c_str(),size+1,pcchValue, args);
	this->m_sValue += sFormatValue;
}
advstring advstring::MakeReverse()
{
	std::reverse(this->m_sValue.begin(),this->m_sValue.end());
	return this->m_sValue;
}
advstring advstring::MakeLower()
{
	std::transform(this->m_sValue.begin(), this->m_sValue.end(), this->m_sValue.begin(), ::tolower);
	return this->m_sValue;
}
advstring advstring::MakeUpper()
{
	std::transform(this->m_sValue.begin(), this->m_sValue.end(), this->m_sValue.begin(), ::toupper);
	return this->m_sValue;
}
int advstring::CompareNoCase(advstring asCompValue)
{
	std::string sCurLower = this->m_sValue;
	std::transform(sCurLower.begin(),sCurLower.end(), sCurLower.begin(), ::tolower);
	std::transform(asCompValue.m_sValue.begin(),asCompValue.m_sValue.end(), asCompValue.m_sValue.begin(), ::tolower);
	return sCurLower.compare(asCompValue.m_sValue);
}
int advstring::IsLower()
{
	std::string sCurLower = this->m_sValue;
	std::transform(sCurLower.begin(),sCurLower.end(), sCurLower.begin(), ::tolower);
	return sCurLower.compare(this->m_sValue);
}
int advstring::IsUpper()
{
	std::string sCurLower = this->m_sValue;
	std::transform(sCurLower.begin(),sCurLower.end(), sCurLower.begin(), ::toupper);
	return sCurLower.compare(this->m_sValue);
}
void advstring::Swap(advstring &asSwap)
{
	advstring asTemp = asSwap;
	asSwap.m_sValue = this->m_sValue;
	this->m_sValue = asTemp.m_sValue;
}

advstring advstring::GetCurDateTime()
{
	return advstring(GetDateTime("%Y/%m/%d %H:%M:%S"));
}
advstring advstring::GetCurTime()
{
	return advstring(GetDateTime("%H:%M:%S"));
}
advstring advstring::GetCurDateTimeStamp()
{
	return advstring(GetDateTime("%Y%m%d%H%M%S"));
}
advstring advstring::GetCurDate()
{
	return advstring(GetDateTime("%Y/%m/%d"));
}
int advstring::SetCurDate()
{
	this->m_sValue = GetDateTime("%Y/%m/%d");
	return 1;
}
int advstring::AppCurDate()
{
	this->m_sValue += GetDateTime("%Y/%m/%d");
	return 1;
}
advstring advstring::GetXOREncryptedData(advstring asKey)
{
	int nKeyLen = asKey.GetLength(),nDataSize = this->m_sValue.size();
	std::string sOutPut;
	sOutPut.resize(nDataSize);

	for (int i = 0; i < nDataSize; i++)
		sOutPut[i] = this->m_sValue[i] ^ asKey.m_sValue[i % nKeyLen];

	return advstring(sOutPut);
}
advstring advstring::GetXORDecryptedData(advstring asKey)
{
	int nKeyLen = asKey.GetLength(),nDataSize = this->m_sValue.size();
	std::string sOutPut;
	sOutPut.resize(nDataSize);

	for (int i = 0; i < nDataSize; i++)
		sOutPut[i] = this->m_sValue[i] ^ asKey.m_sValue[i % nKeyLen];

	return advstring(sOutPut);
}
int advstring::SetXOREncryptedData(advstring asKey)
{
	int nKeyLen = asKey.GetLength(),nDataSize = this->m_sValue.size();
	for (int i = 0; i < nDataSize; i++)
		this->m_sValue[i] = this->m_sValue[i] ^ asKey.m_sValue[i % nKeyLen];
	return 1;
}
int advstring::SetXORDecryptedData(advstring asKey)
{
	int nKeyLen = asKey.GetLength(),nDataSize = this->m_sValue.size();
	for (int i = 0; i < nDataSize; i++)
		this->m_sValue[i] = this->m_sValue[i] ^ asKey.m_sValue[i % nKeyLen];
	return 1;
}
int advstring::AppXOREncryptedData(advstring asKey)
{
	int nKeyLen = asKey.GetLength(),nDataSize = this->m_sValue.size();
	std::string sOutPut;
	sOutPut.resize(nDataSize);
	for (int i = 0; i < nDataSize; i++)
		sOutPut[i] = this->m_sValue[i] ^ asKey.m_sValue[i % nKeyLen];
	this->m_sValue += sOutPut;
	return 1;
}
int advstring::AppXORDecryptedData(advstring asKey)
{
	int nKeyLen = asKey.GetLength(),nDataSize = this->m_sValue.size();
	std::string sOutPut;
	sOutPut.resize(nDataSize);
	for (int i = 0; i < nDataSize; i++)
		sOutPut[i] = this->m_sValue[i] ^ asKey.m_sValue[i % nKeyLen];
	this->m_sValue += sOutPut;
	return 1;
}
std::string* advstring::GetData()
{
	return &this->m_sValue;
}
advstring advstring::Trim()
{
	size_t startpos = this->m_sValue.find_first_not_of(" \n\r\t");
	if(startpos != std::string::npos) this->m_sValue = this->m_sValue.substr(startpos);
	size_t endpos = this->m_sValue.find_last_not_of(" \n\r\t");
	if(endpos != std::string::npos) this->m_sValue = this->m_sValue.substr(0,endpos+1);
	return advstring(this->m_sValue);
}
advstring advstring::TrimLeft()
{
	size_t startpos = this->m_sValue.find_first_not_of(" \n\r\t");
	if(startpos != std::string::npos) this->m_sValue = this->m_sValue.substr(startpos);
	return advstring(this->m_sValue);
}
advstring advstring::TrimRight()
{
	size_t endpos = this->m_sValue.find_last_not_of(" \n\r\t");
	if(endpos != std::string::npos) this->m_sValue = this->m_sValue.substr(0,endpos+1);
	return advstring(this->m_sValue);
}
advstring advstring::Trim(char chTrim)
{
	size_t startpos = this->m_sValue.find_first_not_of(chTrim);
	if(startpos != std::string::npos) this->m_sValue = this->m_sValue.substr(startpos);
	size_t endpos = this->m_sValue.find_last_not_of(chTrim);
	if(endpos != std::string::npos) this->m_sValue = this->m_sValue.substr(0,endpos+1);
	return advstring(this->m_sValue);
}
advstring advstring::TrimLeft(char chTrim)
{
	size_t startpos = this->m_sValue.find_first_not_of(chTrim);
	if(startpos != std::string::npos) this->m_sValue = this->m_sValue.substr(startpos);
	return advstring(this->m_sValue);
}
advstring advstring::TrimRight(char chTrim)
{
	size_t endpos = this->m_sValue.find_last_not_of(chTrim);
	if(endpos != std::string::npos) this->m_sValue = this->m_sValue.substr(0,endpos+1);
	return advstring(this->m_sValue);
}
advstring advstring::Trim(advstring asTrim)
{
	size_t startpos = this->m_sValue.find_first_not_of(asTrim.m_sValue);
	if(startpos != std::string::npos) this->m_sValue = this->m_sValue.substr(startpos);
	size_t endpos = this->m_sValue.find_last_not_of(asTrim.m_sValue);
	if(endpos != std::string::npos) this->m_sValue = this->m_sValue.substr(0,endpos+1);
	return advstring(this->m_sValue);
}
advstring advstring::TrimLeft(advstring asTrim)
{
	size_t startpos = this->m_sValue.find_first_not_of(asTrim.m_sValue);
	if(startpos != std::string::npos) this->m_sValue = this->m_sValue.substr(startpos);
	return advstring(this->m_sValue);
}
advstring advstring::TrimRight(advstring asTrim)
{
	size_t endpos = this->m_sValue.find_last_not_of(asTrim.m_sValue);
	if(endpos != std::string::npos) this->m_sValue = this->m_sValue.substr(0,endpos+1);
	return advstring(this->m_sValue);
}