typedef double Money;
class Account {
    public:
        Money balance() { return bal; }
    private:
        typedef double Money; //  error: changes meaning of ‘Money’ from ‘typedef double Money’
        Money bal;
};

int main(void)
{

}

