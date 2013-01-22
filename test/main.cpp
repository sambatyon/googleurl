#include <iostream>

#include <googleurl/gurl.h>

void print_uri(GURL &url) {
    std::cout << "scheme:\t\t" << url.scheme() << "\nusername:\t" << url.username() << "\npassword:\t" << url.password()
        << "\nhost:\t\t" << url.host() << "\nport:\t\t" << url.port() << "\npath:\t\t" << url.path() << "\nquery:\t\t"
        << url.query() << "\nfragment:\t" << url.ref() << "\n\n";
}

int main(int argc, char **argv) {
    GURL real1("file://localhost/e:/Alex/workspace/demonstrator/Genesis/build/bin/x64/DEBUG/L32f.png");
    std::cout << (real1.is_valid() ? "is valid" : "is invalid") << '\n';
    std::cout << (real1.IsStandard() ? "is standard" : "is not standard") << '\n';
    print_uri(real1);

    GURL url("http://alex:ppm@wwww.furious-typing.com:1234/test/main.html?id=12356&mid=carlos#location");
    std::cout << (url.is_valid() ? "is valid" : "is invalid") << '\n';
    std::cout << (url.IsStandard() ? "is standard" : "is not standard") << '\n';
    print_uri(url);

    GURL invalid1("c:\\blubber");
    std::cout << (invalid1.is_valid() ? "is valid" : "is invalid") << '\n';
    std::cout << (invalid1.IsStandard() ? "is standard" : "is not standard") << '\n';
    print_uri(invalid1);

    GURL invalid2("file:/host/path");
    std::cout << (invalid2.is_valid() ? "is valid" : "is invalid") << '\n';
    std::cout << (invalid2.IsStandard() ? "is standard" : "is not standard") << '\n';
    print_uri(invalid2);

    GURL url1("http://alex:ppm@wwww.furious-typing.com:1234/test/main file.html?id=12356&mid=carlos#location");
    std::cout << (url1.is_valid() ? "is valid" : "is invalid") << '\n';
    std::cout << (url1.IsStandard() ? "is standard" : "is not standard") << '\n';
    print_uri(url1);

    GURL real2("file://localhost///192.168.0.2/path/to/file.txt");
    std::cout << (real2.is_valid() ? "is valid" : "is invalid") << '\n';
    std::cout << (real2.IsStandard() ? "is standard" : "is not standard") << '\n';
    print_uri(real2);

    GURL real3("file://localhost/e%3A/Alex/workspace/demonstrator/Genesis/build/bin/x64/DEBUG/L%5B32%5Df.pfm");
    std::cout << (real3.is_valid() ? "is valid" : "is invalid") << '\n';
    std::cout << (real3.IsStandard() ? "is standard" : "is not standard") << '\n';
    print_uri(real3);

    GURL real4("file://localhost/e:/Alex/workspace/demonstrator/Genesis/build/bin/x64/DEBUG/L[32]f.pfm");
    std::cout << (real4.is_valid() ? "is valid" : "is invalid") << '\n';
    std::cout << (real4.IsStandard() ? "is standard" : "is not standard") << '\n';
    print_uri(real4);
    return 0;
}
