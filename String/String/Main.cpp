//Main.cpp - String class testing program main entry point
//Written by Berty Ruan


#include <iostream>
#include "String.h"
using namespace std;



// L means it is a UNICODE string given by wide characters
//wchar_t* unicodeString = L"my unicode string";
//C-string null terminated array of characters
// / -> esxape character
//null terminator -> '/0'
//size of string is length string plus one

//pointer CANNOT be modified

void main()
{


String testCase("Happy Birthday!");
String testCase2 =  "I love you!";
String testCase3(testCase);

cout << "Initializing three testCases" << endl;
cout << "testCase('Happy Birthday!')" << endl;
cout << "testCase2 =  'I love you!'" << endl;
cout << "testCase3(testCase)" << endl << endl;

cout << "Testing the GetSize() Function" << endl;
cout << "Expected size of testCase is 15" << endl;
cout << "Actual size is: " << testCase.GetSize() << endl;
cout << "Expected size of testCase2 is 11" << endl;
cout << "Actual size is: " << testCase2.GetSize() << endl << endl;

cout << "Testing the GetText() Function" << endl;
cout << "Expected text of testCase is - Happy Birthday!" << endl;
cout << "Actual text is: " << testCase.GetText() << endl;
cout << "Expected text of testCase2 is - I love you!" << endl;
cout << "Actual text is: " << testCase2.GetText() << endl << endl;

cout << "Testing the index [] operator" << endl;
cout << "Expect testCase[0] = 'H'" << endl;
cout << "Actual output for testCase[0] = " << testCase[0] << endl;
cout << "Expect testCase2[4] = 'v'" << endl;
cout << "Actual output for testCase2[4] = " << testCase2[4] << endl << endl;

cout << "Testing the equality == operator" << endl;
cout << "Expect (testCase == testCase2) -> 0" << endl;
cout << "testCase == testCase2 -> " << (testCase == testCase2) << endl;
cout << "Expect (testCase == testCase3) -> 1" << endl;
cout << "testCase == testCase3 -> " << (testCase == testCase3) << endl << endl;

cout << "Testing the inequality != operator" << endl;
cout << "Expect (testCase != testCase2) -> 1" << endl;
cout << "testCase != testCase2 -> " << (testCase != testCase2) << endl;
cout << "Expect (testCase != testCase3) -> 0" << endl;
cout << "testCase != testCase3 -> " << (testCase != testCase3) << endl << endl;

cout << "Testing the greaterThan > operator" << endl;
cout << "Expect (testCase > testCase2) -> 1" << endl;
cout << "testCase > testCase2 -> " << (testCase > testCase2) << endl;
cout << "Expect (testCase > testCase3) -> 0" << endl;
cout << "testCase > testCase3 -> " << (testCase > testCase3) << endl << endl;

cout << "Testing the lessThan < operator" << endl;
cout << "Expect (testCase < testCase2) -> 0" << endl;
cout << "testCase > testCase2 -> " << (testCase < testCase2) << endl;
cout << "Expect (testCase < testCase3) -> 0" << endl;
cout << "testCase < testCase3 -> " << (testCase < testCase3) << endl << endl;

cout << "Testing the concatenation + operator" << endl;
cout << "Expect (testCase + testCase2) -> 'Happy Birthday!I love you!" << endl;
cout << "(testCase + testCase2) -> " << (testCase + testCase2) << endl;
cout << "Expect (testCase + testCase + testCase) -> 'Happy Birthday!Happy Birthday!Happy Birthday!" << endl;
cout << "(testCase + testCase + testCase)-> " << (testCase + testCase + testCase)  << endl << endl;

cout << "Testing the Find(foo,boo) Function" << endl;
cout << "Expected text of testCase.Find('a', 2) is 12" << endl;
cout << "Actual index is: " << testCase.Find('a', 2) << endl;
cout << "Expected text of testCase.Find('B', 1) is 6" << endl;
cout << "Actual index is: " << testCase.Find('B', 1) << endl;
cout << "Expected text of testCase2.Find('5', 3) is -1" << endl;
cout << "Actual index is: " << testCase.Find('5', 3) << endl;
cout << "Expected text of testCase2.Find('e', 0) is 5" << endl;
cout << "Actual index is: " << testCase2.Find('e', 0) << endl << endl;

cout << "Testing the Substring(foo,boo) Function" << endl;
cout << "Expected substring of testCase.Substring(0,2) is 'Ha'" << endl;
cout << "Actual text is: " << testCase.Substring(0,2) << endl;
cout << "Expected substring of testCase2.Substring(4,5) is 've yo'" << endl;
cout << "Actual text is: " << testCase2.Substring(4,5) << endl << endl;

cout << "Time to Break Our Code!" << endl;
try
{
	cout << endl << "Index Tests: out of range" << endl;
	cout << "testCase[-2]" << endl;
	testCase[-2];
	cout << "This Message will appear if implementation is successful" << endl;
}
catch(string error)
{
	cout << error << endl;
}
try
{
	cout << endl << "Index Tests: out of range" << endl;
	cout << "testCase[testCase.GetSize()]" << endl;
	testCase[testCase.GetSize()];
	cout << "This Message will appear if implementation is successful" << endl;
}
catch(string error)
{
	cout << error << endl << endl;
}
try
{
	cout << endl << "Substring Tests: out of range" << endl;
	cout << "testCase.Substring(-1,3)" << endl;
	testCase.Substring(-1,3);
	cout << "This Message will appear if implementation is successful" << endl;
}
catch(string error)
{
	cout << error << endl;
}
try
{
	cout << endl << "Substring Tests: out of range" << endl;
	cout << "testCase.Substring(1,18)" << endl;
	testCase.Substring(1,18);
	cout << "This Message will appear if implementation is successful" << endl;
}
catch(string error)
{
	cout << error << endl;
}
try
{
	cout << endl << "Substring Tests: out of range" << endl;
	cout << "testCase.Substring(10,7)" << endl;
	testCase.Substring(10,7);
	cout << "This Message will appear if implementation is successful" << endl;
}
catch(string error)
{
	cout << error << endl;
}



system("pause");

}