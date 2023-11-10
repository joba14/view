
#define enable_utf8_string_view_implementation
#include "../include/utf8_string_view.h"

#include <stdio.h>

signed int main(
	void)
{
	const utf8_string_view_s sv1 = utf8_string_view_from_cstring("hello");
	const utf8_string_view_s sv2 = utf8_string_view_from_parts("hello", 5);

	const bool equal = utf8_string_view_equal(sv1, sv2);
	printf("sv1 == sv2 => %s\n", equal ? "true" : "false");

	printf(utf8_fmt "\n", utf8_arg(
		utf8_string_view_from_cstring("+++++hello+++++")
	));

	printf(utf8_fmt "\n", utf8_arg(
		utf8_string_view_trim_left(
			utf8_string_view_from_cstring("+++++hello+++++"), '+'
		)
	));

	printf(utf8_fmt "\n", utf8_arg(
		utf8_string_view_trim_right(
			utf8_string_view_from_cstring("+++++hello+++++"), '+'
		)
	));

	printf(utf8_fmt "\n", utf8_arg(
		utf8_string_view_trim(
			utf8_string_view_from_cstring("+++++hello+++++"), '+'
		)
	));

	return 0;
}
