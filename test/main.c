#define CTEST_MAIN

#include <ctest.h>
#include <functions.h>

int main(int argc, const char** argv)
{
	return ctest_main(argc, argv);
}

CTEST(inputcheck_test, correct_input)
{
	//Given
	char ch[] = "asdf";

	//When
 	format(ch);
 	const char exp[] = "asdf";

 	//Then
 	ASSERT_STR(exp, ch);
}

CTEST(inputcheck_test, correct_input_2)
{
	//Given
	char ch[] = "as-df";


	//When
 	format(ch);
 	const char exp[] = "as-df";

 	//Then
 	ASSERT_STR(exp, ch);
}

CTEST(inputcheck_test, incorrect_input_sym)
{
	//Given
	char ch[] = "a@sd/f";


	//When
 	format(ch);
 	const char exp[] = "a sd f";

 	//Then
 	ASSERT_STR(exp, ch);
}

