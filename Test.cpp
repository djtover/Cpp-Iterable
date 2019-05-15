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
		int num = 5;
		for (int i : range(5, 9))
		{
			testcase.CHECK_OUTPUT(i, std::to_string(num));
			num++;
		}
		double d = 5.1;
		for (double i : range(5.1, 9.1))
		{
			string str = to_string(d);
			str.erase(str.find_last_not_of('0') + 1, string::npos);
			testcase.CHECK_OUTPUT(i, str);
			d++;
		}

		char c = 'a';
		for (char i : range('a', 'e'))
		{
			string str(1, c);
			testcase.CHECK_OUTPUT(i, str);
			c++;
		}

		testcase.setname("tests for chain");
		// first test range and range
		num = 1;
		for (int i : chain(range(1, 4), range(5, 8)))
		{
			testcase.CHECK_OUTPUT(i, to_string(num));
			num++;
			if (num == 4)
			{
				num = 5;
			}
		}
		// second test range and string
		c = 'a';
		string s = "hello";
		int j = 0;
		for (char i : chain(range('a', 'e'), string("hello")))
		{
			string str(1, c);
			testcase.CHECK_OUTPUT(i, str);
			c++;
			if (c == 'e')
			{
				c = s.at(j);
				j++;
			}
		}

		testcase.setname("tests for zip");
		// first test range and string
		num = 1;
		s = "hello";
		j = 0;
		for (auto pair : zip(range(1, 6), string("hello")))
		{
			string str1(1, s.at(j));
			string str2 = to_string(num) + "," + str1;
			testcase.CHECK_OUTPUT(pair, str2);
			j++;
			num++;
		}

		// second test, two ranges and two strings
		int num1 = 1;
		int num6 = 6;
		string s1 = "xyz";
		string s2 = "abc";
		j = 0;

		for (auto pair : zip(zip(range(1, 4), string("xyz")), zip(string("abc"), range(6, 9))))
		{
			string str1(1, s1.at(j));
			string str2  (1, s2.at(j));
			string str3 = to_string(num1) + "," + str1 + "," + str2 + "," + to_string(num6);
			testcase.CHECK_OUTPUT(pair, str3);
			num1++;
			num6++;

			j++;
		}

		testcase.setname("product test");
		num1 = 1;
		s = "hello";
		j=0;
		for (auto pair : product(range(1, 4), string("hello")))
		{
			string str1(1,s.at(j));
			string str2 = to_string(num1) +"," + str1;
			testcase.CHECK_OUTPUT(pair,str2);
			j++;
			if(j==5){
				num1++;
				j++;
			}
		}

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
