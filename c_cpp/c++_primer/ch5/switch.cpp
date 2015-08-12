#include <iostream>

int getVal()
{
    return 0;
}

int main(void)
{
    unsigned int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;

    switch (int i = 0) {
        case 0:
            std::cout << "result of 'int i = 0' is 0" << std::endl;
            break;
    }

    unsigned int vowelCnt = 0;

    char ch;
    while (std::cin >> ch) {
        /*
        switch (ch) {
            case 'a':
                ++aCnt;
                break;
            case 'e':
                ++eCnt;
                break;
            case 'i':
                ++iCnt;
                break;
            case 'o':
                ++oCnt;
                break;
            case 'u':
                ++uCnt;
                break;
        }
        */
        switch (ch) {
            /*
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            */
            case 'a': case 'e' : case 'i' : case 'o' : case 'u' :
                ++vowelCnt;
                break;
            case 'b':
                ;
            default : {


            }
        }
    }

    std::cout << aCnt << " " << eCnt << " " << iCnt << " " << oCnt
              << " " << uCnt << std::endl;

    ch = getVal();
    int ival = 42;
    constexpr int ival2 = 42;
    /* case label must be integral constexpr */
    switch (ch) {
    //    case 3.14: // error : case label does not reduce to an integer constant
        case 3: ;
    //    case ival: ; // ‘ival’ cannot appear in a constant-expression
        case ival2: ; // ok, due to the fact that ival2 is constexpr
    }

    ch = 0;
    switch (ch) {
        case true:;
//            std::string file_name; // error, 因為同個scope中這個case label可能會被bypass且後面的case label可能會用到file_name，這樣就會error，所以language不會讓這件事發生
            int jval;
        case false:
            jval = 1;
            {
                std::string file_name; // ok, 因為限制file_name在這個block scope裡(block就是一個scope)，保證file_name只會存在這個case label的statement scope中。
            }
    }

    return 0;
}

