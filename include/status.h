/*
 * *****************************************************************************
 *
 * Copyright 2018 Gavin D. Howard
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
 * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
 * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 *
 * *****************************************************************************
 *
 * All bc status codes.
 *
 */

#ifndef BC_STATUS_H
#define BC_STATUS_H

typedef enum BcStatus {

	BC_STATUS_SUCCESS = 0,
	BC_STATUS_ERROR,
	BC_STATUS_EOF,
	BC_STATUS_EMPTY_EXPR,
	BC_STATUS_SIGNAL,
	BC_STATUS_QUIT,

} BcStatus;

typedef enum BcError {

	BC_ERROR_VM_ALLOC_ERR,
	BC_ERROR_VM_IO_ERR,
	BC_ERROR_VM_FILE_ERR,
	BC_ERROR_VM_BIN_FILE,
	BC_ERROR_VM_PATH_DIR,
	BC_ERROR_VM_OPTION,

	BC_ERROR_PARSE_EOF,
	BC_ERROR_PARSE_CHAR,
	BC_ERROR_PARSE_STRING,
	BC_ERROR_PARSE_COMMENT,
	BC_ERROR_PARSE_TOKEN,
#if BC_ENABLED
	BC_ERROR_PARSE_EXPR,
	BC_ERROR_PARSE_EMPTY_EXPR,
	BC_ERROR_PARSE_PRINT,
	BC_ERROR_PARSE_FUNC,
	BC_ERROR_PARSE_ASSIGN,
	BC_ERROR_PARSE_NO_AUTO,
	BC_ERROR_PARSE_DUP_LOCAL,
	BC_ERROR_PARSE_BLOCK,
	BC_ERROR_PARSE_RET_VOID,
#if BC_ENABLE_REFERENCES
	BC_ERROR_PARSE_REF_VAR,
#endif // BC_ENABLE_REFERENCES
#endif // BC_ENABLED

	BC_ERROR_MATH_NEGATIVE,
	BC_ERROR_MATH_NON_INTEGER,
	BC_ERROR_MATH_OVERFLOW,
	BC_ERROR_MATH_DIVIDE_BY_ZERO,
#if BC_ENABLE_EXTRA_MATH
	BC_ERROR_MATH_UNDERFLOW,
#endif // BC_ENABLE_EXTRA_MATH

	BC_ERROR_EXEC_IBASE,
	BC_ERROR_EXEC_OBASE,
	BC_ERROR_EXEC_SCALE,
	BC_ERROR_EXEC_READ_EXPR,
	BC_ERROR_EXEC_REC_READ,
	BC_ERROR_EXEC_TYPE,
#if DC_ENABLED
	BC_ERROR_EXEC_STACK,
#endif // DC_ENABLED
#if BC_ENABLED
	BC_ERROR_EXEC_PARAMS,
	BC_ERROR_EXEC_UNDEF_FUNC,
	BC_ERROR_EXEC_VOID_VAL,
#endif // BC_ENABLED

	BC_ERROR_POSIX_START,

#if BC_ENABLED
	BC_ERROR_POSIX_NAME_LEN = BC_ERROR_POSIX_START,
	BC_ERROR_POSIX_COMMENT,
	BC_ERROR_POSIX_KW,
	BC_ERROR_POSIX_DOT,
	BC_ERROR_POSIX_RET,
	BC_ERROR_POSIX_BOOL,
	BC_ERROR_POSIX_REL_POS,
	BC_ERROR_POSIX_MULTIREL,
	BC_ERROR_POSIX_FOR1,
	BC_ERROR_POSIX_FOR2,
	BC_ERROR_POSIX_FOR3,
	BC_ERROR_POSIX_BRACE,
	BC_ERROR_POSIX_REF,
#endif // BC_ENABLED

} BcError;

#define BC_ERR_IDX_VM (0)
#define BC_ERR_IDX_PARSE (1)
#define BC_ERR_IDX_MATH (2)
#define BC_ERR_IDX_EXEC (3)
#if BC_ENABLED
#define BC_ERR_IDX_POSIX (4)
#endif // BC_ENABLED

#define BC_UNUSED(e) ((void) (e))

#endif // BC_STATUS_H
