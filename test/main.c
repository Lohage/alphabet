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

CTEST(inputcheck_test, incorrect_input_digit)
{
	//Given
	char** ch = "as1df";


	//When
 	format(ch[0]);
 	const char exp[] = "as";

 	//Then
 	ASSERT_STR(exp, ch);
}

CTEST(inputcheck_test, incorrect_input_sym)
{
	//Given
	char ch[] = "a@sd/f";

	format(ch);

	//When
 	format(ch);
 	const char exp[] = "a";

 	//Then
 	ASSERT_STR(exp, ch);
}