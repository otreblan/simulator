# Ufdtd
# Copyright © 2025 Otreblan
#
# ufdtd is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# ufdtd is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with ufdtd.  If not, see <http://www.gnu.org/licenses/>.

add_subdirectory(book)

target_sources(${PROJECT_NAME}
	PRIVATE
		main.c
		utils.c
)
