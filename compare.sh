# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    compare.sh                                         :+:    :+:             #
#                                                      +:+                     #
#    By: novan-ve <novan-ve@student.codam.n>          +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/29 17:08:48 by novan-ve      #+#    #+#                  #
#    Updated: 2020/12/03 17:43:55 by novan-ve      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

check () {

echo -en "$1:\t"
DIFF=$( diff mains/my.txt mains/real.txt )
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
  clang++ -Wall -Werror -Wextra -pedantic -std=c++98 -fsanitize=address main.cpp mains/list_main.cpp mains/vector_main.cpp -o mains/my
  sed 's/ft\:\:/std\:\:/g' mains/list_main.cpp > mains/list_main2.cpp
  sed -i '13 a \#include \<list\>' mains/list_main2.cpp
  clang++ -Wall -Werror -Wextra -pedantic -std=c++98 -fsanitize=address main.cpp mains/list_main2.cpp mains/vector_main.cpp -o mains/real
  ./mains/my > mains/my.txt
  ./mains/real > mains/real.txt
  check "List"
  rm mains/list_main2.cpp mains/my mains/real mains/my.txt mains/real.txt
fi

if [ $# -eq 0 ]||[ "$1" = "vector" ]
then
  # vector
  clang++ -Wall -Werror -Wextra -pedantic -std=c++98 -fsanitize=address main.cpp mains/list_main.cpp mains/vector_main.cpp -o mains/my
  sed 's/ft\:\:/std\:\:/g' mains/vector_main.cpp > mains/vector_main2.cpp
  sed -i '13 a \#include \<vector\>' mains/vector_main2.cpp
  clang++ -Wall -Werror -Wextra -pedantic -std=c++98 -fsanitize=address main.cpp mains/list_main.cpp mains/vector_main2.cpp -o mains/real
  ./mains/my > mains/my.txt
  ./mains/real > mains/real.txt
  check "Vector"
  rm mains/vector_main2.cpp mains/my mains/real mains/my.txt mains/real.txt
fi
