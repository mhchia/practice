#define JSS(x) const std::string x ( #x )

int main(void)
{
    JSS (abs);
}

