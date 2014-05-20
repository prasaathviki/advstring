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

#ifndef __ADVSTRING_H
#define __ADVSTRING_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <assert.h>
#include <memory>
#include <stdarg.h>
#include <stdio.h>
#include <list>
#include <time.h>
#include <algorithm>

using namespace std;

class advstring 
{

private:

	std::string m_sValue;	// Internal value
	static std::string IntToString(int nValue);
	static std::string FloatToString(float nValue);
	static std::string DoubleToString(double nValue);
	static int StringToInt(std::string sValue);
	static float StringToFloat(std::string sValue);
	static double StringToDouble(std::string sValue);
	static std::string GetDateTime(std::string sFormatValue);

public:

	/*!
	* Empty constructor, initialized to ''
	*/
	advstring();

	/*!
	* std::string oriented constructor
	*/
	advstring(std::string sValue);

	/*!
	* const char* type constructor
	*/
	advstring(const char *pcchValue);

	/*!
	* int type constructor
	*/
	advstring(int nValue);

	/*!
	* float type constructor
	*/
	advstring(float nValue);

	/*!
	* double type constructor
	*/
	advstring(double nValue);

	/*!
	* Get The class type in a std::string variable.
	* \return "advstring"
	*/
	std::string GetClass();

	/*!
	* Display string using cout.
	*/
	void  DispString();

	/*!
	* Display string using cout with endl.
	*/
	void  DispStringEndl();

	/*!
	* To change the value with a standard std::string
	* \arg value The value to assign
	*/
	void operator = (std::string sValue);

	/*!
	* To change the value with a advstring
	* \arg value The value to assign
	*/
	void operator = (advstring asValue);

	/*!
	*To change the value with a const char *
	*\arg value The value to assign
	*/
	void operator = (const char *pcchValue);

	/*!
	* Return a advstring which is the concatenation between the current value and the value passed in argument.
	* \arg value The value to concatenate
	* \return The concatenation between current and argument value.
	*/
	friend advstring operator+( advstring asValue, const advstring& asValue2);

	/*!
	* Return a advstring which is the concatenation between the current value and the value passed in argument.
	* \arg value The value to concatenate
	* \return The concatenation between current and argument value.
	*/
	friend advstring operator+( const char* pcchValue ,const advstring& asValue2);

	/*!
	* Return a advstring which is the concatenation between the current value and the value passed in argument.
	* \arg value The value to concatenate
	* \return The concatenation between current and argument value.
	*/
	friend advstring operator+( int nValue, const advstring& asValue2);

	/*!
	* Return a advstring which is the concatenation between the current value and the value passed in argument.
	* \arg value The value to concatenate
	* \return The concatenation between current and argument value.
	*/
	friend advstring operator+( float nValue ,const advstring& asValue2);

	/*!
	* Return a advstring which is the concatenation between the current value and the value passed in argument.
	* \arg value The value to concatenate
	* \return The concatenation between current and argument value.
	*/
	friend advstring operator+( double nValue ,const advstring& asValue2);

	/*!
	* Return a advstring which is the concatenation between the current value and the value passed in argument.
	* \arg value The value to concatenate
	* \return The concatenation between current and argument value.
	*/
	advstring operator + (const char *pcchValue);

	/*!
	* Return a advstring which is the concatenation between the current value and the value passed in argument.
	* \arg value The value to concatenate
	* \return The concatenation between current and argument value.
	*/
	advstring operator + (int nValue);

	/*!
	* Return a advstring which is the concatenation between the current value and the value passed in argument.
	* \arg value The value to concatenate
	* \return The concatenation between current and argument value.
	*/
	advstring operator + (float nValue);

	/*!
	* Return a advstring which is the concatenation between the current value and the value passed in argument.
	* \arg value The value to concatenate
	* \return The concatenation between current and argument value.
	*/
	advstring operator + (double nValue);

	/*!
	* Concatenate current advstring with another advstring (the argument is placed behind the current advstring).
	* \arg to_add The string we want to concatenate with.
	*/
	void operator += (advstring asValue);
	
	/*!
	* Return a advstring which is the concatenation between the current value and the value passed in argument.
	* \arg value The value to concatenate
	* \return The concatenation between current and argument value.
	*/
	void operator += (const char *pcchValue);

	/*!
	* Concatenate current advstring with int value.
	* \arg to_add The string we want to concatenate with.
	*/
	void operator += (int nValue);

	/*!
	* Concatenate current advstring with float value.
	* \arg to_add The string we want to concatenate with.
	*/
	void operator += (float nValue);

	/*!
	* Concatenate current advstring with double value.
	* \arg to_add The string we want to concatenate with.
	*/
	void operator += (double nValue);

	//advstring operator + (advstring asValue,advstring asValue2);

	/*!
	* Comparison between two advstring.
	* \return A boolean : true if the values are the same, false if not.
	*/
	bool operator == (advstring asValue);

	/*!
	* Comparison between a advstring and a int.
	* \return A boolean : true if the values are the same, false if not.
	*/
	bool operator == (int nValue);

	/*! 
	* Comparison between a advstring and a float.
	* \return A boolean : true if the values are the same, false if not.
	*/
	bool operator == (float nValue);

	/*! 
	* Comparison between a advstring and a double.
	* \return A boolean : true if the values are the same, false if not.
	*/
	bool operator == (double nValue);

	/*!
	* Comparison between a advstring and a const char*
	* \return A boolean : true if the values are the same, false if not.
	*/
	bool operator == (const char* pcchValue);

	/*!
	* Comparison between two advstring.
	* \return A boolean : true if the values are different, true if they are the same.
	*/
	bool operator != (advstring asValue);

	/*!
	* Comparison between a advstring and a int.
	* \return A boolean : true if the values are the same, false if not.
	*/
	bool operator != (int nValue);

	/*!
	* Comparison between a advstring and a float.
	* \return A boolean : true if the values are the same, false if not.
	*/
	bool operator != (float nValue);

	/*!
	* Comparison between a advstring and a double.
	* \return A boolean : true if the values are the same, false if not.
	*/
	bool operator != (double nValue);

	/*!
	* Comparison between a advstring and a const char*.
	* \return A boolean : true if the values are the same, false if not.
	*/
	bool operator != (const char* pcchValue);

	/*!
	* Converts to int.
	*/
   operator int();

	/*!
	* Converts to float.
	*/
	operator float();

	/*!
	* Converts to double.
	*/
	operator double();

	/*!
	* Converts to const char *.
	*/
	operator const char*();

	/*!
	* Converts to char*.
	* Please delete the chNewValue after usage. if not deleted it may cause memory leak.
	*/
	operator char*();

	/*!
	* Converts to int.
	* \return int
	*/
	int ToInt();
	
	/*!
	* Converts to float.
	* \return float
	*/
	float ToFloat();
	
	/*!
	* Converts to double.
	* \return double
	*/
	double ToDouble();

	/*!
	* Convert the current string to a std::string.
	* \return A std::string.
	*/
	std::string ToStdString();

	/*!
	* Convert advstring to a const char array (the same way as std::string.c_str()).
	* \return A const char* version of the current advstring.
	*/
	const char* GetBuffer();

	/*!
	* Convert advstring to a char array.
	* \return A char* version of the current advstring.
	*/
	char* GetNewBuffer();

	/*!
	* Clear the content of the current advstring (same effect as = "").
	*/
	void Empty();

	/*!
	* Return the number of characters in advstring.
	* \return length of the advstring.
	*/
	int GetLength();

	/*!
	* Maximum size of advstring without reallocation (the same as std::string).
	*\return max size without reallocation.
	*/
	int MaxSize();

	/*!
	* Ask if the current advstring is empty or not.
	* \return A boolean : true = the advstring is empty ; false = the advstring is not empty.
	*/
	bool IsEmpty();

	/*!
	* Get char at given Index.
	*\arg Index of the letter.
	*\return char value.
	*\assert if Index below zero and if Index greater than size of the advstring
	*/
	char GetAt(int nIndex);

	/*!
	*Set char at given Index and replaces the old value.
	*\arg Index of the letter , value.
	*\assert if Index below zero and if Index greater than length of the advstring
	*/
	void SetAt(int nIndex,char chValue);

	/*!
	* Insert char to respected index.
	* \arg: Index the advstring, char value to insert.
	* \return: length of the updated advstring. 
	*/
	int Insert(int nIndex,char chValue);

	/*!
	* Insert advstring to respected index.
	* \arg: Index of the advstring, advstring value to insert.
	* \return: length of the updated advstring. 
	*/
	int Insert(int nIndex,advstring asValue);

	/*!
	* Replace all old char with new char.
	* \arg old char, new char.
	* \return int:  replaced char count.
	*/
	int Replace(char chOldValue,char chNewValue);

	/*!
	* Replace old advstring with new advstring.
	* \arg old advstring , new advstring.
	* \return int: replaced advstring count.
	*/
	int Replace(advstring asOldValue,advstring asNewValue);

	/*!
	* Remove all given char from advstring.
	* \arg char value to remove from the advstring.
	*/
	void Remove(char chRemValue);

	/*!
	* Find the given char in advstring.
	* \return first given char find index
	*/
	int Find(char chFindValue,int nIndex = 0);

	/*!
	* Find the given char in string 
	* \return first given advstring find index
	*/
	int Find(advstring asFindValue,int nIndex = 0);

	/*!
	* Find the position of the first occurrence of one of the elements passed in argument.
	* \return reverse find index
	*/
	int ReverseFind(char chFindValue);

	/*!
	* Find the position of the first occurrence of one of the elements passed in argument.
	* \return reverse find index
	*/
	int ReverseFind(advstring asFindValue);

	/*!
	* Extract the substring in the current advstring.
	* \arg beginning nIndex we want to start the extraction.
	* \arg The length of the advstring we wants to extract.
	* \return The extracted advstring.
	*/
	advstring Mid(int nIndex, int nLength);

	/*!
	* Compare advstring with current value.
	* /return 0	They compare equal
	* /return <0	Either the value of the first character that does not match is lower in the compared string, or all compared characters match but the compared string is shorter.
	* /return >0	Either the value of the first character that does not match is greater in the compared string, or all compared characters match but the compared string is longer.
	*/
	int Compare(advstring asCompValue);

	/*!
	* Format advstring
	* \arg format code for string and followed by value. 
	*/
	void Format(const char* pcchValue, ...);

	/*!
	* Release buffer set to size -1
	*/
	void ReleaseBuffer();

	/*!
	*  Return the substring consisting of the Leftmost Count characters.
	*  /arg count to substring from Left.
	*  /return substring advstring value.
	*/
	advstring Left(int nLength);

	/*!
	*  Return the substring consisting of the Rightmost Count characters.
	*  /arg count to substring from right.
	*  /return substring advstring value.
	*/
	advstring Right(int nLength);

	/*!
	* Append current advstring with another advstring .
	* \arg asAppString The string we want to Append with.
	*/
	void Append(advstring asAppString);

	/*!
	* Append current advstring with char value .
	* \arg chApp The char we want to Append with.
	*/
	void AppendChar(char chApp);

	/*!
	* Write current advstring value to path specified.  If a file with the same name already exists, its contents are discarded and the file is treated as a new empty file.
	* \arg asFpath Path with file name.
	* \return 1 - success -1 - failure
	*/
	int FileWrite(advstring asFpath);

	/*!
	* Write current advstring value to path specified. Open file for output at the end of a file. Output operations always write data at the end of the file, expanding it. The file is created if it does not exist.
	* \arg asFpath Path with file name.
	* \return 1 - success -1 - failure
	*/
	int FileAppend(advstring asFpath);

	/*!
	* Write current advstring value with current date and time to path specified. Open file for output at the end of a file. Output operations always write data at the end of the file, expanding it. The file is created if it does not exist.
	* \arg asFpath Path with file name.
	* \return 1 - success -1 - failure
	*/
	int FileAppendWithDateTime(advstring asFpath);
	
	/*!
	* Read File from the file path specified and save the current value to current advstring value.
	* \arg asFpath Path with file name.
	* \return 1 - success -1 - failure
	*/
	int FileRead(advstring asFpath);

	/*!
	* Set current time to advstring value.
	* \return 1 - success -1 - failure
	*/
	int SetCurTime();

	/*!
	* Set current date and time to advstring value.
	* \return 1 - success -1 - failure
	*/
	int SetCurDateTime();

	/*!
	* Set current date and time stamp to advstring value.
	* \return 1 - success -1 - failure
	*/
	int SetCurDateTimeStamp();

	/*!
	* Append current time to advstring value.
	* \return 1 - success -1 - failure
	*/
	int AppCurTime();

	/*!
	* Append current date and time to advstring value.
	* \return 1 - success -1 - failure
	*/
	int AppCurDateTime();

	/*!
	* Append current date and time stamp to current advstring value.
	* \return 1 - success -1 - failure
	*/
	int AppCurDateTimeStamp();

	/*!
	* AppendFormat : Append the formated values to current advstring value
	* \return (1) - success (-1) - failure
	*/
	void AppendFormat(const char* pcchValue, ...);

	/*!
	* Format value with va_list and update the current advstring value
	* \arg data and va_list initialized object. 
	*/
	void FormatV(const char* pcchValue,va_list args);

	/*!
	* Format value with va_list and Append the current advstring value
	* \arg data and va_list initialized object. 
	*/
	void AppendFormatV(const char* pcchValue,va_list args);

	/*!
	* Make current advstring values to Reverse.
	* \return return Reversed string.
	*/
	advstring MakeReverse();

	/*!
	* Make current advstring values to Lower.
	* \return return converted string.
	*/
	advstring MakeLower();

	/*!
	* Make current advstring values to Upper.
	* \return return converted string.
	*/
	advstring MakeUpper();

	/*!
	* Make the given value and current value to Lower and compare the strings.
	* /return 0	They compare equal
	* /return <0	Either the value of the first character that does not match is lower in the compared string, or all compared characters match but the compared string is shorter.
	* /return >0	Either the value of the first character that does not match is greater in the compared string, or all compared characters match but the compared string is longer.
	*/
	int CompareNoCase(advstring asCompValue);

	/*!
	* check current advstring values are Lower.
	* /return 0	They compare equal
	* /return <0	Either the value of the first character that does not match is lower in the compared string, or all compared characters match but the compared string is shorter.
	* /return >0	Either the value of the first character that does not match is greater in the compared string, or all compared characters match but the compared string is longer.
	*/
	int IsLower();

	/*!
	* check current advstring values are Upper.
	* /return 0	They compare equal
	* /return <0	Either the value of the first character that does not match is lower in the compared string, or all compared characters match but the compared string is shorter.
	* /return >0	Either the value of the first character that does not match is greater in the compared string, or all compared characters match but the compared string is longer.
	*/
	int IsUpper();

	/*!
	* Swap the given advstring value to current value and current value to swap string.
	*/
	void Swap(advstring &asSwap);

	/*!
	* Get current date and time.
	* \return advstring
	*/
	advstring GetCurDateTime();
	
	/*!
	* Set current time.
	* \return advstring
	*/
	advstring GetCurTime();
	
	/*!
	* Get current date time stamp.
	* \return advstring
	*/
	advstring GetCurDateTimeStamp();

	/*!
	* Get current date.
	* \return advstring
	*/
	advstring GetCurDate();
	
	/*!
	* Set current date to advstring value.
	* \return 1 - success -1 - failure
	*/
	int SetCurDate();
	
	/*!
	* App current date to advstring value.
	* \return 1 - success -1 - failure
	*/
	int AppCurDate();

	/*!
	* Get XOR Encrypted Data
	* XOR Encryption is very simple encryption technique.
	* XOR Encryption is very easy to break. Use with care.
	* Don't use key with same letters. Key should be same as the length of the text.
	* Encryption and Decryption both are same algorithm.
	* \return 1 - success -1 - failure
	*/
	advstring GetXOREncryptedData(advstring asKey);
	
	/*!
	* Get XOR Encrypted Data
	* XOR Encryption is very simple encryption technique.
	* XOR Encryption is very easy to break. Use with care.
	* Don't use key with same letters. Key should be same as the length of the text.
	* Encryption and Decryption both are same algorithm.
	* \return 1 - success -1 - failure
	*/
	advstring GetXORDecryptedData(advstring asKey);

	/*!
	* Set XOR Encrypted Data
	* XOR Encryption is very simple encryption technique.
	* XOR Encryption is very easy to break. Use with care.
	* Don't use key with same letters. Key should be same as the length of the text.
	* Encryption and Decryption both are same algorithm.
	* \return 1 - success -1 - failure
	*/
	int SetXOREncryptedData(advstring asKey);
	
	/*!
	* Set XOR Encrypted Data
	* XOR Encryption is very simple encryption technique.
	* XOR Encryption is very easy to break. Use with care.
	* Don't use key with same letters. Key should be same as the length of the text.
	* Encryption and Decryption both are same algorithm.
	* \return 1 - success -1 - failure
	*/
	int SetXORDecryptedData(advstring asKey);

	/*!
	* Append XOR Encrypted Data
	* XOR Encryption is very simple encryption technique.
	* XOR Encryption is very easy to break. Use with care.
	* Don't use key with same letters. Key should be same as the length of the text.
	* Encryption and Decryption both are same algorithm.
	* \return 1 - success -1 - failure
	*/
	int AppXOREncryptedData(advstring asKey);
	
	/*!
	* Append XOR Encrypted Data
	* XOR Encryption is very simple encryption technique.
	* XOR Encryption is very easy to break. Use with care.
	* Don't use key with same letters. Key should be same as the length of the text.
	* Encryption and Decryption both are same algorithm.
	* \return 1 - success -1 - failure
	*/
	int AppXORDecryptedData(advstring asKey);

	/*!
	 * Get current data of the advstring. 
	 * If you change the values of the std::string* data it also change the data values of the advstring.
	 * Don't clear this pointer it will cleared automatically when the advstring is cleared. 
	 * \return std::string*
	 */
	std::string* GetData();

	/*!
	 * Remove all leading and trailing occurrences in the advstring value.
	 * \return advstring 
	 */
	advstring Trim();

	/*!
	 * Remove all leading and trailing occurrences of any of the char in the advstring value.
	 * \return advstring 
	 */
	advstring Trim(char chTrim);
	

	/*!
	 * Remove all leading and trailing occurrences of any of the string in the advstring value.
	 * \return advstring 
	 */
	advstring Trim(advstring asTrim);

	/*!
	 * Remove all leading occurrences in the advstring value.
	 * \return advstring 
	 */
	advstring TrimLeft();

	/*!
	 * Remove all leading occurrences of any of the char in the advstring value.
	 * \return advstring 
	 */
	advstring TrimLeft(char chTrim);

	/*!
	 * Remove all leading occurrences of any of the string in the advstring value.
	 * \return advstring 
	 */
	advstring TrimLeft(advstring asTrim);

	/*!
	 * Remove all trailing occurrences in the advstring value.
	 * \return advstring 
	 */
	advstring TrimRight();

	/*!
	 * Remove all trailing occurrences of any of the char in the advstring value.
	 * \return advstring 
	 */
	advstring TrimRight(char chTrim);

	/*!
	 * Remove all trailing occurrences of any of the string in the advstring value.
	 * \return advstring 
	 */
	advstring TrimRight(advstring asTrim);
	
};

#endif
