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

#include <stdio.h>

void f11()
{
	float a;

	a = 1.0/11.0;

	if(a + a + a + a + a + a + a + a + a + a + a == 1.0)
		printf("Equal\n");
	else
		printf("Not equal\n");
}

void f12()
{
	float a = 1.0, b = 0.5, c;

	c = a+b;

	while(c != a)
	{
		b = b / 2.0;
		c = a + b;
	}

	printf("%12g %12g %12g\n", a, b, c);
}

