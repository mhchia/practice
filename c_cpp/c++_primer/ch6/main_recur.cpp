int main(void)
{
    static int i = 0;
    if (i == 2) {
        return 0;
    }
    ++i;

    main();
}
