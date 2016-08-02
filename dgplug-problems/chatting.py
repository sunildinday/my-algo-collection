"""
Description :To find out which nick spoke to whom highest number of times
File Required:(1) Test.txt contains all the test data
"""
#to get all the unique nick in the file
nick={}#dictionary to get all the unique nick names
ans={}#a dictionary to get  key,val where key will a tuple which contains names of the people with whom  tuple first
#element chatted with
srv={}#a dictionary to get the  names of the person with whom he chatted most
import collections
with open('test','r') as f:#opening the test file to get all the chats
    for line in f:
        first=line.find("<")
        second=line.find(">")

        if first!=-1 and second !=-1:
            #nick.add(line[first+1:second])
            nick[line[first+1:second]]=True#getting all the nicknames
with open('test','r') as f:
    for line in f:#getting chats line by line
        first=line.find("<")
        second=line.find(">")
        if first!=-1 and second !=-1:
            nikki=line[first+1:second]#nikki will be the person who is in angular bracket
            newline=line.split(' ')[2:]#split the line by space after the end of the angular bracket
            for names in newline:#getting all the words  from the line
                for  key in nick:
                #for every nick name find whether a match is found in the names
                    if key in names  and key!=nikki:
                        if (nikki,key) in ans:#if the pair(nikki ,key) exists in ans then increase its value by 1)
                            ans[(nikki,key)]+=1
                        else:#if this is the first time they chatted then ans will be 1
                            ans[(nikki,key)]=1
                        break;#break after finding a match
for key,val in ans.items():# utility to get  the name of the person with whom he chatted most
    if key[0] in srv:#if for the nickname key[0]  already exists then compare its value
        temp=srv[key[0]]
        name=temp[0]
        vl=temp[1]
        if vl<val:
            srv[key[0]]=(name,val)
    else:
        srv[key[0]]=(key[1],val)
fuck=collections.OrderedDict(sorted(srv.items()))#sort all the nickname
with open('ans.txt','w') as f:
    for key,val in fuck.items():#writing the sorted list to the file
        out=""
        out+=str(key)
        out+="  "
        out+=str(val[0])
        out+="  "
        out+=str(val[1])
        f.write(out)
        f.write("\n")
