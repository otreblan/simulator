#!/usr/bin/env bash
# shellcheck disable=SC2155

NAME="mini-crypto"
DESCRIPTION="Toy blockchain"
VERSION="0.0.0"
HOMEPAGE_URL="https://github.com/utec-2023-2-seguridad/$NAME"
YEAR="$(date +%Y)"
USER_NAME="Otreblan"
USER_EMAIL="alberto.oporto@utec.edu.pe"

function esc() {
	printf "%s" "$@" | sed -e 's/[\/&]/\\&/g'
}

while IFS= read -rd "" filename; do
	sed -i "$filename" \
		-e "s/{{ NAME }}/$(esc "$NAME")/g" \
		-e "s/{{ DESCRIPTION }}/$(esc "$DESCRIPTION")/g" \
		-e "s/{{ VERSION }}/$(esc "$VERSION")/g" \
		-e "s/{{ HOMEPAGE_URL }}/$(esc "$HOMEPAGE_URL")/g" \
		-e "s/{{ YEAR }}/$(esc "$YEAR")/g" \
		-e "s/{{ USER_NAME }}/$(esc "$USER_NAME")/g" \
		-e "s/{{ USER_EMAIL }}/$(esc "$USER_EMAIL")/g"

	git mv --verbose --force "$filename" "${filename%.in}"
done < <(find . -name "*.in" -print0)
