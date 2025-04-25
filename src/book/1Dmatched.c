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
#include <strings.h>

#define SIZE 200

void f39(int maxTime)
{
	const size_t boundary = 50;
	const size_t dielectric_layer = 100;
	const size_t loss_layer = 180;
	const double loss = 0.01;
	const double imp0 = 377.0;

	double ez[SIZE];
	double hy[SIZE-1];
	double ceze[SIZE];
	double cezh[SIZE];
	double chyh[SIZE-1];
	double chye[SIZE-1];

	// Initialize electric field
	for(int mm = 0; mm < SIZE; mm++)
		ez[mm] = 0.;

	// Initialize magnetic field
	for(int mm = 0; mm < SIZE-1; mm++)
		hy[mm] = 0.;

	// Set relative permittivity
	for(size_t mm = 0; mm < SIZE; mm++)
		if(mm < dielectric_layer)
		{
			ceze[mm] = 1.0;
			cezh[mm] = imp0;
		}
		else if(mm < loss_layer)
		{
			ceze[mm] = 1.0;
			cezh[mm] = imp0 / 9.0;
		}
		else
		{
			ceze[mm] = (1.0 - loss) / (1.0 + loss);
			cezh[mm] = imp0 / 9.0 / (1.0 + loss);
		}

	// Set magnetic field update coefficients
	for(size_t mm = 0; mm < SIZE-1; mm++)
		if(mm < loss_layer)
		{
			chyh[mm] = 1.0;
			chye[mm] = 1.0/imp0;
		}
		else
		{
			chyh[mm] = (1.0-loss) / (1.0+loss);
			chye[mm] = 1.0/imp0 /(1.0+loss);
		}

	const int interval = 4;
	const int width = ceil(log10(maxTime/interval));

	int frame = 0;

	for(int qTime = 0; qTime < maxTime; qTime++)
	{
		// Magnetic field update
		for(int mm = 0; mm < SIZE - 1; mm++)
			hy[mm] = hy[mm]*chyh[mm] + chye[mm]*(ez[mm+1] - ez[mm]);

		// Correction for Hy adjacent to to TFSF boundary
		hy[boundary-1] -= exp(-(qTime-30.)*(qTime-30.)/100.) / imp0;

		// Simple ABC for ez[0] and ez[SIZE-1]
		ez[0] = ez[1];

		// Electric field update
		for(int mm = 1; mm < SIZE ; mm++)
			ez[mm] = ez[mm]*ceze[mm] + cezh[mm]*(hy[mm] - hy[mm-1]);

		// Correction for Ez adjacent to TFSF boundary
		ez[boundary] += exp(-(qTime+0.5-(-0.5)-30.)*(qTime+0.5-(-0.5)-30.)/100.);

		if(qTime % interval == 0)
			write_snapshot(ez, SIZE, frame++, width);
	}

}

