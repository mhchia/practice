struct Y; // forward declaration so that Y can be a class member's pointer/ref type.

struct X {
    Y *a; // because that Y is declared, so type Y can be a class member's pointer/ref type.
};

struct Y {
    X b; // because that X is well-defined, so type X can be a class member.
};

int main(void)
{

}

