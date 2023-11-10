
/**
 * @file view.h
 * 
 * @copyright This file is part of the "view" project and is distributed under
 * "View GPLv1" license.
 * 
 * @author joba14
 * 
 * @date 2023-11-10
 */

#ifndef __VIEW_H__
#define __VIEW_H__

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifndef _view_assert
#	include <assert.h>
#	define _view_assert(_expression) assert(_expression)
#endif

#ifndef enable_view_implementation
#	define define_view_type(_view_type, _data_type)                            \
		typedef struct                                                         \
		{                                                                      \
			const _data_type* data;                                            \
			uint64_t length;                                                   \
		} _view_type ## _s;                                                    \
		                                                                       \
		_view_type ## _s _view_type ## _from_parts(                            \
			const _data_type* const data,                                      \
			const uint64_t length);                                            \
		                                                                       \
		bool _view_type ## _equal_range(                                       \
			const _view_type ## _s left,                                       \
			const _view_type ## _s right,                                      \
			const uint64_t length);                                            \
		                                                                       \
		bool _view_type ## _equal(                                             \
			const _view_type ## _s left,                                       \
			const _view_type ## _s right);                                     \
		                                                                       \
		_Static_assert(1, "") // NOTE: For ending the macro call with ;
#else
#	define define_view_type(_view_type, _data_type)                            \
		typedef struct                                                         \
		{                                                                      \
			const _data_type* data;                                            \
			uint64_t length;                                                   \
		} _view_type ## _s;                                                    \
		                                                                       \
		_view_type ## _s _view_type ## _from_parts(                            \
			const _data_type* const data,                                      \
			const uint64_t length);                                            \
		                                                                       \
		bool _view_type ## _equal_range(                                       \
			const _view_type ## _s left,                                       \
			const _view_type ## _s right,                                      \
			const uint64_t length);                                            \
		                                                                       \
		bool _view_type ## _equal(                                             \
			const _view_type ## _s left,                                       \
			const _view_type ## _s right);                                     \
		                                                                       \
		_view_type ## _s _view_type ## _from_parts(                            \
			const _data_type* const data,                                      \
			const uint64_t length)                                             \
		{                                                                      \
			_view_assert(data != NULL);                                        \
			                                                                   \
			return (_view_type ## _s)                                          \
			{                                                                  \
				.data = data,                                                  \
				.length = length                                               \
			};                                                                 \
		}                                                                      \
		                                                                       \
		bool _view_type ## _equal_range(                                       \
			const _view_type ## _s left,                                       \
			const _view_type ## _s right,                                      \
			const uint64_t length)                                             \
		{                                                                      \
			_view_assert(left.data != NULL);                                   \
			_view_assert(right.data != NULL);                                  \
			                                                                   \
			if (left.length < length || right.length < length)                 \
			{                                                                  \
				return false;                                                  \
			}                                                                  \
			                                                                   \
			for (uint64_t index = 0; index < length; ++index)                  \
			{                                                                  \
				if (left.data[index] != right.data[index])                     \
				{                                                              \
					return false;                                              \
				}                                                              \
			}                                                                  \
			                                                                   \
			return true;                                                       \
		}                                                                      \
		                                                                       \
		bool _view_type ## _equal(                                             \
			const _view_type ## _s left,                                       \
			const _view_type ## _s right)                                      \
		{                                                                      \
			_view_assert(left.data != NULL);                                   \
			_view_assert(right.data != NULL);                                  \
			                                                                   \
			if (left.length != right.length)                                   \
			{                                                                  \
				return false;                                                  \
			}                                                                  \
			                                                                   \
			return _view_type ## _equal_range(left, right, left.length);       \
		}                                                                      \
		                                                                       \
		_Static_assert(1, "") // NOTE: For ending the macro call with ;
#endif

#endif
