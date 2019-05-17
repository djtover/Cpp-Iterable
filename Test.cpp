#include <iostream>
#include <iomanip>
using namespace std;

#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"
#include "badkan.hpp"
#define COMMA ,

using namespace itertools;

int main()
{

	badkan::TestCase testcase;
	int grade = 0;
	int right = 0;
	int wrong = 0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0)
	{

		// My Tests

		testcase.setname("Range tests");
		string str = "";
		for (int i : range(5, 9))
		{
			str += to_string(i);
		}
		testcase.CHECK_OUTPUT(str, "5678");
		str = "";
		for (double i : range(5.1, 9.1))
		{
			string s = to_string(i);
			s.erase(s.find_last_not_of('0') + 1, string::npos);

			str += s;
		}
		testcase.CHECK_OUTPUT(str, "5.16.17.18.1");

		str = "";
		for (char i : range('a', 'e'))
		{

			str += i;
		}
		testcase.CHECK_OUTPUT(str, "abcd");

		testcase.setname("tests for chain");
		// first test range and range
		str = "";
		for (int i : chain(range(1, 4), range(5, 8)))
		{
			str += to_string(i);
		}
		testcase.CHECK_OUTPUT(str, "123567");

		// second test range and string
		str = "";
		for (char i : chain(range('a', 'e'), string("hello")))
		{
			str += i;
		}
		testcase.CHECK_OUTPUT(str, "abcdhello");

		testcase.setname("tests for zip");
		stringstream ss;
		// first test range and string
		str = "";
		for (auto pair : zip(range(1, 6), string("hello")))
		{

			// str += to_string(pair);
			ss << pair;
		}
		ss >> str;
		testcase.CHECK_OUTPUT(str, "1,h2,e3,l4,l5,o");


		// second test of zipping two zips
		ss.clear();
		str = "";
		for (auto pair : zip(zip(range(1, 4), string("xyz")), zip(string("abc"), range(6, 9))))
		{
			ss << pair;
		}
		ss >> str;
		testcase.CHECK_OUTPUT(str, "1,x,a,62,y,b,73,z,c,8");

		testcase.setname("product test");
		ss.clear();
		str = "";
		for (auto pair : product(range(1, 4), string("hello")))
		{
			// str += pair;
		ss << pair;
		}
		ss >> str;
		testcase.CHECK_OUTPUT(str, "1,h1,e1,l1,l1,o2,h2,e2,l2,l2,o3,h3,e3,l3,l3,o");

		testcase.setname("powerset tests");
		// first test
		str = "";
		// ss.clear();
		for (auto subset : powerset(range(1, 4)))
		{
			str += subset;
		}
		testcase.CHECK_OUTPUT(str, "{}{1}{2}{1,2}{3}{1,3}{2,3}{1,2,3}");
		// second test
		str = "";
		for (auto subset : powerset(chain(range('a', 'c'), range('x', 'z'))))
		{
			str += subset;
		}
		testcase.CHECK_OUTPUT(str, "{}{a}{b}{a,b}{x}{a,x}{b,x}{a,b,x}{y}{a,y}{b,y}{a,b,y}{x,y}{a,x,y}{b,x,y}{a,b,x,y}");
		grade = testcase.grade();
		right = testcase.right();
		wrong = testcase.wrong();
	}
	else
	{
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "\nYour grade is: " << grade << "\nRight: " << right << "\nWrong: " << wrong << endl;
	return 0;
}
