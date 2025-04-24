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
#include "../utils.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 200

void f36(int maxTime)
{
	double ez[SIZE] = {.0};
	double hy[SIZE] = {.0};

	const double imp0 = 377.0;
	const int interval = 10;
	const int width = ceil(log10(maxTime/interval));

	const size_t boundary = 50;

	int frame = 0;

	for(int qTime = 0; qTime < maxTime; qTime++)
	{
		// Simple ABC for hy[size - 1]
		hy[SIZE-1] = hy[SIZE-2];

		// Magnetic field update
		for(int mm = 0; mm < SIZE - 1; mm++)
			hy[mm] += (ez[mm+1] - ez[mm]) / imp0;

		// Correction for Hy adjacent to to TFSF boundary
		hy[boundary-1] -= exp(-(qTime-30.)*(qTime-30.)/100.) / imp0;

		// Simple ABC for ez[0]
		ez[0] = ez[1];

		// Electric field update
		for(int mm = 1; mm < SIZE ; mm++)
			ez[mm] += (hy[mm] - hy[mm-1]) * imp0;

		// Correction for Ez adjacent to TFSF boundary
		ez[boundary] += exp(-(qTime+0.5-(-0.5)-30.)*(qTime+0.5-(-0.5)-30.)/100.);

		if(qTime % interval == 0)
			write_snapshot(ez, SIZE, frame++, width);
	}

}

