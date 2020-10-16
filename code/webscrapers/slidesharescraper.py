"""
===================================================================================
    Scrape and Extract ALL the powerpoint Slides From slideshare.net 
    Just Enter the page url and the directory to which you want to save the files And Done!
===================================================================================
##Eg Url:https://www.slideshare.net/gpkm/8086-new -> For 8086 programming..

"""

import requests
import os
from bs4 import BeautifulSoup
import argparse
from random import randint
from img2pdf import convert

parser = argparse.ArgumentParser(description="\tDownloads Images from slideshare.net url and combines them to a pdf")
parser.add_argument('url')
parser.add_argument('outpath',metavar='outpath',help="The output path to which the files will be saved")
parser.add_argument('-p',metavar='prefix',help="The prefix that each file will have..(default:slide)\n\t(Eg. egg => files save will be of form egg1 egg2 egg3 ...)")   


def download_slides_as_image(url, dir, filenamePrefix, ext):
    try:
        slideCount = 1
        imgList = []
        complete = False
        mainUrl = url
        rawData = requests.get(mainUrl)
        parser = BeautifulSoup(rawData.content, "html.parser")
        listOfSection = parser.find_all("section", {"class": "slide"})
        listOfSlideUrls = []
        noOfSlides =0
        for i in listOfSection:
            try:
                url = i.img["data-full"]
                listOfSlideUrls.append(i.img["data-full"])
            except (e):
                print("Error occured while Parsing url ")
                print(e.what())
        noOfSlides = len(listOfSlideUrls)
        print(f"No of Files To Download : {noOfSlides}")
        for url in listOfSlideUrls:
            filename = f"{filenamePrefix}{slideCount}.{ext}"
            fileContentStream = requests.get(url, stream=True)
            curImagePath = os.path.join(dir, f"{filename}")
            with open(curImagePath, "wb") as file:
                print(f"Downloading :  {filename} ")
                for chunk in fileContentStream.iter_content(chunk_size=1024):
                    if chunk:
                        file.write(chunk)
            imgList.append(curImagePath)
            slideCount += 1
            print(f"Done..({slideCount-1}/{noOfSlides})")
    except KeyboardInterrupt:
        print(
            """
    Cancelling Download.."""
        )
    return imgList,complete,slideCount


if __name__ == "__main__":
    

    args = parser.parse_args()
    try:
        url =args.url
        dir = args.outpath
        try:
            if os.path.exists(dir):
                createSubDir =  input("Dir Already Exists Create a new subDir called Slides? (y/n): ").lower()
                if 'y' in createSubDir:
                    # dir+="Slides"
                    subDir = "Slides"
                    
                    while os.path.exists(os.path.join(dir,subDir)):
                        subDir+=str(randint(1,10))
                    dir  = os.path.join(dir,subDir)
                    print(f"Files Will be saved in {dir}")
                else:
                    print(f"Saving in {os.path.relpath(dir)}")
            if not os.path.exists(dir):
                os.makedirs(dir)
        except OSError as e:
            if e.errno != os.errno.EXIST:
                raise e
        if args.p:
            filenamePrefix = args.p
        else:
            filenamePrefix = 'slide'

        ext = "png"
        # ext = input('Enter the file Extension..')


        print("--------Starting-----------")
        imgList,completed,slideCount =download_slides_as_image(url, dir, filenamePrefix, ext)
        if completed:
            print("-------------Done!------------")
        else:
            print(f"Cancelled..(Downloaded {slideCount-1} files)")

        if slideCount>1:
            print("Converting To Pdf..")
            outPath = os.path.join(dir,"output")
            if not os.path.exists(outPath):
                os.mkdir(outPath)    
            outfile = os.path.join(dir,"output/Output.pdf")
            convert(imgList,outputstream = outfile)
            print(f"Saved {outfile}")
    except KeyboardInterrupt:
        print(
            """
===============================
    Action Cancelled by User
    BYE..
==============================="""
        )
