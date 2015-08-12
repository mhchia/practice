int main(void)
{
    const int i = 42;
    auto j = i; const auto &k = i; auto *p = &i;
    const auto j2 = i, &k2 = i;

    j = 1; // ok, so j is "int"

//    k = 1; // not ok, so k is "ref-to-const-int"

//    *p = 2; // not ok
//    p = nullptr; // ok, from these two lines, p is "ptr-to-const-int"

//    j2 = 1; // not ok, so j2 is const int

//    k2 = 1; // not ok, so k2 is ref-to-const-int
}
