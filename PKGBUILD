pkgname="dollarskip"
pkgver="3.1.1"
pkgrel="1"
source=(https://github.com/CleanMachine1/DollarSkip/archive/3.1.2.tar.gz)
pkgdesc="Skip the dollar!"
arch=('any')
url="https://github.com/CleanMachine1/DollarSkip"
license=('MIT')
depends=('glibc')
makedepends=('gcc' 'make' 'glibc')
build() {
    cd DollarSkip-${pkgver}
    make
}

package() {
    cd DollarSkip-${pkgver} &&
    install -m 755 -D temp "${pkgdir}/usr/local/bin/\$" 
}
sha256sums=('SKIP')
