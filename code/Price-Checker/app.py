import sys
from bs4 import BeautifulSoup
import requests
from datetime import datetime

def intter(k):
    num = ''
    for i in k:
        if i != ',':
            num = num + i
    return int(num)

c = ['a-span12', '_1vC4OE _3qQ9m1']
valini = []

urls = open(str(sys.argv[1]), 'r').readlines()

for i in range(0, len(urls)):

    if urls[i] == '0':
        break
    
    content = requests.request('GET', urls[i][:-2])

    soup = BeautifulSoup(content.text)

    if 'flipkart' in urls[i]:
        k = soup.find_all('div', class_=c[1])
        print(k)
        j = str(k[0])
        soup = BeautifulSoup(j, 'html.parser')
        tag = soup.div
        p_flipkart = intter(tag.string[1::])
        valini.append(p_flipkart)

    elif 'amazon' in urls[i]:
        k = soup.find_all('div', class_=c[0])
        print(k)
        j = str(k[0])
        soup = BeautifulSoup(j, 'html.parser')
        tag = soup.span
        p_amazon = intter(tag.string[1::])
        valini.append(p_amazon)

print(valini)

t1 = datetime.now()
while True:
    tTemp = datetime.now()
    if (tTemp - t1).total_seconds() == 3600:
        recheckkk()
        t1 = datetime.now()


def recheckkk():
    message = []
    for i in range(1, len(urls)):
        if urls[i] == None:
            continue
    
        content = requests.request('GET', urls[i][:-2])

        soup = BeautifulSoup(content.text)

        if 'flipkart' in urls[i]:
            k = soup.find_all('div', class_=c[1])
            j = str(k[0])
            soup = BeautifulSoup(j, 'html.parser')
            tag = soup.div
            p_flipkart = int(tag.string[1::])
            if p_flipkart > valini[i]:
                message.append(urls[i] + ' = ' + p_flipkart)

        elif 'amazon' in urls[i]:
            k = soup.find_all('div', class_=c[0])
            j = str(k[0])
            soup = BeautifulSoup(j, 'html.parser')
            tag = soup.span
            p_amazon = int(tag.string[1::])
            if p_amazon > valini[i]:
                message.append(urls[i] + ' = ' + p_amazon)

    print(message)


