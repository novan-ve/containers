# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    compare.sh                                         :+:    :+:             #
#                                                      +:+                     #
#    By: novan-ve <novan-ve@student.codam.n>          +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/29 17:08:48 by novan-ve      #+#    #+#                  #
#    Updated: 2020/12/02 15:57:37 by novan-ve      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

check () {

echo -en "$1:\t"
DIFF=$( diff my.txt real.txt )
if [ "$DIFF" != "" ]
then
  echo -e "${RED}[FAIL]${NC}"
  echo "$1" >> output.txt
  echo "$DIFF" >> output.txt
  echo "" >> output.txt
else
  echo -e "${GREEN}[OK]${NC}"
fi
}

rm output.txt 2> /dev/null

if [ $# -eq 0 ]||[ "$1" = "list" ]
then
  # list
  clang++ -Wall -Werror -Wextra -pedantic -std=c++98 -fsanitize=address main.cpp list_main.cpp vector_main.cpp -o my
  sed 's/ft\:\:/std\:\:/g' list_main.cpp > list_main2.cpp
  sed -i '13 a \#include \<list\>' list_main2.cpp
  clang++ -Wall -Werror -Wextra -pedantic -std=c++98 -fsanitize=address main.cpp list_main2.cpp vector_main.cpp -o real
  ./my > my.txt
  ./real > real.txt
  check "List"
  rm list_main2.cpp my real my.txt real.txt
fi

if [ $# -eq 0 ]||[ "$1" = "vector" ]
then
  # vector
  clang++ -Wall -Werror -Wextra -pedantic -std=c++98 -fsanitize=address main.cpp list_main.cpp vector_main.cpp -o my
  sed 's/ft\:\:/std\:\:/g' vector_main.cpp > vector_main2.cpp
  sed -i '13 a \#include \<vector\>' vector_main2.cpp
  clang++ -Wall -Werror -Wextra -pedantic -std=c++98 -fsanitize=address main.cpp list_main.cpp vector_main2.cpp -o real
  ./my > my.txt
  ./real > real.txt
  check "Vector"
  rm vector_main2.cpp my real my.txt real.txt
fi
