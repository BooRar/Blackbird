#!/bin/bash
clear
# RED='\033[0;31m'
RED='\e[31m ' 
CYAN='\e[36m'
GREEN=' \e[92m'
NC='\033[0m' # No Color

printf "${RED}"
cat <<- xx
===================JAMES SOFTWARE=================	
     ___       _ __   __  __  ___
    / _ )__ __(_) /__/ / /  |/  /__ ___  __ __
   / _  / // / / / _  / / /|_/ / -_) _ \/ // /
  /____/\_,_/_/_/\_,_/ /_/  /_/\__/_//_/\_,_/

==================================================

xx
printf "${NC}"

PS3='Please enter your choice: '

options=("Rebuild" "Run" "AltPath" "EditMain" "Help" "Quit")
select opt in "${options[@]}"
do
    case $opt in
        "Rebuild")
printf "${GREEN}"
          echo "you chose to rebuild project"
		  echo
printf "${CYAN}"
		  echo "I'm in `pwd`"
		  echo 
printf "${RED}"
		 echo "  Building ============"
printf "${NC}"
		 echo

		 cmake -B./build -H. -DCMAKE_BUILD_TYPE=Release
		echo
printf "${RED}"
		echo "  Installing ============"
echo
echo
printf "${NC}"

cmake --build ./build -- install		 
echo
echo ""
            ;;
        "Run")
printf "${GREEN}"
            echo "you chose choice 2"
printf "${NC}"
	clear
	./socket
            ;;
        "AltPath")
printf "${GREEN}"
            echo "you chose choice $REPLY which is $opt"
printf "${NC}"
            ;;
        "EditMain")
printf "${GREEN}"
            echo "you chose choice $REPLY which is $opt"
nano src/main.cpp
printf "${NC}"
            ;;

		 "Help")
printf "${GREEN}"
            echo "you chose choice $REPLY which is $opt"
printf "${NC}"		
   x=1
   NAME="John"
echo $NAME

count(){
		echo -n "opening Help! "
		  spin &
		  pid=$!
		 
		  for i in `seq 1 5`
		  do
			sleep 1;
						
		  done
		 echo "Done !"
		
		  NAME="simon"
		
		 
		 echo
		 echo 
		  kill  $pid 
		man ./moo 
		
}
 
spin(){

			

			while [ "$NAME" == "John" ]
			  do
					
					echo -ne ".";
					sleep 0.2;
					if [[ "$NAME" == "simon" ]]; then
						return [1]					
						break
					
					fi
			 
			  done

}
 
count
            ;;
        "Quit")
            break
            ;;
        *) echo "invalid option $REPLY";;
    esac
done









