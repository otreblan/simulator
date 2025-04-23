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

#include "utils.h"

#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void exit_errno()
{
	fprintf(stderr, "ufdtd: %s\n", strerror(errno));
	exit(EXIT_FAILURE);
}

void clean_str(char** str)
{
	assert(str != NULL);
	free(*str);
}

void clean_file(FILE** file)
{
	assert(file != NULL);

	if(fclose(*file) == EOF)
		exit_errno();
}

void write_snapshot_to_file(double* ez, size_t ez_size, FILE* file)
{
	PRINT_CHECK(fprintf(file, "x,value\n"));

	for(size_t mm = 0; mm < ez_size; mm++)
		PRINT_CHECK(fprintf(file, "%d,%g\n", (int)mm, ez[mm]));
}

void write_snapshot(double* ez, size_t ez_size, int frame, int width)
{
	[[gnu::cleanup(clean_str)]]
	char* filename = NULL;

	PRINT_CHECK(asprintf(&filename, "sim.%0*d.csv", width, frame));

	[[gnu::cleanup(clean_file)]]
	FILE* snapshost = NULL;

	if((snapshost = fopen(filename, "w")) == NULL)
		exit_errno();

	write_snapshot_to_file(ez, ez_size, snapshost);
}
