import praw
from PyDictionary import PyDictionary

reddit =praw.Reddit(client_id='mesVy0qDcd5Dkw',client_secret='ULpF5mFIBtBJs8Q4J0OxxBwqEdxPNw',username='CobblerOld3836',password='testbot',user_agent='testbot')
subreddit=reddit.subreddit('words')
dictionary=PyDictionary()

call='!testbot'

for comment in subreddit.stream.comments():
    if call in comment.body:
        word=comment.body.replace(call,'')
        try:
            words=dictionary.meaning(word)
            reply=[item[0] for item in words.values()]
            comment.reply(word + ': '+ reply[0])
        except :
            print('Word not found')
