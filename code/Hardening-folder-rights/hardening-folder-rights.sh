#!/bin/bash
echo [O]pen or [C]lose rights ? O / C

read etat
case $etat in
O)	for website in wordpress
do
  echo Opening rights /$website
  cd ~/$website
  find . -type f -exec chmod 604 {} \;;find . -type d -exec chmod 705 {} \;
  
done
	;;
F)   for website in wordpress
do
  echo Hardening rights /$website
  cd ~/$website
  find . -type f -exec chmod 404 {} \;;find . -type d -exec chmod 505 {} \;;find . -name ".htaccess" -exec chmod 404 {} \;;find . -name "*upload*" -exec chmod -R 705 {} \;;find . -name "*blogs.dir*" -exec chmod -R 705 {} \;
  
done
  ;;
esac
