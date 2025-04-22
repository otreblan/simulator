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

#include "book.h"

#include <math.h>
#include <stdio.h>

#define SIZE 200

void f31(int maxTime)
{
	double ez[SIZE] = {.0};
	double hy[SIZE] = {.0};
	const double imp0 = 377.0;

	for(int qTime = 0; qTime < maxTime; qTime++)
	{
		// Magnetic field update
		for(int mm = 0; mm < SIZE - 1; mm++)
			hy[mm] += (ez[mm+1] - ez[mm]) / imp0;

		// Electric field update
		for(int mm = 1; mm < SIZE ; mm++)
			ez[mm] += (hy[mm] - hy[mm-1]) * imp0;

		// Hardcoded source node
		ez[0] = exp(-(qTime-30.) * (qTime - 30.) / 100);

		printf("%g\n", ez[50]);
	}

}

