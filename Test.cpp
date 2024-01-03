#include "./cute/cute.h"
#include "./cute/ide_listener.h"
#include "./cute/xml_listener.h"
#include "./cute/cute_runner.h"
#include "Question1.h"
#include <iostream>


void testQuestion1() {
	int operand1 = 3, operand2 = 4;
	int expected = operand1 + operand2;

	int actual = add(operand1, operand2);

	ASSERT_EQUAL(expected, actual);
}

// add two more test cases for your unit test learning purpose


bool runAllTests(int argc, char const *argv[]) {
	cute::suite s;

    s.push_back(CUTE(testQuestion1));
	//TODO add your test here

	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<> > lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
