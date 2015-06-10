int global_uninit_var;

int main(void)
{
    static int static_var;

    printf("%d %d\n", global_uninit_var, static_var);
}
