pkgname="dollarskip"
pkgver="3.1"
pkgrel="1"
source=(https://github.com/CleanMachine1/DollarSkip/archive/3.1.tar.gz)
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
sha256sums=('b873e967df7e163df7eec92a94b4655ab4bdb85802333be2a0f4412d838c1a9d')
