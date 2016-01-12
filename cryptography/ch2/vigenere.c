#include <stdio.h>
#include <string.h>

int Coincidence(char *cipher_text, int place)
{
    int count = 0;
    int i;
    int n = strlen(cipher_text);
    for (i = 0; i < n; ++i) {
        int j = i + place;
        if (j >= n) break;
        if (cipher_text[i] == cipher_text[j]) ++count;
    }
    return count;
}

int KeyLength(char *cipher_text)
{
    int max_coincidence = 0;
    int i, j, key_length;
    printf("position\tsame alphatbet\n");
    for (i = 1; i <= 13; ++i) {
        j = Coincidence(cipher_text, i);
        printf("%d\t%d\n", i, j);
        if (j > max_coincidence) {
            max_coincidence = j;
            key_length = i;
        }
    }
    return key_length;
}

int main(void)
{
    // The Code Book stage 4
    char a[] = "KQOWEFVJPUJUUNUKGLMEKJINMWUXFQMKJBGWRLFNFGHUDWUUMBSVLPSNCMUEKQCTESWREEKOYSSIWCTUAXYOTAPXPLWPNTCGOJBGFQHTDWXIZAYGFFNSXCSEYNCTSSPNTUJNYTGGWZGRWUUNEJUUQEAPYMEKQHUIDUXFPGUYTSMTFFSHNUOCZGMRUWEYTRGKMEEDCTVRECFBDJQCUSWVBPNLGOYLSKMTEFVJJTWWMFMWPNMEMTMHRSPXFSSKFFSTNUOCZGMDOEOYEEKCPJRGPMURSKHFRSEIUEVGOYCWXIZAYGOSAANYDOEOYJLWUNHAMEBFELXYVLWNOJNSIOFRWUCCESWKVIDGMUCGOCRUWGNMAAFFVNSIUDEKQHCEUCPFCMPVSUDGAVEMNYMAMVLFMAOYFNTQCUAFVFJNXKLNEIWCWODCCULWRIFTWGMUSWOVMATNYBUHTCOCWFYTNMGYTQMKBBNLGFBTWOJFTWGNTEJKNEEDCLDHWTVBUVGFBIJGYYIDGMVRDGMPLSWGJLAGOEEKJOFEKNYNOLRIVRWVUHEIWUURWGMUTJCDBNKGMBIDGMEEYGUOTDGGQEUJYOTVGGBRUJYS";
    a = "";
    printf("%d\n", KeyLength(a));

    return 0;
}

