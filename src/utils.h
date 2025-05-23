// Ufdtd
// Copyright © 2025 Otreblan
//
// ufdtd is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// ufdtd is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with ufdtd.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <stdio.h>

#define PRINT_CHECK(print) \
{ \
	if(print < 0) \
	{\
		exit_errno(); \
	}\
} \

[[noreturn]]
void exit_errno();

void clean_str(char** str);
void clean_file(FILE** file);

void write_snapshot_to_file(double* ez, size_t ez_size, FILE* file);
void write_snapshot(double* ez, size_t ez_size, int frame, int width);

