## 過程
我平常會用python來處理資料，因為寫code起來方便然後有很多package可使用。
google了一下發現python-evtx可處理windows的evtx檔案。

花了一段時間在看如何使用這套件，原本想直接import該套件來用但發現document不太清楚也找不太到使用tutorial，
我試著看他的source code但包的滿多層的我看不太懂要如何轉成我想要的格式，因為趕時間所以放棄了。
後來我找到他裏面其中一個現成的script evtxdump.py可以將evtx格式檔案轉成xml。
因此開始動手寫code，將evtx file轉成xml後，再利用xml.etree來parse xml檔。

後來主要時間都花在熟悉如何parsexml檔案(沒碰過xml格式)，parse的方式不像我想像中的像是遞迴的樹狀格式，
而是必須依照順序的遍歷所有tags，找到想要的tags拿到其內容。

最後我寫了一個簡單的script，可以印出evtx檔案中，對應到某event_id之所有event的event_record_id。
然後我的code是用從朋友電腦載來的某一個evtx檔來測試。

由於時間緊迫放棄了直接import該套件來處理，而轉成xml檔後再處理。
非常不好意思orz，這樣頗髒，之後會好好看裏面的source code了解如何用該package，然後直接處理。

## 時間花費
0.5hr 嘗試import package直接處理data
1.5hr 練習parse xml資料
0.5hr 寫code
0.5hr 中間去吃飯


## Steps to run the code in linux

1. Download parse.py

2. clone python-evtx code in the same directory as parse.py
e.g.
$ mkdir test && cd test
download parse.py and put it in the "test" directory
$ git clone https://github.com/williballenthin/python-evtx

3. Execute the parse.py script
$ python parse.py {evtx_file} {event_id}

