for i in $(seq 1 65535);
do
    curl http://ctf2015.hitcon.org:$i --connect-timeout 0.1
done
