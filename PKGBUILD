pkgname="dollarskip"
pkgver="3.0"
pkgrel="1"
source=(https://github.com/CleanMachine1/DollarSkip/archive/3.0.tar.gz)
pkgdesc="Skip the dollar!"
arch=('any')
url="https://github.com/CleanMachine1/DollarSkip"
license=('MIT')
depends('make')
build() {
    cd DollarSkip-${pkgver}
    make
}

package() {
    cd DollarSkip-${pkgver} &&
    install -m 755 -D temp "${pkgdir}/usr/bin/\$" 
}
sha256sums=('8826bd814c543566130152e6e2da02b0d43363ca51f5e806e208760918a2531e')
