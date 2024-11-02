#include <iostream>
#include <sstream>

const int BASE = 10;

#include "bigint.inc.cpp" // NOLINT
#include "doctest.h"

#define TASK_1
#define TASK_2
#define TASK_3
#define TASK_4
#define TASK_5
#define TASK_6

// NOLINTBEGIN(readability-function-cognitive-complexity)
// NOLINTBEGIN(misc-use-anonymous-namespace)

using lab_bigint::bigint;

#ifdef TASK_1
TEST_CASE("Constructor") {
    [[maybe_unused]] const bigint x("179");
    [[maybe_unused]] const bigint y(57);
}

TEST_CASE("operator==") {
    CHECK(!(bigint("0") == bigint("1")));
    CHECK(
        !(bigint("111111111111111999999999999999") ==
          bigint("999999999999999111111111111111"))
    );
    CHECK(
        !(bigint("999999999999999999999999999999") ==
          bigint("1000000000000000000000000000000"))
    );
    CHECK(!(100 == bigint("101")));
    CHECK(!(bigint("100") == 101));

    CHECK(!(bigint("1") == bigint("0")));
    CHECK(
        !(bigint("999999999999999111111111111111") ==
          bigint("111111111111111999999999999999"))
    );
    CHECK(
        !(bigint("1000000000000000000000000000000") ==
          bigint("999999999999999999999999999999"))
    );
    CHECK(!(bigint("101") == 100));
    CHECK(!(101 == bigint("100")));

    CHECK(bigint("0") == bigint("0"));
    CHECK(
        bigint("111111111111111111111111111111111") ==
        bigint("111111111111111111111111111111111")
    );
    CHECK(100 == bigint("100"));
    CHECK(bigint("100") == 100);
}

TEST_CASE("operator!=") {
    CHECK(bigint("0") != bigint("1"));
    CHECK(
        bigint("111111111111111999999999999999") !=
        bigint("999999999999999111111111111111")
    );
    CHECK(
        bigint("999999999999999999999999999999") !=
        bigint("1000000000000000000000000000000")
    );
    CHECK(100 != bigint("101"));
    CHECK(bigint("100") != 101);

    CHECK(bigint("1") != bigint("0"));
    CHECK(
        bigint("999999999999999111111111111111") !=
        bigint("111111111111111999999999999999")
    );
    CHECK(
        bigint("1000000000000000000000000000000") !=
        bigint("999999999999999999999999999999")
    );
    CHECK(bigint("101") != 100);
    CHECK(101 != bigint("100"));

    CHECK(!(bigint("0") != bigint("0")));
    CHECK(
        !(bigint("111111111111111111111111111111111") !=
          bigint("111111111111111111111111111111111"))
    );
    CHECK(!(100 != bigint("100")));
    CHECK(!(bigint("100") != 100));
}

TEST_CASE("operator<") {
    CHECK(bigint("0") < bigint("1"));
    CHECK(
        bigint("111111111111111999999999999999") <
        bigint("999999999999999111111111111111")
    );
    CHECK(
        bigint("999999999999999999999999999999") <
        bigint("1000000000000000000000000000000")
    );
    CHECK(100 < bigint("101"));
    CHECK(bigint("100") < 101);

    CHECK(!(bigint("1") < bigint("0")));
    CHECK(
        !(bigint("999999999999999111111111111111") <
          bigint("111111111111111999999999999999"))
    );
    CHECK(
        !(bigint("1000000000000000000000000000000") <
          bigint("999999999999999999999999999999"))
    );
    CHECK(!(bigint("101") < 100));
    CHECK(!(101 < bigint("100")));

    CHECK(!(bigint("0") < bigint("0")));
    CHECK(
        !(bigint("111111111111111111111111111111111") <
          bigint("111111111111111111111111111111111"))
    );
    CHECK(!(100 < bigint("100")));
    CHECK(!(bigint("100") < 100));
}

TEST_CASE("operator>") {
    CHECK(!(bigint("0") > bigint("1")));
    CHECK(
        !(bigint("111111111111111999999999999999") >
          bigint("999999999999999111111111111111"))
    );
    CHECK(
        !(bigint("999999999999999999999999999999") >
          bigint("1000000000000000000000000000000"))
    );
    CHECK(!(100 > bigint("101")));
    CHECK(!(bigint("100") > 101));

    CHECK(bigint("1") > bigint("0"));
    CHECK(
        bigint("999999999999999111111111111111") >
        bigint("111111111111111999999999999999")
    );
    CHECK(
        bigint("1000000000000000000000000000000") >
        bigint("999999999999999999999999999999")
    );
    CHECK(bigint("101") > 100);
    CHECK(101 > bigint("100"));

    CHECK(!(bigint("0") > bigint("0")));
    CHECK(
        !(bigint("111111111111111111111111111111111") >
          bigint("111111111111111111111111111111111"))
    );
    CHECK(!(100 > bigint("100")));
    CHECK(!(bigint("100") > 100));
}

TEST_CASE("operator<=") {
    CHECK(bigint("0") <= bigint("1"));
    CHECK(
        bigint("111111111111111999999999999999") <=
        bigint("999999999999999111111111111111")
    );
    CHECK(
        bigint("999999999999999999999999999999") <=
        bigint("1000000000000000000000000000000")
    );
    CHECK(100 <= bigint("101"));
    CHECK(bigint("100") <= 101);

    CHECK(!(bigint("1") <= bigint("0")));
    CHECK(
        !(bigint("999999999999999111111111111111") <=
          bigint("111111111111111999999999999999"))
    );
    CHECK(
        !(bigint("1000000000000000000000000000000") <=
          bigint("999999999999999999999999999999"))
    );
    CHECK(!(bigint("101") <= 100));
    CHECK(!(101 <= bigint("100")));

    CHECK(bigint("0") <= bigint("0"));
    CHECK(
        bigint("111111111111111111111111111111111") <=
        bigint("111111111111111111111111111111111")
    );
    CHECK(100 <= bigint("100"));
    CHECK(bigint("100") <= 100);
}

TEST_CASE("operator>=") {
    CHECK(!(bigint("0") >= bigint("1")));
    CHECK(
        !(bigint("111111111111111999999999999999") >=
          bigint("999999999999999111111111111111"))
    );
    CHECK(
        !(bigint("999999999999999999999999999999") >=
          bigint("1000000000000000000000000000000"))
    );
    CHECK(!(100 >= bigint("101")));
    CHECK(!(bigint("100") >= 101));

    CHECK(bigint("1") >= bigint("0"));
    CHECK(
        bigint("999999999999999111111111111111") >=
        bigint("111111111111111999999999999999")
    );
    CHECK(
        bigint("1000000000000000000000000000000") >=
        bigint("999999999999999999999999999999")
    );
    CHECK(bigint("101") >= 100);
    CHECK(101 >= bigint("100"));

    CHECK(bigint("0") >= bigint("0"));
    CHECK(
        bigint("111111111111111111111111111111111") >=
        bigint("111111111111111111111111111111111")
    );
    CHECK(100 >= bigint("100"));
    CHECK(bigint("100") >= 100);
}

bool check_to_string(const std::string &value) {
    return value == bigint(value).to_string();
}

TEST_CASE("to_string()") {
    CHECK(check_to_string("0"));
    CHECK(check_to_string("1"));
    CHECK(check_to_string("10"));
    CHECK(check_to_string("999"));
    CHECK(check_to_string("1234567890123456"));
    CHECK(check_to_string("100000000000000000000000000000000"));
    CHECK(check_to_string("14759328346542391834675032346958210394540"));
}
#endif  // TASK_1

#ifdef TASK_2
TEST_CASE("Leading zeros do not matter") {
    CHECK(bigint("00000001") == bigint("1"));
    CHECK(bigint("00000001") == bigint("00001"));
    CHECK(bigint("00000001").to_string() == "1");
}

TEST_CASE("Conversion to unsigned int works") {
    CHECK(static_cast<unsigned int>(bigint("12345678")) == 12345678);
    CHECK(static_cast<unsigned int>(bigint("00000")) == 0);
    CHECK(static_cast<unsigned int>(bigint("00001")) == 1);
}
#endif  // TASK_2

#ifdef TASK_3
TEST_CASE("operator+= and operator+") {
    bigint a;
    const bigint b = a += 10000;
    CHECK("10000" == a.to_string());
    CHECK("10000" == b.to_string());
    a += 0;
    CHECK("10000" == a.to_string());
    a += bigint("999999999999999999999999999999");
    CHECK("1000000000000000000000000009999" == a.to_string());
    a += 1;
    CHECK("1000000000000000000000000010000" == a.to_string());

    CHECK(
        "1000000000000000000000000009999" ==
        (bigint("999999999999999999999999999999") + 10000).to_string()
    );
    CHECK(
        "1000000000000000000000000009999" ==
        (10000 + bigint("999999999999999999999999999999")).to_string()
    );
}

TEST_CASE("operator+ with leading zeros") {
    CHECK(bigint("12345") == bigint("00012000") + 345);
}

TEST_CASE("operator+= to itself") {
    bigint a = 12345;
    a += a;
    CHECK(24690 == a);
}
#endif  // TASK_3

#ifdef TASK_4
TEST_CASE("operator-= and operator-") {
    bigint a("1000000000000000000000000010000");
    const bigint b = a -= 1;
    CHECK("1000000000000000000000000009999" == a.to_string());
    CHECK("1000000000000000000000000009999" == b.to_string());
    a -= 0;
    CHECK("1000000000000000000000000009999" == a.to_string());
    a -= bigint("999999999999999999999999999999");
    CHECK("10000" == a.to_string());
    a -= 10000;
    CHECK("0" == a.to_string());

    CHECK(
        "999999999999999999999999999999" ==
        (bigint("1000000000000000000000000009999") - 10000).to_string()
    );
    CHECK("9999" == (10000 - bigint("1")).to_string());
}

TEST_CASE("operator- with leading zeros") {
    CHECK(123000 == bigint("123456") - bigint("000456"));
}

TEST_CASE("assignment operators") {
    const bigint a("1234");
    const bigint b("56");

    CHECK(a == bigint(a));
    CHECK(1290 == a + b);
    CHECK(1178 == a - b);
    CHECK("1234" == a.to_string());
    CHECK(!(a == b));
    CHECK(a != b);
    CHECK(b < a);
    CHECK(b <= a);
    CHECK(a > b);
    CHECK(a >= b);

    bigint c;
    c += a;
    CHECK(1234 == c);
    c = a;
    CHECK(1234 == c);
    c -= b;
    CHECK(1178 == c);

    CHECK("1234" == a.to_string());
    CHECK("56" == b.to_string());
    CHECK("1178" == c.to_string());
}
#endif  // TASK_4

#ifdef TASK_5
TEST_CASE("operator++ and operator++(int)") {
    bigint a("999999999999998");
    bigint b = ++a;
    CHECK("999999999999999" == a.to_string());
    CHECK("999999999999999" == b.to_string());
    b = a++;
    CHECK("999999999999999" == b.to_string());
    CHECK("1000000000000000" == a.to_string());
    // (a++) should return bigint by value, and it's possible
    // to assign to it even though it's a useless operation with a temporary.
    (a++) = 10;
    CHECK("1000000000000001" == a.to_string());
}

TEST_CASE("operator-- and operator--(int)") {
    bigint a("1000000000000001");
    bigint b = --a;
    CHECK("1000000000000000" == a.to_string());
    CHECK("1000000000000000" == b.to_string());
    b = a--;
    CHECK("1000000000000000" == b.to_string());
    CHECK("999999999999999" == a.to_string());
    // (a--) should return bigint by value, and it's possible
    // to assign to it even though it's a useless operation with a temporary.
    (a--) = 10;
    CHECK("999999999999998" == a.to_string());
}
#endif  // TASK_5

#ifdef TASK_6
TEST_CASE("operator>>") {
    bigint a;

    std::stringstream("1234") >> a;
    CHECK(1234 == a);
    std::stringstream("438758234729356000000000000001230000000000000000000") >>
        a;
    CHECK(bigint("438758234729356000000000000001230000000000000000000") == a);
}

bool check_output(const std::string &value) {
    std::stringstream ss;
    ss << bigint(value);
    return value == ss.str();
}

TEST_CASE("operator<<") {
    CHECK(check_output("0"));
    CHECK(check_output("1"));
    CHECK(check_output("10"));
    CHECK(check_output("999"));
    CHECK(check_output("1234567890123456"));
    CHECK(check_output("100000000000000000000000000000000"));
}
#endif  // TASK_6

// NOLINTEND(misc-use-anonymous-namespace)
// NOLINTEND(readability-function-cognitive-complexity)
