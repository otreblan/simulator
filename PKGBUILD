# Maintainer: Otreblan <otreblain@gmail.com>

pkgname=hello-git
pkgver=r24.d58b411
pkgrel=1
epoch=
pkgdesc="A c++ template"
arch=('x86_64')
url="https://github.com/otreblan/hello"
license=('GPL3')
groups=()
depends=()
makedepends=('git' 'asciidoctor')
checkdepends=()
optdepends=()
provides=('hello')
conflicts=('hello')
source=("${pkgname}::git+${url}.git")
md5sums=('SKIP')

pkgver() {
	cd "$srcdir/$pkgname"
	( set -o pipefail
	git describe --long 2>/dev/null | sed 's/^v-//;s/\([^-]*-g\)/r\1/;s/-/./g' ||
	printf "r%s.%s" "$(git rev-list --count HEAD)" "$(git rev-parse --short HEAD)"
	)
}

build() {
	cd "$srcdir/$pkgname"
	autoreconf --install
	./configure --prefix=/usr
	make
}

package() {
	cd "$srcdir/$pkgname"
	make DESTDIR="$pkgdir/" install
}
