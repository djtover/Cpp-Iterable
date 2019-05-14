#include <iostream>
using namespace std;

#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"
#include "badkan.hpp"
#define COMMA ,

using namespace itertools;

int main() {
	
	badkan::TestCase testcase;
	int grade=0;
	int right=0;
	int wrong = 0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {



    grade = testcase.grade();
		right = testcase.right();
		wrong = testcase.wrong();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "\nYour grade is: "  << grade <<"\nRight: "<< right << "\nWrong: "<< wrong <<endl;
	return 0;
}

