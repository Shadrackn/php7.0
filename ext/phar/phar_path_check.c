/* Generated by re2c 0.13.5 */
#line 1 "ext/phar/phar_path_check.re"
/*
  +----------------------------------------------------------------------+
  | phar php single-file executable PHP extension                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 2007-2015 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt.                                 |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Authors: Marcus Boerger <helly@php.net>                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#include "phar_internal.h"

phar_path_check_result phar_path_check(char **s, int *len, const char **error)
{
	const unsigned char *p = (const unsigned char*)*s;
	const unsigned char *m;

	if (*len == 1 && *p == '.') {
		*error = "current directory reference";
		return pcr_err_curr_dir;
	} else if (*len == 2 && p[0] == '.' && p[1] == '.') {
		*error = "upper directory reference";
		return pcr_err_up_dir;
	}

#define YYCTYPE         unsigned char
#define YYCURSOR        p
#define YYLIMIT         p+*len
#define YYMARKER        m
#define YYFILL(n)

loop:

#line 47 "ext/phar/phar_path_check.c"
{
	YYCTYPE yych;
	unsigned int yyaccept = 0;

	if ((YYLIMIT - YYCURSOR) < 4) YYFILL(4);
	yych = *YYCURSOR;
	if (yych <= '[') {
		if (yych <= ')') {
			if (yych <= '\t') {
				if (yych <= 0x00) goto yy21;
				goto yy23;
			} else {
				if (yych <= '\n') goto yy2;
				if (yych <= 0x19) goto yy23;
				goto yy11;
			}
		} else {
			if (yych <= '/') {
				if (yych <= '*') goto yy7;
				if (yych <= '.') goto yy11;
				goto yy3;
			} else {
				if (yych == '?') goto yy9;
				goto yy11;
			}
		}
	} else {
		if (yych <= 0xEC) {
			if (yych <= 0xC1) {
				if (yych <= '\\') goto yy5;
				if (yych <= 0x7F) goto yy11;
				goto yy23;
			} else {
				if (yych <= 0xDF) goto yy12;
				if (yych <= 0xE0) goto yy14;
				goto yy15;
			}
		} else {
			if (yych <= 0xF0) {
				if (yych <= 0xED) goto yy16;
				if (yych <= 0xEF) goto yy17;
				goto yy18;
			} else {
				if (yych <= 0xF3) goto yy19;
				if (yych <= 0xF4) goto yy20;
				goto yy23;
			}
		}
	}
yy2:
	YYCURSOR = YYMARKER;
	if (yyaccept <= 0) {
		goto yy4;
	} else {
		goto yy13;
	}
yy3:
	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych <= '-') goto yy4;
	if (yych <= '.') goto yy35;
	if (yych <= '/') goto yy36;
yy4:
#line 88 "ext/phar/phar_path_check.re"
	{
			goto loop;
		}
#line 115 "ext/phar/phar_path_check.c"
yy5:
	++YYCURSOR;
#line 72 "ext/phar/phar_path_check.re"
	{
			*error = "back-slash";
			return pcr_err_back_slash;
		}
#line 123 "ext/phar/phar_path_check.c"
yy7:
	++YYCURSOR;
#line 76 "ext/phar/phar_path_check.re"
	{
			*error = "star";
			return pcr_err_star;
		}
#line 131 "ext/phar/phar_path_check.c"
yy9:
	++YYCURSOR;
#line 80 "ext/phar/phar_path_check.re"
	{
			if (**s == '/') {
				(*s)++;
			}
			*len = (p - (const unsigned char*)*s) -1;
			*error = NULL;
			return pcr_use_query;
		}
#line 143 "ext/phar/phar_path_check.c"
yy11:
	yych = *++YYCURSOR;
	goto yy4;
yy12:
	++YYCURSOR;
	if ((yych = *YYCURSOR) <= 0x7F) goto yy13;
	if (yych <= 0xBF) goto yy26;
yy13:
#line 104 "ext/phar/phar_path_check.re"
	{
			*error ="illegal character";
			return pcr_err_illegal_char;
		}
#line 157 "ext/phar/phar_path_check.c"
yy14:
	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych <= 0x9F) goto yy13;
	if (yych <= 0xBF) goto yy34;
	goto yy13;
yy15:
	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych <= 0x7F) goto yy13;
	if (yych <= 0xBF) goto yy33;
	goto yy13;
yy16:
	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych <= 0x7F) goto yy13;
	if (yych <= 0x9F) goto yy32;
	goto yy13;
yy17:
	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych <= 0x7F) goto yy13;
	if (yych <= 0xBF) goto yy31;
	goto yy13;
yy18:
	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych <= 0x8F) goto yy13;
	if (yych <= 0xBF) goto yy29;
	goto yy13;
yy19:
	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych <= 0x7F) goto yy13;
	if (yych <= 0xBF) goto yy27;
	goto yy13;
yy20:
	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych <= 0x7F) goto yy13;
	if (yych <= 0x8F) goto yy24;
	goto yy13;
yy21:
	++YYCURSOR;
#line 91 "ext/phar/phar_path_check.re"
	{
			if (**s == '/') {
				(*s)++;
				(*len)--;
			}
			if ((p - (const unsigned char*)*s) - 1 != *len)
			{
				*error ="illegal character";
				return pcr_err_illegal_char;
			}
			*error = NULL;
			return pcr_is_ok;
		}
#line 216 "ext/phar/phar_path_check.c"
yy23:
	yych = *++YYCURSOR;
	goto yy13;
yy24:
	yych = *++YYCURSOR;
	if (yych <= 0x7F) goto yy2;
	if (yych >= 0xC0) goto yy2;
	yych = *++YYCURSOR;
	if (yych <= 0x7F) goto yy2;
	if (yych >= 0xC0) goto yy2;
yy26:
	yych = *++YYCURSOR;
	goto yy4;
yy27:
	yych = *++YYCURSOR;
	if (yych <= 0x7F) goto yy2;
	if (yych >= 0xC0) goto yy2;
	yych = *++YYCURSOR;
	if (yych <= 0x7F) goto yy2;
	if (yych <= 0xBF) goto yy26;
	goto yy2;
yy29:
	yych = *++YYCURSOR;
	if (yych <= 0x7F) goto yy2;
	if (yych >= 0xC0) goto yy2;
	yych = *++YYCURSOR;
	if (yych <= 0x7F) goto yy2;
	if (yych <= 0xBF) goto yy26;
	goto yy2;
yy31:
	yych = *++YYCURSOR;
	if (yych <= 0x7F) goto yy2;
	if (yych <= 0xBF) goto yy26;
	goto yy2;
yy32:
	yych = *++YYCURSOR;
	if (yych <= 0x7F) goto yy2;
	if (yych <= 0xBF) goto yy26;
	goto yy2;
yy33:
	yych = *++YYCURSOR;
	if (yych <= 0x7F) goto yy2;
	if (yych <= 0xBF) goto yy26;
	goto yy2;
yy34:
	yych = *++YYCURSOR;
	if (yych <= 0x7F) goto yy2;
	if (yych <= 0xBF) goto yy26;
	goto yy2;
yy35:
	yych = *++YYCURSOR;
	if (yych <= 0x00) goto yy39;
	if (yych <= '-') goto yy2;
	if (yych <= '.') goto yy38;
	if (yych <= '/') goto yy39;
	goto yy2;
yy36:
	++YYCURSOR;
#line 60 "ext/phar/phar_path_check.re"
	{
			*error = "double slash";
			return pcr_err_double_slash;
		}
#line 280 "ext/phar/phar_path_check.c"
yy38:
	yych = *++YYCURSOR;
	if (yych <= 0x00) goto yy41;
	if (yych == '/') goto yy41;
	goto yy2;
yy39:
	++YYCURSOR;
#line 68 "ext/phar/phar_path_check.re"
	{
			*error = "current directory reference";
			return pcr_err_curr_dir;
		}
#line 293 "ext/phar/phar_path_check.c"
yy41:
	++YYCURSOR;
#line 64 "ext/phar/phar_path_check.re"
	{
			*error = "upper directory reference";
			return pcr_err_up_dir;
		}
#line 301 "ext/phar/phar_path_check.c"
}
#line 108 "ext/phar/phar_path_check.re"

}
