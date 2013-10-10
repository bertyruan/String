//String.h - ASCII string class declaration
//Written by Berty Ruan

#pragma once
#include <ostream>
#include <sstream>


# define NOT_FOUND -1

//Encapsulates C-string
//Prototype ALWAYs unless there is a template class


class String
{
public:
	//Default constructor
	String();

	//Init-constructor to initialize this String with a C-String
	String(const char* text);
	
	//Init-constructor to allocate a string of a specified size
	String(int size);

	//Copy-constructor
	String(const String& source);

	//Destructor
	~String();

	//Assignment operator, performs deep copy
	String& operator = (const String& source);

	//Assigns C-string to this String
	String& operator = (const char* soruce);

	//Returns the size of this String
	int GetSize() const;

	//Determines the size of a C-string that is supplied as argument
	static int GetSize(const char* text);

	//Returns C-String pointer
	char* GetText() const;

	//Index operator
	char& operator [] (int index) const;

	//Comparison operators: strings are equal when they are the same size
	//and they contain the same characters
	bool operator == (const String& compareTo) const;
	bool operator != (const String& compareTo) const;
	bool operator > (const String& compareTo) const;
	bool operator < (const String& compareTo) const;

	//Concatentation operator appends appendix to this String and returns a new string
	String operator + (const String& appendix) const;


	//Returns an index of aChar in this String starting the search at startPosition
	//when the character is present; return NOT_FOUND otherwise
	int Find(char aChar, int startPosition = 0) const;

	//Returns a new String which is a substring of this String that begins at
	//startPosition and is length characters long; when the length is not specified
	//the default of value of zero means that the substring shall span from 
	//startPosition to '/0'
	String Substring(int startPosition, int length = 0) const;

private:
	//The encapsulated C-string
	char* Text;

	void CheckBounds(int index) const;

};



//Global stream output operator
std::ostream& operator << (std::ostream& out, const String& text);