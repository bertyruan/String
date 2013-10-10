//String.cpp - ASCII string class implementation
//Written by Berty Ruan

//Cannot have default arguments duplicated in .cpp file


#include "String.h"
#include <sstream>
using namespace std;

# define NOT_FOUND -1

//Encapsulates C-string
//Prototype ALWAYs unless there is a template class


//Default constructor
String::String()
{
	Text = NULL;
}

//Init-constructor to initialize this String with a C-String
String::String(const char* text)
{
	Text = NULL;
	*this = text;
}
	
//Init-constructor to allocate a string of a specified size
String::String(int size)
{
	Text = new char[size];
}

//Copy-constructor
String::String(const String& source)
{
	Text = NULL;
	//Calls the assignment operator to perform deep copy
	*this = source;
}

//Destructor
String::~String()
{
	delete[] Text;
}

//Assignment operator, performs deep copy
String& String::operator = (const String& source)
{

	*this = source.Text;
	return *this;

}

//Assigns C-string to this String
String& String::operator = (const char* source)
{

	delete[] Text;

	int trueLength = GetSize(source) + 1;

	Text = new char[trueLength];

	for (int i = 0; i < trueLength; i++)
		Text[i] = source[i];

	return *this;

}

//Index operator
char& String::operator [] (int index) const
{
	int length = GetSize();

	// Check for valid index
	CheckBounds(index);

	return Text[index];

}

//Comparison operators: strings are equal when they are the same size
//and they contain the same characters
bool String::operator == (const String& compareTo) const
{
	bool sameSize = true;
	if (GetSize() == compareTo.GetSize() )
	{
		for (int i = 0; i < GetSize(); i++)
		{
			if (Text[i] != compareTo.Text[i])
			{
				sameSize = false;
				break;
			}
		}
	}
	else
		sameSize = false;

	return sameSize;
}

bool String::operator != (const String& compareTo) const
{
	return !(*this == compareTo);
}

bool String::operator > (const String& compareTo) const
{
	bool greaterThan = false;
	if (GetSize() > compareTo.GetSize())
		greaterThan = true;
	return greaterThan;

}
bool String::operator < (const String& compareTo) const
{
	bool lessThan = false;
	if (GetSize() == compareTo.GetSize())
		return lessThan;
	return !(*this > compareTo);
}

//Concatentation operator appends appendix to this String and returns a new string
String String::operator + (const String& appendix) const
{

	// -1 for the '/0' in this
	int newStringLength = GetSize() + appendix.GetSize() + 1 ;

	String newString(newStringLength);

	for (int i = 0; i < GetSize(); i++)
		newString[i] = Text[i];

	int counter = 0;
	for (int i = GetSize(); i < newStringLength - 1; i++)
	{
		newString[i] = appendix.Text[counter];
		counter++;
	}
	
	newString[newStringLength - 1] = '\0';

	return newString;
}

//Returns the size of this String
int String::GetSize() const
{
	return GetSize(Text);
}

//Determines the size of a C-string that is supplied as argument
/*static*/ int String::GetSize(const char* text)
{
	int counter = 0;

	for (int i = 0; text[i] != '\0'; i++)
		counter++;

	return counter;
}


//Returns C-String pointer
char* String::GetText() const
{
	return Text;
}

//Returns an index of aChar in this String starting the search at startPosition
//when the character is present; return NOT_FOUND otherwise
int String::Find(char aChar, int startPosition/* = 0*/) const
{
	int index = NOT_FOUND;
	for (int i = startPosition; i < GetSize() -1; i++)
	{
		if (Text[i] == aChar)
		{
			index = i;
			break;
		}
	}

	return index;
}

//Returns a new String which is a substring of this String that begins at
//startPosition and is length characters long; when the length is not specified
//the default of value of zero means that the substring shall span from 
//startPosition to '\0'
String String::Substring(int startPosition, int length/* = 0*/) const
{
	int substringEndIndex = startPosition + length;
	CheckBounds(length);
	CheckBounds(startPosition);
	CheckBounds(substringEndIndex);


	String newString(length + 1);
	int j = 0;
	for (int i = startPosition; i < substringEndIndex; i ++)
	{
		newString[j] = Text[i];
		j++;
	}
	newString[length] = '\0';

	return newString;
}


void String::CheckBounds(int index) const
{
	if ( (index < 0) || (index >= GetSize()) )
	{
		stringstream error;
		error << "Your parameters are out of bounds (0.." << GetSize() - 1 << ")";
		throw error.str();
	}


}


//Global stream output operator
std::ostream& operator << (std::ostream& out, const String& text)
{
	return
		//Prints C-string
		out << text.GetText();
}