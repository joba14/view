
/**
 * @file utf8_string_view.h
 * 
 * @copyright This file is part of the "view" project and is distributed under
 * "View GPLv1" license.
 * 
 * @author joba14
 * 
 * @date 2023-11-10
 */

#ifndef __UTF8_STRING_VIEW_H__
#define __UTF8_STRING_VIEW_H__

#ifdef enable_utf8_string_view_implementation
#	define enable_view_implementation
#endif

#include <view.h>
define_view_type(utf8_string_view, char);

/**
 * @brief String view format for printf-like functions.
 */
#define utf8_fmt "%.*s"

/**
 * @brief String view argument for printf-like functions.
 */
#define utf8_arg(_string_view) ((signed int)(_string_view).length), (_string_view).data

/**
 * @brief Create string view from a cstring.
 * 
 * @param cstring[in] pointer to a cstring
 * 
 * @return utf8_string_view_s
 */
utf8_string_view_s utf8_string_view_from_cstring(
	const char* const cstring);

/**
 * @brief Trim a sequence of characters decided by 'compare' function on the left side of the string view.
 * 
 * @param string_view[in]  string view to be trimmed
 * @param char_to_trim[in] trimming character (in first sequence)
 * 
 * @return utf8_string_view_s
 */
utf8_string_view_s utf8_string_view_trim_left(
	const utf8_string_view_s string_view,
	const char char_to_trim);

/**
 * @brief Trim a sequence of characters decided by 'compare' function on the right side of the string view.
 * 
 * @param string_view[in]  string view to be trimmed
 * @param char_to_trim[in] trimming character (in first sequence)
 * 
 * @return utf8_string_view_s
 */
utf8_string_view_s utf8_string_view_trim_right(
	const utf8_string_view_s string_view,
	const char char_to_trim);

/**
 * @brief Trim a sequence of characters decided by 'compare' function on both sides of the string view.
 * 
 * @param string_view[in]  string view to be trimmed
 * @param char_to_trim[in] trimming character (in first sequence)
 * 
 * @return utf8_string_view_s
 */
utf8_string_view_s utf8_string_view_trim(
	const utf8_string_view_s string_view,
	const char char_to_trim);

#ifdef enable_utf8_string_view_implementation
#	include <string.h>

utf8_string_view_s utf8_string_view_from_cstring(
	const char* const cstring)
{
	_view_assert(cstring != NULL);
	const uint64_t length = (uint64_t)strlen(cstring);
	return utf8_string_view_from_parts(cstring, length);
}

utf8_string_view_s utf8_string_view_trim_left(
	const utf8_string_view_s string_view,
	const char char_to_trim)
{
	_view_assert(string_view.data != NULL);

	if (string_view.length <= 0)
	{
		return string_view;
	}

	uint64_t index = 0;

	while ((index < string_view.length) && (string_view.data[index] == char_to_trim))
	{
		++index;
	}

	return utf8_string_view_from_parts(string_view.data + index, string_view.length - index);
}

utf8_string_view_s utf8_string_view_trim_right(
	const utf8_string_view_s string_view,
	const char char_to_trim)
{
	_view_assert(string_view.data != NULL);

	if (string_view.length <= 0)
	{
		return string_view;
	}

	uint64_t index = 0;

	while ((index < string_view.length) && (string_view.data[string_view.length - index - 1] == char_to_trim))
	{
		++index;
	}

	return utf8_string_view_from_parts(string_view.data, string_view.length - index);
}

utf8_string_view_s utf8_string_view_trim(
	const utf8_string_view_s string_view,
	const char char_to_trim)
{
	return utf8_string_view_trim_left(
		utf8_string_view_trim_right(string_view, char_to_trim), char_to_trim
	);
}
#endif

#endif
