#include <iostream>
#include <bitset>
#include <random>

// the order of these defines tells a story of how i started reasonably and went increasingly insane
#define in std::cin
#define out std::cout
#define nl '\n'
#define thrash(x,y) ((addr << x) >> y)
#define octetloop for (i = 24; i >= 0; i -= 8)
#define getaddr addr = 0;                                             \
                out << "Enter the IP address, one octet at a time:\n";\
                octetloop                                             \
                {                                                     \
                    in >> input;                                      \
                    addr |= (input << i);                             \
                }                                                     \
// idk if u know but that last one is a joke reference to the socket function https://en.wikipedia.org/wiki/getaddrinfo

int main()
{
    uint32_t addr, input;
    char i;

    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, UINT32_MAX);

    getaddr

    //out << "\nValue " << addr << "\nBits " << std::bitset<32>(addr) << nl; // debug

    while (true)
    {
        out << "\nHow would you like to see your IP address?\n1) single value \n2) four values \n3) two values \n4) the value of a single bit\n5) all bit values\n6) enter new IP\n7) IP roulette\n8) quit\n> ";

        in >> input;
        out << nl;

        switch (input)
        {
            case 1:
                out << addr;
                break;

            case 2:
                octetloop
                    out << thrash(24 - i,24) << (i != 0 ? '.' : ' '); // UGH I HATE BRANCHING EVERY ITERATION
                break;

            case 3:
                out << "How many bits in the host portion of netmask?\n>";
                in >> input;
                out << nl << (addr >> 32-input) << ", " << thrash(input,input);
                break;

            case 4:
                out << "WHAT BIT U WANT\n>";
                in >> input;
                out << thrash(31-input,31);
                break;

            case 5:
                octetloop
                    out << std::bitset<8>(thrash(24-i,24)) << ' '; // no branch this time >:D
                break;

            case 6:
                getaddr
                break;

            case 7:
                while (input < 10000)
                {
                    out << '\r';
                    ++input;

                    addr = distribution(generator);

                    octetloop
                        out << std::bitset<8>(thrash(24 - i, 24)) << ' '; // no branch this time >:D
                }

                break;

            default:
                return(0);
        }

        out << nl;
    }
}