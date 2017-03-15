#include <iostream>
#include <string>

class CMyString
{
public:
    CMyString(const std::string& s = "") {
        m_pData = new char[s.size() + 1];
        strcpy(m_pData, s.c_str());
    }
    CMyString(const CMyString& str) { m_pData = str.m_pData;}
    ~CMyString(void)
    {
        delete []m_pData;
    }
    /*
    CMyString& operator =(const CMyString& str)
    {
        if (this == &str) {
            return *this;
        }
        delete []m_pData;
        m_pData = NULL;
        m_pData = new char[strlen(str.m_pData) + 1];
        strcpy(m_pData, str.m_pData);
        return *this;
    }
    */
    CMyString& operator =(const CMyString& str)
    {
        if (this != &str) {
            CMyString strTemp(str);

            char* pTemp = strTemp.m_pData;
            strTemp.m_pData = m_pData;
            m_pData = pTemp;
        }

        return *this;
    }
    void print() {
        std::cout << &m_pData << std::endl;
    }
private:
    char* m_pData;

};


int main(void)
{
    CMyString a, c;
    CMyString b("Ha");
    b = b;
    a = b;
    /*
    a = c = b;
    b = b;
    a.print(); b.print();
    */
}

