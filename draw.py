import numpy
import matplotlib.pyplot as plt

mylist = [] #记录时间安排，两个一组表示开头结尾
labels = [] #记录调度方案，用于产生不同的颜色

def getColor(mstr):
    "对于不同的工件产生不同的RGB颜色"
    num = int(mstr)
    num = num / 23
    x = num * 256 * 256 * 256
    r = x % 256
    g = ((x - r) / 256 % 256)
    b = ((x - r - g * 256) / (256 * 256) % 256)
    r = round(float(r / 256), 2) #四舍五入，保留两位
    g = round(float(g / 256), 2)
    b = round(float(b / 256), 2)
    return (r , g , b)


inputfile = open("time.txt" , 'r' , encoding='utf-8')
while 1:
    templine = inputfile.readline()
    if templine == '' :
        break
    templine = templine.strip('\t\n')
    templist = templine.split('\t')
    templist1 = []
    for iterm in templist :
        templist1.append(int(iterm))
    mylist.append(templist1)
inputfile.close() #以上部分输入每个机器上的每个工件加工时间段

inputfile = open("management.txt" , 'r' , encoding='utf-8')
while 1:
    templine = inputfile.readline()
    if templine == '' :
        break
    templine = templine.strip('\t\n')
    templist = templine.split('\t')
    labels.append(templist)
inputfile.close() #以上部分读入调度方案

y = numpy.array(mylist)
for i in range(0 , len(mylist)):
    for j in range(0 , int(len(mylist[i])/2)):
        plt.barh(i + 1 , y[i][2*j + 1] - y[i][2*j] , left= y[i][2*j] , color= getColor(labels[i][j]))
plt.xlabel("time")
plt.ylabel("machine")
plt.show() #画出甘特图