# A C++ template
# Copyright © 2019-2020 otreblan
#
# hello is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# hello is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with hello.  If not, see <http://www.gnu.org/licenses/>.

find_program(ASCIIDOCTOR asciidoctor)

if(NOT ASCIIDOCTOR)
	message(SEND_ERROR "asciidoctor not found in $PATH")
endif()


add_custom_target(doc
	DEPENDS
		man1
)

# Man pages that end in *.1
set(MAN1_SOURCES
	hello.adoc
)

add_custom_target(man1
	SOURCES
		${MAN1_SOURCES}
)

foreach(MAN IN LISTS MAN1_SOURCES)

	# Deleting the extension
	get_filename_component(MAN ${MAN} NAME_WE)

	add_custom_command(
		TARGET doc
		COMMAND asciidoctor --backend manpage --out-file ${MAN}.1
			${CMAKE_CURRENT_SOURCE_DIR}/${MAN}.adoc

		OUTPUTS ${CMAKE_CURRENT_BINARY_DIR}/${MAN}.1
	)

	install(FILES
		${CMAKE_CURRENT_BINARY_DIR}/${MAN}.1
		DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/man/man1/
	)

endforeach()
