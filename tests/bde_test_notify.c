/*
 * Library notification functions test program
 *
 * Copyright (C) 2011-2018, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <file_stream.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "bde_test_libbde.h"
#include "bde_test_libcerror.h"
#include "bde_test_macros.h"
#include "bde_test_unused.h"

/* Tests the libbde_notify_set_verbose function
 * Returns 1 if successful or 0 if not
 */
int bde_test_notify_set_verbose(
     void )
{
	/* Test invocation of function only
	 */
	libbde_notify_set_verbose(
	 0 );

	return( 1 );
}

/* Tests the libbde_notify_set_stream function
 * Returns 1 if successful or 0 if not
 */
int bde_test_notify_set_stream(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test regular cases
	 */
	result = libbde_notify_set_stream(
	          NULL,
	          &error );

	BDE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	BDE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
/* TODO test libcnotify_stream_set failure */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libbde_notify_stream_open function
 * Returns 1 if successful or 0 if not
 */
int bde_test_notify_stream_open(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test regular cases
	 */
	result = libbde_notify_stream_open(
	          "notify_stream.log",
	          &error );

	BDE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	BDE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libbde_notify_stream_open(
	          NULL,
	          &error );

	BDE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	BDE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libbde_notify_stream_close(
	          &error );

	BDE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	BDE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libbde_notify_stream_close function
 * Returns 1 if successful or 0 if not
 */
int bde_test_notify_stream_close(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test regular cases
	 */
	result = libbde_notify_stream_close(
	          &error );

	BDE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	BDE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
/* TODO test libcnotify_stream_close failure */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* The main program
 */
#if defined( HAVE_WIDE_SYSTEM_CHARACTER )
int wmain(
     int argc BDE_TEST_ATTRIBUTE_UNUSED,
     wchar_t * const argv[] BDE_TEST_ATTRIBUTE_UNUSED )
#else
int main(
     int argc BDE_TEST_ATTRIBUTE_UNUSED,
     char * const argv[] BDE_TEST_ATTRIBUTE_UNUSED )
#endif
{
	BDE_TEST_UNREFERENCED_PARAMETER( argc )
	BDE_TEST_UNREFERENCED_PARAMETER( argv )

	BDE_TEST_RUN(
	 "libbde_notify_set_verbose",
	 bde_test_notify_set_verbose )

	BDE_TEST_RUN(
	 "libbde_notify_set_stream",
	 bde_test_notify_set_stream )

	BDE_TEST_RUN(
	 "libbde_notify_stream_open",
	 bde_test_notify_stream_open )

	BDE_TEST_RUN(
	 "libbde_notify_stream_close",
	 bde_test_notify_stream_close )

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}
